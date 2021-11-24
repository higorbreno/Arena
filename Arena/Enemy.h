#ifndef ENEMY_H
#define ENEMY_H

#include "Object.h"
#include "Animation.h"
#include "TileSet.h"
#include "Vector.h"

enum EnemyType { ICEZOMBIE, GOBLIN, GHOST, ZOMBIE, DEMON };

class Enemy : public Object {
private:
	int health;
	Sprite* spr;
	EnemyType id;
	Vector* direction;
	TileSet* ts;
	Animation* a;
	int vel;
	int turnVel;
	float randMovTime;
	float dmgCooldown = 0.5f;
	float attackCooldown = 4.0f;

public:
	static int count;

	Enemy(EnemyType id, float x, float y);
	~Enemy();
	void Update();
	void OnCollision(Object* obj);
	void Draw();

	void DoPhys(int dmg);
	void DoMagic(int dmg);

	void Follow();
	void SoftFollow();
	void KeepDistance();
	void SoftKeepDistance();
	void RandomMovement();
	void AttackDistance(int type);
};

#endif