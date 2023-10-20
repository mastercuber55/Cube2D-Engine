#include <raylib.h>
#include <wrenbind17/wrenbind17.hpp>
#include "Raylib.hpp"
namespace Wren = wrenbind17;

//------------------------------------------------------------------------------------
// Camera System Functions (Module: rcamera)
//------------------------------------------------------------------------------------

void BindRaylibCamera(Wren::ForeignModule& Module, Wren::ForeignKlassImpl<rl>& Class) {
	Class.funcStaticExt<&UpdateCamera>("UpdateCamera");
	Class.funcStaticExt<&UpdateCameraPro>("UpdateCameraPro");
}