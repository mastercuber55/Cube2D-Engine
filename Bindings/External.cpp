#include <wrenbind17/wrenbind17.hpp>
#include "RLL.hpp"
#include <iostream>
#include <filesystem>

namespace RL {
	#include <raylib.h>
}

namespace fs = std::filesystem;
namespace Wren = wrenbind17;

void LoadPlugins(Wren::VM &VM) {

	if (!fs::exists("Plugins")) return;

	RL::TraceLog(RL::LOG_INFO, "Initializing plugins"); 

	for (const auto& Entry : fs::directory_iterator("Plugins")) {
    	std::string EntryName = Entry.path().filename().string();
    	RLL Library("Plugins/" + EntryName);
    	if(Library.Handle == nullptr) {
    		RL::TraceLog(RL::LOG_ERROR, "    > [%s] Unable to load plugin", EntryName.c_str());
    		continue;
    	}
    	auto Main = Library.GetFunction<bool(*)(Wren::VM&)>("Main");
    	if(Main == nullptr) {
    		RL::TraceLog(RL::LOG_ERROR, "    > [%s] Unable to find Main", EntryName.c_str());
    		continue;
    	}
    	if(Main(VM) == EXIT_SUCCESS) RL::TraceLog(RL::LOG_INFO, "    > [%s] Initialized successfully", EntryName.c_str());
    }
}
