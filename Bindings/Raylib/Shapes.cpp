#include <raylib.h>
#include <wrenbind17/wrenbind17.hpp>
#include "Raylib.hpp"
namespace Wren = wrenbind17;

//------------------------------------------------------------------------------------
// Basic Shapes Drawing Functions (Module: shapes)
//------------------------------------------------------------------------------------
//
void BindRaylibShapes(Wren::ForeignModule& Module, Wren::ForeignKlassImpl<rl>& Class) {
	// Set texture and rectangle to be used on shapes drawing
	Class.funcStaticExt<&SetShapesTexture>("SetShapesTexture");

	// Basic shapes drawing functions
	Class.funcStaticExt<&DrawPixel>("DrawPixel");
	Class.funcStaticExt<&DrawPixelV>("DrawPixelV");
	Class.funcStaticExt<&DrawLine>("DrawLine");
	Class.funcStaticExt<&DrawLineV>("DrawLineV");
	Class.funcStaticExt<&DrawLineEx>("DrawLineEx");
	Class.funcStaticExt<&DrawLineBezier>("DrawLineBezier");
	Class.funcStaticExt<&DrawLineBezierQuad>("DrawLineBezierQuad");
	Class.funcStaticExt<&DrawLineBezierCubic>("DrawLineBezierCubic");
	Class.funcStaticExt<&DrawLineStrip>("DrawLineStrip");
	Class.funcStaticExt<&DrawCircle>("DrawCircle");
	Class.funcStaticExt<&DrawCircleSector>("DrawCircleSector");
	Class.funcStaticExt<&DrawCircleSectorLines>("DrawCircleSectorLines");
	Class.funcStaticExt<&DrawCircleGradient>("DrawCircleGradient");
	Class.funcStaticExt<&DrawCircleV>("DrawCircleV");
	Class.funcStaticExt<&DrawCircleLines>("DrawCircleLines");
	Class.funcStaticExt<&DrawEllipse>("DrawEllipse");
	Class.funcStaticExt<&DrawEllipseLines>("DrawEllipseLines");
	Class.funcStaticExt<&DrawRing>("DrawRing");
	Class.funcStaticExt<&DrawRingLines>("DrawRingLines");
	Class.funcStaticExt<&DrawRectangle>("DrawRectangle");
	Class.funcStaticExt<&DrawRectangleV>("DrawRectangleV");
	Class.funcStaticExt<&DrawRectangleRec>("DrawRectangleRec");
	Class.funcStaticExt<&DrawRectanglePro>("DrawRectanglePro");
	Class.funcStaticExt<&DrawRectangleGradientV>("DrawRectangleGradientV");
	Class.funcStaticExt<&DrawRectangleGradientH>("DrawRectangleGradientH");
	Class.funcStaticExt<&DrawRectangleGradientEx>("DrawRectangleGradientEx");
	Class.funcStaticExt<&DrawRectangleLines>("DrawRectangleLines");
	Class.funcStaticExt<&DrawRectangleLinesEx>("DrawRectangleLinesEx");
	Class.funcStaticExt<&DrawRectangleRounded>("DrawRectangleRounded");
	Class.funcStaticExt<&DrawRectangleRoundedLines>("DrawRectangleRoundedLines");
	Class.funcStaticExt<&DrawTriangle>("DrawTriangle");
	Class.funcStaticExt<&DrawTriangleLines>("DrawTriangleLines");
	Class.funcStaticExt<&DrawTriangleFan>("DrawTriangleFan");
	Class.funcStaticExt<&DrawTriangleStrip>("DrawTriangleStrip");
	Class.funcStaticExt<&DrawPoly>("DrawPoly");
	Class.funcStaticExt<&DrawPolyLines>("DrawPolyLines");
	Class.funcStaticExt<&DrawPolyLinesEx>("DrawPolyLinesEx");
	
	// Basic shapes collision detection functions
	Class.funcStaticExt<&CheckCollisionRecs>("CheckCollisionRecs");
	Class.funcStaticExt<&CheckCollisionCircles>("CheckCollisionCircles");
	Class.funcStaticExt<&CheckCollisionCircleRec>("CheckCollisionCircleRec");
	Class.funcStaticExt<&CheckCollisionPointRec>("CheckCollisionPointRec");
	Class.funcStaticExt<&CheckCollisionPointCircle>("CheckCollisionPointCircle");
	Class.funcStaticExt<&CheckCollisionPointTriangle>("CheckCollisionPointTriangle");
	Class.funcStaticExt<&CheckCollisionPointPoly>("CheckCollisionPointPoly");
	Class.funcStaticExt<&CheckCollisionLines>("CheckCollisionLines");
	Class.funcStaticExt<&CheckCollisionPointLine>("CheckCollisionPointLine");
	Class.funcStaticExt<&GetCollisionRec>("GetCollisionRec");

}