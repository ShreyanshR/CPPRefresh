# Simple Makefile for quick builds
# Usage: make (or make run)

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./include
SRCDIR = src
INCDIR = include
BUILDDIR = build
TARGET = $(BUILDDIR)/cpprefresh

# Find all source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

# Default target
all: $(TARGET)

# Create target executable
$(TARGET): $(OBJECTS) | $(BUILDDIR)
	$(CXX) $(OBJECTS) -o $(TARGET)
	@echo "✅ Build complete!"

# Compile source files to object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Run the program
run: $(TARGET)
	@echo "🚀 Running $(TARGET)..."
	@echo "----------------------------------------"
	./$(TARGET)

# Clean build artifacts
clean:
	rm -rf $(BUILDDIR)
	@echo "🧹 Cleaned build directory"

# Rebuild from scratch
rebuild: clean all

.PHONY: all run clean rebuild
