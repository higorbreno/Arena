#include "Object.h"

#ifndef COLLIDER_H
#define COLLIDER_H

class Collider : public Object {
private:

public:
	Collider(int, float, float);
	~Collider();
	void Update();
	void Draw();
};

#endif