#include "Object.h"
#include "Animation.h"

#ifndef SLASH_H
#define SLASH_H

class Slash : public Object {
private:
	float timeLeft;
	int damage;
	TileSet* ts = nullptr;
	Animation* anim = nullptr;

public:
	Slash(float px, float py, float rot, int dmg = 2);
	~Slash();
	void Update();
	void OnCollision(Object* obj);
	void Draw();
};

#endif