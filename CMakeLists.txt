cmake_minimum_required(VERSION 3.24)

project(
    cpp-practice 
    VERSION 0.0.1
    DESCRIPTION "practice and test cpp"
    HOMEPAGE_URL "https://github.com"
    LANGUAGES CXX
)

# https://docs.conan.io/en/latest/integrations/build_system/cmake/cmake_generator.html#targets-approach
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# https://cmake.org/cmake/help/latest/command/file.html#filesystem
# The GLOB_RECURSE mode will traverse all the subdirectories of the matched directory and match the files.
# If the CONFIGURE_DEPENDS flag is specified, CMake will add logic to the main build system check target
# to rerun the flagged GLOB commands at build time. If any of the outputs change, CMake will regenerate the build system.
file(GLOB_RECURSE include CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE src CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.[ch]pp")

add_executable(${PROJECT_NAME} ${include} ${src})

set_target_properties(
  ${PROJECT_NAME} 
  PROPERTIES

  # https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html#prop_tgt:CXX_STANDARD
  # This property specifies the C++ standard whose features are requested to build this target. 
  # For some compilers, this results in adding a flag such as -std=gnu++11 to the compile line. 
  # For compilers that have no notion of a standard level, such as Microsoft Visual C++ before
  # 2015 Update 3, this has no effect.
  CXX_STANDARD 23

  # https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD_REQUIRED.html#prop_tgt:CXX_STANDARD_REQUIRED
  # If this property is set to ON, then the value of the CXX_STANDARD target property is treated as a requirement. 
  # If this property is OFF or unset, the CXX_STANDARD target property is treated as optional and may "decay" to a
  # previous standard if the requested is not available. For compilers that have no notion of a standard level, 
  # such as MSVC 1800 (Visual Studio 2013) and lower, this has no effect.
  CXX_STANDARD_REQUIRED ON

  # https://cmake.org/cmake/help/latest/prop_tgt/CXX_EXTENSIONS.html#prop_tgt:CXX_EXTENSIONS
  # This property specifies whether compiler specific extensions should be used. For some compilers,
  # this results in adding a flag such as -std=gnu++11 instead of -std=c++11 to the compile line.
  # This property is ON by default. The basic C++ standard level is controlled by the CXX_STANDARD target property.
  CXX_EXTENSIONS OFF
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic)

target_link_libraries(
  ${PROJECT_NAME} 
  CONAN_PKG::fmt 
  CONAN_PKG::nlohmann_json 
  CONAN_PKG::cpr
  CONAN_PKG::abseil
)
