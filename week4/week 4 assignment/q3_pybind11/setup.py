from setuptools import setup, Extension
import pybind11

ext_modules = [
    Extension(
        "strcat_cpp",
        ["main.cpp"],
        include_dirs=[pybind11.get_include()],
        language="c++"
    )
]

setup(
    name="strcat_cpp",
    version="1.0",
    ext_modules=ext_modules
)
