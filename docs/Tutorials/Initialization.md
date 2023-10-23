---
title: Initialization
layout: default
parent: Tutorials
nav_order: 2
---

# Initialization

Any projects needs a initializer of its own, so create a file in your desired scripts folder with your desired name ( I Like Scripts/Main.wren ) but of course you need it specified in `Game.wren`

For now, lets make a simple game where you have to move player around.

```js
// File: Main.wren
// import whatever you need.
import "raylib" for RL, COLOR
import "raymath" for RM
import "Cube2D" for Engine, Scene, Rect

// Sorry, Coudn't think of much here.

```
**The above code has been tested with correct paths.**
Very Minimal, but you can do a lots of initialization stuff for your game like loading config files etc.
speaking of loading config files, you surely want some sort of configuration data saving file etc.
And Cube2D Engine provides nothing of a sort but there's a alternative that takes no time at all to setup.
We will look into that later though, cuz can't start compilacated stuff even before you know anything.