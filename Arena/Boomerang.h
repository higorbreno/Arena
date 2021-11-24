#include "Object.h"
#include "Animation.h"
#include "Vector.h"

#ifndef BOOMERANG_H
#define BOOMERANG_H

class Boomerang : public Object {
private:
	Sprite* spr;
	Vector* direction;
	float timeToStop;
	float timeToBack;
	int damage;
	bool isComingBack;

public:
	Boomerang(Vector* v);
	~Boomerang();
	void Update();
	void Draw();
	void OnCollision(Object* obj);
	void ComeBack();

};

#endif // !BOOMERANG_H
