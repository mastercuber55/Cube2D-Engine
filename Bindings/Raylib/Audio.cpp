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
	Class.funcStaticExt<&LoadWaveFromMemory>("LoadWaveFromMemory");
	Class.funcStaticExt<&IsWaveReady>("IsWaveReady");
	Class.funcStaticExt<&rl::wLoadSound>("LoadSound");
	Class.funcStaticExt<&LoadSoundFromWave>("LoadSoundFromWave");
	Class.funcStaticExt<&IsSoundReady>("IsSoundReady");
	Class.funcStaticExt<&UpdateSound>("UpdateSound");
	Class.funcStaticExt<&UnloadWave>("UnloadWave");
	Class.funcStaticExt<&UnloadSound>("UnloadSound");
	Class.funcStaticExt<&rl::wExportWave>("ExportWave");

	// Wave/Sound management functions
	Class.funcStaticExt<&PlaySound>("PlaySound");
	Class.funcStaticExt<&StopSound>("StopSound");
	Class.funcStaticExt<&PauseSound>("PauseSound");
	Class.funcStaticExt<&ResumeSound>("ResumeSound");
	Class.funcStaticExt<&IsSoundPlaying>("IsSoundPlaying");
	Class.funcStaticExt<&SetSoundVolume>("SetSoundVolume");
	Class.funcStaticExt<&SetSoundPitch>("SetSoundPitch");
	Class.funcStaticExt<&SetSoundPan>("SetSoundPan");
	Class.funcStaticExt<&WaveCopy>("WaveCopy");
	Class.funcStaticExt<&WaveCrop>("WaveCrop");
	Class.funcStaticExt<&WaveFormat>("WaveFormat");
	Class.funcStaticExt<&LoadWaveSamples>("LoadWaveSamples");
	Class.funcStaticExt<&UnloadWaveSamples>("UnloadWaveSamples");

	// Music management functions
	Class.funcStaticExt<&rl::wLoadMusicStream>("LoadMusicStream");
	Class.funcStaticExt<&rl::wLoadMusicStreamFromMemory>("LoadMusicStreamFromMemory");
	Class.funcStaticExt<&IsMusicReady>("IsMusicReady");
	Class.funcStaticExt<&UnloadMusicStream>("UnloadMusicStream");
	Class.funcStaticExt<&PlayMusicStream>("PlayMusicStream");
	Class.funcStaticExt<&IsMusicStreamPlaying>("IsMusicStreamPlaying");
	Class.funcStaticExt<&UpdateMusicStream>("UpdateMusicStream");
	Class.funcStaticExt<&StopMusicStream>("StopMusicStream");
	Class.funcStaticExt<&PauseMusicStream>("PauseMusicStream");
	Class.funcStaticExt<&ResumeMusicStream>("ResumeMusicStream");
	Class.funcStaticExt<&SeekMusicStream>("SeekMusicStream");
	Class.funcStaticExt<&SetMusicVolume>("SetMusicVolume");
	Class.funcStaticExt<&SetMusicPitch>("SetMusicPitch");
	Class.funcStaticExt<&SetMusicPan>("SetMusicPan");
	Class.funcStaticExt<&GetMusicTimeLength>("GetMusicTimeLength");
	Class.funcStaticExt<&GetMusicTimePlayed>("GetMusicTimePlayed");

	// AudioStream management functions
	Class.funcStaticExt<&LoadAudioStream>("LoadAudioStream");
	Class.funcStaticExt<&IsAudioStreamReady>("IsAudioStreamReady");
	Class.funcStaticExt<&UnloadAudioStream>("UnloadAudioStream");
	Class.funcStaticExt<&UpdateAudioStream>("UpdateAudioStream");
	Class.funcStaticExt<&IsAudioStreamProcessed>("IsAudioStreamProcessed");
	Class.funcStaticExt<&PlayAudioStream>("PlayAudioStream");
	Class.funcStaticExt<&PauseAudioStream>("PauseAudioStream");
	Class.funcStaticExt<&ResumeAudioStream>("ResumeAudioStream");
	Class.funcStaticExt<&IsAudioStreamPlaying>("IsAudioStreamPlaying");
	Class.funcStaticExt<&StopAudioStream>("StopAudioStream");
	Class.funcStaticExt<&SetAudioStreamVolume>("SetAudioStreamVolume");
	Class.funcStaticExt<&SetAudioStreamPitch>("SetAudioStreamPitch");
	Class.funcStaticExt<&SetAudioStreamPan>("SetAudioStreamPan");
	Class.funcStaticExt<&SetAudioStreamBufferSizeDefault>("SetAudioStreamBufferSizeDefault");
	Class.funcStaticExt<&SetAudioStreamCallback>("SetAudioStreamCallback");

	Class.funcStaticExt<&AttachAudioStreamProcessor>("AttachAudioStreamProcessor");
	Class.funcStaticExt<&DetachAudioStreamProcessor>("DetachAudioStreamProcessor");

	Class.funcStaticExt<&AttachAudioMixedProcessor>("AttachAudioMixedProcessor");
	Class.funcStaticExt<&DetachAudioMixedProcessor>("DetachAudioMixedProcessor");
}