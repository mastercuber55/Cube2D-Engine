---
title: API Documentation
layout: default
nav_order: 3
---

# API Documentation

Cube2D Engine just binds or recreate things from [raylib], [raymath], [Cube2D Framework] so there is no need for docs of my own and as [raylib] says, you can just learn things just by looking at the cheatsheet, but in my personal opinion, switching between cheetsheet and code editor is kinda pain so just include [raylib.h], [raymath], [Cube2D.hpp] in your project and your code editor most likely supports better file switch compared to what you would do if those files were not included.

## How To Use Enums & Defines?
[raylib] defines the following enums
```c 
typedef enum {
    MOUSE_BUTTON_LEFT    = 0,       // Mouse button left
    MOUSE_BUTTON_RIGHT   = 1,       // Mouse button right
    MOUSE_BUTTON_MIDDLE  = 2,       // Mouse button middle (pressed wheel)
    MOUSE_BUTTON_SIDE    = 3,       // Mouse button side (advanced mouse device)
    MOUSE_BUTTON_EXTRA   = 4,       // Mouse button extra (advanced mouse device)
    MOUSE_BUTTON_FORWARD = 5,       // Mouse button forward (advanced mouse device)
    MOUSE_BUTTON_BACK    = 6,       // Mouse button back (advanced mouse device)
} MouseButton;
```

which can be `import`ed in [wren] as `MOUSE_BUTTON` and be used like `MOUSE_BUTTON["LEFT"]` cuz I don't want you to import every single enum manually like `import "raylib" for MOUSE_BUTTON_LEFT, MOUSE_BUTTON_RIGHT, MOUSE_BUTTON_MIDDLE, MOUSE_BUTTON_SIDE, MOUSE_BUTTON_EXTRA, MOUSE_BUTTON_FORWARD, MOUSE_BUTTON_BACK`

## What Cube2D Engine Doesn't Bind?

Q: Wait, what? I thought Cube2D Engine binds everything from those files.
A: Nuh uh, not currently at least.

Cube2D Engine also does not yet bind classes which have members like `float v[3]`, you know, the c style array thing. but they will be bind-ed later.

{: .warning }
What you are unable to find is currently not bind-ed in [wren] because of a little problem with them and my laziness to fix those problems. If something important doesn't work for your project then please open a [issue on Github].

### Cube2D Framework
Lets start with the simplest, [Cube2D Framework]

#### `Scene`
`Scene` is a `class` for scene management which heavily relies on inheritance but for some reason [wren] doesn't support inheritance from `foreign` classes, `foreign` classes refer to classes bind-ed by the engine in our case.

Q: But according to home page's example, we were totally doing inheritance of `Scene`
A: In order to make it work I had to create equivalent of `Scene` `class` in [wren] to support inheritance which is contained in the `Cube2D` module you `import` in your wren file. 

Q: So here will be documentation for equivalent of `Scene` `class` ?
A: Nope, it works exactly the same.

#### `Rect`

{: .note }
`Rect` is bind-ed into wren but there's a catch.

`Rect` is a `class` for easier rectangular manipulation which you would also like to add inheritance to create stuff like entity, tile, player, enemy, etc. but `Rect` is a little more hard `class` to be recreated in wren, so I created bind-ed `Rect` `class` from c++ as `OrignalRect` in wren and created a wrapper `class` in purely in wren which calls `OrignalRect` behind the scenes   


Q: So why we were using `.Base` for `Engine.WASDMovement`?
A: `Engine.WASDMovement` takes `OrignalRect` aka C++ `Rect` to move it but `Rect` in [wren] is a [wren] `class` so it throws a bad cast error so I added a `.Base` getter to get the real deal which you can pass onto `Engine.WASDMovement`.

### raymath

The next simplest one is [raymath] 

Q: How do I use [raymath]'s `PI` and stuff, it doesn't follow the syntax shown in [How To Use Enums & Defines]
A: `import "raymath" for PI, EPSILON, DEG2RAD, RAD2DEG`

Q: What about `MatrixToFloat` and `Vector3ToFloat`?
A: Later.

#### Things that [raylib] defines
It would be real dumb to rebind things that [raylib] also defines so `import` those stuff from `raylib` module.

#### `float3` & `float16`
those two classes are not defined for the reason told in [What Cube2D Engine Doesn't Bind?]

#### `Vector3ToFloatV`, `MatrixToFloatV`
these are functions that use unbind-ed classes

### raylib
My worst nightmare.

### `Material`, `BoneInfo`, `ModelAnimation`, `VrDeviceInfo`, `VrSteroConfig` `AudioStream`, `Sound`, `Music`, `FilePathList`
those two classes are not defined for the reason told in [What Cube2D Engine Doesn't Bind?]

### `LoadVrStereoConfig`, `UnloadVrStereoConfig`, `LoadFileData`, `SaveFileData`, `ExportDataAsCode`, `LoadDirectoryFiles`, `LoadDirectoryFilesEx`, `LoadDroppedFiles`, `UnloadDirectoryFiles`, `LoadMaterials`, `LoadMaterialDefault`, `IsMaterialReady`, `UnloadMaterial`, `SetMaterialTexture`, `LoadWaveFromMemory`, `PlaySound`, `StopSound`, `PauseSound`, `ResumeSound`, `IsSoundPlaying`, `SetSoundVolume`, `SetSoundPitch`, `SetSoundPan`, `WaveCopy`, `WaveCrop`, `WaveFormat`, `LoadWaveSamples`, `LoadMusicStream`, `LoadMusicStreamFromMemory`, `IsMusicReady`, `UnloadMusicStream`, `PlayMusicStream`, `IsMusicStreamPlaying`, `UpdateMusicStream`, `StopMusicStream`, `PauseMusicStream`, `ResumeMusicStream`, `SeekMusicStream`, `SetMusicVolume`, `SetMusicPitch`, `SetMusicPan`, `GetMusicTimeLength`, `GetMusicTimePlayed`
, `LoadAudioStream`, `IsAudioStreamReady`, `UnloadAudioStream`, `UpdateAudioStream`, `IsAudioStreamProcessed`, `PlayAudioStream`, `PauseAudioStream`, `ResumeAudioStream`, `IsAudioStreamPlaying`, `StopAudioStream`, `SetAudioStreamVolume`, `SetAudioStreamPitch`, `SetAudioStreamPan`, `SetAudioStreamBufferSizeDefault`, `SetAudioStreamCallback`, `AttachAudioStreamProcessor`, `DetachAudioStreamProcessor`, `AttachAudioMixedProcessor`, `DetachAudioMixedProcessor`

those are functions that use unbind-ed classes

### `SetTraceLogCallback`, `SetLoadFileDataCallback`, `SetSaveFileDataCallback`, `SetLoadFileTextCallback`, `SetSaveFileTextCallback`
First of all I don't want you to modify my engine's callback and stuff.
Second, I don't remember what went wrong while binding those functions.

### `LoadFileData`, `UnloadFileData` , `CompressData`, `DecompressData`, `EncodeDataBase64`, `DecodeDataBase64`, `LoadImageFromMemory`
these functions use `unsigned char *` which my brain can't comprehend.

### `UnloadFileText`
this function was also out of my brain, so I just made `LoadFileText` call this function automatically once done and its probably better this way.

### `GenImageFontAtlas`
Just one `*` pointer drives me crazy and you expect me to comprehend two `*` pointers

### `TextCopy`, `TextIsEqual`, `TextLength`, `TextFormat`, `TextSubtext`, `TextReplace`, `TextInsert`, `TextJoin`, `TextSplit`, `TextAppend`, `TextFindIndex`
These text related stuff are not needed in [wren], [wren] has awesome string interpolation and stuff.

### `InitAudioDevice` , `CloseAudioDevice` , `IsAudioDeviceReady`
Those are handled by [Cube2D Framework]

[raylib]: https://raylib.com
[raymath]: https://github.com/raysan5/raylib/blob/master/src/raylib.h
[Cube2D Framework]: https://github.com/mastercuber55/Cube2D-Framework
[raylib.h]: https://github.com/raysan5/raylib/blob/master/src/raylib.h
[Cube2D.hpp]: https://github.com/mastercuber55/Cube2D-Framework/blob/main/Cube2D.hpp
[wren]: https://wren.io
[issue on Github] https://github.com/mastercuber55/Cube2D-Engine/issues