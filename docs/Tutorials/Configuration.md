---
title: Configuration
layout: default
parent: Tutorials
nav_order: 1
---

# Configuration

- Any projects needs a folder of its own, so first of all create a folder for your project!
- Now, copy Cube2D executable to this folder
- Create Game.wren such as following

```js
// File: Game.wren
var Window = {
	"Width" 	: 	1280, // (Default: 640)
	"Height" 	: 	768,  // (Default: 480)
	"FPS" 		: 	60,   // (Default: 60)
	"Title" 	: 	"Square Wars",
	"Fullscreen": 	true  // (Default: false)
}

var Path = {
	"Icon" 		: 	"Icon.png", // (Default: None)
	"Scripts"	:	"Scripts/", // (Default: Scripts/)
	"Resources"	: 	"Resources/", // (Default: Resources/)
	"MainScript":	"Main.wren", // (Default: Main.wren)
	"SceneError": 	"Scenes/SceneError.wren"
}
```
**The above code has been tested with correct paths.**
As for the current version, it is a absolute must that you have a file named Game.wren in same folder as Cube2D executable or it will crash but sooner or later we will make it so that the engine lets you know that no Game.wren was found atleast.
