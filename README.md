# SDL2 Graphics Setup

Pfff... Are you still using `graphics.h` for displaying graphics using C/C++ ?
That "ms-dos stuff" is old fashioned now in windows and never worked on linux to begin with.

This repository provides a sample setup template for using **SDL2** in your C/C++ projects to handle graphics rendering, events, and more. I have made it such that you don't have to initialize/close the SDL each and everytime you write a new code. I have provided a header for this purpose. 

This README will guide you through the process of setting up SDL2 on both **Windows** and **Linux**.

---

## Table of Contents

- [What is SDL2?](#what-is-sdl2)
- [Windows Setup](#windows-setup)
- [Linux Setup](#linux-setup)

---

## What is SDL2?

SDL2 (Simple DirectMedia Layer 2) is an open-source, cross-platform multimedia library designed to handle graphics, events, audio, and more. It provides a unified API to make it easier for developers to create cross-platform applications without worrying about specific operating system details.

It is especially popular for creating games, graphical applications, and simulations. Unlike older libraries such as `graphics.h`, SDL2 is modern, efficient, and works seamlessly across different platforms (Windows, Linux, macOS, etc.).

SDL2 replaces the need for platform-specific graphics libraries, providing an abstraction layer over the graphics hardware.

---

## Windows Setup

Follow these steps to set up SDL2 for your C++ project on **Windows**.

### 1. Reference this video: [SDL2 Setup Tutorial](https://youtu.be/H08t6gD1Y1E?si=pC5MXzJEne0Wvq5A) for downloading and setting up SDL2 in windows
- You may download the required release from the official [SDL Github Repo](https://github.com/libsdl-org/SDL/releases)

### 2. Setup Your IDE (optional)
#### For Visual Studio:
- Open your project in Visual Studio.
- Right-click on the project name and go to **Properties**.
- Under **VC++ Directories**, add the following paths:
  - **Include Directories**: Point to the `include` folder inside the extracted SDL2 folder.
  - **Library Directories**: Point to the `lib` folder inside the extracted SDL2 folder.

#### For MinGW/GCC:
- Open your terminal or IDE (e.g., Code::Blocks or Visual Studio Code).
- Add the path to the `include` directory of SDL2 in your build system or IDE settings.
- Link the SDL2 library by adding `-lSDL2` to your linker flags.
- Ensure the `SDL2.dll` file is located in the same folder as your executable, or add it to your system path.

### 3. Write Your First SDL2 Program
Clone this repo, create a new C/C++ source file (e.g., `main.cpp`) and add the "sdl_custom_header.h" file given in this repo on top of your code by :
    ```
    
    #include "sdl_custom_header.h"
    #include <stdio.h>
    //I've created the drawFunc in the sdl_custom_header.h
    void drawFunc(SDL_Renderer *renderer, float points[]){
        ...
    }
    int main(){
        ...

        float points[4] = {x1,y1,x2,y2};
        SDL_Start(points);
        return 0;
    }
    ```

---

## Linux Setup

Follow these steps to set up SDL2 for your C++ project on **Linux**.

### 1. Install SDL2
Open the terminal and type in the following commands for your respective linux package manager.
#### For Debian/Ubuntu-based distros:
    ```bash
    sudo apt-get update
    sudo apt-get install libsdl2-dev
    ```
#### For Fedora:
    ```bash
    sudo dnf install SDL2-devel
    ```
#### For Arch Linux:
    ```bash
    sudo pacman -S sdl2
    ```

### 2. Create your C/C++ source file or clone this repository
Create a new C++ source file (e.g., main.cpp) and add the same test code as shown in the Windows Setup section

### 3. Compile Your Code
```bash
g++ main.cpp -o app -lSDL2  #for cpp source file
#or
gcc -o app main.c -lSDL2    #for c source file
```

Enjoy SDL2