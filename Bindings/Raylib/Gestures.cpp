#include <raylib.h>
#include <wrenbind17/wrenbind17.hpp>
#include "Raylib.hpp"
namespace Wren = wrenbind17;

//------------------------------------------------------------------------------------
// Gestures and Touch Handling Functions (Module: rgestures)
//------------------------------------------------------------------------------------

void BindRaylibGestures(Wren::ForeignModule& Module, Wren::ForeignKlassImpl<rl>& Class) {
	Class.funcStaticExt<&SetGesturesEnabled>("SetGesturesEnabled");
	Class.funcStaticExt<&IsGestureDetected>("IsGestureDetected");
	Class.funcStaticExt<&GetGestureDetected>("GetGestureDetected");
	Class.funcStaticExt<&GetGestureHoldDuration>("GetGestureHoldDuration");
	Class.funcStaticExt<&GetGestureDragVector>("GetGestureDragVector");
	Class.funcStaticExt<&GetGestureDragAngle>("GetGestureDragAngle");
	Class.funcStaticExt<&GetGesturePinchVector>("GetGesturePinchVector");
	Class.funcStaticExt<&GetGesturePinchAngle>("GetGesturePinchAngle");
}