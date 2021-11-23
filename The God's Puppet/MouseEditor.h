#include "Object.h"
#include "Sprite.h"
#include <vector>

#ifndef MOUSEEDITOR_H
#define MOUSEEDITOR_H

class MouseEditor : public Object {
private:
	static const uint MAX_OBJECTS;
	static const uint MAX_ENEMIES;
	static const uint MAX_COLLIDERS;

	bool isColliding;
	std::vector<Sprite*> objects;
	std::vector<Sprite*> enemies;
	std::vector<Sprite*> colliders;
	Sprite* playerTile;
	uint mode;
	bool playerOnScene;
	int gridState = 0;

	void snapToGrid();
	void clampObjectId();
	void clampEnemiesId();
	void clampCollidersId();
	void clampMode();

public:
	static int objectsId;
	static int enemiesId;
	static int collidersId;

	MouseEditor();
	~MouseEditor();
	void Update();
	void Draw();
	void OnCollision(Object* obj);
};

#endif