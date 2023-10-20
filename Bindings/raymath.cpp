#include <raymath.h>
#include <wrenbind17/wrenbind17.hpp>

namespace Wren = wrenbind17;

class rm {};

void BindRaymath(Wren::VM & VM) {

	Wren::ForeignModule& Module = VM.module("raymath");
	
	Module.append(R"(
		var PI = 3.14159265358979323846
		var EPSILON = 0.000001
		var DEG2RAD = (PI/180.0)
		var RAD2DEG = (180.0/PI)
	)");

	Wren::ForeignKlassImpl<rm>& Class = Module.klass<rm>("RM");
	//----------------------------------------------------------------------------------
	// Module Functions Definition - Utils math
	//----------------------------------------------------------------------------------
	Class.funcStaticExt<&Clamp>("Clamp");
	Class.funcStaticExt<&Lerp>("Lerp");
	Class.funcStaticExt<&Normalize>("Normalize");
	Class.funcStaticExt<&Remap>("Remap");
	Class.funcStaticExt<&Wrap>("Wrap");
	Class.funcStaticExt<&FloatEquals>("FloatEquals");
	//----------------------------------------------------------------------------------
	// Module Functions Definition - Vector2 math
	//----------------------------------------------------------------------------------
	Class.funcStaticExt<&Vector2Zero>("Vector2Zero");
	Class.funcStaticExt<&Vector2One>("Vector2One");
	Class.funcStaticExt<&Vector2Add>("Vector2Add");
	Class.funcStaticExt<&Vector2AddValue>("Vector2AddValue");
	Class.funcStaticExt<&Vector2Subtract>("Vector2Subtract");
	Class.funcStaticExt<&Vector2SubtractValue>("Vector2SubtractValue");
	Class.funcStaticExt<&Vector2Length>("Vector2Length");
	Class.funcStaticExt<&Vector2LengthSqr>("Vector2LengthSqr");
	Class.funcStaticExt<&Vector2DotProduct>("Vector2DotProduct");
	Class.funcStaticExt<&Vector2Distance>("Vector2Distance");
	Class.funcStaticExt<&Vector2DistanceSqr>("Vector2DistanceSqr");
	Class.funcStaticExt<&Vector2Angle>("Vector2Angle");
	Class.funcStaticExt<&Vector2LineAngle>("Vector2LineAngle");
	Class.funcStaticExt<&Vector2Scale>("Vector2Scale");
	Class.funcStaticExt<&Vector2Multiply>("Vector2Multiply");
	Class.funcStaticExt<&Vector2Negate>("Vector2Negate");
	Class.funcStaticExt<&Vector2Divide>("Vector2Divide");
	Class.funcStaticExt<&Vector2Normalize>("Vector2Normalize");
	Class.funcStaticExt<&Vector2Transform>("Vector2Transform");
	Class.funcStaticExt<&Vector2Lerp>("Vector2Lerp");
	Class.funcStaticExt<&Vector2Reflect>("Vector2Reflect");
	Class.funcStaticExt<&Vector2Rotate>("Vector2Rotate");
	Class.funcStaticExt<&Vector2MoveTowards>("Vector2MoveTowards");
	Class.funcStaticExt<&Vector2Invert>("Vector2Invert");
	Class.funcStaticExt<&Vector2Clamp>("Vector2Clamp");
	Class.funcStaticExt<&Vector2ClampValue>("Vector2ClampValue");
	Class.funcStaticExt<&Vector2Equals>("Vector2Equals");
	//----------------------------------------------------------------------------------
	// Module Functions Definition - Vector3 math
	//----------------------------------------------------------------------------------
	Class.funcStaticExt<&Vector3Zero>("Vector3Zero");
	Class.funcStaticExt<&Vector3One>("Vector3One");
	Class.funcStaticExt<&Vector3Add>("Vector3Add");
	Class.funcStaticExt<&Vector3AddValue>("Vector3AddValue");
	Class.funcStaticExt<&Vector3Subtract>("Vector3Subtract");
	Class.funcStaticExt<&Vector3SubtractValue>("Vector3SubtractValue");
	Class.funcStaticExt<&Vector3Scale>("Vector3Scale");
	Class.funcStaticExt<&Vector3Multiply>("Vector3Multiply");
	Class.funcStaticExt<&Vector3CrossProduct>("Vector3CrossProduct");
	Class.funcStaticExt<&Vector3Perpendicular>("Vector3Perpendicular");
	Class.funcStaticExt<&Vector3Length>("Vector3Length");
	Class.funcStaticExt<&Vector3LengthSqr>("Vector3LengthSqr");
	Class.funcStaticExt<&Vector3DotProduct>("Vector3DotProduct");
	Class.funcStaticExt<&Vector3Distance>("Vector3Distance");
	Class.funcStaticExt<&Vector3DistanceSqr>("Vector3DistanceSqr");
	Class.funcStaticExt<&Vector3Angle>("Vector3Angle");
	Class.funcStaticExt<&Vector3Negate>("Vector3Negate");
	Class.funcStaticExt<&Vector3Divide>("Vector3Divide");
	Class.funcStaticExt<&Vector3Normalize>("Vector3Normalize");
	Class.funcStaticExt<&Vector3OrthoNormalize>("Vector3OrthoNormalize");
	Class.funcStaticExt<&Vector3Transform>("Vector3Transform");
	Class.funcStaticExt<&Vector3RotateByQuaternion>("Vector3RotateByQuaternion");
	Class.funcStaticExt<&Vector3RotateByAxisAngle>("Vector3RotateByAxisAngle");
	Class.funcStaticExt<&Vector3Lerp>("Vector3Lerp");
	Class.funcStaticExt<&Vector3Reflect>("Vector3Reflect");
	Class.funcStaticExt<&Vector3Min>("Vector3Min");
	Class.funcStaticExt<&Vector3Max>("Vector3Max");
	Class.funcStaticExt<&Vector3Barycenter>("Vector3Barycenter");
	Class.funcStaticExt<&Vector3Unproject>("Vector3Unproject");
	Class.funcStaticExt<&Vector3ToFloatV>("Vector3ToFloatV");
	Class.funcStaticExt<&Vector3Invert>("Vector3Invert");
	Class.funcStaticExt<&Vector3Clamp>("Vector3Clamp");
	Class.funcStaticExt<&Vector3ClampValue>("Vector3ClampValue");
	Class.funcStaticExt<&Vector3Equals>("Vector3Equals");
	Class.funcStaticExt<&Vector3Refract>("Vector3Refract");
	//----------------------------------------------------------------------------------
	// Module Functions Definition - Matrix math
	//----------------------------------------------------------------------------------
	Class.funcStaticExt<&MatrixDeterminant>("MatrixDeterminant");
	Class.funcStaticExt<&MatrixTrace>("MatrixTrace");
	Class.funcStaticExt<&MatrixTranspose>("MatrixTranspose");
	Class.funcStaticExt<&MatrixInvert>("MatrixInvert");
	Class.funcStaticExt<&MatrixIdentity>("MatrixIdentity");
	Class.funcStaticExt<&MatrixAdd>("MatrixAdd");
	Class.funcStaticExt<&MatrixSubtract>("MatrixSubtract");
	Class.funcStaticExt<&MatrixMultiply>("MatrixMultiply");
	Class.funcStaticExt<&MatrixTranslate>("MatrixTranslate");
	Class.funcStaticExt<&MatrixRotate>("MatrixRotate");
	Class.funcStaticExt<&MatrixRotateX>("MatrixRotateX");
	Class.funcStaticExt<&MatrixRotateY>("MatrixRotateY");
	Class.funcStaticExt<&MatrixRotateZ>("MatrixRotateZ");
	Class.funcStaticExt<&MatrixRotateXYZ>("MatrixRotateXYZ");
	Class.funcStaticExt<&MatrixRotateZYX>("MatrixRotateZYX");
	Class.funcStaticExt<&MatrixScale>("MatrixScale");
	Class.funcStaticExt<&MatrixFrustum>("MatrixFrustum");
	Class.funcStaticExt<&MatrixPerspective>("MatrixPerspective");
	Class.funcStaticExt<&MatrixOrtho>("MatrixOrtho");
	Class.funcStaticExt<&MatrixLookAt>("MatrixLookAt");
	// Class.funcStaticExt<&MatrixToFloatV>("MatrixToFloatV");
	//----------------------------------------------------------------------------------
	// Module Functions Definition - Quaternion math
	//----------------------------------------------------------------------------------
	Class.funcStaticExt<&QuaternionAdd>("QuaternionAdd");
	Class.funcStaticExt<&QuaternionAddValue>("QuaternionAddValue");
	Class.funcStaticExt<&QuaternionSubtract>("QuaternionSubtract");
	Class.funcStaticExt<&QuaternionSubtractValue>("QuaternionSubtractValue");
	Class.funcStaticExt<&QuaternionIdentity>("QuaternionIdentity");
	Class.funcStaticExt<&QuaternionLength>("QuaternionLength");
	Class.funcStaticExt<&QuaternionNormalize>("QuaternionNormalize");
	Class.funcStaticExt<&QuaternionInvert>("QuaternionInvert");
	Class.funcStaticExt<&QuaternionMultiply>("QuaternionMultiply");
	Class.funcStaticExt<&QuaternionScale>("QuaternionScale");
	Class.funcStaticExt<&QuaternionDivide>("QuaternionDivide");
	Class.funcStaticExt<&QuaternionLerp>("QuaternionLerp");
	Class.funcStaticExt<&QuaternionNlerp>("QuaternionNlerp");
	Class.funcStaticExt<&QuaternionSlerp>("QuaternionSlerp");
	Class.funcStaticExt<&QuaternionFromVector3ToVector3>("QuaternionFromVector3ToVector3");
	Class.funcStaticExt<&QuaternionFromMatrix>("QuaternionFromMatrix");
	Class.funcStaticExt<&QuaternionToMatrix>("QuaternionToMatrix");
	Class.funcStaticExt<&QuaternionFromAxisAngle>("QuaternionFromAxisAngle");
	Class.funcStaticExt<&QuaternionToAxisAngle>("QuaternionToAxisAngle");
	Class.funcStaticExt<&QuaternionFromEuler>("QuaternionFromEuler");
	Class.funcStaticExt<&QuaternionToEuler>("QuaternionToEuler");
	Class.funcStaticExt<&QuaternionTransform>("QuaternionTransform");
	Class.funcStaticExt<&QuaternionEquals>("QuaternionEquals");

}