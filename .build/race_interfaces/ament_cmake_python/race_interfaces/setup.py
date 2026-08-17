from setuptools import find_packages
from setuptools import setup

setup(
    name='race_interfaces',
    version='0.1.0',
    packages=find_packages(
        include=('race_interfaces', 'race_interfaces.*')),
)
