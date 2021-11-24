#include "Enemy.h"
#include "Random.h"

Enemy::Enemy(EnemyType id, SpawnPoint* spawn, float x, float y)
{
	type = id;

	if (type == EnemyType::ICEZOMBIE) {
		spr = new Sprite("Resources/Enemies/0.png");
		BBox(new Rect(-8.0f, -16.0f, 8.0f, 16.0f));
	}
	else if (type == EnemyType::GOBLIN) {
		spr = new Sprite("Resources/Enemies/1.png");
		BBox(new Rect(-8.0f, -4.0f, 10.0f, 16.0f));
	}
	else if (type == EnemyType::GHOST) {
		spr = new Sprite("Resources/Enemies/2.png");
		BBox(new Rect(-10.0f, -18.0f, 13.0f, 23.0f));
	}
	else if (type == EnemyType::ZOMBIE) {
		spr = new Sprite("Resources/Enemies/3.png");
		BBox(new Rect(-16.0f, -18.0f, 16.0f, 36.0f));
	}
	else if (type == EnemyType::DEMON) {
		spr = new Sprite("Resources/Enemies/4.png");
		BBox(new Rect(-16.0f, -20.0f, 18.0f, 36.0f));
	}

	sp = spawn;

	RandF rand(0.0f, 360.0f);

	direction = new Vector();

	direction->setPolar(rand.Rand(), 100.0f);

	MoveTo(x, y);
}

Enemy::~Enemy()
{
	delete spr;
	delete direction;
}

void Enemy::Update()
{
	float dist = sqrt(pow(sp->X() - x, 2) + pow(sp->Y(), 2));
	if (dist > 192)
		direction->Rotate(90);

	Translate(direction->X() * gameTime, direction->Y() * gameTime);
}

void Enemy::OnCollision(Object* obj)
{
}

void Enemy::Draw()
{
	spr->Draw(x, y);
}
