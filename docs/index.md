---
title: Home
layout: home
nav_order: 1
---

# Home

Cube2D Engine, A minimal 2D simple and easy to use game development engine that provides everything you need for game development and utilizes super fast and super simple [wren] as its scripting language.

## Features

- Minimal
- Simple And Easy To Use
- Highly Customizable
- Utilizes [wren] as its scripting language.
- Binds almost all of [raylib], [raymath], [Cube2D Framework]
- Automatic asset management using [Cube2D Framework]
- Scene Management using [Cube2D Framework]

## Example

Whats a programming project without example on its home page?

```js

// File: SceneGame.wren
// Scene Management
// Creating A Simple Player

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
		// .Base seems weird but we will look into it later.
		Engine.WASDMovement(_Player.Base, Speed)
	}
	Draw() {
		_Player.Draw()
	}
}
```

[wren]: https://wren.io
[raylib]: https://raylib.com
[raymath]: https://github.com/raysan5/raylib/blob/master/src/raylib.h\
[Cube2D Framework]: https://github.com/mastercuber55/Cube2D-Framework