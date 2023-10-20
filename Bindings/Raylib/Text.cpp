#include <raylib.h>
#include <wrenbind17/wrenbind17.hpp>
#include "Raylib.hpp"
namespace Wren = wrenbind17;

//------------------------------------------------------------------------------------
// Font Loading and Text Drawing Functions (Module: text)
//------------------------------------------------------------------------------------

void BindRaylibText(Wren::ForeignModule& Module, Wren::ForeignKlassImpl<rl>& Class) {
	// Font loading/unloading functions
	Class.funcStaticExt<&GetFontDefault>("GetFontDefault");
	Class.funcStaticExt<&rl::wLoadFont>("LoadFont");
	Class.funcStaticExt<&rl::wLoadFontEx>("LoadFontEx");
	Class.funcStaticExt<&LoadFontFromImage>("LoadFontFromImage");
	Class.funcStaticExt<&rl::wLoadFontFromMemory>("LoadFontFromMemory");
	Class.funcStaticExt<&IsFontReady>("IsFontReady");
	Class.funcStaticExt<&LoadFontData>("LoadFontData");
	// Class.funcStaticExt<&GenImageFontAtlas>("GenImageFontAtlas");
	Class.funcStaticExt<&UnloadFontData>("UnloadFontData");
	Class.funcStaticExt<&UnloadFont>("UnloadFont");
	Class.funcStaticExt<&rl::wExportFontAsCode>("ExportFontAsCode");

	// Text drawing functions
	Class.funcStaticExt<&DrawFPS>("DrawFPS");
	Class.funcStaticExt<&rl::wDrawText>("DrawText");
	Class.funcStaticExt<&rl::wDrawTextEx>("DrawTextEx");
	Class.funcStaticExt<&rl::wDrawTextPro>("DrawTextPro");
	Class.funcStaticExt<&DrawTextCodepoint>("DrawTextCodepoint");
	Class.funcStaticExt<&DrawTextCodepoints>("DrawTextCodepoints");

	// Text font info functions
	Class.funcStaticExt<&rl::wMeasureText>("MeasureText");
	Class.funcStaticExt<&rl::wMeasureTextEx>("MeasureTextEx");
	Class.funcStaticExt<&GetGlyphIndex>("GetGlyphIndex");
	Class.funcStaticExt<&GetGlyphInfo>("GetGlyphInfo");
	Class.funcStaticExt<&GetGlyphAtlasRec>("GetGlyphAtlasRec");

	// Text codepoints management functions (unicode characters)
	Class.funcStaticExt<&LoadUTF8>("LoadUTF8");
	Class.funcStaticExt<&rl::wLoadCodepoints>("LoadCodepoints");
	Class.funcStaticExt<&UnloadCodepoints>("UnloadCodepoints");
	Class.funcStaticExt<&rl::wGetCodepointCount>("GetCodepointCount");
	Class.funcStaticExt<&rl::wGetCodepoint>("GetCodepoint");
	Class.funcStaticExt<&rl::wGetCodepointNext>("GetCodepointNext");
	Class.funcStaticExt<&rl::wGetCodepointPrevious>("GetCodepointPrevious");
	Class.funcStaticExt<&CodepointToUTF8>("CodepointToUTF8");

	// Text strings management functions (no UTF-8 strings, only byte chars)
	
	Class.funcStaticExt<&rl::wTextToUpper>("TextToUpper");
	Class.funcStaticExt<&rl::wTextToLower>("TextToLower");
	Class.funcStaticExt<&rl::wTextToPascal>("TextToPascal");
	Class.funcStaticExt<&rl::wTextToInteger>("TextToInteger");
}