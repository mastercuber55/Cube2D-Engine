R"(
class Tools {
	static WASDMovement(Object, Speed, dt) {
		if(RL.IsKeyDown(KEY["W"])) Object.y = Object.y - Speed * dt
		if(RL.IsKeyDown(KEY["A"])) Object.x = Object.x - Speed * dt
		if(RL.IsKeyDown(KEY["S"])) Object.y = Object.y + Speed * dt
		if(RL.IsKeyDown(KEY["D"])) Object.x = Object.x + Speed * dt
	}
	static AreColorSame(A, B) { RL.ColorToInt(A) == RL.ColorToInt(B) }
	static GetRandomPosition(Cam) {
		if(__Vector2ToReturn is Null) __Vector2ToReturn = Vector2.new()

		__Vector2ToReturn.x = RL.GetRandomValue(0, Cam.offset.x * 2) 
		__Vector2ToReturn.y = RL.GetRandomValue(0, Cam.offset.y * 2)

		return RL.GetScreenToWorld2D(__Vector2ToReturn, Cam)
	}
	static GetRandomColor(a) {
		if(__ColorToReturn is Null) __ColorToReturn = Color.new()
		__ColorToReturn.r = RL.GetRandomValue(0, 255)
		__ColorToReturn.g = RL.GetRandomValue(0, 255)
		__ColorToReturn.b = RL.GetRandomValue(0, 255)
		__ColorToReturn.a = a is Null ? RL.GetRandomValue(0, 255) : a
		return __ColorToReturn
	}
}
)"