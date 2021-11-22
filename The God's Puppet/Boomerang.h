#include "Object.h"
#include "Animation.h"
#include "Vector.h"

#ifndef BOOMERANG_H
#define BOOMERANG_H

class Boomerang : public Object {
private:
	Object* player;
	Sprite* spr;
	Vector* direction;
	float timeToStop;
	int damage;
	bool isComingBack;

public:
	Boomerang(Object* p, Vector* v);
	~Boomerang();
	void Update();
	void Draw();
	void OnCollision(Object* obj);
	void ComeBack();

};

#endif // !BOOMERANG_H
