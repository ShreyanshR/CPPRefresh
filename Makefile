# Simple Makefile for quick builds
# Usage: make (or make run) - Release build
# Usage: make debug - Debug build with debug symbols
# Usage: make run-debug - Build debug and run

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./include
CXXFLAGS_DEBUG = $(CXXFLAGS) -g -O0 -DDEBUG
CXXFLAGS_RELEASE = $(CXXFLAGS) -O3 -DNDEBUG
SRCDIR = src
INCDIR = include
BUILDDIR = build
BUILDDIR_DEBUG = build/debug
TARGET = $(BUILDDIR)/cpprefresh
TARGET_DEBUG = $(BUILDDIR_DEBUG)/cpprefresh

# Find all source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)
OBJECTS_DEBUG = $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR_DEBUG)/%.o)

# Default target (Release)
all: $(TARGET)

# Debug target
debug: $(TARGET_DEBUG)

# Create release executable
$(TARGET): $(OBJECTS) | $(BUILDDIR)
	$(CXX) $(CXXFLAGS_RELEASE) $(OBJECTS) -o $(TARGET)
	@echo "✅ Release build complete!"

# Create debug executable
$(TARGET_DEBUG): $(OBJECTS_DEBUG) | $(BUILDDIR_DEBUG)
	$(CXX) $(CXXFLAGS_DEBUG) $(OBJECTS_DEBUG) -o $(TARGET_DEBUG)
	@echo "✅ Debug build complete! (with -g flag for debugging)"

# Compile source files to object files (Release)
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS_RELEASE) -c $< -o $@

# Compile source files to object files (Debug)
$(BUILDDIR_DEBUG)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR_DEBUG)
	$(CXX) $(CXXFLAGS_DEBUG) -c $< -o $@

# Create build directories
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR_DEBUG):
	mkdir -p $(BUILDDIR_DEBUG)

# Run the program (Release)
run: $(TARGET)
	@echo "🚀 Running $(TARGET)..."
	@echo "----------------------------------------"
	./$(TARGET)

# Run the program (Debug)
run-debug: $(TARGET_DEBUG)
	@echo "🚀 Running $(TARGET_DEBUG) (Debug)..."
	@echo "----------------------------------------"
	./$(TARGET_DEBUG)

# Clean build artifacts
clean:
	rm -rf $(BUILDDIR)
	@echo "🧹 Cleaned build directory"

# Rebuild from scratch
rebuild: clean all

.PHONY: all debug run run-debug clean rebuild
