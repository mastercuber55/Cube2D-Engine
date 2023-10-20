#include <raylib.h>
#include <wrenbind17/wrenbind17.hpp>
#include "Raylib.hpp"
namespace Wren = wrenbind17;

//------------------------------------------------------------------------------------
// Basic 3d Shapes Drawing Functions (Module: models)
//------------------------------------------------------------------------------------

void BindModuleels(Wren::ForeignModule& Module, Wren::ForeignKlassImpl<rl>& Class) {

	//------------------------------------------------------------------------------------
	// Basic 3d Shapes Drawing Functions (Module: models)
	//------------------------------------------------------------------------------------
	// Basic geometric 3D shapes drawing functions
	Class.funcStaticExt<&DrawLine3D>("DrawLine3D");
	Class.funcStaticExt<&DrawPoint3D>("DrawPoint3D");
	Class.funcStaticExt<&DrawCircle3D>("DrawCircle3D");
	Class.funcStaticExt<&DrawTriangle3D>("DrawTriangle3D");
	Class.funcStaticExt<&DrawTriangleStrip3D>("DrawTriangleStrip3D");
	Class.funcStaticExt<&DrawCube>("DrawCube");
	Class.funcStaticExt<&DrawCubeV>("DrawCubeV");
	Class.funcStaticExt<&DrawCubeWires>("DrawCubeWires");
	Class.funcStaticExt<&DrawCubeWiresV>("DrawCubeWiresV");
	Class.funcStaticExt<&DrawSphere>("DrawSphere");
	Class.funcStaticExt<&DrawSphereEx>("DrawSphereEx");
	Class.funcStaticExt<&DrawSphereWires>("DrawSphereWires");
	Class.funcStaticExt<&DrawCylinder>("DrawCylinder");
	Class.funcStaticExt<&DrawCylinderEx>("DrawCylinderEx");
	Class.funcStaticExt<&DrawCylinderWires>("DrawCylinderWires");
	Class.funcStaticExt<&DrawCylinderWiresEx>("DrawCylinderWiresEx");
	Class.funcStaticExt<&DrawCapsule>("DrawCapsule");
	Class.funcStaticExt<&DrawCapsuleWires>("DrawCapsuleWires");
	Class.funcStaticExt<&DrawPlane>("DrawPlane");
	Class.funcStaticExt<&DrawRay>("DrawRay");
	Class.funcStaticExt<&DrawGrid>("DrawGrid");

	//------------------------------------------------------------------------------------
	// Model 3d Loading and Drawing Functions (Module: models)
	//-----------------------------------------------------------------------------------
	
	// Model management functions
	Class.funcStaticExt<&rl::wLoadModel>("LoadModel");
	Class.funcStaticExt<&LoadModelFromMesh>("LoadModelFromMesh");
	Class.funcStaticExt<&IsModelReady>("IsModelReady");
	Class.funcStaticExt<&UnloadModel>("UnloadModel");
	Class.funcStaticExt<&GetModelBoundingBox>("GetModelBoundingBox");

	// Model drawing functions
	Class.funcStaticExt<&DrawModel>("DrawModel");
	Class.funcStaticExt<&DrawModelEx>("DrawModelEx");
	Class.funcStaticExt<&DrawModelWires>("DrawModelWires");
	Class.funcStaticExt<&DrawModelWiresEx>("DrawModelWiresEx");
	Class.funcStaticExt<&DrawBoundingBox>("DrawBoundingBox");
	Class.funcStaticExt<&DrawBillboard>("DrawBillboard");
	Class.funcStaticExt<&DrawBillboardRec>("DrawBillboardRec");
	Class.funcStaticExt<&DrawBillboardPro>("DrawBillboardPro");

	// Mesh management functions
	Class.funcStaticExt<&UploadMesh>("UploadMesh");
	Class.funcStaticExt<&UpdateMeshBuffer>("UpdateMeshBuffer");
	Class.funcStaticExt<&UnloadMesh>("UnloadMesh");
	Class.funcStaticExt<&DrawMesh>("DrawMesh");
	Class.funcStaticExt<&DrawMeshInstanced>("DrawMeshInstanced");
	Class.funcStaticExt<&rl::wExportMesh>("ExportMesh");
	Class.funcStaticExt<&GetMeshBoundingBox>("GetMeshBoundingBox");
	Class.funcStaticExt<&GenMeshTangents>("GenMeshTangents");

	// Mesh generation functions
	Class.funcStaticExt<&GenMeshPoly>("GenMeshPoly");
	Class.funcStaticExt<&GenMeshPlane>("GenMeshPlane");
	Class.funcStaticExt<&GenMeshCube>("GenMeshCube");
	Class.funcStaticExt<&GenMeshSphere>("GenMeshSphere");
	Class.funcStaticExt<&GenMeshHemiSphere>("GenMeshHemiSphere");
	Class.funcStaticExt<&GenMeshCylinder>("GenMeshCylinder");
	Class.funcStaticExt<&GenMeshCone>("GenMeshCone");
	Class.funcStaticExt<&GenMeshTorus>("GenMeshTorus");
	Class.funcStaticExt<&GenMeshKnot>("GenMeshKnot");
	Class.funcStaticExt<&GenMeshHeightmap>("GenMeshHeightmap");
	Class.funcStaticExt<&GenMeshCubicmap>("GenMeshCubicmap");

	// Material loading/unloading functions
	Class.funcStaticExt<&rl::wLoadMaterials>("LoadMaterials");
	Class.funcStaticExt<&LoadMaterialDefault>("LoadMaterialDefault");
	Class.funcStaticExt<&IsMaterialReady>("IsMaterialReady");
	Class.funcStaticExt<&UnloadMaterial>("UnloadMaterial");
	Class.funcStaticExt<&SetMaterialTexture>("SetMaterialTexture");
	Class.funcStaticExt<&SetModelMeshMaterial>("SetModelMeshMaterial");

	// Model animations loading/unloading functions
	Class.funcStaticExt<&rl::wLoadModelAnimations>("LoadModelAnimations");
	Class.funcStaticExt<&UpdateModelAnimation>("UpdateModelAnimation");
	Class.funcStaticExt<&UnloadModelAnimation>("UnloadModelAnimation");
	Class.funcStaticExt<&UnloadModelAnimations>("UnloadModelAnimations");
	Class.funcStaticExt<&IsModelAnimationValid>("IsModelAnimationValid");

	// Collision detection functions
	Class.funcStaticExt<&CheckCollisionSpheres>("CheckCollisionSpheres");
	Class.funcStaticExt<&CheckCollisionBoxes>("CheckCollisionBoxes");
	Class.funcStaticExt<&CheckCollisionBoxSphere>("CheckCollisionBoxSphere");
	Class.funcStaticExt<&GetRayCollisionSphere>("GetRayCollisionSphere");
	Class.funcStaticExt<&GetRayCollisionBox>("GetRayCollisionBox");
	Class.funcStaticExt<&GetRayCollisionMesh>("GetRayCollisionMesh");
	Class.funcStaticExt<&GetRayCollisionTriangle>("GetRayCollisionTriangle");
	Class.funcStaticExt<&GetRayCollisionQuad>("GetRayCollisionQuad");
}