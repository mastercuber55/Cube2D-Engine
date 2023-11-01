---
title: ConfigSave Files
layout: default
parent: Tutorials
nav_order: 5
---

# Save Files
You probably need somewhat files for saving game's current state to be used in the next session. However, Cube2D Engine supports nothing of a sort but the original idea was to bind [ini.h] & [json] to [wren] for that purpose and previous versions of the engine were using [ini.h] instead of `Game.wren`. I did try to bind [json] to [wren] but my brain just couldn't comprehend the greatness of [json] to be bind-ed into [wren] and as for [ini.h], I never even tried binding it to [wren] so lets see how you do it.

# Wren Files

{: .note }
Only for manual configuration, unless you make somesort of wren parser and stringifier.

[wren] has really nice `import` statements so you may just want to have simple wren files where you have `var`iables, below are two files demonstrating a example of using [wren] files as configuration files.

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

# Json Files

- Q: But didn't you say you were unable to bind [json] to [wren]
- A: Yes, but there is a better alternative than binding [json] to [wren] because C++ is not dynamically typed while [wren] is so it would be smarter to just code a json library in [wren] so lets see how to do that.

I wasn't going to code a json library but luckily for you, someone has already made it for wren and its called [wren-json]..

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
// File: SceneExample.wren
import "Engine"
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
[wren-json]: https://github.com/ruby0x1/wren-json