---
title: Textures
layout: default
parent: Tutorials
nav_order: 4
---

# Textures
[Cube2D Framework]'s `Rect` `class` is the best way to use textures if you are creating rectangles.

```cpp
import "Engine" for Engine, Scene, Rect

class SceneGame is Scene {
	construct new() {
		_Player = Rect.new(0, 0, 32, 32)
		_Player.SetTextureFile("Resources/Icon.png")
		// You don't want to do _Player.Texture= because you will then have to manually load texture which is not possible in my engine.

		super()
	}
	Update() {
		var Speed = 10
		Engine.WASDMovement(_Player.Base, Speed)
	}
	Draw() {
		_Player.Draw()
	}
}

```
**The above code has been tested with correct paths.**

I'll not be using single file approach from now cuz by now, you should know how to run that code and have a well defined project folder.

[Cube2D Framework]: https://github.com/mastercuber55/Cube2D-Framework