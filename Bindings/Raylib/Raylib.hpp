#include <string>

struct rl {
	static void wInitWindow(int width, int height, const std::string& title);
	static void wSetWindowTitle(const std::string& title);

	static void wSetClipboardText(const std::string& text);
	static Shader wLoadShader(const std::string& vsFileName, const std::string& fsFileName);
	static Shader wLoadShaderFromMemory(const std::string& vsCode, const std::string& fsCode);
	static int wGetShaderLocation(Shader shader, const std::string& uniformName);
	static int wGetShaderLocationAttrib(Shader shader, const std::string& uniformName);
	static void wTakeScreenshot(const std::string& fileName);
	static void wTraceLog(int logLevel, const std::string& text);
	static void wOpenURL(std::string& url);
	// static const std::string wLoadFileData(const std::string& fileName, unsigned int * bytesRead);
	// static bool wSaveFileData(const std::string& fileName, void *data, unsigned int bytesToWrite);
	// static bool wExportDataAsCode(const std::string& data, unsigned int size, const std::string& fileName);
	static const std::string wLoadFileText(const std::string& fileName);
	static bool wSaveFileText(const std::string& fileName, const std::string& text);
	static bool wFileExists(const std::string& fileName);
	static bool wDirectoryExists(const std::string& dirPath);
	static bool wIsFileExtension(const std::string& fileName, const std::string& ext);
	static int wGetFileLength(const std::string& fileName);
	static bool wChangeDirectory(const std::string& dir);
	static bool wIsPathFile(const std::string& path);
	static long wGetFileModTime(const std::string& fileName);
	static int wSetGamepadMappings(const std::string& mapping);
	static Image wLoadImage(const std::string& fileName);
	static Image wLoadImageRaw(const std::string& fileName, int width, int height, int format, int headerSize);
	static Image wLoadImageAnim(const std::string& fileName, int *frames);
	static bool wExportImage(Image image, const std::string& fileName);
	static bool wExportImageAsCode(Image image, const std::string& fileName);
	static Image wGenImageText(int width, int height, const std::string& text);
	static Image wImageText(const std::string& text, int fontSize, Color color);
	static Image wImageTextEx(Font font, const std::string& text, float fontSize, float spacing, Color tint);
	static void wImageDrawText(Image *dst, const std::string& text, int posX, int posY, int fontSize, Color color);
	static void wImageDrawTextEx(Image *dst, Font font, const std::string& text, Vector2 position, float fontSize, float spacing, Color tint);
	static Texture2D wLoadTexture(const std::string& fileName);
	static Font wLoadFont(const std::string& fileName);
	static Font wLoadFontEx(const std::string& fileName, int fontSize, int *fontChars, int glyphCount);
	static Font wLoadFontFromMemory(const std::string& fileType, const unsigned char *fileData, int dataSize, int fontSize, int *fontChars, int glyphCount);
	static GlyphInfo *wLoadFontData(const unsigned char *fileData, int dataSize, int  fontSize, int *fontChars, int glyphCount, int type);
	static bool wExportFontAsCode(Font font, const std::string& fileName);
	static void wDrawText(const std::string& text, int posX, int posY, int fontSize, Color color);
	static void wDrawTextEx(Font font, const std::string& text, Vector2 position, float fontSize, float spacing, Color tint);
	static void wDrawTextPro(Font font, const std::string& text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint);
	static int wMeasureText(const std::string& text, int fontSize);
	static Vector2 wMeasureTextEx(Font font, const std::string& text, float fontSize, float spacing);
	static int *wLoadCodepoints(const std::string& text, int *count);
	static int wGetCodepointCount(const std::string& text);
	static int wGetCodepoint(const std::string& text, int *codepointSize);
	static int wGetCodepointNext(const std::string& text, int *codepointSize);
	static int wGetCodepointPrevious(const std::string& text, int *codepointSize);
	static const char * wTextToUpper(const std::string& text);
	static const char * wTextToLower(const std::string& text);
	static const char * wTextToPascal(const std::string& text);
	static int wTextToInteger(const std::string& text);
	static Model wLoadModel(const std::string& fileName);
	static bool wExportMesh(Mesh mesh, const std::string& fileName);  
	static Material *wLoadMaterials(const std::string& fileName, int *materialCount);
	static ModelAnimation *wLoadModelAnimations(const std::string& fileName, unsigned int *animCount);
	static Wave wLoadWave(const std::string& fileName);
	static Wave wLoadWaveFromMemory(const std::string& fileType, const unsigned char *fileData, int dataSize);
	static Sound wLoadSound(const std::string& fileName);
	static bool wExportWave(Wave wave, const std::string& fileName);
	static bool wExportWaveAsCode(Wave wave, const std::string& fileName);
	static Music wLoadMusicStream(const std::string& fileName);
	static Music wLoadMusicStreamFromMemory(const std::string& fileType, const unsigned char *data, int dataSize);
};