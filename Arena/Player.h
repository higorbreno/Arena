#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"
#include "Animation.h"
#include "Vector.h"
#include "Controller.h"
#include "Boomerang.h"
#include <list>

class Player : public Object {
private:
	float verticalM, horizontalM;
	float verticalL, horizontalL;
	bool hasMoved = false;
	Vector* speed;
	Vector* pointerVector;
	Sprite* spr;
	Sprite* pointer;

	Color color = { 1,1,1,1 };

	int MaxHealth = 10;

	bool isSpeed = false;
	bool hasBurnFirst = false;

	void Attack();
	void Speed();
	void KnockBack();
	void RangedAbility();
	void Heal();

public:
	static int score;

	const float ATTACK_COOLDOWN = 0.2f;
	const float SPEED_COOLDOWN = 2.0f;
	const float KNOCKBACK_COOLDOWN = 4.0f;
	const float RANGED_COOLDOWN = 7.0f;
	const float HEAL_COOLDOWN = 4.0f;

	float attackCooldown = 0.0f;
	float speedCooldown = 0.0f;
	float knockbackCooldown = 0.0f;
	float rangedCooldown = 0.0f;
	float healCooldown = 0.0f;

	float weakCooldown = 0.0f;
	float burnCooldown = 0.0f;
	float slowCooldown = 0.0f;
	float dmgCooldown = 0.0f;

	int health = 10;
	bool hasReleased;
	std::list<Boomerang*> boomerangs;

	Player();
	~Player();
	void Update();
	void OnCollision(Object* obj);
	void Draw();
};

#endif