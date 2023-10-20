#define CGE_IMPL   
#include <Cube2D.hpp>
#include <wrenbind17/wrenbind17.hpp>
   
namespace Wren = wrenbind17;
 
struct EngineCls {};

void BindEngine(Wren::VM & VM) {
	auto& Module = VM.module("Cube2D");

	Module.append("import \"raylib\" for RL, KEY, COLOR");

	auto& Cube2DCls = Module.klass<EngineCls>("Engine");
 
	// Cube2DCls.funcStaticExt<&Engine::Init>("Init");
	// Cube2DCls.funcStaticExt<&Engine::Close>("Close");
	Cube2DCls.funcStaticExt<&Engine::WASDMovement>("WASDMovement");
	Cube2DCls.funcStaticExt<&Engine::GetRectsCount>("GetRectsCount");
	Cube2DCls.funcStaticExt<&Engine::AreColorSame>("AreColorsSame");
	Cube2DCls.funcStaticExt<&Engine::GetRandomPosition>("GetRandomPosition");

	Module.append(R"(
		class Scene {

			construct new() {
				_BackgroundColor = COLOR["BLACK"]
				_KeepRunning = true
				_CodeToReturn = 0
			}
			construct new(Background) {
				_BackgroundColor = Background
				_KeepRunning = true
				_CodeToReturn = 0
			}

			ShouldClose() { RL.WindowShouldClose()  }
			Update() {}
			Draw() {}
			Run() {
				while(!this.ShouldClose()) {
					this.Update()
					RL.BeginDrawing()
						RL.ClearBackground(_BackgroundColor)
						this.Draw()
					RL.EndDrawing()
				}

				return _CodeToReturn
			}
			Close(CodeToReturn) {
				_CodeToReturn = CodeToReturn
				_KeepRunning = false
			}


			BackgroundColor { _BackgroundColor }
			KeepRunning { _KeepRunning }
			CodeToReturn { _CodeToReturn }

			BackgroundColor=(Tint) { _BackgroundColor = Tint }
			KeepRunning=(Boolean) { _KeepRunning = Boolean }
			CodeToReturn=(Code) { _CodeToReturn = Code }
		}
	)");
 
	auto& RectCls = Module.klass<Engine::Rect>("OrignalRect");
	RectCls.ctor<float, float, float, float>();

	RectCls.var<&Engine::Rect::x>("x");
	RectCls.var<&Engine::Rect::y>("y");
	RectCls.var<&Engine::Rect::w>("w");
	RectCls.var<&Engine::Rect::h>("h");

	RectCls.var<&Engine::Rect::Rotation>("Rotation");

	RectCls.var<&Engine::Rect::TextureFile>("TextureFile");
	RectCls.var<&Engine::Rect::Source>("Source");
	RectCls.var<&Engine::Rect::Tint>("Tint");

	RectCls.func<&Engine::Rect::SetPosition>("SetPosition");
	RectCls.func<&Engine::Rect::SetTextureFile>("SetTextureFile");
	RectCls.func<&Engine::Rect::SetTint>("SetTint");
	RectCls.func<&Engine::Rect::Draw>("Draw");

	RectCls.func<&Engine::Rect::GetCenter>("GetCenter");
	RectCls.func<&Engine::Rect::GetPosition>("GetPosition");
	RectCls.func<&Engine::Rect::GetRectangle>("GetRectangle");

	RectCls.func<&Engine::Rect::IsColliding>("IsColliding");

	Module.append(R"(
		class Rect {
		 	construct new(x, y, w, h) {
				_Base = OrignalRect.new(x, y, w, h)
		 	}
		 	x { _Base.x }
		 	x=(rhs) { _Base.x=rhs }
		 	y { _Base.y }
		 	y=(rhs) { _Base.y=rhs }
		 	w { _Base.w }
		 	w=(rhs) { _Base.w=rhs }
		 	h { _Base.h }
		 	h=(rhs) { _Base.h=rhs }
		 	Rotation { _Base.Rotation }
		 	Rotation=(rhs) { _Base.Rotation=rhs }
		 	TextureFile { _Base.TextureFile }
		 	TextureFile=(rhs) { _Base.TextureFile=rhs }
		 	Tint { _Base.Tint }
		 	Tint=(rhs) { _Base.Tint=rhs }

		 	SetPosition(rhs) { _Base.SetPosition(rhs) }
		 	SetTextureFile(rhs) { _Base.SetTextureFile(rhs) }
		 	SetTint(rhs) { _Base.SetTint(rhs) }
		 	Draw() { _Base.Draw() }
		 	GetCenter() { _Base.GetCenter() }
		 	GetPosition() { _Base.GetPosition() }
			GetRectangle() { _Base.GetRectangle() }

			IsColliding(rhs) { _Base.IsColliding(rhs.Base) }

			Base { _Base }  
		}
	)");

}