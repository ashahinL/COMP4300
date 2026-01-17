# COMP4300 Game Development

A clean repository for following along with the COMP4300 Game Development course on YouTube.

## Setup

### Prerequisites

- macOS with Homebrew
- CMake 3.22+
- Ninja build system

### Installation

1. **Install dependencies:**
   ```bash
   brew install sfml pkg-config ninja
   ```

2. **Clone external dependencies:**
   ```bash
   git submodule update --init --recursive
   ```
   Or manually:
   ```bash
   cd external
   git clone --depth 1 --branch v1.91.1 https://github.com/ocornut/imgui.git
   git clone --depth 1 --branch v3.0 https://github.com/SFML/imgui-sfml.git
   ```

## Building & Running

### Available Presets

- `lecture03` — ImGui + SFML integration
- `assignment01` — Assignment placeholder

### Build a specific preset

```bash
cmake --preset lecture03
cmake --build --preset lecture03
```

### Run the executable

```bash
./build/lecture03/bin/lecture03
```

Or use the custom `run` target:

```bash
cmake --build --preset lecture3 --target run
```

## Project Structure

```
comp4300/
├── CMakeLists.txt           # Main build config with preset support
├── CMakePresets.json        # Preset definitions for easy switching
├── README.md                # This file
├── .gitignore               # Git ignore rules
├── .vscode/                 # VS Code configuration
│   ├── c_cpp_properties.json # IntelliSense paths
│   └── settings.json        # Editor settings
├── apps/                    # Lecture and assignment code
│   ├── lecture03/
│   └── assignment01/
├── external/                # Third-party dependencies
│   ├── imgui/
│   └── imgui-sfml/
└── build/                   # Build output (generated)
```

## Adding New Lectures or Assignments

1. Create a new directory under `apps/`:
   ```bash
   mkdir apps/lecture03
   touch apps/lecture03/main.cpp
   ```

2. Add a new preset to `CMakeLists.txt`:
   ```cmake
   elseif(APP STREQUAL "lecture03")
       add_executable(lecture03 apps/lecture03/main.cpp)
       target_link_libraries(lecture03 PRIVATE SFML::Graphics SFML::Window SFML::System)
       # ... add custom target run
   endif()
   ```

3. Add to `CMakePresets.json`:
   ```json
   {
     "name": "lecture03",
     "displayName": "Lecture 03",
     ...
   }
   ```

## Tools Used (First 3 Lectures)

- **SFML 3.0.2** — Graphics and windowing
- **ImGui 1.91.1** — UI widgets (Lecture 2+)
- **ImGui-SFML 3.0** — SFML backend for ImGui
- **CMake + Ninja** — Build system
- **Clang 17.0.0** — Development environment
