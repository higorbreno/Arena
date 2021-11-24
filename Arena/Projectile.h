#include "Object.h"
#include "Sprite.h"
#include "Vector.h"

#ifndef PROJECTILE_H
#define PROJECTILE_H

class Projectile : public Object {
private:
	int id;
	Sprite* spr;
	Vector* direction;
	float timeToDisappear = 10.0f;

public:
	Projectile(int id, float px, float py, Vector* dir);
	~Projectile();
	void Update();
	void OnCollision(Object* obj);
	void Draw();
};

#endif