#include <raylib.h>
#include <wrenbind17/wrenbind17.hpp>
#include "Raylib.hpp"
namespace Wren = wrenbind17;

//------------------------------------------------------------------------------------
// Texture Loading and Drawing Functions (Module: textures)
//------------------------------------------------------------------------------------

void BindRaylibTextures(Wren::ForeignModule& Module, Wren::ForeignKlassImpl<rl>& Class) {
	// Image loading functions
	Class.funcStaticExt<&rl::wLoadImage>("LoadImage");
	Class.funcStaticExt<&rl::wLoadImageRaw>("LoadImageRaw");
	Class.funcStaticExt<&rl::wLoadImageAnim>("LoadImageAnim");
	// Class.funcStaticExt<&rl::wLoadImageFromMemory>("LoadImageFromMemory");
	Class.funcStaticExt<&LoadImageFromTexture>("LoadImageFromTexture");
	Class.funcStaticExt<&LoadImageFromScreen>("LoadImageFromScreen");
	Class.funcStaticExt<&IsImageReady>("IsImageReady");
	Class.funcStaticExt<&UnloadImage>("UnloadImage");
	Class.funcStaticExt<&rl::wExportImage>("ExportImage");
	Class.funcStaticExt<&rl::wExportImageAsCode>("ExportImageAsCode");

	// Image generation functions
	Class.funcStaticExt<&GenImageColor>("GenImageColor");
	Class.funcStaticExt<&GenImageGradientV>("GenImageGradientV");
	Class.funcStaticExt<&GenImageGradientH>("GenImageGradientH");
	Class.funcStaticExt<&GenImageGradientRadial>("GenImageGradientRadial");
	Class.funcStaticExt<&GenImageChecked>("GenImageChecked");
	Class.funcStaticExt<&GenImageWhiteNoise>("GenImageWhiteNoise");
	Class.funcStaticExt<&GenImagePerlinNoise>("GenImagePerlinNoise");
	Class.funcStaticExt<&GenImageCellular>("GenImageCellular");
	Class.funcStaticExt<&rl::wGenImageText>("GenImageText");

	// Image manipulation functions
	Class.funcStaticExt<&ImageCopy>("ImageCopy");
	Class.funcStaticExt<&ImageFromImage>("ImageFromImage");
	Class.funcStaticExt<&rl::wImageText>("ImageText");
	Class.funcStaticExt<&rl::wImageTextEx>("ImageTextEx");
	Class.funcStaticExt<&ImageFormat>("ImageFormat");
	Class.funcStaticExt<&ImageToPOT>("ImageToPOT");
	Class.funcStaticExt<&ImageCrop>("ImageCrop");
	Class.funcStaticExt<&ImageAlphaCrop>("ImageAlphaCrop");
	Class.funcStaticExt<&ImageAlphaClear>("ImageAlphaClear");
	Class.funcStaticExt<&ImageAlphaMask>("ImageAlphaMask");
	Class.funcStaticExt<&ImageAlphaPremultiply>("ImageAlphaPremultiply");
	Class.funcStaticExt<&ImageBlurGaussian>("ImageBlurGaussian");
	Class.funcStaticExt<&ImageResize>("ImageResize");
	Class.funcStaticExt<&ImageResizeNN>("ImageResizeNN");
	Class.funcStaticExt<&ImageResizeCanvas>("ImageResizeCanvas");
	Class.funcStaticExt<&ImageMipmaps>("ImageMipmaps");
	Class.funcStaticExt<&ImageDither>("ImageDither");
	Class.funcStaticExt<&ImageFlipVertical>("ImageFlipVertical");
	Class.funcStaticExt<&ImageFlipHorizontal>("ImageFlipHorizontal");
	Class.funcStaticExt<&ImageRotateCW>("ImageRotateCW");
	Class.funcStaticExt<&ImageRotateCCW>("ImageRotateCCW");
	Class.funcStaticExt<&ImageColorTint>("ImageColorTint");
	Class.funcStaticExt<&ImageColorInvert>("ImageColorInvert");
	Class.funcStaticExt<&ImageColorGrayscale>("ImageColorGrayscale");
	Class.funcStaticExt<&ImageColorContrast>("ImageColorContrast");
	Class.funcStaticExt<&ImageColorBrightness>("ImageColorBrightness");
	Class.funcStaticExt<&ImageColorReplace>("ImageColorReplace");
	Class.funcStaticExt<&LoadImageColors>("LoadImageColors");
	Class.funcStaticExt<&LoadImagePalette>("LoadImagePalette");
	Class.funcStaticExt<&UnloadImageColors>("UnloadImageColors");
	Class.funcStaticExt<&UnloadImagePalette>("UnloadImagePalette");
	Class.funcStaticExt<&GetImageAlphaBorder>("GetImageAlphaBorder");
	Class.funcStaticExt<&GetImageColor>("GetImageColor");

	// Image drawing functions
	Class.funcStaticExt<&ImageClearBackground>("ImageClearBackground");
	Class.funcStaticExt<&ImageDrawPixel>("ImageDrawPixel");
	Class.funcStaticExt<&ImageDrawPixelV>("ImageDrawPixelV");
	Class.funcStaticExt<&ImageDrawLine>("ImageDrawLine");
	Class.funcStaticExt<&ImageDrawLineV>("ImageDrawLineV");
	Class.funcStaticExt<&ImageDrawCircle>("ImageDrawCircle");
	Class.funcStaticExt<&ImageDrawCircleV>("ImageDrawCircleV");
	Class.funcStaticExt<&ImageDrawCircleLines>("ImageDrawCircleLines");
	Class.funcStaticExt<&ImageDrawCircleLinesV>("ImageDrawCircleLinesV");
	Class.funcStaticExt<&ImageDrawRectangle>("ImageDrawRectangle");
	Class.funcStaticExt<&ImageDrawRectangleV>("ImageDrawRectangleV");
	Class.funcStaticExt<&ImageDrawRectangleRec>("ImageDrawRectangleRec");
	Class.funcStaticExt<&ImageDrawRectangleLines>("ImageDrawRectangleLines");
	Class.funcStaticExt<&ImageDraw>("ImageDraw");
	Class.funcStaticExt<&rl::wImageDrawText>("ImageDrawText");
	Class.funcStaticExt<&rl::wImageDrawTextEx>("ImageDrawTextEx");

	// Texture loading functions
	Class.funcStaticExt<&rl::wLoadTexture>("LoadTexture");
	Class.funcStaticExt<&LoadTextureFromImage>("LoadTextureFromImage");
	Class.funcStaticExt<&LoadTextureCubemap>("LoadTextureCubemap");
	Class.funcStaticExt<&LoadRenderTexture>("LoadRenderTexture");
	Class.funcStaticExt<&IsTextureReady>("IsTextureReady");
	Class.funcStaticExt<&UnloadTexture>("UnloadTexture");
	Class.funcStaticExt<&IsRenderTextureReady>("IsRenderTextureReady");
	Class.funcStaticExt<&UnloadRenderTexture>("UnloadRenderTexture");
	Class.funcStaticExt<&UpdateTexture>("UpdateTexture");
	Class.funcStaticExt<&UpdateTextureRec>("UpdateTextureRec");

	// Texture configuration functions
	Class.funcStaticExt<&GenTextureMipmaps>("GenTextureMipmaps");
	Class.funcStaticExt<&SetTextureFilter>("SetTextureFilter");
	Class.funcStaticExt<&SetTextureWrap>("SetTextureWrap");

	// Texture drawing functions
	Class.funcStaticExt<&DrawTexture>("DrawTexture");
	Class.funcStaticExt<&DrawTextureV>("DrawTextureV");
	Class.funcStaticExt<&DrawTextureEx>("DrawTextureEx");
	Class.funcStaticExt<&DrawTextureRec>("DrawTextureRec");
	Class.funcStaticExt<&DrawTexturePro>("DrawTexturePro");
	Class.funcStaticExt<&DrawTextureNPatch>("DrawTextureNPatch");

	// Color/pixel related functions
	Class.funcStaticExt<&Fade>("Fade");
	Class.funcStaticExt<&ColorToInt>("ColorToInt");
	Class.funcStaticExt<&ColorNormalize>("ColorNormalize");
	Class.funcStaticExt<&ColorFromNormalized>("ColorFromNormalized");
	Class.funcStaticExt<&ColorToHSV>("ColorToHSV");
	Class.funcStaticExt<&ColorFromHSV>("ColorFromHSV");
	Class.funcStaticExt<&ColorTint>("ColorTint");
	Class.funcStaticExt<&ColorBrightness>("ColorBrightness");
	Class.funcStaticExt<&ColorContrast>("ColorContrast");
	Class.funcStaticExt<&ColorAlpha>("ColorAlpha");
	Class.funcStaticExt<&ColorAlphaBlend>("ColorAlphaBlend");
	Class.funcStaticExt<&GetColor>("GetColor");
	Class.funcStaticExt<&GetPixelColor>("GetPixelColor");
	Class.funcStaticExt<&SetPixelColor>("SetPixelColor");
	Class.funcStaticExt<&GetPixelDataSize>("GetPixelDataSize");
}