---
title: Error Handling
layout: default
nav_order: 5
---

# Error Handling

As you saw in [Tutorials/Configuration], `Game.wren`'s `Path` variable has a key named "SceneError" which is used for error handling but how exactly?

Don't worry, It will be real simple.

Here is a example
```js
import "raylib" for RL, COLOR
import "Cube2D" for Scene

class SceneError is Scene {
	construct new() { 
		_Error = "NONE"
		super()
	}

	SetError(Error) {
		_Error = Error
	}

	Update() {

	}

	Draw() {
		if(_Error != "NONE") RL.DrawText(_Error, 32, 32, 16, COLOR["RED"])
	}
}

var Instance = SceneError.new()
```
**The above code has been tested with correct paths.**

You just need a `var` named `Instance` in your error scene file will engine use to throw error and a special method in your scene named `SetError` with signature `_` i.e `SetError(Error)` where you can save the error for displaying later on using Draw() method and as of course you don't need to call `.Run()` cuz the engine does that when the time is right.