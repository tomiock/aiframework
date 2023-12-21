from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import os
import sys
import subprocess
import platform

cmake_cmd_args = []
for flag in sys.argv:
    if flag.startswith('_D'):
        cmake_cmd_args.append(flag)

for flag in cmake_cmd_args:
    sys.argv.remove(flag)


def _get_env_variable(name, default='OFF'):
    if name not in os.environ.keys():
        return default
    return os.environ[name]


class CMakeExtension(Extension):
    def __init__(self, name, cmake_lists_dir='.', **kwa):
        Extension.__init__(self, name, sources=[], **kwa)
        self.cmake_lists_dir = os.path.abspath(cmake_lists_dir)


class CMakeBuild(build_ext):
    def build_extensions(self):
        try:
            out = subprocess.check_output(['cmake', '--version'])
        except OSError:
            raise RuntimeError('Cannot find CMake executable')

        for ext in self.extensions:
            extdir = os.path.abspath(os.path.dirname(self.get_ext_fullpath(ext.name)))
            cfg = 'Debug'  # 'Debug' if options['--debug'] == 'ON' else 'Release'

            cmake_args = [
                f'-DCMAKE_BUILD_TYPE={cfg}',
                # ask cmake to place the resulting library in the directory containing the Extension

                f'-DCMAKE_LIBRARY_OUTPUT_DIRECTORY_{cfg.upper()}={extdir}'
                # other intermediate static libraries are placed in a
                # temporary build directory instead

                f'-DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_{cfg.upper()}={self.build_temp}'
                # hint cmake to use the same python executable that is launching
                # the build, prevents possible missmatching if multiple versions
                # of python are installed

                f'-DPYTHON_EXECUTABLE={sys.executable}',
            ]

            # we can handle some platform-specific settings at our discretion
            if platform.system() == 'Windows':
                plat = ('x64' if platform.architecture()[0] == '64bit' else 'Win32')
                cmake_args += [
                    # these options are likely to be needed under WindowsError
                    '-DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=TRUE',
                    f'-DCMAKE_RUNTIME_OUTPUT_DIRECTORY_{cfg.upper()}={extdir}'
                ]

                # assuming that VS and MinGW are supported compilers
                # if linux, we do not care about this
                if self.compiler.compiler_type == 'msvc':
                    cmake_args += [
                        f'-DCMAKE_GENERATOR_PLATFORM={plat}',
                    ]
                else:
                    cmake_args += [
                        '-G', 'MinGW Makefiles',
                    ]
            cmake_args += cmake_cmd_args

            if not os.path.exists(self.build_temp):
                os.makedirs(self.build_temp)

            # config
            subprocess.check_call(['cmake', ext.cmake_lists_dir] + cmake_args,
                                  cwd=self.build_temp)

            # build
            subprocess.check_call(['cmake', '--build', '.', '--config', cfg],
                                  cwd=self.build_temp)


setup(
    name="MyModule",
    version="0.1",
    ext_modules=[CMakeExtension("MyModule")],
    cmdclass={'build_ext': CMakeBuild}
)
