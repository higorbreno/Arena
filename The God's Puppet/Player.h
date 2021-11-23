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

	bool hasReleased;

	int MaxHealth = 10;
	int MaxAdrenaline = 20;
	int health = 10;
	int adrenaline = 20;

	const float ATTACK_COOLDOWN = 0.2f;
	const float SPEED_COOLDOWN = 2.0f;
	const float KNOCKBACK_COOLDOWN = 4.0f;
	const float RANGED_COOLDOWN = 7.0f;
	const float HEAL_COOLDOWN = 20.0f;

	float attackCooldown = 0.0f;
	float speedCooldown = 0.0f;
	float knockbackCooldown = 0.0f;
	float rangedCooldown = 0.0f;
	float healCooldown = 0.0f;

	bool isSpeed = false;

	void Attack();
	void Speed();
	void KnockBack();
	void RangedAbility();
	void Heal();

public:
	std::list<Boomerang*> boomerangs;

	Player();
	~Player();
	void Update();
	void OnCollision(Object* obj);
	void Draw();
};

#endif