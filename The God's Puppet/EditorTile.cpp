#include "EditorTile.h"

std::vector<Image*> EditorTile::objects;
std::vector<Image*> EditorTile::enemies;
std::vector<Image*> EditorTile::colliders;

EditorTile::EditorTile(float x, float y, TileType t, int id)
{
	if (objects.empty()) {
		for (int i = 0; i < 70; ++i) {
			string idString = std::to_string(i);
			objects.push_back(new Image("Resources/Objects/" + idString + ".png"));
		}
	}
	if (enemies.empty()) {
		for (int i = 0; i < 70; ++i) {
			string idString = std::to_string(i);
			enemies.push_back(new Image("Resources/Enemies/" + idString + ".png"));
		}
	}
	if (colliders.empty()) {
		colliders.push_back(new Image("Resources/Collider.png"));
		colliders.push_back(new Image("Resources/Collider2.png"));
	}

	this->id = id;
	tileType = t;

	switch (t) {
	case TileType::PLAYERT:
		spr = new Sprite("Resources/Player.png");
		BBox(new Rect(-32.0f, -32.0f, 32.0f, 32.0f));
		break;
	case TileType::COLLIDER:
		spr = new Sprite(colliders[id]);
		if (id == 0)
			BBox(new Rect(-32.0f, -32.0f, 32.0f, 32.0f));
		else if (id == 1)
			BBox(new Rect(-16.0f, -16.0f, 16.0f, 16.0f));
		break;
	case TileType::ENEMY:
		spr = new Sprite(enemies[id]);
		BBox(new Rect(-32.0f, -32.0f, 32.0f, 32.0f));
		break;
	case TileType::OBJECT:
		spr = new Sprite(objects[id]);
		BBox(new Rect(-32.0f, -32.0f, 32.0f, 32.0f));
		break;
	}
}

EditorTile::~EditorTile()
{
	delete spr;
}

void EditorTile::Update()
{
}

void EditorTile::Draw()
{
	spr->Draw(x, y);
}