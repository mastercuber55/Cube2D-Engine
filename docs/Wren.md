---
title: Wren
layout: default
nav_order: 3
---

# Wren
Over here we will learn a little about [wren] and why we choose [wren].

Here's a little example from [wren]

```js
System.print("Hello, world!")

class Wren {
  flyTo(city) {
    System.print("Flying to %(city)")
  }
}

var adjectives = Fiber.new {
  ["small", "clean", "fast"].each {|word| Fiber.yield(word) }
}

while (!adjectives.isDone) System.print(adjectives.call())
```

## Syntax

### Types

Very Much Like Javascript

```js
var MyInteger = -5
var MyDecimal = -5.1
var MyString = "Hello Wren"
var MyList = [-5, -5.1, MyInteger, MyDecimal, MyString]
var MyListInList = [MyList, MyList]
var MyMap = { "Key": "Value", "Foo": "Bar", 1: "One", "One": 1 }
var MyNothing = null
var MyClassInstance = Rect.new(0, 0, 32, 32)
var MyAddition = MyInteger + MyDecimal
```

### Control Flow

Very Much Like In Any Other Usual Language

```js
if (happy && knowIt) {
  hands.clap()
} else System.print("sad")

while(Player is Rect) {
	var Something = GetSomething()
	if(Something is null) continue;
}

for(i in 1...10) {
	DoSomething()
}

```

### Modules

```js
// Loading built into engine things.
import "raylib" for RL
import "Cube2D" for Engine, Scene, Rect
// Loading your stuff.
import "Scenes/SceneGame.wren" for SceneGame
// you don't do .wren in original wren btw.
import "Scenes/SceneTitle" for SceneGame
// As you see, .wren is optional for my engine.
```

{: .note }
`import` statement in my engine doesn't look for modules from the current file location instead it looks for modules in configured folder in `Game.wren`

### Classes

```js
// remove "is Rect" to avoid inheritance.
class Entity is Rect {
	construct new(Parameters, Health) {
		_Health = Health // Class Private Variable ( Must Start With "_").
		super(Parameters, 3) // Pass Parameters to base class if inheritance and base class takes any parameters.
	}
	Health { _Health } // A Class Getter // You surely wanna atleast see what the variable's value is.
	Health=(rhs) { _Health = rhs } // A Class Setter // Maybe you also wanna modify it.
	SetHealth(rhs) { _Health = rhs } // A Class Method // Entity.Health = Doesn't suit you?

	+(Position) {
		// Add that position to this
		// Position is raylib's Vector2 in this case.
		_x = Position.x
		_y = Position.y 
	}
}
```

### So Why Did We Choose Wren?

- Dynamic Typing
- No Semicolons
- Fast
- Modular
- Classes
- Inheritance

[wren]: https://wren.io