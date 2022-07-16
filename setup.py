import sys
from pathlib import Path
from distutils.core import setup, Extension
from Cython.Build import cythonize

PARAMETEREDITOR_module = Extension('Simple_PARAMETER_EDITOR.PARAMETEREDITOR',
                sources=['Simple_PARAMETER_EDITOR_wrapper.pyx', 'PARAMETEREDITOR/Simple_PARAMETER_EDITOR.cpp'],
                zip_safe=False,
                language='c++')

this_directory = Path(__file__).parent
long_description = (this_directory / "README.md").read_text()

setup(
    name="PARAMETEREDITOR",
    version="1.06",
    description="Randomizes enemy stat values for most of the enemies in the game Metroid Prime.",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/Fantaselion/PARAMETEREDITOR",
    author="Fantaselion",
    author_email="fantaselion@gmail.com",
    license="MIT",
    packages=['PARAMETEREDITOR'],
    ext_modules=cythonize(PARAMETEREDITOR_module),
)
