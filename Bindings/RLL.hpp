#ifdef _WIN32
    #include <windows.h>
    #define HANDLE_TYPE HMODULE
    #define LOAD_LIB(LIB) LoadLibrary(LIB.c_str())
    #define UNLOAD_LIB(HANDLE) FreeLibrary(HANDLE)
    #define GET_FUNC(HANDLE, FUNC) GetProcAddress(HANDLE, FUNC)
#else
    #include <dlfcn.h>
    #define HANDLE_TYPE void*
    #define LOAD_LIB(LIB) dlopen(LIB.c_str(), RTLD_LAZY)
    #define UNLOAD_LIB(HANDLE) dlclose(HANDLE)
    #define GET_FUNC(HANDLE, FUNC) dlsym(HANDLE, FUNC)
#endif

#include <iostream>

struct RLL {

    HANDLE_TYPE Handle = nullptr;
    
    RLL(const std::string& Lib) {
        Handle = LOAD_LIB(Lib);
    }

    ~RLL() {
        if (Handle != nullptr) UNLOAD_LIB(Handle);
    }

    template <typename FunctionType>
    FunctionType GetFunction(const std::string& FunctionName) {
        if (Handle == nullptr) return nullptr;

        FunctionType Function = reinterpret_cast<FunctionType>(GET_FUNC(Handle, FunctionName.c_str()));
        return Function;
    }
};
