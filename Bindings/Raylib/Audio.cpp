#include <raylib.h>
#include <wrenbind17/wrenbind17.hpp>
#include "Raylib.hpp"
namespace Wren = wrenbind17;

//------------------------------------------------------------------------------------
// Audio Loading and Playing Functions (Module: audio)
//------------------------------------------------------------------------------------

void BindRaylibAudio(Wren::ForeignModule& Module, Wren::ForeignKlassImpl<rl>& Class) {
	// Audio device management functions
	Class.funcStaticExt<&SetMasterVolume>("SetMasterVolume");

	// Wave/Sound loading/unloading functions
	Class.funcStaticExt<&rl::wLoadWave>("LoadWave");
	Class.funcStaticExt<&IsWaveReady>("IsWaveReady");
	Class.funcStaticExt<&rl::wLoadSound>("LoadSound");
	Class.funcStaticExt<&LoadSoundFromWave>("LoadSoundFromWave");
	Class.funcStaticExt<&IsSoundReady>("IsSoundReady");
	Class.funcStaticExt<&UpdateSound>("UpdateSound");
	Class.funcStaticExt<&UnloadWave>("UnloadWave");
	Class.funcStaticExt<&UnloadSound>("UnloadSound");
	Class.funcStaticExt<&rl::wExportWave>("ExportWave");

	// Wave/Sound management functions
	Class.funcStaticExt<&UnloadWaveSamples>("UnloadWaveSamples");

	// AudioStream management functions
}