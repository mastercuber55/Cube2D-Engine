#include <raylib.h>
#include <wrenbind17/wrenbind17.hpp>
namespace Wren = wrenbind17;

//----------------------------------------------------------------------------------
// Structures Definition
// Excluded: Material, BoneInfo, ModelAnimation, VrDeviceInfo and VrSteroConfig 
//----------------------------------------------------------------------------------

void BindRaylibStructs(Wren::ForeignModule& Module) {
	auto& Vector2Cls = Module.klass<Vector2>("Vector2");
	Vector2Cls.ctor<>();
	Vector2Cls.var<&Vector2::x>("x");
	Vector2Cls.var<&Vector2::y>("y");

	auto& Vector3Cls = Module.klass<Vector3>("Vector3");
	Vector3Cls.ctor<>();
	Vector3Cls.var<&Vector3::x>("x");
	Vector3Cls.var<&Vector3::y>("y");
	Vector3Cls.var<&Vector3::z>("z");

	auto& Vector4Cls = Module.klass<Vector4>("Vector4");
	Vector4Cls.ctor<>();
	Vector4Cls.var<&Vector4::x>("x");
	Vector4Cls.var<&Vector4::y>("y");
	Vector4Cls.var<&Vector4::y>("z");
	Vector4Cls.var<&Vector4::w>("w");

	auto& MatrixCls = Module.klass<Matrix>("Matrix");
	MatrixCls.ctor<>();
	MatrixCls.var<&Matrix::m0>("m0");
	MatrixCls.var<&Matrix::m1>("m1");
	MatrixCls.var<&Matrix::m2>("m2");
	MatrixCls.var<&Matrix::m3>("m3");
	MatrixCls.var<&Matrix::m4>("m4");
	MatrixCls.var<&Matrix::m5>("m5");
	MatrixCls.var<&Matrix::m6>("m6");
	MatrixCls.var<&Matrix::m7>("m7");
	MatrixCls.var<&Matrix::m8>("m8");
	MatrixCls.var<&Matrix::m9>("m9");
	MatrixCls.var<&Matrix::m10>("m10");
	MatrixCls.var<&Matrix::m11>("m11");
	MatrixCls.var<&Matrix::m12>("m12");
	MatrixCls.var<&Matrix::m13>("m13");
	MatrixCls.var<&Matrix::m14>("m14");
	MatrixCls.var<&Matrix::m15>("m15");
	MatrixCls.var<&Matrix::m15>("m16");

	auto& ColorCls = Module.klass<Color>("Color");
	ColorCls.ctor<>();
	ColorCls.var<&Color::r>("r");
	ColorCls.var<&Color::g>("g");
	ColorCls.var<&Color::b>("b");
	ColorCls.var<&Color::a>("a");

	auto& RectangleCls = Module.klass<Rectangle>("Rectangle");
	RectangleCls.ctor<>();
	RectangleCls.var<&Rectangle::x>("x");
	RectangleCls.var<&Rectangle::y>("y");
	RectangleCls.var<&Rectangle::width>("width");
	RectangleCls.var<&Rectangle::height>("height");

	auto& ImageCls = Module.klass<Image>("Image");
	ImageCls.ctor<>();
	ImageCls.var<&Image::data>("data");
	ImageCls.var<&Image::width>("width");
	ImageCls.var<&Image::height>("height");
	ImageCls.var<&Image::mipmaps>("mipmaps");
	ImageCls.var<&Image::format>("format");

	auto& TextureCls = Module.klass<Texture>("Texture");
	TextureCls.ctor<>();
	TextureCls.var<&Texture::id>("id");
	TextureCls.var<&Texture::width>("width");
	TextureCls.var<&Texture::height>("height");
	TextureCls.var<&Texture::mipmaps>("mipmaps");
	TextureCls.var<&Texture::format>("format");
	
	auto& RenderTextureCls = Module.klass<RenderTexture>("RenderTexture");
	RenderTextureCls.ctor<>();
	RenderTextureCls.var<&RenderTexture::id>("id");
	RenderTextureCls.var<&RenderTexture::texture>("texture");
	RenderTextureCls.var<&RenderTexture::depth>("depth");

	auto& NPatchInfoCls = Module.klass<NPatchInfo>("NPatchInfo");
	NPatchInfoCls.ctor<>();
	NPatchInfoCls.var<&NPatchInfo::source>("source");
	NPatchInfoCls.var<&NPatchInfo::left>("left");
	NPatchInfoCls.var<&NPatchInfo::top>("top");
	NPatchInfoCls.var<&NPatchInfo::right>("right");
	NPatchInfoCls.var<&NPatchInfo::bottom>("bottom");
	NPatchInfoCls.var<&NPatchInfo::layout>("layout");

	auto& GlyphInfoCls = Module.klass<GlyphInfo>("GlyphInfo");
	GlyphInfoCls.ctor<>();
	GlyphInfoCls.var<&GlyphInfo::value>("value");
	GlyphInfoCls.var<&GlyphInfo::offsetX>("offsetX");
	GlyphInfoCls.var<&GlyphInfo::offsetY>("offsetY");
	GlyphInfoCls.var<&GlyphInfo::advanceX>("advanceX");
	GlyphInfoCls.var<&GlyphInfo::image>("image");
	
	auto& FontCls = Module.klass<Font>("Font");
	FontCls.ctor<>();
	FontCls.var<&Font::baseSize>("baseSize");
	FontCls.var<&Font::glyphCount>("glyphCount");
	FontCls.var<&Font::glyphPadding>("glyphPadding");
	FontCls.var<&Font::texture>("texture");
	FontCls.var<&Font::recs>("recs");
	FontCls.var<&Font::glyphs>("glyphs");

	auto& Camera3DCls = Module.klass<Camera3D>("Camera3D");
	Camera3DCls.ctor<>();
	Camera3DCls.var<&Camera3D::position>("position");
	Camera3DCls.var<&Camera3D::target>("target");
	Camera3DCls.var<&Camera3D::up>("up");
	Camera3DCls.var<&Camera3D::fovy>("fovy");
	Camera3DCls.var<&Camera3D::projection>("projection");

	auto& Camera2DCls = Module.klass<Camera2D>("Camera2D");
	Camera2DCls.ctor<>();
	Camera2DCls.var<&Camera2D::offset>("offset");
	Camera2DCls.var<&Camera2D::target>("target");
	Camera2DCls.var<&Camera2D::rotation>("rotation");
	Camera2DCls.var<&Camera2D::zoom>("zoom");

	auto& MeshCls = Module.klass<Mesh>("Mesh");
	MeshCls.ctor<>();
	MeshCls.var<&Mesh::vertexCount>("vertexCount");
	MeshCls.var<&Mesh::triangleCount>("triangleCount");
	MeshCls.var<&Mesh::vertices>("vertices");
	MeshCls.var<&Mesh::texcoords>("texcoords");
	MeshCls.var<&Mesh::texcoords2>("texcoords2");
	MeshCls.var<&Mesh::normals>("normals");
	MeshCls.var<&Mesh::tangents>("tangents");
	MeshCls.var<&Mesh::colors>("colors");
	MeshCls.var<&Mesh::indices>("indices");
	MeshCls.var<&Mesh::animVertices>("animVertices");
	MeshCls.var<&Mesh::animNormals>("animNormals");
	MeshCls.var<&Mesh::boneIds>("boneIds");
	MeshCls.var<&Mesh::boneWeights>("boneWeights");
	MeshCls.var<&Mesh::vaoId>("vaoId");
	MeshCls.var<&Mesh::vboId>("vboId");

	auto& ShaderCls = Module.klass<Shader>("Shader");
	ShaderCls.ctor<>();
	ShaderCls.var<&Shader::id>("id");
	ShaderCls.var<&Shader::locs>("locs");

	auto& MaterialMapCls = Module.klass<MaterialMap>("MaterialMap");
	MaterialMapCls.ctor<>();
	MaterialMapCls.var<&MaterialMap::texture>("texture");
	MaterialMapCls.var<&MaterialMap::color>("color");
	MaterialMapCls.var<&MaterialMap::value>("value");


	auto& TransformCls = Module.klass<Transform>("Transform");
	TransformCls.ctor<>();
	TransformCls.var<&Transform::translation>("translation");
	TransformCls.var<&Transform::rotation>("rotation");
	TransformCls.var<&Transform::scale>("scale");

	auto& ModelCls = Module.klass<Model>("Model");
	ModelCls.ctor<>();
	ModelCls.var<&Model::transform>("transform");
	ModelCls.var<&Model::meshCount>("meshCount");
	ModelCls.var<&Model::materialCount>("materialCount");
	ModelCls.var<&Model::meshes>("meshes");
	ModelCls.var<&Model::materials>("materials");
	ModelCls.var<&Model::meshMaterial>("meshMaterial");
	ModelCls.var<&Model::boneCount>("boneCount");
	ModelCls.var<&Model::bones>("bones");
	ModelCls.var<&Model::bindPose>("bindPose");

	auto& RayCls = Module.klass<Ray>("Ray");
	RayCls.ctor<>();
	RayCls.var<&Ray::position>("position");
	RayCls.var<&Ray::direction>("direction");

	auto& RayCollisionCls = Module.klass<RayCollision>("RayCollision");
	RayCollisionCls.ctor<>();
	RayCollisionCls.var<&RayCollision::hit>("hit");
	RayCollisionCls.var<&RayCollision::distance>("distance");
	RayCollisionCls.var<&RayCollision::point>("point");
	RayCollisionCls.var<&RayCollision::normal>("normal");

	auto& BoundingBoxCls = Module.klass<BoundingBox>("BoundingBox");
	BoundingBoxCls.ctor<>();
	BoundingBoxCls.var<&BoundingBox::min>("min");
	BoundingBoxCls.var<&BoundingBox::max>("max");

	auto& WaveCls = Module.klass<Wave>("Wave");
	WaveCls.ctor<>();
	WaveCls.var<&Wave::frameCount>("frameCount");
	WaveCls.var<&Wave::sampleRate>("sampleRate");
	WaveCls.var<&Wave::sampleSize>("sampleSize");
	WaveCls.var<&Wave::channels>("channels");
	WaveCls.var<&Wave::data>("data");

	// auto& AudioStreamCls = Module.klass<AudioStream>("AudioStream");
	// AudioStreamCls.ctor<>();
	// AudioStreamCls.var<&AudioStream::buffer>("buffer");
	// AudioStreamCls.var<&AudioStream::processor>("processor");
	// AudioStreamCls.var<&AudioStream::sampleRate>("sampleRate");
	// AudioStreamCls.var<&AudioStream::sampleSize>("sampleSize");
	// AudioStreamCls.var<&AudioStream::channels>("channels");

	// auto& SoundCls = Module.klass<Sound>("Sound");
	// SoundCls.ctor<>();
	// SoundCls.var<&Sound::stream>("stream");
	// SoundCls.var<&Sound::frameCount>("frameCount");

	// auto& MusicCls = Module.klass<Music>("Music");
	// MusicCls.ctor<>();
	// MusicCls.var<&Music::stream>("stream");
	// MusicCls.var<&Music::frameCount>("frameCount");
	// MusicCls.var<&Music::looping>("looping");
	// MusicCls.var<&Music::ctxType>("ctxType");
	// MusicCls.var<&Music::ctxData>("ctxData");

	// auto& FilePathListCls = Module.klass<FilePathList>("FilePathList");
	// FilePathListCls.ctor<>();
	// FilePathListCls.var<&FilePathList::capacity>("capacity");
	// FilePathListCls.var<&FilePathList::count>("count");
	// FilePathListCls.var<&FilePathList::paths>("paths");
}