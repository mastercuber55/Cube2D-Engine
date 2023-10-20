#include <raylib.h>
#include <wrenbind17/wrenbind17.hpp>
namespace Wren = wrenbind17;

//----------------------------------------------------------------------------------
// Some basic Defines
//----------------------------------------------------------------------------------

// Some Basic Colors
void BindRaylibColors(Wren::ForeignModule& Module) {
	std::string ColorsCode = R"(
		var COLOR = {}
		COLOR["LIGHTGRAY"]	   = Color.new()
		COLOR["LIGHTGRAY"].r   = 200
		COLOR["LIGHTGRAY"].g   = 200
		COLOR["LIGHTGRAY"].b   = 200
		COLOR["LIGHTGRAY"].a   = 255

		COLOR["GRAY"]	  	   = Color.new()
		COLOR["GRAY"].r   	   = 130
		COLOR["GRAY"].g   	   = 130
		COLOR["GRAY"].b   	   = 130
		COLOR["GRAY"].a   	   = 255

		COLOR["DARKGRAY"]	  = Color.new()
		COLOR["DARKGRAY"].r   = 80
		COLOR["DARKGRAY"].g   = 80
		COLOR["DARKGRAY"].b   = 80
		COLOR["DARKGRAY"].a   = 255

		COLOR["YELLOW"]	  = Color.new()
		COLOR["YELLOW"].r   = 253
		COLOR["YELLOW"].g   = 249
		COLOR["YELLOW"].b   = 0
		COLOR["YELLOW"].a   = 255

		COLOR["GOLD"]	  = Color.new()
		COLOR["GOLD"].r   = 255
		COLOR["GOLD"].g   = 203
		COLOR["GOLD"].b   = 0
		COLOR["GOLD"].a   = 255

		COLOR["ORANGE"]	  = Color.new()
		COLOR["ORANGE"].r   = 255
		COLOR["ORANGE"].g   = 161
		COLOR["ORANGE"].b   = 0
		COLOR["ORANGE"].a   = 255

		COLOR["PINK"]	  = Color.new()
		COLOR["PINK"].r   = 255
		COLOR["PINK"].g   = 109
		COLOR["PINK"].b   = 194
		COLOR["PINK"].a   = 255

		COLOR["RED"]	  = Color.new()
		COLOR["RED"].r   = 230
		COLOR["RED"].g   = 41
		COLOR["RED"].b   = 55
		COLOR["RED"].a   = 255

		COLOR["MAROON"]	  = Color.new()
		COLOR["MAROON"].r   = 190
		COLOR["MAROON"].g   = 33
		COLOR["MAROON"].b   = 55
		COLOR["MAROON"].a   = 255

		COLOR["GREEN"]	  = Color.new()
		COLOR["GREEN"].r   = 0
		COLOR["GREEN"].g   = 228
		COLOR["GREEN"].b   = 48
		COLOR["GREEN"].a   = 255

		COLOR["LIME"]	  = Color.new()
		COLOR["LIME"].r   = 0
		COLOR["LIME"].g   = 158
		COLOR["LIME"].b   = 47
		COLOR["LIME"].a   = 255

		COLOR["DARKGREEN"]	  = Color.new()
		COLOR["DARKGREEN"].r   = 0
		COLOR["DARKGREEN"].g   = 117
		COLOR["DARKGREEN"].b   = 44
		COLOR["DARKGREEN"].a   = 255

		COLOR["SKYBLUE"]	  = Color.new()
		COLOR["SKYBLUE"].r   = 102
		COLOR["SKYBLUE"].g   = 191
		COLOR["SKYBLUE"].b   = 255
		COLOR["SKYBLUE"].a   = 255

		COLOR["BLUE"]	  = Color.new()
		COLOR["BLUE"].r   = 0
		COLOR["BLUE"].g   = 121
		COLOR["BLUE"].b   = 241
		COLOR["BLUE"].a   = 255

		COLOR["DARKBLUE"]	  = Color.new()
		COLOR["DARKBLUE"].r   = 0
		COLOR["DARKBLUE"].g   = 82
		COLOR["DARKBLUE"].b   = 172
		COLOR["DARKBLUE"].a   = 255

		COLOR["PURPLE"]	  = Color.new()
		COLOR["PURPLE"].r   = 200
		COLOR["PURPLE"].g   = 122
		COLOR["PURPLE"].b   = 255
		COLOR["PURPLE"].a   = 255

		COLOR["VIOLET"]	  = Color.new()
		COLOR["VIOLET"].r   = 135
		COLOR["VIOLET"].g   = 60
		COLOR["VIOLET"].b   = 190
		COLOR["VIOLET"].a   = 255

		COLOR["DARKPURPLE"]	  = Color.new()
		COLOR["DARKPURPLE"].r   = 112
		COLOR["DARKPURPLE"].g   = 31
		COLOR["DARKPURPLE"].b   = 126
		COLOR["DARKPURPLE"].a   = 255

		COLOR["BEIGE"]	  = Color.new()
		COLOR["BEIGE"].r   = 211
		COLOR["BEIGE"].g   = 176
		COLOR["BEIGE"].b   = 131
		COLOR["BEIGE"].a   = 255

		COLOR["BROWN"]	  = Color.new()
		COLOR["BROWN"].r   = 127
		COLOR["BROWN"].g   = 106
		COLOR["BROWN"].b   = 79
		COLOR["BROWN"].a   = 255

		COLOR["DARKBROWN"]	  = Color.new()
		COLOR["DARKBROWN"].r   = 76
		COLOR["DARKBROWN"].g   = 63
		COLOR["DARKBROWN"].b   = 47
		COLOR["DARKBROWN"].a   = 255

		COLOR["WHITE"]	  = Color.new()
		COLOR["WHITE"].r   = 255
		COLOR["WHITE"].g   = 255
		COLOR["WHITE"].b   = 255
		COLOR["WHITE"].a   = 255

		COLOR["BLACK"]	  = Color.new()
		COLOR["BLACK"].r   = 0
		COLOR["BLACK"].g   = 0
		COLOR["BLACK"].b   = 0
		COLOR["BLACK"].a   = 255

		COLOR["BLANK"]	  = Color.new()
		COLOR["BLANK"].r   = 0
		COLOR["BLANK"].g   = 0
		COLOR["BLANK"].b   = 0
		COLOR["BLANK"].a   = 0

		COLOR["MAGENTA"]	  = Color.new()
		COLOR["MAGENTA"].r   = 255
		COLOR["MAGENTA"].g   = 255
		COLOR["MAGENTA"].b   = 0
		COLOR["MAGENTA"].a   = 255

		COLOR["RAYWHITE"]	  = Color.new()
		COLOR["RAYWHITE"].r   = 245
		COLOR["RAYWHITE"].g   = 245
		COLOR["RAYWHITE"].b   = 245
		COLOR["RAYWHITE"].a   = 255
	)";

	Module.append(ColorsCode);
}