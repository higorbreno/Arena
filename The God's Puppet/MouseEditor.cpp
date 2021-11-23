#include "MouseEditor.h"
#include "EditorTile.h"
#include "Editor.h"

int MouseEditor::objectsId = 0;
int MouseEditor::enemiesId = 0;
int MouseEditor::collidersId = 0;

const uint MouseEditor::MAX_OBJECTS = 40;
const uint MouseEditor::MAX_ENEMIES = 5;
const uint MouseEditor::MAX_COLLIDERS = 2;

MouseEditor::MouseEditor()
{
	isColliding = false;
	mode = TileType::PLAYERT;
	playerOnScene = false;

	if (objects.empty()) {
		for (int i = 0; i < MAX_OBJECTS; ++i) {
			string idString = std::to_string(i);
			objects.push_back(new Sprite("Resources/Objects/" + idString + ".png"));
		}
	}
	if (enemies.empty()) {
		for (int i = 0; i < MAX_ENEMIES; ++i) {
			string idString = std::to_string(i);
			enemies.push_back(new Sprite("Resources/Enemies/" + idString + ".png"));
		}
	}
	if (colliders.empty()) {
		colliders.push_back(new Sprite("Resources/Collider.png"));
		colliders.push_back(new Sprite("Resources/Collider2.png"));
	}

	playerTile = new Sprite("Resources/Player.png");

	BBox(new Point());
}

MouseEditor::~MouseEditor()
{
	if (!objects.empty()) {
		for (auto object : objects)
			delete object;
		objects.clear();
	}
	if (!enemies.empty()) {
		for (auto enemy : enemies)
			delete enemy;
		enemies.clear();
	}
	delete playerTile;
}

void MouseEditor::Update()
{
	MoveTo(window->MouseX(), window->MouseY());
	snapToGrid();

	int* id = &objectsId;

	switch (mode) {
	case TileType::OBJECT:
		id = &objectsId;
		break;
	case TileType::ENEMY:
		id = &enemiesId;
		break;
	case TileType::COLLIDER:
		id = &collidersId;
		break;
	}

	if (mode != TileType::PLAYERT) {
		if (window->KeyPress(VK_LEFT))
			--* id;
		if (window->KeyPress(VK_DOWN))
			*id -= 10;
		if (window->KeyPress(VK_RIGHT))
			++* id;
		if (window->KeyPress(VK_UP))
			*id += 10;
	}

	clampObjectId();
	clampEnemiesId();
	clampCollidersId();

	if (window->KeyPress('M'))
		mode = TileType(mode + 1);

	clampMode();

	if (window->KeyPress('G')) {
		++gridState;
		if (gridState >= 3)
			gridState = 0;
	}

	if (window->KeyDown(VK_LBUTTON) && !isColliding) {
		if (mode == TileType::PLAYERT && !playerOnScene) {
			playerOnScene = true;
			EditorTile* tile = new EditorTile(x, y, TileType(mode));
			tile->MoveTo(x, y);
			Editor::scene->Add(tile, STATIC);
			Editor::tiles.push_back(tile);
		}
		else if (mode == TileType::COLLIDER) {
			EditorTile* tile = new EditorTile(x, y, TileType(mode), collidersId);
			tile->MoveTo(x, y);
			Editor::scene->Add(tile, STATIC);
			Editor::tiles.push_back(tile);
		}
		else if (mode == TileType::OBJECT) {
			EditorTile* tile = new EditorTile(x, y, TileType(mode), objectsId);
			tile->MoveTo(x, y);
			Editor::scene->Add(tile, STATIC);
			Editor::tiles.push_back(tile);
		}
		else if (mode == TileType::ENEMY) {
			EditorTile* tile = new EditorTile(x, y, TileType(mode), enemiesId);
			tile->MoveTo(x, y);
			Editor::scene->Add(tile, STATIC);
			Editor::tiles.push_back(tile);
		}
	}

	isColliding = false;
}

void MouseEditor::Draw()
{
	if (mode == TileType::PLAYERT)
		playerTile->Draw(x, y, z, scale, rotation, { 1,1,1,0.6f });
	else if (mode == TileType::COLLIDER)
		colliders[collidersId]->Draw(x, y, z, scale, rotation, { 1,1,1,0.6f });
	else if (mode == TileType::OBJECT)
		objects[objectsId]->Draw(x, y, z, scale, rotation, { 1,1,1,0.6f });
	else if (mode == TileType::ENEMY)
		enemies[enemiesId]->Draw(x, y, z, scale, rotation, { 1,1,1,0.6f });
}

void MouseEditor::OnCollision(Object* obj)
{
	isColliding = true;
	if (window->KeyDown(VK_RBUTTON)) {
		EditorTile* tile = (EditorTile*)obj;
		if (tile->tileType == TileType::PLAYERT)
			playerOnScene = false;
		Editor::tiles.remove(tile);
		Editor::scene->Delete(obj, STATIC);
	}
	else if (window->KeyPress(VK_MBUTTON)) {
		EditorTile* tile = (EditorTile*)obj;
		switch (tile->tileType) {
		case TileType::OBJECT:
			objectsId = tile->Id();
			mode = TileType::OBJECT;
			break;
		case TileType::ENEMY:
			enemiesId = tile->Id();
			mode = TileType::ENEMY;
			break;
		case TileType::COLLIDER:
			collidersId = tile->Id();
			mode = TileType::COLLIDER;
			break;
		default:
			mode = tile->tileType;
			break;
		}
	}
}

void MouseEditor::snapToGrid()
{
	int posx = x, posy = y;
	if (gridState == 0) {
		posx = ((int(x + game->viewport.left) / 64) * 64) + 32;
		posy = ((int(y + game->viewport.top) / 64) * 64) + 32;
	}
	else if (gridState == 1) {
		posx = ((int(x + game->viewport.left) / 32) * 32) + 16;
		posy = ((int(y + game->viewport.top) / 32) * 32) + 16;
	}
	else if (gridState == 2) {
		posx = x + game->viewport.left;
		posy = y + game->viewport.top;
	}
	MoveTo(posx, posy);
}

void MouseEditor::clampObjectId()
{
	while (objectsId < 0)
		objectsId += MAX_OBJECTS;
	while (objectsId >= MAX_OBJECTS)
		objectsId -= MAX_OBJECTS;
}

void MouseEditor::clampEnemiesId()
{
	while (enemiesId < 0)
		enemiesId += MAX_ENEMIES;
	while (enemiesId >= MAX_ENEMIES)
		enemiesId -= MAX_ENEMIES;
}

void MouseEditor::clampCollidersId()
{
	while (collidersId < 0)
		collidersId += MAX_COLLIDERS;
	while (collidersId >= MAX_COLLIDERS)
		collidersId -= MAX_COLLIDERS;
}

void MouseEditor::clampMode()
{
	while (mode < TileType::PLAYERT)
		mode = TileType(mode + TileType::Count);
	while (mode >= TileType::Count)
		mode = TileType(mode - TileType::Count);
}