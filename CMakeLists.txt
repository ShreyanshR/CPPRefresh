cmake_minimum_required(VERSION 3.15)
project(CPPRefresh VERSION 1.0.0 LANGUAGES CXX)

# Generate compile_commands.json for IDE IntelliSense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build type (Debug/Release)
# Default to Debug for better development experience
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Allow switching between Debug and Release
set(CMAKE_BUILD_TYPE "${CMAKE_BUILD_TYPE}" CACHE STRING "Choose the type of build." FORCE)
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files - exclude example files with their own main() functions
file(GLOB_RECURSE ALL_SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h" "include/*.hpp")

# Exclude example/test files that have their own main() functions
list(FILTER ALL_SOURCES EXCLUDE REGEX ".*/vector\\.cpp$")
list(FILTER ALL_SOURCES EXCLUDE REGEX ".*/vectors\\.cpp$")
list(FILTER ALL_SOURCES EXCLUDE REGEX ".*/unorderedMap\\.cpp$")

# Create executable

file(GLOB TEST_SOURCES "*.cpp")
if(TEST_SOURCES)
    add_executable(all_tests ${TEST_SOURCES})
endif()

#add_executable(${PROJECT_NAME} ${ALL_SOURCES} ${HEADERS}
        #src/MyVector.cpp
        #tests/test_myvector.cpp)

# Standalone target for debugging single files (e.g. RAII.cpp)
add_executable(RAII_standalone src/RAII.cpp)
target_compile_definitions(RAII_standalone PRIVATE RAII_STANDALONE)

# Sub-projects (each has its own src/, include/, CMakeLists.txt)
add_subdirectory(projects)

# Testing
include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

# Installation (optional)
if(TARGET ${PROJECT_NAME})
    install(TARGETS ${PROJECT_NAME} DESTINATION bin)
endif()
