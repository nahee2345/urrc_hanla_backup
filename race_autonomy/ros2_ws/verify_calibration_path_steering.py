#!/usr/bin/env python3
import argparse, math, sys, os
import numpy as np

def load_modules(ws):
    src = os.path.join(ws, "src", "camera_navigation", "camera_navigation")
    if src not in sys.path:
        sys.path.insert(0, src)
    import ground_plane_calibration as gpc
    import pure_pursuit as pp
    return gpc, pp

def load_mount_yaml(path):
    import yaml
    with open(path) as f:
        data = yaml.safe_load(f)
    return data["/**"]["ros__parameters"]["camera_mount"]

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--ws", required=True)
    ap.add_argument("--mount", required=True)
    ap.add_argument("--fx", type=float, default=430.0)
    ap.add_argument("--fy", type=float, default=430.0)
    ap.add_argument("--cx", type=float, default=424.0)
    ap.add_argument("--cy", type=float, default=240.0)
    ap.add_argument("--height", type=int, default=480)
    ap.add_argument("--speed", type=float, default=2.0)
    ap.add_argument("--wheelbase", type=float, default=0.73)
    ap.add_argument("--lookahead", type=float, default=3.0)
    ap.add_argument("--max-steering", type=float, default=27.0)
    args = ap.parse_args()

    gpc, pp = load_modules(args.ws)
    m = load_mount_yaml(args.mount)

    print("="*60); print("STEP 0  mount config"); print("="*60)
    mount = gpc.CameraMountConfig(
        configured=bool(m.get("configured", False)),
        position_x_m=float(m.get("position_x_m", 0.0)),
        position_y_m=float(m.get("position_y_m", 0.0)),
        height_z_m=float(m.get("height_z_m", 0.0)),
        reference_roll_deg=float(m.get("reference_roll_deg", 0.0)),
        reference_pitch_deg=float(m.get("reference_pitch_deg", 0.0)),
        reference_yaw_deg=float(m.get("reference_yaw_deg", 0.0)),
    )
    for k in ("configured","position_x_m","position_y_m","height_z_m",
              "reference_roll_deg","reference_pitch_deg","reference_yaw_deg"):
        print(f"  {k:22s} = {getattr(mount,k)}")
    print(f"  is_usable()            = {mount.is_usable()}")
    if not mount.is_usable():
        print("\n[!] is_usable()=False. configured:true + height_z_m>0 필요.")
        return 2

    print("\n"+"="*60); print("STEP 1  effective extrinsic (IMU delta=0)"); print("="*60)
    roll, pitch, yaw, R, quat = gpc.compose_effective_orientation(
        (mount.reference_roll_deg, mount.reference_pitch_deg, mount.reference_yaw_deg),
        delta_pitch_deg=0.0, delta_roll_deg=0.0)
    print(f"  effective rpy (deg)    = roll {roll:.3f}, pitch {pitch:.3f}, yaw {yaw:.3f}")
    cam_pos = np.array([mount.position_x_m, mount.position_y_m, mount.height_z_m])
    print(f"  camera_position_base   = {cam_pos.tolist()}")

    print("\n"+"="*60); print("STEP 2  pixel path -> metric projection"); print("="*60)
    intr = gpc.Intrinsics(fx=args.fx, fy=args.fy, cx=args.cx, cy=args.cy)
    ys = np.linspace(args.height-1, int(args.height*0.55), 12)
    pixel_path = [(args.cx, float(y)) for y in ys]
    metric = gpc.project_pixel_path_to_metric(
        pixel_path, intr, R, cam_pos,
        max_range_m=float(m.get("metric_path_max_range_m", 30.0)))
    print(f"  pixel points in        = {len(pixel_path)}")
    print(f"  metric points out      = {len(metric)}")
    for pt in metric:
        print(f"    x={pt[0]:.3f} m, y={pt[1]:.3f} m")
    if len(metric) < 2:
        print("\n[!] metric point < 2. pitch 부호/값 또는 intrinsic 확인.")
        return 3

    print("\n"+"="*60); print("STEP 3  pure pursuit (speed + steering)"); print("="*60)
    steer = pp.steering_angle_deg(
        metric, speed_mps=args.speed, wheelbase_m=args.wheelbase,
        min_lookahead_m=args.lookahead, max_lookahead_m=args.lookahead,
        lookahead_speed_gain=0.0, max_steering_deg=args.max_steering)
    print(f"  commanded speed        = {args.speed:.2f}  (/cmd_drive)")
    print(f"  steering angle         = {steer:.3f} deg  (/cmd_wheel)")
    ok_range = -args.max_steering-1e-6 <= steer <= args.max_steering+1e-6
    print(f"  in [-{args.max_steering:.0f},+{args.max_steering:.0f}] = {ok_range}")
    print(f"  finite                 = {math.isfinite(steer)}")

    print("\n"+"="*60); print("RESULT"); print("="*60)
    print(f"  metric projection      : {'OK' if len(metric)>=2 else 'FAIL'}")
    print(f"  steering finite/in-range: {'OK' if (ok_range and math.isfinite(steer)) else 'FAIL'}")
    print(f"  centered path -> ~0 str : {'OK' if abs(steer)<3.0 else 'CHECK yaw/cx'}")
    print("\n  주의: 오프라인 계산. 실차 VALID 는 IMU 복구 후 별도 통과 필요.")
    return 0

if __name__ == "__main__":
    sys.exit(main())
