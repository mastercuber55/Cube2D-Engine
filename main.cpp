// #include "ini.h/ini.h"
#include <wrenbind17/wrenbind17.hpp>
#include <raylib.h>
#include <Cube2D.hpp>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>

namespace Wren = wrenbind17;
  
struct SceneError : Engine::Scene {

	std::string Error;
	Vector2 Size;

    SceneError(std::string Error) {
    	this->Error = Error;
    	Size = MeasureTextEx(GetFontDefault(), Error.c_str(), 24, 2);

    	SetWindowTitle("Cube2D - An Error Occured");
    	SetWindowSize(Size.x + 24 / 2, Size.y + 24 / 2);
    }

    void Update() {}
    void Draw() {
    	DrawText(Error.c_str(), 24 / 4, 32 / 4, 24, RED);
    	// GuiTextBox({0, 0, 32 * 5, 32}, const_cast<char*>(this->Error.c_str()), 0, false);
    }

    ~SceneError() {}
};


// struct SceneGen : Engine::Scene {

// 	Vector2 anchor01 = { 0, -24 };

// 	bool TextBoxNameEditMode = false;
//     char TextBox001Text[128] = "Name";
//     bool ValueBOx003EditMode = false;
//     int ValueBOx003Value = 0;
//     bool ValueBOx004EditMode = false;
//     int ValueBOx004Value = 0;
//     bool CreatePressed = false;
//     bool TextBox008EditMode = false;
//     char TextBox008Text[128] = "Main Script";
//     bool TextBox009EditMode = false;
//     char TextBox009Text[128] = "Scripts";
//     bool TextBox010EditMode = false;
//     char TextBox010Text[128] = "Resources";
//     bool Fullscreen = true;
//     bool Logging = true;

//     SceneGen() {
//     	Engine::Init(300, 100, "Cube2D - Game Template Generator");
//     	this->BackgroundColor = BLACK;
//     }

//     void Update() override {

//     }
//     void Draw() override {
//     	if (GuiTextBox((Rectangle){ anchor01.x + 8, anchor01.y + 32, 96, 24 }, TextBox001Text, 128, TextBoxNameEditMode)) TextBoxNameEditMode = !TextBoxNameEditMode;
//         GuiGroupBox((Rectangle){ anchor01.x + 8, anchor01.y + 64, 96, 56 }, "Resolution");
//         if (GuiValueBox((Rectangle){ anchor01.x + 32, anchor01.y + 72, 56, 16 }, "X ", &ValueBOx003Value, 0, 100, ValueBOx003EditMode)) ValueBOx003EditMode = !ValueBOx003EditMode;
//         if (GuiValueBox((Rectangle){ anchor01.x + 32, anchor01.y + 96, 56, 16 }, "Y ", &ValueBOx004Value, 0, 100, ValueBOx004EditMode)) ValueBOx004EditMode = !ValueBOx004EditMode;
//         CreatePressed = GuiButton((Rectangle){ anchor01.x + 112, anchor01.y + 96, 88, 24 }, "Create"); 
//         if (GuiTextBox((Rectangle){ anchor01.x + 208, anchor01.y + 32, 88, 24 }, TextBox008Text, 128, TextBox008EditMode)) TextBox008EditMode = !TextBox008EditMode;
//         if (GuiTextBox((Rectangle){ anchor01.x + 208, anchor01.y + 64, 88, 24 }, TextBox009Text, 128, TextBox009EditMode)) TextBox009EditMode = !TextBox009EditMode;
//         if (GuiTextBox((Rectangle){ anchor01.x + 208, anchor01.y + 96, 88, 24 }, TextBox010Text, 128, TextBox010EditMode)) TextBox010EditMode = !TextBox010EditMode;
//         GuiToggle((Rectangle){ anchor01.x + 112, anchor01.y + 32, 88, 24 }, "Fullscreen", &Fullscreen);
//         GuiToggle((Rectangle){ anchor01.x + 112, anchor01.y + 64, 88, 24 }, "Logging", &Logging);
//     }

//     ~SceneGen() {

//     }
// };

// struct SceneError : Engine::Scene {

// 	char * Error;

//     SceneError(std::string Error) {
//     	this->Error = const_cast<char*>(Error.c_str());
//     	TextCopy(this->Error, Error.c_str());
//     	SetWindowSize(32 * 12, 32 * 3);
//     	SetWindowTitle("Cube2D - An Error Occured");
//     }

//     void Update() override {}
//     void Draw() override {
// 		GuiTextBox({ 0, 0, 32 * 12, 32 * 3 }, this->Error, 32, false);    	
//     }

//     ~SceneError() {}
// };

struct paths {
	std::string Appdata;
	std::string Scripts;
	std::string Resources;
	std::string MainScript;
	std::string SceneError;
	std::string Icon;
};

std::ofstream LogFile;
std::ostringstream LogStream;
paths Paths;

bool Logging;

void CustomLog(int LOG_LEVEL, const char * Text, va_list Args);
int InitFromConfig(Wren::VM & VM);

void BindRaylib(Wren::VM & VM);
void BindRaymath(Wren::VM & VM);
void BindEngine(Wren::VM & VM);

#define FileNotFound(File) Wren::Exception(std::string("[") + File + std::string("] was not found."))

int main() {


	SetTraceLogCallback(CustomLog);

	TraceLog(LOG_INFO, "Initializing Wren::VM");
	Wren::VM VM;

	VM.setPrintFunc([](const char * Text){
		LogFile << ((strlen(Text) != 1) ? "[WREN] " : "") << Text;
	});

	VM.setLoadFileFunc([&Paths](
        const std::vector<std::string>&, 
        const std::string& Name) -> std::string {

		std::string File(Paths.Scripts + (IsFileExtension(Name.c_str(), ".wren") ? Name : (Name + ".wren")));
		if(!FileExists(File.c_str())) {
			TraceLog(LOG_ERROR, "[%s] was not found.", File.c_str());
			return "";
		}
		return LoadFileText(File.c_str());
	});

	// Bind everything
	BindRaylib(VM);
	BindRaymath(VM);
	BindEngine(VM);

	if(InitFromConfig(VM) == EXIT_FAILURE) return EXIT_FAILURE;

	// return SceneGen().Run();

	try {
		VM.runFromModule(Paths.MainScript);
	} catch(wrenbind17::Exception& Error) {
		TraceLog(LOG_ERROR, Error.what());
		// SceneError(Error.what()).Run();
		VM.runFromModule("Scenes/SceneError.wren");
		Wren::Variable Scene = VM.find("Scenes/SceneError.wren", "Instance");
		Wren::Method ErrorSetter = Scene.func("SetError(_)");
		std::string ErrorStr = Error.what();
		ErrorSetter(ErrorStr);
		Wren::Method Runner = Scene.func("Run()");
		Runner();
	}

	Engine::Close();

	if(LogFile.is_open()) LogFile.close();
}

void CustomLog(int LOG_LEVEL, const char * Text, va_list Args) {

	std::string Tag;

	switch(LOG_LEVEL) {
		case LOG_INFO: Tag = "[INFO] "; break;
		case LOG_ERROR: Tag = "[ERROR] "; break;
		case LOG_WARNING: Tag = "[WARN] "; break;
		case LOG_DEBUG: Tag = "[DEBUG] "; break;
		default: break;
	}	

	char buffer[1024];
    vsnprintf(buffer, sizeof(buffer), Text, Args); 

    std::cout << Tag << buffer << std::endl;
    LogFile.is_open() ? (LogFile << Tag << buffer << std::endl) : LogStream << Tag << buffer << std::endl;
}

int InitFromConfig(Wren::VM & VM) {
		// Load Configuration File
	if(!FileExists("Game.wren")) {
		TraceLog(LOG_ERROR, "[%s] was not found.", "Game.wren");
		Engine::Init(640, 480, "Cube2D - An Error Occured");
		SceneError("[Game.wren] was not found.").Run();
		Engine::Close();
		return EXIT_FAILURE;
	}
	VM.runFromModule("Game.wren");

	// Make var Window usable
	Wren::Variable WindowMap = VM.find("Game.wren", "Window");
	Wren::Method WindowGet = WindowMap.func("[_]");
	
	// Initialization
	int Width;
	if(WindowGet("Width").is<int>()) Width = WindowGet("Width").as<int>();
	else {
		TraceLog(LOG_WARNING, "Window width was not provided, switching to 640");
		Width = 640;
	}

	int Height;
	if(WindowGet("Height").is<int>()) Height = WindowGet("Height").as<int>();
	else {
		TraceLog(LOG_WARNING, "Window height was not provided, switching to 640");
		Height = 640;
	}

	if(!WindowGet("Title").is<std::string>()) {
		TraceLog(LOG_ERROR, "Window title which is a must was not provided.");
		return EXIT_FAILURE; 
	}
	std::string Title = WindowGet("Title").as<std::string>();
	Engine::Init(Width, Height, Title);

	// Other Stuff
	Paths.Appdata = std::getenv("APPDATA");
	Paths.Appdata += "/";
	Paths.Appdata += Title;
	Paths.Appdata += "/";

	LogFile.open(Paths.Appdata + "Log.txt");
	LogFile << LogStream.str();

	if(WindowGet("FPS").is<int>()) SetTargetFPS(WindowGet("FPS").as<int>());
	if(WindowGet("Fullscreen").is<bool>() && WindowGet("Fullscreen").as<bool>()) ToggleFullscreen();

	// Make var Path usable
	Wren::Variable PathMap = VM.find("Game.wren", "Path");
	Wren::Method PathGet = PathMap.func("[_]");
	
	//Set Icon
	Paths.Icon = PathGet("Icon").as<std::string>();
	SetWindowIcon(LoadImage(("Resources/" + Paths.Icon).c_str()));

	Paths.Scripts = PathGet("Scripts").as<std::string>();
	Paths.Resources = PathGet("Resources").as<std::string>();
	Paths.MainScript = PathGet("MainScript").as<std::string>();
	Paths.SceneError = PathGet("SceneError").as<std::string>();


	return EXIT_SUCCESS;
}