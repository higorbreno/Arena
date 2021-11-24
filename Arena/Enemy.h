#ifndef ENEMY_H
#define ENEMY_H

#include "Object.h"
#include "Animation.h"
#include "Vector.h"

enum EnemyType { ICEZOMBIE, GOBLIN, GHOST, ZOMBIE, DEMON };

class Enemy : public Object {
private:
	Sprite* spr;
	EnemyType id;
	Vector* direction;
	int vel;
	int turnVel;
	float randMovTime;

public:
	Enemy(EnemyType id, float x, float y);
	~Enemy();
	void Update();
	void OnCollision(Object* obj);
	void Draw();

	void Follow();
	void SoftFollow();
	void KeepDistance();
	void SoftKeepDistance();
	void RandomMovement();
	void Attack();
	void AttackDistance(int type);
};

#endif