---
title: Creating A Scene
layout: default
parent: Tutorials
nav_order: 3
---

# Creating A Scene

Lets create a simple scene where you can move around player.

- Create a folder named "Scenes" in your desired `Scripts` folder (optional)
- Create a file for your scene with your desired name ( I Prefer SceneExample )
- `import "Engine"`
- Create a class as following

```js
import "Engine"


class SceneExample is Scene {
	construct new() {

	}
}
```

As you see we are inheriting Scene from the Cube2D module for our usage. So first of all we need a constructer for our new `SceneExample` class which you can use like `SceneExample.new()` but since we are inheriting `Scene` class we can also call `Scene` classes methods so our class is ready to be used like `SceneExample.new().Run()`. 

- You probably wanna draw something to screen so lets draw a simple rectangle to screen for example.
- Add `Draw() {}` method to your class.
- `import "raylib" for COLOR`
-  also `import` `Rect` from `Cube2D`

```js
import "Cube2D" for Scene, Rect

class SceneExample is Scene {
	construct new() {
		_Player = Rect.new(0, 0, 32, 32) // Create a rectangle at (0, 0) with size (32, 32).
		_Player.Tint = COLOR["RED"] // Add a color to the rectangle.
	}
	Draw() { 
		_Player.Draw()
	}
}
```

- Now You probably also wanna controll that player.
- also `import` `Engine` from `Cube2D`
- Add `Update() {}` method to your class.

```cpp
import "Cube2D" for Engine, Scene, Rect
import "raylib" for COLOR

class SceneExample is Scene {
	construct new() {

		_Player = Rect.new(0, 0, 32, 32)
		_Player.Tint = COLOR["RED"]

		super()
	}
	Update() {
	
		var Speed = 24
		Engine.WASDMovement(_Player.Base, Speed)
	}
	Draw() {
		_Player.Draw()
	}
}
```

- You can also create a new scene that inherits `SceneExample` or any other scene to call methods from that.