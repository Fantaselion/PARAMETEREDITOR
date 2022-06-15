from pathlib import Path
from distutils.core import setup, Extension
from Cython.Build import cythonize

PARAMETEREDITOR_module = Extension('Simple_PARAMETER_EDITOR.PARAMETEREDITOR',
                sources=['Simple_PARAMETER_EDITOR_wrapper.pyx', 'Simple_PARAMETER_EDITOR.cpp'],
                zip_safe=False,
                language='c++')

setup(
    name="Prime_Stat_editor",
    version="1.0",
    description="Randomizes enemy stat values for most of the enemies in the game "Metroid Prime".",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/?/?",
    author="Fantaselion",
    author_email="fantaselion@gmail.com",
    license="MIT",
    package_dir =
        = src
    packages=['Simple_PARAMETER_EDITOR'],
    python_requires = >=3.10
    install_requires=[
        'cython',
    ext_modules=cythonize(PARAMETEREDITOR_module)
)
