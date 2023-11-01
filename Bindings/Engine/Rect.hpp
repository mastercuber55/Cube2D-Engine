#define CGE_WHOLE_FILE { 0, 0, -1, -1 }
std::unordered_map<std::string, Texture> Textures;

struct ForeignRect {
		
	// Transformm
	Rectangle PositionAndScale;		
	double Rotation;

	std::string TextureFile;						
	Rectangle Source;								
	Color Tint;										

	// De-Constructers
	ForeignRect(float x, float y, float w, float h);
	~ForeignRect();

	// Setters
	void SetTextureFile(std::string TextureFile); 

	// Getters
	Vector2 GetCenter();	
	void SetPosition(Vector2 NewPosition);
	Vector2 GetPosition();
	Vector2 GetRectangle();								

	// Utilities
	bool IsColliding(ForeignRect * Other);
	void Draw();									
};

ForeignRect::ForeignRect(float x, float y, float w, float h) {
	this->PositionAndScale.x = x, this->PositionAndScale.y = y;
	this->PositionAndScale.width = w, this->PositionAndScale.height = h;
	this->Tint = WHITE;
	this->Source = CGE_WHOLE_FILE,
	this->Rotation = 0.0;
}
ForeignRect::~ForeignRect() {}
void ForeignRect::SetTextureFile(std::string TextureFile) {

	this->TextureFile = TextureFile; 						
	if(Textures.find(TextureFile) != Textures.end()) return;
	Textures[TextureFile] = LoadTexture(TextureFile.c_str());

	if(
		this->Source.x == 0 && 
		this->Source.y == 0 && 
		this->Source.width == -1 && 
		this->Source.height == -1
	) {
		this->Source.width = Textures[TextureFile].width, 
		this->Source.height = Textures[TextureFile].height;
	} 

}
void ForeignRect::Draw() {

	(this->TextureFile.empty()) ? 
		DrawRectangleRec(this->PositionAndScale, this->Tint)
	:	
		DrawTexturePro(
			Textures[this->TextureFile], 
			this->Source, 
			(Rectangle){ 
				this->PositionAndScale.x + this->PositionAndScale.width / 2.0f, 
				this->PositionAndScale.y + this->PositionAndScale.height / 2.0f, 
				this->PositionAndScale.width, 
				this->PositionAndScale.height 
			}, 
			(Vector2){ this->PositionAndScale.width / 2.0f, this->PositionAndScale.height / 2.0f }, 
			this->Rotation, 
			this->Tint
		);
}
bool ForeignRect::IsColliding(ForeignRect * Other) {
	return CheckCollisionRecs(PositionAndScale, Other->PositionAndScale);
}
void ForeignRect::SetPosition(Vector2 Position) {
	this->PositionAndScale.x = Position.x, this->PositionAndScale.y = Position.y;
}
Vector2 ForeignRect::GetCenter() {
	return { 
		this->PositionAndScale.x + this->PositionAndScale.width / 2.0f, 
		this->PositionAndScale.y + this->PositionAndScale.height / 2.0f 
	};
}
Vector2 ForeignRect::GetPosition() {
	return { this->PositionAndScale.x, this->PositionAndScale.y };
}