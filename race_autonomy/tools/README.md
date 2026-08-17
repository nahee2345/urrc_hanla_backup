# Vehicle terminal test

Run the low-stage Mega v21 test controller from one terminal:

```bash
cd /home/parkjinwoo/urrc_hanla
python3 race_autonomy/tools/vehicle_terminal_test.py
```

Do not run it at the same time as `arduino_serial_bridge_node`; only one
process may own the serial port. Press `Space`, `s`, or `x` for an immediate
software stop. Press `q` or `Ctrl+C` to stop and exit. The physical E-Stop
remains the primary emergency control.
