#include "Object.h"
#include "Sprite.h"

#ifndef VEGETATION_H
#define VEGETATION_H

class Vegetation : public Object {
private:
	Sprite* spr;

public:
	Vegetation(int id, float px, float py);
	~Vegetation();
	void Update();
	void Draw();
};

#endif