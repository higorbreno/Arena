#include "Object.h"
#include "SpawnPoint.h"

#ifndef SPAWNPOOL_H
#define SPAWNPOOL_H

class SpawnPool : public Object {
public:
	std::list<SpawnPoint*> iceZombies;
	std::list<SpawnPoint*> goblins;
	std::list<SpawnPoint*> ghosts;
	std::list<SpawnPoint*> zombies;
	std::list<SpawnPoint*> demons;
	bool hasBoss[5] = { 0 };

private:
	static std::list<SpawnPoint*> spawns[5];

	SpawnPool();
	~SpawnPool();
	void Update();
	void Draw();
};

#endif