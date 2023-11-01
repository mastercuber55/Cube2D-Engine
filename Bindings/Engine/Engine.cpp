#include <wrenbind17/wrenbind17.hpp>
#include <raylib.h>
#include "Rect.hpp"

namespace Wren = wrenbind17;

void BindEngine(Wren::VM & VM) {

	auto& Module = VM.module("Engine");

	auto& RectCls = Module.klass<ForeignRect>("ForeignRect");
	RectCls.ctor<float, float, float, float>();
 
	// Transform
	RectCls.var<&ForeignRect::PositionAndScale>("PositionAndScale"); 
	RectCls.var<&ForeignRect::Rotation>("Rotation");

	RectCls.var<&ForeignRect::TextureFile>("TextureFile");
	RectCls.var<&ForeignRect::Source>("Source");
	RectCls.var<&ForeignRect::Tint>("Tint"); 

	RectCls.func<&ForeignRect::SetPosition>("SetPosition");
	RectCls.func<&ForeignRect::SetTextureFile>("SetTextureFile"); 
	RectCls.func<&ForeignRect::Draw>("Draw");
 
	RectCls.func<&ForeignRect::GetCenter>("GetCenter");
	RectCls.func<&ForeignRect::GetPosition>("GetPosition");

	RectCls.func<&ForeignRect::IsColliding>("IsColliding");

	Module.append("import \"raylib\" for RL, COLOR, Color, KEY, Vector2");
 
	Module.append(
		#include "Rect.wren"
		#include "Scene.wren"
		#include "SceneManager.wren"
		#include "Tools.wren"  
	);
	Module.append("var Shared = {}");
}