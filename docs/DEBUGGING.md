# Debugging Guide

This guide explains how to debug C++ code in this project using breakpoints, similar to Visual Studio.

## Prerequisites

1. **VS Code C++ Extension**: Install the "C/C++" extension by Microsoft
   - Open VS Code Extensions (Cmd+Shift+X)
   - Search for "C/C++"
   - Install the Microsoft extension

2. **Debug Build**: Make sure you build with debug symbols:
   ```bash
   make debug
   ```

## Debugging in VS Code

### Step 1: Build Debug Version
First, build the debug version (this adds `-g` flag for debug symbols):
```bash
make debug
```

### Step 2: Set Breakpoints
- Click in the gutter (left of line numbers) to set a breakpoint
- A red dot will appear indicating the breakpoint is set

### Step 3: Start Debugging
- Press `F5` or go to Run → Start Debugging
- Select "C++ Debug (LLDB)" (default on macOS) or "C++ Debug (GDB)" (Linux)
- The debugger will start and stop at your breakpoints

### Step 4: Debug Controls
- **F5**: Continue
- **F10**: Step Over
- **F11**: Step Into
- **Shift+F11**: Step Out
- **Shift+F5**: Stop Debugging

### Debug Views
- **Variables**: See variable values in the current scope
- **Watch**: Add expressions to monitor
- **Call Stack**: See the function call hierarchy
- **Breakpoints**: Manage all breakpoints

## Command-Line Debugging

### Using LLDB (macOS default)
```bash
# Build debug version
make debug

# Start LLDB
lldb build/debug/cpprefresh

# In LLDB:
(lldb) breakpoint set --file main.cpp --line 10
(lldb) run
(lldb) print var
(lldb) continue
(lldb) quit
```

### Using GDB (Linux/alternative)
```bash
# Build debug version
make debug

# Start GDB
gdb build/debug/cpprefresh

# In GDB:
(gdb) break main.cpp:10
(gdb) run
(gdb) print var
(gdb) continue
(gdb) quit
```

## Troubleshooting

### Breakpoints Not Working?

1. **Make sure you built with debug symbols**:
   ```bash
   make clean
   make debug
   ```

2. **Verify the executable has debug info**:
   ```bash
   # macOS
   file build/debug/cpprefresh
   # Should show "not stripped" or similar
   
   # Or check with:
   lldb build/debug/cpprefresh
   (lldb) image dump sections
   ```

3. **Check VS Code is using the debug build**:
   - Open `.vscode/launch.json`
   - Verify `program` points to `build/debug/cpprefresh`
   - Not `build/cpprefresh` (that's the release build)

4. **Rebuild after code changes**:
   - Always run `make debug` after changing code
   - Or use the preLaunchTask (automatic rebuild before debugging)

### Debugger Not Found?

- **macOS**: LLDB comes with Xcode Command Line Tools
  ```bash
  xcode-select --install
  ```

- **Linux**: Install GDB
  ```bash
  sudo apt-get install gdb  # Ubuntu/Debian
  ```

## Quick Reference

| Action | Command/Shortcut |
|--------|-----------------|
| Build Debug | `make debug` |
| Build Release | `make` or `make all` |
| Run Debug | `make run-debug` |
| Clean Build | `make clean` |
| VS Code Debug | `F5` |
| Set Breakpoint | Click gutter (left of line number) |
