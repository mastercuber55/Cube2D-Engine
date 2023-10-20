#include <raylib.h>
#include "Raylib.hpp"
#include <wrenbind17/wrenbind17.hpp>
#include <string>
namespace Wren = wrenbind17;

void rl::wInitWindow(int width, int height, const std::string& title) {
	InitWindow(width, height, title.c_str());
} 
void rl::wSetWindowTitle(const std::string& title) {
	SetWindowTitle(title.c_str());
}
void rl::wSetClipboardText(const std::string& text) {
	SetClipboardText(text.c_str());
}
Shader rl::wLoadShader(const std::string& vsFileName, const std::string& fsFileName) {
	return LoadShader(vsFileName.c_str(), fsFileName.c_str());
}
Shader rl::wLoadShaderFromMemory(const std::string& vsCode, const std::string& fsCode) {
	return LoadShader(vsCode.c_str(), fsCode.c_str());
}
int rl::wGetShaderLocation(Shader shader, const std::string& uniformName) {
	return GetShaderLocation(shader, uniformName.c_str());
}
int rl::wGetShaderLocationAttrib(Shader shader, const std::string& uniformName) {
	return GetShaderLocationAttrib(shader, uniformName.c_str());
}
void rl::wTakeScreenshot(const std::string& fileName) {
	wTakeScreenshot(fileName.c_str());
}
void rl::wTraceLog(int logLevel, const std::string& text) {
	TraceLog(logLevel, text.c_str()); 
	// "..." Can goto hell, Wren has interpolation in strings 
}
void rl::wOpenURL(std::string& url) {
	OpenURL(url.c_str());
}
// const std::string wLoadFileData(const std::string& fileName, unsigned int * bytesRead) {
// 	unsigned char * Raw = LoadFileData(fileName.c_str(), bytesRead);
// 	const std::string ToReturn = Raw;
// 	UnloadFileData(Raw);
// }
// bool wSaveFileData(const std::string& fileName, void *data, unsigned int bytesToWrite) {
// 	return SaveFileData(fileName.c_str(), data, bytesToWrite);
// } 
// bool wExportDataAsCode(const std::string& data, unsigned int size, const std::string& fileName) {
// 	return ExportDataAsCode(data.c_str(), size, fileName.c_str());
// }
const std::string rl::wLoadFileText(const std::string& fileName) {
	char * Raw = LoadFileText(fileName.c_str());
	const std::string ToReturn = Raw;
	UnloadFileText(Raw);
	return ToReturn;
}
bool rl::wSaveFileText(const std::string& fileName, const std::string& text) {
	
	return SaveFileText(fileName.c_str(),  const_cast<char*>(text.c_str()));
}
bool rl::wFileExists(const std::string& fileName) {
	return FileExists(fileName.c_str());
}
bool rl::wDirectoryExists(const std::string& dirPath) {
	return DirectoryExists(dirPath.c_str());
}
bool rl::wIsFileExtension(const std::string& fileName, const std::string& ext) {
	return IsFileExtension(fileName.c_str(), ext.c_str());
}
int rl::wGetFileLength(const std::string& fileName) {
	return GetFileLength(fileName.c_str());
}
bool rl::wChangeDirectory(const std::string& dir) {
	return ChangeDirectory(dir.c_str());
}
bool rl::wIsPathFile(const std::string& path) {
	return IsPathFile(path.c_str());
}
long rl::wGetFileModTime(const std::string& fileName) {
	return GetFileModTime(fileName.c_str());
}
int rl::wSetGamepadMappings(const std::string& mapping) {
	return SetGamepadMappings(mapping.c_str());
}
Image rl::wLoadImage(const std::string& fileName) {
	return LoadImage(fileName.c_str());
}
Image rl::wLoadImageRaw(const std::string& fileName, int width, int height, int format, int headerSize) {
	return LoadImageRaw(fileName.c_str(), width, height, format, headerSize);
}
Image rl::wLoadImageAnim(const std::string& fileName, int *frames) {
	return LoadImageAnim(fileName.c_str(), frames);
}
bool rl::wExportImage(Image image, const std::string& fileName) {
	return ExportImage(image, fileName.c_str());
}
bool rl::wExportImageAsCode(Image image, const std::string& fileName) {
	return ExportImageAsCode(image, fileName.c_str());
}
Image rl::wGenImageText(int width, int height, const std::string& text) {
	return GenImageText(width, height, text.c_str());
}
Image rl::wImageText(const std::string& text, int fontSize, Color color) {
	return ImageText(text.c_str(), fontSize, color);
}
Image rl::wImageTextEx(Font font, const std::string& text, float fontSize, float spacing, Color tint) {
	return ImageTextEx(font, text.c_str(), fontSize, spacing, tint);
}
void rl::wImageDrawText(Image *dst, const std::string& text, int posX, int posY, int fontSize, Color color) {
	ImageDrawText(dst, text.c_str(), posX, posY, fontSize, color);
}
void rl::wImageDrawTextEx(Image *dst, Font font, const std::string& text, Vector2 position, float fontSize, float spacing, Color tint) {
	ImageDrawTextEx(dst, font, text.c_str(), position, fontSize, spacing, tint);
}
Texture2D rl::wLoadTexture(const std::string& fileName) {
	return LoadTexture(fileName.c_str());
}
Font rl::wLoadFont(const std::string& fileName) {
	return LoadFont(fileName.c_str());
}
Font rl::wLoadFontEx(const std::string& fileName, int fontSize, int *fontChars, int glyphCount) {
	return LoadFontEx(fileName.c_str(), fontSize, fontChars, glyphCount);
}
Font rl::wLoadFontFromMemory(const std::string& fileType, const unsigned char *fileData, int dataSize, int fontSize, int *fontChars, int glyphCount) {
	return wLoadFontFromMemory(fileType.c_str(), fileData, dataSize, fontSize, fontChars, glyphCount);
}
GlyphInfo * rl::wLoadFontData(const unsigned char *fileData, int dataSize, int fontSize, int *fontChars, int glyphCount, int type) {
	return LoadFontData(fileData, dataSize, fontSize, fontChars, glyphCount, type);
}
bool rl::wExportFontAsCode(Font font, const std::string& fileName) {
	return ExportFontAsCode(font, fileName.c_str());
}
void rl::wDrawText(const std::string& text, int posX, int posY, int fontSize, Color color) {
	DrawText(text.c_str(), posX, posY, fontSize, color);
}
void rl::wDrawTextEx(Font font, const std::string& text, Vector2 position, float fontSize, float spacing, Color tint) {
	DrawTextEx(font, text.c_str(), position, fontSize, spacing, tint);
}
void rl::wDrawTextPro(Font font, const std::string& text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint) {
	DrawTextPro(font, text.c_str(), position, origin, rotation, fontSize, spacing, tint);
}
int rl::wMeasureText(const std::string& text, int fontSize) {
	return MeasureText(text.c_str(), fontSize);
}
Vector2 rl::wMeasureTextEx(Font font, const std::string& text, float fontSize, float spacing) {
	return MeasureTextEx(font, text.c_str(), fontSize, spacing);
}
int * rl::wLoadCodepoints(const std::string& text, int *count) {
	return LoadCodepoints(text.c_str(), count);
}
int rl::wGetCodepointCount(const std::string& text) {
	return GetCodepointCount(text.c_str());
}
int rl::wGetCodepoint(const std::string& text, int *codepointSize) {
	return wGetCodepoint(text.c_str(), codepointSize);
}
int rl::wGetCodepointNext(const std::string& text, int *codepointSize) {
	return GetCodepointNext(text.c_str(), codepointSize);
}
int rl::wGetCodepointPrevious(const std::string& text, int *codepointSize) {
	return wGetCodepointPrevious(text.c_str(), codepointSize);
}  
const char * rl::wTextToUpper(const std::string& text) {
	return TextToUpper(text.c_str());
}
const char * rl::wTextToLower(const std::string& text) {
	return TextToLower(text.c_str());
}
const char * rl::wTextToPascal(const std::string& text) {
	return TextToPascal(text.c_str());
}
int rl::wTextToInteger(const std::string& text) {
	return TextToInteger(text.c_str());
}
Model rl::wLoadModel(const std::string& fileName) {
	return LoadModel(fileName.c_str());
}
bool rl::wExportMesh(Mesh mesh, const std::string& fileName) {
	return ExportMesh(mesh, fileName.c_str());
}  
Material * rl::wLoadMaterials(const std::string& fileName, int *materialCount) {
	return LoadMaterials(fileName.c_str(), materialCount);
}
ModelAnimation * rl::wLoadModelAnimations(const std::string& fileName, unsigned int *animCount) {
	return LoadModelAnimations(fileName.c_str(), animCount);
}
Wave rl::wLoadWave(const std::string& fileName) {
	return LoadWave(fileName.c_str());
}
Wave rl::wLoadWaveFromMemory(const std::string& fileType, const unsigned char *fileData, int dataSize) {
	return LoadWaveFromMemory(fileType.c_str(), fileData, dataSize);
}
Sound rl::wLoadSound(const std::string& fileName) {
	return LoadSound(fileName.c_str());
}
bool rl::wExportWave(Wave wave, const std::string& fileName) {
	return ExportWave(wave, fileName.c_str()); 
}
Music rl::wLoadMusicStream(const std::string& fileName) {
	return LoadMusicStream(fileName.c_str());	
}
Music rl::wLoadMusicStreamFromMemory(const std::string& fileType, const unsigned char *data, int dataSize) {
	return LoadMusicStreamFromMemory(fileType.c_str(), data, dataSize);
}

void BindRaylibColors(Wren::ForeignModule& Module);
void BindRaylibStructs(Wren::ForeignModule& Module);
void BindRaylibEnums(Wren::ForeignModule& Module);
void BindRaylibCallbacks(Wren::ForeignModule& Module);
void BindRaylibGlobals(Wren::ForeignModule& Module);

void BindRaylibCore(Wren::ForeignModule& Module, Wren::ForeignKlassImpl<rl>& Class);
void BindRaylibGestures(Wren::ForeignModule& Module, Wren::ForeignKlassImpl<rl>& Class);
void BindRaylibCamera(Wren::ForeignModule& Module, Wren::ForeignKlassImpl<rl>& Class);
void BindRaylibShapes(Wren::ForeignModule& Module, Wren::ForeignKlassImpl<rl>& Class);
void BindRaylibTextures(Wren::ForeignModule& Module, Wren::ForeignKlassImpl<rl>& Class);
void BindRaylibText(Wren::ForeignModule& Module, Wren::ForeignKlassImpl<rl>& Class); 
void BindModuleels(Wren::ForeignModule& Module, Wren::ForeignKlassImpl<rl>& Class);
void BindRaylibAudio(Wren::ForeignModule& Module, Wren::ForeignKlassImpl<rl>& Class);

void BindRaylib(Wren::VM & VM) {

	Wren::ForeignModule& Module = VM.module("raylib");
	
	BindRaylibStructs(Module);
	BindRaylibColors(Module);
	BindRaylibEnums(Module);
	BindRaylibCallbacks(Module);
	BindRaylibGlobals(Module);

	Wren::ForeignKlassImpl<rl>& Class = Module.klass<rl>("RL");

	BindRaylibCore(Module, Class);
	BindRaylibGestures(Module, Class);
	BindRaylibCamera(Module, Class);
	BindRaylibShapes(Module, Class);
	BindRaylibTextures(Module, Class);
	BindRaylibText(Module, Class);
	BindModuleels(Module, Class);
	BindRaylibAudio(Module, Class);
}