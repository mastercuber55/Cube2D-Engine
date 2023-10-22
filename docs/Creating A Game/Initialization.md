---
title: Initialization
layout: default
parent: Creating A Game
nav_order: 2
---

# Initialization

Any projects needs a initializer of its own, so create a file in your desired scripts folder with your desired name ( I Like Scripts/Main.wren ) but of course you need it specified in `Game.wren`

For now, lets make a simple game where you have to move player around.

```js
// File: Main.wren
import "raylib" for COLOR
import "Cube2D" for Engine, Scene, Rect

class SceneGame is Scene {
	construct new() {
		_Player = Rect.new(0, 0, 32, 32)
		_Player.Tint = COLOR["RED"]

		super()
	}
	Update() {
		var Speed = 10
		// We are still too busy to look into why we use .Base here.
		Engine.WASDMovement(_Player.Base, Speed)
	}
	Draw() {
		_Player.Draw()
	}
}

SceneGame.new().Run()

```

Very Minimal, but you can do a lots of initialization stuff for your game like loading config files etc.
speaking of loading config files, you surely want some sort of configuration data saving file etc.
And Cube2D Engine provides nothing of a sort but there's a alternative that takes no time at all to setup.
We will look into that later though, cuz can't start compilacated stuff even before you know anything.


You can also use that file as following supposing that file is located at `Scripts/Scenes/SceneGame.wren`
```js
// File: Main.wren
import "Scenes/SceneGame.wren" for SceneGame

SceneGame.new().Run()

```

As you see you are importing `SceneGame` only not the whole file so any code in that file won't be ran