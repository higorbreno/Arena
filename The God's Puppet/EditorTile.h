#include "Object.h"
#include "Sprite.h"
#include <vector>

#ifndef EDITORTILE_H
#define EDITORTILE_H

enum TileType { PLAYERT, ENEMY, COLLIDER, OBJECT, Count };

class EditorTile : public Object {
private:
	int id;
	Sprite* spr;

public:
	TileType tileType;
	static std::vector<Image*> objects;
	static std::vector<Image*> enemies;
	static std::vector<Image*> colliders;

	int Id();
	EditorTile(float, float, TileType, int id = 0);
	~EditorTile();
	void Update();
	void Draw();
};

inline int EditorTile::Id()
{
	return id;
}

#endif