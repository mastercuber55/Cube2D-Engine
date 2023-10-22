#include <raylib.h>
#include "Raylib.hpp"
#include <wrenbind17/wrenbind17.hpp>
namespace Wren = wrenbind17;

//------------------------------------------------------------------------------------
// Window and Graphics Device Functions (Module: core)
//------------------------------------------------------------------------------------

void BindRaylibCore(Wren::ForeignModule& Module, Wren::ForeignKlassImpl<rl>& Class) {
 
	// Window-related functions
	Class.funcStaticExt<&rl::wInitWindow>("InitWindow");
	Class.funcStaticExt<&WindowShouldClose>("WindowShouldClose");
	Class.funcStaticExt<&CloseWindow>("CloseWindow");
	Class.funcStaticExt<&IsWindowReady>("IsWindowReady");
	Class.funcStaticExt<&IsWindowFullscreen>("IsWindowFullscreen");
	Class.funcStaticExt<&IsWindowHidden>("IsWindowHidden");
	Class.funcStaticExt<&IsWindowMinimized>("IsWindowMinimized");
	Class.funcStaticExt<&IsWindowMaximized>("IsWindowMaximized");
	Class.funcStaticExt<&IsWindowFocused>("IsWindowFocused");
	Class.funcStaticExt<&IsWindowResized>("IsWindowResized");
	Class.funcStaticExt<&IsWindowState>("IsWindowState");
	Class.funcStaticExt<&SetWindowState>("SetWindowState");
	Class.funcStaticExt<&ClearWindowState>("ClearWindowState");
	Class.funcStaticExt<&ToggleFullscreen>("ToggleFullscreen");
	Class.funcStaticExt<&MaximizeWindow>("MaximizeWindow");
	Class.funcStaticExt<&MinimizeWindow>("MinimizeWindow");
	Class.funcStaticExt<&RestoreWindow>("RestoreWindow");
	Class.funcStaticExt<&SetWindowIcon>("SetWindowIcon");
	Class.funcStaticExt<&SetWindowIcons>("SetWindowIcons");
	Class.funcStaticExt<&rl::wSetWindowTitle>("SetWindowTitle");
	Class.funcStaticExt<&SetWindowPosition>("SetWindowPosition");
	Class.funcStaticExt<&SetWindowMonitor>("SetWindowMonitor");
	Class.funcStaticExt<&SetWindowMinSize>("SetWindowMinSize");
	Class.funcStaticExt<&SetWindowSize>("SetWindowSize");
	Class.funcStaticExt<&SetWindowOpacity>("SetWindowOpacity");
	Class.funcStaticExt<&GetWindowHandle>("GetWindowHandle");
	Class.funcStaticExt<&GetScreenWidth>("GetScreenWidth");
	Class.funcStaticExt<&GetScreenHeight>("GetScreenHeight");
	Class.funcStaticExt<&GetRenderWidth>("GetRenderWidth");
	Class.funcStaticExt<&GetRenderHeight>("GetRenderHeight");
	Class.funcStaticExt<&GetMonitorCount>("GetMonitorCount");
	Class.funcStaticExt<&GetCurrentMonitor>("GetCurrentMonitor");
	Class.funcStaticExt<&GetMonitorPosition>("GetMonitorPosition");
	Class.funcStaticExt<&GetMonitorWidth>("GetMonitorWidth");
	Class.funcStaticExt<&GetMonitorHeight>("GetMonitorHeight");
	Class.funcStaticExt<&GetMonitorPhysicalWidth>("GetMonitorPhysicalWidth");
	Class.funcStaticExt<&GetMonitorPhysicalHeight>("GetMonitorPhysicalHeight");
	Class.funcStaticExt<&GetMonitorRefreshRate>("GetMonitorRefreshRate");
	Class.funcStaticExt<&GetWindowPosition>("GetWindowPosition");
	Class.funcStaticExt<&GetWindowScaleDPI>("GetWindowScaleDPI");
	Class.funcStaticExt<&GetMonitorName>("GetMonitorName");
	Class.funcStaticExt<&rl::wSetClipboardText>("SetClipboardText");
	Class.funcStaticExt<&GetClipboardText>("GetClipboardText");
	Class.funcStaticExt<&EnableEventWaiting>("EnableEventWaiting");
	Class.funcStaticExt<&DisableEventWaiting>("DisableEventWaiting");
 
	// Custom frame control functions
	Class.funcStaticExt<&SwapScreenBuffer>("SwapScreenBuffer");
	Class.funcStaticExt<&PollInputEvents>("PollInputEvents");
	Class.funcStaticExt<&WaitTime>("WaitTime");

	// Cursor-related functions
	Class.funcStaticExt<&ShowCursor>("ShowCursor");
	Class.funcStaticExt<&HideCursor>("HideCursor");
	Class.funcStaticExt<&IsCursorHidden>("IsCursorHidden");
	Class.funcStaticExt<&EnableCursor>("EnableCursor");
	Class.funcStaticExt<&DisableCursor>("DisableCursor");
	Class.funcStaticExt<&IsCursorOnScreen>("IsCursorOnScreen");

	// Drawing-related functions
	Class.funcStaticExt<&ClearBackground>("ClearBackground");
	Class.funcStaticExt<&BeginDrawing>("BeginDrawing");
	Class.funcStaticExt<&EndDrawing>("EndDrawing");
	Class.funcStaticExt<&BeginMode2D>("BeginMode2D");
	Class.funcStaticExt<&EndMode2D>("EndMode2D");
	Class.funcStaticExt<&BeginMode3D>("BeginMode3D");
	Class.funcStaticExt<&EndMode3D>("EndMode3D");
	Class.funcStaticExt<&BeginTextureMode>("BeginTextureMode");
	Class.funcStaticExt<&EndTextureMode>("EndTextureMode");
	Class.funcStaticExt<&BeginShaderMode>("BeginShaderMode");
	Class.funcStaticExt<&EndShaderMode>("EnShadereMode");
	Class.funcStaticExt<&BeginBlendMode>("BeginBlendMode");
	Class.funcStaticExt<&EndBlendMode>("EndBlendMode");
	Class.funcStaticExt<&BeginScissorMode>("BeginScissorMode");
	Class.funcStaticExt<&EndScissorMode>("EndScissorMode");
	Class.funcStaticExt<&BeginVrStereoMode>("BeginVrStereoMode");
	Class.funcStaticExt<&EndVrStereoMode>("EndVrStereoMode");

	// VR stereo config functions for VR simulator

	// Shader management functions
	Class.funcStaticExt<&rl::wLoadShader>("LoadShader");
	Class.funcStaticExt<&rl::wLoadShaderFromMemory>("LoadShaderFromMemory");
	Class.funcStaticExt<&IsShaderReady>("IsShaderReady");
	Class.funcStaticExt<&rl::wGetShaderLocation>("GetShaderLocation");
	Class.funcStaticExt<&rl::wGetShaderLocationAttrib>("GetShaderLocationAttrib");
	Class.funcStaticExt<&SetShaderValue>("SetShaderValue");
	Class.funcStaticExt<&SetShaderValueV>("SetShaderValueV");
	Class.funcStaticExt<&SetShaderValueMatrix>("SetShaderValueMatrix");
	Class.funcStaticExt<&SetShaderValueTexture>("SetShaderValueTexture");
	Class.funcStaticExt<&UnloadShader>("UnloadShader");

	// Screen-space-related functions
	Class.funcStaticExt<&GetMouseRay>("GetMouseRay");
	Class.funcStaticExt<&GetCameraMatrix>("GetCameraMatrix");
	Class.funcStaticExt<&GetCameraMatrix2D>("GetCameraMatrix2D");
	Class.funcStaticExt<&GetWorldToScreen>("GetWorldToScreen");
	Class.funcStaticExt<&GetScreenToWorld2D>("GetScreenToWorld2D");
	Class.funcStaticExt<&GetScreenToWorld2D>("GetScreenToWorld2D");
	Class.funcStaticExt<&GetWorldToScreenEx>("GetWorldToScreenEx");
	Class.funcStaticExt<&GetWorldToScreen2D>("GetWorldToScreen2D");

	// Timing-related functionsud
	Class.funcStaticExt<&SetTargetFPS>("SetTargetFPS");
	Class.funcStaticExt<&GetFPS>("GetFPS");
	Class.funcStaticExt<&GetFrameTime>("GetFrameTime");
	Class.funcStaticExt<&GetTime>("GetTime");

	// Misc. functions
	Class.funcStaticExt<&GetRandomValue>("GetRandomValue");
	Class.funcStaticExt<&SetRandomSeed>("SetRandomSeed");
	Class.funcStaticExt<&rl::wTakeScreenshot>("TakeScreenshot");
	Class.funcStaticExt<&SetConfigFlags>("SetConfigFlags");

	Class.funcStaticExt<&rl::wTraceLog>("TraceLog");
	Class.funcStaticExt<&SetTraceLogLevel>("SetTraceLogLevel");

	Class.funcStaticExt<&rl::wOpenURL>("OpenURL");

	// Set custom callbacks
	// Files management functions
	Class.funcStaticExt<&rl::wLoadFileText>("LoadFileText"); 
	Class.funcStaticExt<&rl::wSaveFileText>("SaveFileText");
	Class.funcStaticExt<&rl::wFileExists>("FileExists");
	Class.funcStaticExt<&rl::wDirectoryExists>("DirectoryExists");
	Class.funcStaticExt<&rl::wIsFileExtension>("IsFileExtension");
	Class.funcStaticExt<&rl::wGetFileLength>("GetFileLength");
	Class.funcStaticExt<&GetFileExtension>("GetFileExtension");
	Class.funcStaticExt<&GetFileName>("GetFileName");
	Class.funcStaticExt<&GetFileNameWithoutExt>("GetFileNameWithoutExt");
	Class.funcStaticExt<&GetDirectoryPath>("GetDirectoryPath");
	Class.funcStaticExt<&GetPrevDirectoryPath>("GetPrevDirectoryPath");
	Class.funcStaticExt<&GetWorkingDirectory>("GetWorkingDirectory");
	Class.funcStaticExt<&GetApplicationDirectory>("GetApplicationDirectory");
	Class.funcStaticExt<&rl::wChangeDirectory>("ChangeDirectory");
	Class.funcStaticExt<&rl::wIsPathFile>("IsPathFile");
	Class.funcStaticExt<&IsFileDropped>("IsFileDropped");
	Class.funcStaticExt<&GetFileModTime>("GetFileModTime");
	// Compression/Encoding functionality
	//------------------------------------------------------------------------------------
	// Input Handling Functions (Module: core)
	//------------------------------------------------------------------------------------
	// Input-related functions: keyboard
	Class.funcStaticExt<&IsKeyPressed>("IsKeyPressed");
	Class.funcStaticExt<&IsKeyDown>("IsKeyDown");
	Class.funcStaticExt<&IsKeyReleased>("IsKeyReleased");
	Class.funcStaticExt<&IsKeyUp>("IsKeyUp");
	Class.funcStaticExt<&SetExitKey>("SetExitKey");
	Class.funcStaticExt<&GetKeyPressed>("GetKeyPressed");
	Class.funcStaticExt<&GetCharPressed>("GetCharPressed");

	// Input-related functions: gamepads
	Class.funcStaticExt<&IsGamepadAvailable>("IsGamepadAvailable");
	Class.funcStaticExt<&GetGamepadName>("GetGamepadName");
	Class.funcStaticExt<&IsGamepadButtonPressed>("IsGamepadButtonPressed");
	Class.funcStaticExt<&IsGamepadButtonDown>("IsGamepadButtonDown");
	Class.funcStaticExt<&IsGamepadButtonReleased>("IsGamepadButtonReleased");
	Class.funcStaticExt<&IsGamepadButtonUp>("IsGamepadButtonUp");
	Class.funcStaticExt<&GetGamepadButtonPressed>("GetGamepadButtonPressed");
	Class.funcStaticExt<&GetGamepadAxisCount>("GetGamepadAxisCount");
	Class.funcStaticExt<&GetGamepadAxisMovement>("GetGamepadAxisMovement");
	Class.funcStaticExt<&rl::wSetGamepadMappings>("SetGamepadMappings");

	// Input-related functions: mouse
	Class.funcStaticExt<&IsMouseButtonPressed>("IsMouseButtonPressed");
	Class.funcStaticExt<&IsMouseButtonDown>("IsMouseButtonDown");
	Class.funcStaticExt<&IsMouseButtonReleased>("IsMouseButtonReleased");
	Class.funcStaticExt<&IsMouseButtonUp>("IsMouseButtonUp");
	Class.funcStaticExt<&GetMouseX>("GetMouseX");
	Class.funcStaticExt<&GetMouseY>("GetMouseY");
	Class.funcStaticExt<&GetMousePosition>("GetMousePosition");
	Class.funcStaticExt<&GetMouseDelta>("GetMouseDelta");
	Class.funcStaticExt<&SetMousePosition>("SetMousePosition");
	Class.funcStaticExt<&SetMouseOffset>("SetMouseOffset");
	Class.funcStaticExt<&SetMouseScale>("SetMouseScale");
	Class.funcStaticExt<&GetMouseWheelMove>("GetMouseWheelMove");
	Class.funcStaticExt<&GetMouseWheelMoveV>("GetMouseWheelMoveV");
	Class.funcStaticExt<&SetMouseCursor>("SetMouseCursor");

	// Input-related functions: touch
	Class.funcStaticExt<&GetTouchX>("GetTouchX");
	Class.funcStaticExt<&GetTouchY>("GetTouchY");
	Class.funcStaticExt<&GetTouchPosition>("GetTouchPosition");
	Class.funcStaticExt<&GetTouchPointId>("GetTouchPointId");
	Class.funcStaticExt<&GetTouchPointCount>("GetTouchPointCount");
}