# kuliya for C

Algeria's college hierarchy dataset as a C library

# Installation

You can use `kuliya` library with one of these 2 options:

1. Build it locally as it shown in [Get Started](#get-started) section then copy `kuliya.h` and `data.h` to your project.
   
2. Use conan package manager in your CMake project by following these steps:
    - Add `kuliya` recipe to your `conanfile.txt`:
    ```
    [requires]
    kuliya/1.0.0

    [generators]
    CMakeDeps
    CMakeToolchain
    ```
    - Install the recipe with conan:
    ```sh
    conan install . --output-folder=build --build=missing
    ```
    - Update your `CMakeLists.txt` file accordingly:
    ```cmake
    cmake_minimum_required(VERSION 3.15)
    project(sandbox C)

    find_package(kuliya REQUIRED)

    add_executable(${PROJECT_NAME} src/main.c)

    target_link_libraries(${PROJECT_NAME} kuliya::kuliya)
    ```
    - Build and run your executable.

You can check the usage [here](#usage).

# Prerequisites

- [CMake](https://cmake.org/download/) build system (minimum required version 3.19)
- [Conan](https://conan.io/downloads) package manager
- [Clang](https://clang.llvm.org/get_started.html) or [GCC](https://gcc.gnu.org/releases.html) compiler (on macOS clang comes with the developer tools)
- [Doxygen](https://www.doxygen.nl/download.html) docs generator
- Any IDE out there, preferably [VSCode](https://code.visualstudio.com/download) with the following extensions:
  - [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
  - [CMake](https://marketplace.visualstudio.com/items?itemName=twxs.cmake)
  - [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
  - [conan-extension](https://marketplace.visualstudio.com/items?itemName=konicy.conan-extension)

# Get Started

- Install build dependencies:
  ```sh
  cd c && conan install . --output-folder=build --build=missing
  ```
- Click on CMake Tools icon <img src="https://ms-vscode.gallerycdn.vsassets.io/extensions/ms-vscode/cmake-tools/1.18.16/1711685798086/Microsoft.VisualStudio.Services.Icons.Default" width="20px"/> in the extensions sidebar (Open [CMakeLists.txt](./CMakeLists.txt) if it doesn't appear for some reason).
- Follow these steps:

https://github.com/dzcode-io/kuliya/assets/48713070/f2037ee9-68a9-462d-aa1c-c33699d8f05f

- To build docs locally:
  ```sh
  cd c && doxygen
  ```

# Usage

```c
#include <stdio.h>
#include <kuliya.h>

int main(void)
{
    kuliya_init();
    kuliya_schema *res = get_node_by_path("umkb/fst/dee/sec");
    if (res != NULL)
    {
        printf("%s\n", res->name.en);
    }
    kuliya_deinit();
}
```

Check practical example usage [here](./example/main.c).

# Contribute

Feel free to ask for help in [#kuliya](https://dzcode.slack.com/archives/C01C0155CKC) group chat
