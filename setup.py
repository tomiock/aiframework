from setuptools import Extension, setup


setup(
    name="aiframework",
    version="0.0.1",
    ext_modules=[Extension("aiframework", ["src/py_module.c"])],
)
