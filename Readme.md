

````markdown
# SFML Basics & Snake Game

A collection of introductory **C++** projects using **SFML 3.0**. This repository contains basic window management examples, sprite manipulation, and a fully functional **Snake Game**.

## 📂 Project Contents

| Executable | Source File | Description |
| :--- | :--- | :--- |
| **game** | `main.cpp` | Basic window creation and event handling (resize events, text entry logging). |
| **game1** | `tut1.cpp` | Sprite manipulation demo. Move the sprite using `D` and `S` keys. |
| **snake** | `snake.cpp` | A complete Snake game implementation. Controls: `W` (Up), `A` (Left), `S` (Down), `D` (Right). |

## 🛠️ Prerequisites

* **C++ Compiler** (supporting C++17)
* **CMake** (Version 3.16 or higher)
* **vcpkg** (Package Manager)

## ⚙️ Setup & Installation

### 1. Install SFML via vcpkg
If you haven't installed SFML yet, run the following commands in your terminal (Windows):

```powershell
git clone [https://github.com/microsoft/vcpkg](https://github.com/microsoft/vcpkg)
.\vcpkg\bootstrap-vcpkg.bat
.\vcpkg\vcpkg install sfml
````

### 2\. Configure CMake

You must tell CMake where SFML is installed.

1.  Open `CMakeLists.txt`.
2.  Locate the line:
    ```cmake
    set(SFML_DIR "C:/Users/Dell/Desktop/SFML_VCPKG/vcpkg/installed/x64-windows/share/sfml")
    ```
3.  **Replace the path** inside the quotes with the actual path to your `vcpkg/installed/x64-windows/share/sfml` directory.

## 🏗️ Build Instructions

Run these commands from the project root directory to generate build files and compile all executables:

1.  **Configure:**

    ```bash
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
    ```

2.  **Build:**

    ```bash
    cmake --build build --config Release
    ```

## ▶️ How to Run

Once built, the executables will be located in the `build/Release` folder. You can run them from the terminal:

  * **Run Basic Window:**
    ```bash
    ./build/Release/game.exe
    ```
  * **Run Sprite Demo:**
    ```bash
    ./build/Release/game1.exe
    ```
  * **Run Snake Game:**
    ```bash
    ./build/Release/snake.exe
    ```

> **Note:** Ensure the image file `download.png` is in the same directory where you run the executable (or in the project root depending on how your debugger is configured), as `snake.cpp` and `tut1.cpp` require it to load textures.

```
```
