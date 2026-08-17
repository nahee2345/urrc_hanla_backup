from glob import glob
from setuptools import find_packages, setup

package_name = "camera_navigation"
setup(
    name=package_name, version="0.1.0", packages=find_packages(),
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml", "README.md"]),
        ("share/" + package_name + "/launch", glob("launch/*.launch.py")),
        ("share/" + package_name + "/config", glob("config/*.yaml")),
    ],
    install_requires=["setuptools"], tests_require=["pytest"], zip_safe=True,
    maintainer="ww", maintainer_email="ww@todo.todo",
    description="Original-image-coordinate camera path generation",
    license="Apache-2.0",
    entry_points={"console_scripts": [
        "camera_path_controller_node=camera_navigation.camera_path_controller_node:main",
        "camera_image_path_node=camera_navigation.camera_image_path_node:main",
        "camera_metric_path_node=camera_navigation.camera_metric_path_node:main",
    ]},
)
