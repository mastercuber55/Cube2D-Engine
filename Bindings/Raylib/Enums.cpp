#include <raylib.h>
#include <wrenbind17/wrenbind17.hpp>
namespace Wren = wrenbind17;

//----------------------------------------------------------------------------------
// Enumerators Definition
//----------------------------------------------------------------------------------

void BindRaylibEnums(Wren::ForeignModule& Module) {
	// System/Window config flags
	Module.append(R"(
		var FLAG = {}
		FLAG["VSYNC_HINT"]         = 0x00000040
		FLAG["FULLSCREEN_MODE"]    = 0x00000002
		FLAG["WINDOW_RESIZABLE"]   = 0x00000004
		FLAG["WINDOW_UNDECORATED"] = 0x00000008
		FLAG["WINDOW_HIDDEN"]      = 0x00000080
		FLAG["WINDOW_MINIMIZED"]   = 0x00000200
		FLAG["WINDOW_MAXIMIZED"]   = 0x00000400
		FLAG["WINDOW_UNFOCUSED"]   = 0x00000800
		FLAG["WINDOW_TOPMOST"]     = 0x00001000
		FLAG["WINDOW_ALWAYS_RUN"]  = 0x00000100
		FLAG["WINDOW_TRANSPARENT"] = 0x00000010
		FLAG["WINDOW_HIGHDPI"]     = 0x00002000
		FLAG["WINDOW_MOUSE_PASSTHROUGH"] = 0x00004000
		FLAG["MSAA_4X_HINT"]       = 0x00000020
		FLAG["INTERLACED_HINT"]    = 0x00010000
	)");
	// Trace log level
	// Module.append(R"(
	// 	var LOG = {}
	// 	LOG["ALL"] = 0
	// 	LOG["TRACE"]
	// 	LOG["DEBUG"]
	// 	LOG["INFO"]
	// 	LOG["WARNING"]
	// 	LOG["ERROR"]
	// 	LOG["FATAL"]
	// 	LOG["NONE"]
	// )");
	// Keyboard keys (US keyboard layout)
	Module.append(R"(
		var KEY = {}
	    KEY["NULL"]            = 0

	    KEY["APOSTROPHE"]      = 39
	    KEY["COMMA"]           = 44
	    KEY["MINUS"]           = 45
	    KEY["PERIOD"]          = 46
	    KEY["SLASH"]           = 47
	    KEY["ZERO"]            = 48
	    KEY["ONE"]             = 49
	    KEY["TWO"]             = 50
	    KEY["THREE"]           = 51
	    KEY["FOUR"]            = 52
	    KEY["FIVE"]            = 53
	    KEY["SIX"]             = 54
	    KEY["SEVEN"]           = 55
	    KEY["EIGHT"]           = 56
	    KEY["NINE"]            = 57
	    KEY["SEMICOLON"]       = 59
	    KEY["EQUAL"]           = 61
	    KEY["A"]               = 65
	    KEY["B"]               = 66
	    KEY["C"]               = 67
	    KEY["D"]               = 68
	    KEY["E"]               = 69
	    KEY["F"]               = 70
	    KEY["G"]               = 71
	    KEY["H"]               = 72
	    KEY["I"]               = 73
	    KEY["J"]               = 74
	    KEY["K"]               = 75
	    KEY["L"]               = 76
	    KEY["M"]               = 77
	    KEY["N"]               = 78
	    KEY["O"]               = 79
	    KEY["P"]               = 80
	    KEY["Q"]               = 81
	    KEY["R"]               = 82
	    KEY["S"]               = 83
	    KEY["T"]               = 84
	    KEY["U"]               = 85
	    KEY["V"]               = 86
	    KEY["W"]               = 87
	    KEY["X"]               = 88
	    KEY["Y"]               = 89
	    KEY["Z"]               = 90
	    KEY["LEFT_BRACKET"]    = 91
	    KEY["BACKSLASH"]       = 92
	    KEY["RIGHT_BRACKET"]   = 93
	    KEY["GRAVE"]           = 96

	    KEY["SPACE"]           = 32
	    KEY["ESCAPE"]          = 256
	    KEY["ENTER"]           = 257
	    KEY["TAB"]             = 258
	    KEY["BACKSPACE"]       = 259
	    KEY["INSERT"]          = 260
	    KEY["DELETE"]          = 261
	    KEY["RIGHT"]           = 262
	    KEY["LEFT"]            = 263
	    KEY["DOWN"]            = 264
	    KEY["UP"]              = 265
	    KEY["PAGE_UP"]         = 266
	    KEY["PAGE_DOWN"]       = 267
	    KEY["HOME"]            = 268
	    KEY["END"]             = 269
	    KEY["CAPS_LOCK"]       = 280
	    KEY["SCROLL_LOCK"]     = 281
	    KEY["NUM_LOCK"]        = 282
	    KEY["PRINT_SCREEN"]    = 283
	    KEY["PAUSE"]           = 284
	    KEY["F1"]              = 290
	    KEY["F2"]              = 291
	    KEY["F3"]              = 292
	    KEY["F4"]              = 293
	    KEY["F5"]              = 294
	    KEY["F6"]              = 295
	    KEY["F7"]              = 296
	    KEY["F8"]              = 297
	    KEY["F9"]              = 298
	    KEY["F10"]             = 299
	    KEY["F11"]             = 300
	    KEY["F12"]             = 301
	    KEY["LEFT_SHIFT"]      = 340
	    KEY["LEFT_CONTROL"]    = 341
	    KEY["LEFT_ALT"]        = 342
	    KEY["LEFT_SUPER"]      = 343
	    KEY["RIGHT_SHIFT"]     = 344
	    KEY["RIGHT_CONTROL"]   = 345
	    KEY["RIGHT_ALT"]       = 346
	    KEY["RIGHT_SUPER"]     = 347
	    KEY["KB_MENU"]         = 348

	    KEY["KP_0"]            = 320
	    KEY["KP_1"]            = 321
	    KEY["KP_2"]            = 322
	    KEY["KP_3"]            = 323
	    KEY["KP_4"]            = 324
	    KEY["KP_5"]            = 325
	    KEY["KP_6"]            = 326
	    KEY["KP_7"]            = 327
	    KEY["KP_8"]            = 328
	    KEY["KP_9"]            = 329
	    KEY["KP_DECIMAL"]      = 330
	    KEY["KP_DIVIDE"]       = 331
	    KEY["KP_MULTIPLY"]     = 332
	    KEY["KP_SUBTRACT"]     = 333
	    KEY["KP_ADD"]          = 334
	    KEY["KP_ENTER"]        = 335
	    KEY["KP_EQUAL"]        = 336
	    KEY["BACK"]            = 4
	    KEY["MENU"]            = 82
	    KEY["VOLUME_UP"]       = 24
	    KEY["VOLUME_DOWN"]     = 25
	)");
	// Mouse buttons
	Module.append(R"(
		var MOUSE_BUTTON = {}
		MOUSE_BUTTON["LEFT"]    = 0
		MOUSE_BUTTON["RIGHT"]   = 1
		MOUSE_BUTTON["MIDDLE"]  = 2
		MOUSE_BUTTON["SIDE"]    = 3
		MOUSE_BUTTON["EXTRA"]   = 4
		MOUSE_BUTTON["FORWARD"] = 5
		MOUSE_BUTTON["BACK"]    = 6
	)");
	// Mouse cursor
	Module.append(R"(
		var MOUSE_CURSOR = {}
		MOUSE_CURSOR["DEFAULT"]       = 0
		MOUSE_CURSOR["ARROW"]         = 1
		MOUSE_CURSOR["IBEAM"]         = 2
		MOUSE_CURSOR["CROSSHAIR"]     = 3
		MOUSE_CURSOR["POINTING_HAND"] = 4
		MOUSE_CURSOR["RESIZE_EW"]     = 5
		MOUSE_CURSOR["RESIZE_NS"]     = 6
		MOUSE_CURSOR["RESIZE_NWSE"]   = 7
		MOUSE_CURSOR["RESIZE_NESW"]   = 8
		MOUSE_CURSOR["RESIZE_ALL"]    = 9
		MOUSE_CURSOR["NOT_ALLOWED"]   = 10
	)");
	// Gamepad buttons
	// Module.append(R"(
	// 	var GAMEPAD_BUTTON = {}
	// 	GAMEPAD_BUTTON["UNKNOWN"] = 0
	// 	GAMEPAD_BUTTON["LEFT_FACE_UP"]
	// 	GAMEPAD_BUTTON["LEFT_FACE_RIGHT"]
	// 	GAMEPAD_BUTTON["LEFT_FACE_DOWN"]
	// 	GAMEPAD_BUTTON["LEFT_FACE_LEFT"]
	// 	GAMEPAD_BUTTON["RIGHT_FACE_UP"]
	// 	GAMEPAD_BUTTON["RIGHT_FACE_RIGHT"]
	// 	GAMEPAD_BUTTON["RIGHT_FACE_DOWN"]
	// 	GAMEPAD_BUTTON["RIGHT_FACE_LEFT"]
	// 	GAMEPAD_BUTTON["LEFT_TRIGGER_1"]
	// 	GAMEPAD_BUTTON["LEFT_TRIGGER_2"]
	// 	GAMEPAD_BUTTON["RIGHT_TRIGGER_1"]
	// 	GAMEPAD_BUTTON["RIGHT_TRIGGER_2"]
	// 	GAMEPAD_BUTTON["MIDDLE_LEFT"]
	// 	GAMEPAD_BUTTON["MIDDLE"]
	// 	GAMEPAD_BUTTON["MIDDLE_RIGHT"]
	// 	GAMEPAD_BUTTON["LEFT_THUMB"]
	// 	GAMEPAD_BUTTON["RIGHT_THUMB"]
	// )");
	// Gamepad axis
	Module.append(R"(
		var GAMEPAD_AXIS = {}
		GAMEPAD_AXIS["LEFT_X"]        = 0
		GAMEPAD_AXIS["LEFT_Y"]        = 1
		GAMEPAD_AXIS["RIGHT_X"]       = 2
		GAMEPAD_AXIS["RIGHT_Y"]       = 3
		GAMEPAD_AXIS["LEFT_TRIGGER"]  = 4
		GAMEPAD_AXIS["RIGHT_TRIGGER"] = 5
	)");
	// Material map index
	// Shader location index
	// Shader uniform data type
	// Shader attribute data types
	// Pixel formats
	// Texture parameters: filter mode
	// Texture parameters: wrap mode
	// Cubemap layouts
	// Font type, defines generation method
	// Color blending modes (pre-defined)
	// Gesture
	Module.append(R"(
		var GESTURE = {}
		GESTURE["NONE"]        = 0
		GESTURE["TAP"]         = 1
		GESTURE["DOUBLETAP"]   = 2
		GESTURE["HOLD"]        = 4
		GESTURE["DRAG"]        = 8
		GESTURE["SWIPE_RIGHT"] = 16
		GESTURE["SWIPE_LEFT"]  = 32
		GESTURE["SWIPE_UP"]    = 64
		GESTURE["SWIPE_DOWN"]  = 128
		GESTURE["PINCH_IN"]    = 256
		GESTURE["PINCH_OUT"]   = 512
	)");
	// Camera system modes
}