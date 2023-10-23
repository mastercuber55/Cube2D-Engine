---
title: Config/Save Files
layout: default
parent: Tutorials
nav_order: 4
---

# Config/Save Files
You probably need files somewhat files for user configuration or for saving user data to be used in the next session. However, Cube2D Engine supports nothing of a sort but the original idea was to bind [ini.h] & [json] to [wren] for configuration files and save files and previous versions of the engine were using [ini.h] instead of `Game.wren`. I did try to bind [json] to [wren] but my brain just couldn't comprehend the greatness of [json] to be bind-ed into [wren] and as for [ini.h], I never even tried binding it to [wren] so lets see how you do it.

# Configuration Files (.wren Files)

{: .note }
When I say configuration files I mean manual configuration by user of your program.

For configuration files you would want to use [wren] files ( with maps I prefer ) cuz [wren] has really nice `import` statements for those stuff, below are two files demonstrating a example of using [wren] files as configuration files.

```js
// File: Config.wren
var Config = {
	"Key": "Val",
	"MyInteger": -5,
	"MyString": "Something"
}
```  
```js
// File: Main.wren
import "/path/to/Config.wren" for Config

DoSomethingWith(Config["Key"])
DoSomethingElseWith(Config["MyInteger"])
System.print(Config["MyString"])

```

# Save Files (.json Files)
{: .note }
This may also be used for non-user configuration files

- Q: But didn't you say you were unable to bind [json] to [wren]
- A: Yes, but there is a better alternative than binding [json] to [wren] because C++ is not dynamically typed while [wren] is so it would be smarter to just code a json library in [wren] so lets see how to do that.

I wasn't going to code a json library but luckily for you, someone has already made it for wren and its called [wren-json] and if you see the readme.md there is not much to it, it just shows `JSON.parse(Str)` & `JSON.stringify(Obj)` which doesn't explain how to use it but its easy to guess so lets see how to use it.

{: .note }
You need [wren-json] in your desired scripts directory.

First, here's a .json file
```js
// File: Save.json
{
	"Player": {
		"Color": "RED",
		"Size": 32
	},
	"Coins": 50
}
```

Second, Here's a .wren file
```js
// File: SceneSomething.wren
import "Cube2D" for Engine, Scene, Rect
import "raylib" for RL, COLOR
import "path/to/json.wren" for JSON

class SceneGame is Scene {
	construct new() {

		_Save = JSON.parse(RL.LoadFileText("Path/To/Config/File/From/Executable/Save.json"))

		var Size = _Save["Player"]["Size"]
		_Player = Rect.new(0, 0, Size, Size)
		// Yea, ["Stuff"] for .json, of course
		_Player.Tint = COLOR[_Save["Player"]["Color"]]

		_Coins = _Save["Coins"]

		_Coins = _Coins + 1

		super()
	}
	Update() {
		
		RL.SaveFileText("Path/To/Config/File/From/Executable/Save.json", JSON.stringify(_Save))

		var Speed = 10
		Engine.WASDMovement(_Player.Base, Speed)
	}
	Draw() {
		_Player.Draw()
	}
}
```

**The above code has been tested with correct paths.**

If I'm correct, [wren-json] doesn't have a file loading or saving system or nothing of a sort that's why we have to rely on raylib's file management functionality here.

- Q: So why can't we use it for manual user configuration?
- A: [wren-json] stringifys json objects into a single lined .json code and when its saved your user configuration file will become a single lined file and hard for user to configure whereas in non-manual configuration i.e. in game options configuration the single lining doesn't really matter.

[ini.h]: https://giosali.github.io/ini.h/
[json]: https://json.nlohmann.me/
[wren]: https://wren.io
[wren-json]: https://github.com/brandly/wren-json