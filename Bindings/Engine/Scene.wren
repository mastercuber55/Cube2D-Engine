R"(
class Scene {

	construct new() {}
	ShouldClose {
		if(_ShouldClose is Null) this.ShouldClose = false
		return _ShouldClose
	}
	ShouldClose=(rhs) { _ShouldClose = rhs }
	Update(dt) {}
	Draw() {}
}
)"