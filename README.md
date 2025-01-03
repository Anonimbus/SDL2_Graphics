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

## Windows Setup [time : 2-8 mins]

Reference this video: [SDL2 Setup Tutorial](https://youtu.be/H08t6gD1Y1E?si=pC5MXzJEne0Wvq5A) or Follow along these steps to set up SDL2 for your C++ project on **Windows**.

### 1.  For downloading SDL2
Steps are as follows : 
- You may download the required release from the official [SDL Github Repo](https://github.com/libsdl-org/SDL/releases) here we download the Development Library : SDL2-devel-2.xx.xx-mingw.tar.gz

### 2. Extract the development library
Open command prompt and cd to your download location and type in :
```cmd
mkdir sdl

tar -xvzf SDL2-devel-2.xx.xx-mingw.tar.gz -C sdl
```

### 3. Copy the required files/folders to your graphics folder
- copy the i686-w64-mingw32/**include** and i686-w64-mingw32/**lib** folders to your Graphics/src  directory
- copy the bin/**SDL2.dll** on same level as your src folder i.e. at Graphics folder


### 4. Write Your First SDL2 Program
Clone this repo, create a new C/C++ source file (e.g., `main.cpp`) and add the "sdl_custom_header.h" file given in this repo on top of your code by :
```c/cpp
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

### 5. Compile your c/cpp code

You can do 

```terminal
g++ -Isrc/Include -Lsrc/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2
```
or you can use the Makefile 

```makefile
all:
    g++ -Isrc/Include -Lsrc/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2
```
If it still doesn't work, go to the C/C++ extension, and you could change the include path from ${default} to  ${workspaceFolder}/**

---

## Linux Setup [time : ~1 min]

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