R"(
var Scenes = []
class SceneManager /* is List */ {

	// super.Methods
	static add 			(item) 			{ Scenes.add 			(item) 			}
	static addAll		(other) 		{ Scenes.addAll			(other) 		}
	static clear 		() 				{ Scenes.clear 			() 				}
	static count 						{ Scenes.count 							}
	static indexOf 		(value) 		{ Scenes.indexOf		(value)			}
	static insert 		(index, item) 	{ Scenes.insert			(index, item) 	}
	static iterate 		(iterator) 		{ Scenes.iterate 		(iterator) 		}
	static iteratorValue(iterator) 		{ Scenes.iteratorValue	(iterator) 		}
	static remove 		(value) 		{ Scenes.remove 		(value) 		}
	static removeAt		(index) 		{ Scenes.removeAt 		(index) 		}
	static swap			(index0, index1){ Scenes.swap 			(index0, index1)}
	static [index] 						{ Scenes[index] 						}
	static [index]=		(item) 			{ Scenes[index]= 		item 			}
	static +			(other) 		{ Scenes.addAll 		(other) 		}

	// this.Methods
	static swapTo		(item)			{
		this.clear()
		this.add(other)
	}
	static swapToAll	(other)			{
		this.clear()
		this.addAll(other)
	}

	static Run(BackgroundColor, KeepRunningCallback) {

		if(this.count == 0) return false

		for(i in 0...this.count) if(this[i] is Class) this[i] = this[i].new()

		while(!KeepRunningCallback.call()) {
			for(i in 0...this.count) {

				this[i].Update(RL.GetFrameTime())

				if(i == 0) {
					RL.BeginDrawing()
					RL.ClearBackground(BackgroundColor)
				}
					this[i].Draw()

				if(i == this.count - 1) RL.EndDrawing()

				// if(this[i].ShouldClose) this.removeAt(i)

			}
		}

		return true
	}
}
)"