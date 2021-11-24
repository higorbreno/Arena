#include "SpawnPoint.h"
#include "Principal.h"

SpawnPoint::SpawnPoint(int id, float x, float y)
{
	type = EnemyType(id);

	MoveTo(x, y);
}

SpawnPoint::~SpawnPoint()
{
}

void SpawnPoint::Update()
{
	if (!isAggro && count < 3) {
		Enemy* enemy = new Enemy(type, this, x, y);
		Principal::scene->Add(enemy, MOVING);
		++count;
	}
}

void SpawnPoint::Draw()
{
}
