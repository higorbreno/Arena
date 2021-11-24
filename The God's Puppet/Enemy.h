#ifndef ENEMY_H
#define ENEMY_H

#include "Object.h"
#include "Animation.h"
#include "Vector.h"
#include "SpawnPoint.h"

enum EnemyType { ICEZOMBIE, GOBLIN, GHOST, ZOMBIE, DEMON };

class SpawnPoint;

class Enemy : public Object {
private:
	Sprite* spr;
	EnemyType type;
	SpawnPoint* sp;
	Vector* direction;
	bool isAggro = false;

public:
	Enemy(EnemyType id, SpawnPoint* spawn, float x, float y);
	~Enemy();
	void Update();
	void OnCollision(Object* obj);
	void Draw();
};

#endif