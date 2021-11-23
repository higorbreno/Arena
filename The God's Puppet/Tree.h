#include "Object.h"
#include "Sprite.h"

#ifndef TREE_H
#define TREE_H

class Tree : public Object {
private:
	Sprite* spr;
	Color color;

public:
	Tree(int id, float x, float y);
	~Tree();
	void Update();
	void OnCollision(Object* obj);
	void Draw();
};

#endif