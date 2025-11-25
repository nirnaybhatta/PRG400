from setuptools import setup, Extension

module = Extension('arraymodule', sources=['arraylib.c'])

setup(
    name='arraymodule',
    version='1.0',
    ext_modules=[module]
)
