#ifndef SPAWNPOINT_H
#define SPAWNPOINT_H

#include "Object.h"
#include "Enemy.h"

class Enemy;
enum EnemyType;

class SpawnPoint : public Object {
private:
	int count = 0;
	bool isAggro = false;
	EnemyType type;
	std::list<Object*> enemies;

public:
	SpawnPoint(int id, float x, float y);
	~SpawnPoint();
	void Update();
	void Draw();
};

#endif