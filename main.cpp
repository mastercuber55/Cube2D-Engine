#include <wrenbind17/wrenbind17.hpp>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem> 
#include <tinyfiledialogs.h>
#include <raylib.h>

namespace Wren = wrenbind17;

std::ofstream LogFile;

void CustomLog(int LOG_LEVEL, const char * Text, va_list Args);

void BindRaylib(Wren::VM & VM);
void BindRaymath(Wren::VM & VM);
void BindEngine(Wren::VM & VM);
void LoadPlugins(Wren::VM & VM);

#define FileNotFound(File) Wren::Exception(std::string("[") + File + std::string("] was not found."))

int main() {

	LogFile.open("./Log.txt");
	if(!LogFile.is_open()) {
		TraceLog(LOG_WARNING, "Unable to open log file!");
		TraceLog(LOG_WARNING, "Printing only to stderr!");
	}
	
	SetTraceLogCallback(CustomLog);
	TraceLog(LOG_INFO, "Initializing Cube2D Engine"); 
	
	if(!FileExists("main.wren")) {
		TraceLog(LOG_ERROR, "[%s] was not found.", "main.wren");
		tinyfd_messageBox("Cube2D - An Error Occured" , "[main.wren] was not found." , "ok" , "error", 1);
		return EXIT_FAILURE;
	}


	TraceLog(LOG_INFO, "Initializing Wren::VM");
	Wren::VM VM;

	VM.setPrintFunc([](const char * Text){
		std::clog << ((strlen(Text) != 1) ? "[WREN] " : "") << Text;
		LogFile << ((strlen(Text) != 1) ? "[WREN] " : "") << Text;
	});

	VM.setLoadFileFunc([](
        const std::vector<std::string>&, 
        const std::string& Name) -> std::string {


		std::string File;
		Name != "main.wren" ? File = "Scripts/" + (IsFileExtension(Name.c_str(), ".wren") ? Name : (Name + ".wren"))
		: File = Name;

		if(!FileExists(File.c_str())) {
			std::string Error = "[" + File + "] was not found.";
			TraceLog(LOG_ERROR, Error.c_str());
			tinyfd_messageBox("Cube2D - An Error Occured", Error.c_str(), "ok", "error", 1);
			return "";
		}
		char * Text = LoadFileText(File.c_str());
		Text = TextReplace(Text, "import \"Engine\"", "import \"Engine\" for Rect, Scene, SceneManager, Tools, Shared");
		std::string ToReturn = Text;
		UnloadFileText(Text);
		return ToReturn;
	});

	// Bind everything
	BindRaylib(VM);
	BindRaymath(VM);
	BindEngine(VM);
	// LoadPlugins(VM);

	InitWindow(640, 480, "Cube2D");
	InitAudioDevice();
	SetExitKey(KEY_NULL);
	
	std::string Icon = "Resources/Icon.png";
	if(FileExists(Icon.c_str())) SetWindowIcon(LoadImage(Icon.c_str()));

	try {
		VM.runFromModule("main.wren");
	} catch(wrenbind17::Exception& Error) {
		TraceLog(LOG_ERROR, Error.what());
		tinyfd_messageBox("Cube2D - An Error Occured", Error.what(), "ok", "error", 1);
	}

	CloseAudioDevice();
	CloseWindow();

	if(LogFile.is_open()) LogFile.close();
	return EXIT_SUCCESS;
}

void CustomLog(int LOG_LEVEL, const char * Text, va_list Args) {

	std::string Tag;

	switch(LOG_LEVEL) {
		case LOG_INFO: 		Tag = "[INFO] ";	break;
		case LOG_ERROR: 	Tag = "[ERROR] ";	break;
		case LOG_WARNING:	Tag = "[WARN] ";	break;
		case LOG_DEBUG: 	Tag = "[DEBUG] "; 	break;
		default: 								break;
	}

	char Buffer[1024];
    vsnprintf(Buffer, sizeof(Buffer), Text, Args); 

    std::clog << Tag << Buffer << std::endl;
    if(LogFile.is_open()) LogFile << Tag << Buffer << std::endl;

}