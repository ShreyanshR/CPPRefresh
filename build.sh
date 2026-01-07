#!/bin/bash

# Build and run script for CPPRefresh

set -e  # Exit on error

BUILD_DIR="build"
PROJECT_NAME="CPPRefresh"

# Create build directory if it doesn't exist
mkdir -p $BUILD_DIR

# Navigate to build directory
cd $BUILD_DIR

# Configure and build
echo "🔨 Configuring CMake..."
cmake .. -DCMAKE_BUILD_TYPE=Release

echo "🔨 Building project..."
cmake --build . -j$(sysctl -n hw.ncpu 2>/dev/null || nproc 2>/dev/null || echo 4)

# Run the executable
echo "🚀 Running $PROJECT_NAME..."
echo "----------------------------------------"
./$PROJECT_NAME
