R"(
class Rect {
 	construct new(x, y, w, h) {
		_Base = ForeignRect.new(x, y, w, h)
 	}
 	construct new(x, y, w, h, TintOrTextureFile) {
 		_Base = ForeignRect.new(x, y, w, h)

 		if(TintOrTextureFile is String) {
 			_Base.Tint = COLOR["WHITE"]
 			_Base.SetTextureFile(TintOrTextureFile)
 		} else {
 			_Base.Tint = TintOrTextureFile
 		}
 	}

 	// Transformation
 	// Getters
 	x { _Base.PositionAndScale.x }
 	y { _Base.PositionAndScale.y }
 	w { _Base.PositionAndScale.width }
 	h { _Base.PositionAndScale.height }
 	// Setters
 	x=(rhs) { _Base.PositionAndScale.x=rhs }
 	y=(rhs) { _Base.PositionAndScale.y=rhs }
 	w=(rhs) { _Base.PositionAndScale.width=rhs }
 	h=(rhs) { _Base.PositionAndScale.height=rhs }
 	
 	// Position object
 	Position { _Base.GetPosition() }
 	Position=(rhs) { _Base.SetPosition(rhs) }
 	Center { _Base.GetCenter() }

 	// Position And Scale literal object
 	PositionAndScale { _Base.PositionAndScale }
 	PositionAndScale=(rhs) { _Base.PositionAndScale=rhs }

 	// Rotation
 	Rotation { _Base.Rotation }
 	Rotation=(rhs) { _Base.Rotation=rhs }

 	// Other Variables
 	TextureFile { _Base.TextureFile }
 	TextureFile=(rhs) { _Base.SetTextureFile(rhs) }

 	Source { _Base.Source }
 	Source=(rhs) { _Base.Source=rhs }
 	
 	Tint { _Base.Tint }
 	Tint=(rhs) { _Base.Tint=rhs }
 	
 	Draw() { _Base.Draw() }

	IsColliding(rhs) { _Base.IsColliding(rhs.Base) }

	Base { _Base }  
}
)"