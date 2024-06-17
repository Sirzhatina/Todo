from conan import ConanFile
from conan.tools.cmake.layout import cmake_layout

class BoostPkg(ConanFile):
    settings = "os", "arch", "build_type", "compiler"

    requires = "boost/1.85.0"
    generators = "CMakeDeps", "CMakeToolchain"

    def layout(self):
        cmake_layout(self)