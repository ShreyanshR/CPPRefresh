# CPPRefresh

A modern C++ project structure with CMake build system.

## Project Structure

```
CPPRefresh/
├── CMakeLists.txt      # CMake build configuration
├── README.md           # This file
├── .gitignore          # Git ignore patterns
├── build/              # Build output directory (generated)
├── docs/               # Documentation
├── include/            # Header files (.h, .hpp)
│   └── utils.h
├── src/                # Source files (.cpp)
│   ├── main.cpp
│   └── utils.cpp
└── tests/              # Test files
```

## Building and Compiling

### Quick Start (Recommended) 🚀

**Option 1: Use the build script** (easiest):
```bash
./build.sh
```

**Option 2: Use Makefile** (simple and fast):
```bash
make run
```

That's it! Both will build and run your project automatically.

### Prerequisites

- CMake (version 3.15 or higher) - for `build.sh`
- C++ compiler (GCC, Clang, or MSVC)
  - macOS: Xcode Command Line Tools (`xcode-select --install`)
  - Linux: `sudo apt-get install build-essential` (Ubuntu/Debian)
  - Windows: Visual Studio or MinGW

### Build Options

**Using Makefile:**
- `make` or `make run` - Build and run
- `make clean` - Clean build artifacts
- `make rebuild` - Clean and rebuild

**Using build.sh:**
- `./build.sh` - Build and run (uses CMake)

**Manual CMake build:**
1. `mkdir -p build && cd build`
2. `cmake ..`
3. `cmake --build .`
4. `./CPPRefresh`

### Alternative: Direct Compilation (without CMake)

For simple projects, you can compile directly:
```bash
g++ -std=c++17 -I./include src/*.cpp -o cpprefresh
./cpprefresh
```

## Development Workflow

1. Add header files to `include/`
2. Add implementation files to `src/`
3. Update `CMakeLists.txt` if adding new source files (or use GLOB_RECURSE)
4. Rebuild: `cd build && cmake --build .`

## Adding Dependencies

For external libraries, update `CMakeLists.txt`:
```cmake
# Example: Find a package
find_package(Boost REQUIRED COMPONENTS system filesystem)

# Link libraries
target_link_libraries(${PROJECT_NAME} Boost::system Boost::filesystem)
```

## Testing

GoogleTest is wired through `tests/CMakeLists.txt`.

1. Configure with tests enabled:
```bash
cmake -S . -B cmake-build-debug -DBUILD_TESTING=ON
```
2. Build the test target:
```bash
cmake --build cmake-build-debug --target lru_cache_tests
```
3. Run tests:
```bash
cd cmake-build-debug && ctest --output-on-failure
```

If `GTest` is already installed on your machine, CMake will use it.
Otherwise CMake downloads GoogleTest from GitHub during configure.
