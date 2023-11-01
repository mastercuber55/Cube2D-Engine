---
title: Installation
layout: default
nav_order: 2
---

# Installation

## Windows
If you are on Windows64x, you are in luck, we provide precompiled executable for that.
btw, if you use Windows32x for some reason, let me know to create 32x executables for you in the [issues tab on github]

## Other
As for the moment, we provide no precompiled executable for any other platform
but we plan on providing a precompiled linux executable.

You will have to build the precompiled executable for your platform.
see [Build From Source] 

## Building From Source
### Requirements
- A C++17 Compiler Installed ( I Use MinGW32 )
- [raylib] Installed
- [wren] Installed

I see about compiler but having to install libraries seems a bit trouble so we will try to remove that need sooner or later.

### Install Engine
Once you have the requirements completed just run the following code.
```sh
git clone https://github.com/mastercuber55/Cube2D-Engine
cd Cube2D-Engine
git submodule init
git submodule update
mingw32-make // or however you do it for your Makefile
```

### Done

Thats it, you should now have Cube2D executable in that folder.
but you gotta learn how to use it of course.

[issues tab on github]: https://github.com/mastercuber55/Cube2D-Engine/Issues
[Build From Source]: https://just-the-docs.com/docs/navigation-structure/#Build-From-Source
[raylib]: https://raylib.com
[wren]: https://wren.io