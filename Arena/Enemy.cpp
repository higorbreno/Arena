#include "Enemy.h"
#include "Random.h"
#include "Principal.h"
#include "Geometry.h"

Enemy::Enemy(EnemyType id, float x, float y)
{
	type = ObjTypes::ENEMY;
	id = id;

	if (id == EnemyType::ICEZOMBIE) {
		spr = new Sprite("Resources/Enemies/0.png");
		BBox(new Rect(-8.0f, -16.0f, 8.0f, 16.0f));
		vel = 200;
		turnVel = 20;
	}
	else if (id == EnemyType::GOBLIN) {
		spr = new Sprite("Resources/Enemies/1.png");
		BBox(new Rect(-8.0f, -4.0f, 10.0f, 16.0f));
		vel = 300;
		turnVel = 20;
	}
	else if (id == EnemyType::GHOST) {
		spr = new Sprite("Resources/Enemies/2.png");
		BBox(new Rect(-10.0f, -18.0f, 13.0f, 23.0f));
		vel = 200;
		turnVel = 20;
	}
	else if (id == EnemyType::ZOMBIE) {
		spr = new Sprite("Resources/Enemies/3.png");
		BBox(new Rect(-16.0f, -18.0f, 16.0f, 36.0f));
		vel = 100;
		turnVel = 20;
	}
	else if (id == EnemyType::DEMON) {
		spr = new Sprite("Resources/Enemies/4.png");
		BBox(new Rect(-16.0f, -20.0f, 18.0f, 36.0f));
		vel = 200;
		turnVel = 20;
	}

	RandF rand(0.0f, 360.0f);

	direction = new Vector();

	MoveTo(x, y);
}

Enemy::~Enemy()
{
	delete spr;
	delete direction;
}

void Enemy::Update()
{
	float distance = Point::Distance(Point(x, y), Point(Principal::player->X(), Principal::player->Y()));

	if (type == EnemyType::ICEZOMBIE) {
		if (distance > 300)
			Follow();
		else
			KeepDistance();
	}
	else if (type == EnemyType::GOBLIN) {
		Follow();
	}
	else if (type == EnemyType::GHOST) {
		if (distance > 100)
			SoftFollow();
		else
			SoftKeepDistance();
	}
	else if (type == EnemyType::ZOMBIE) {
		Follow();
	}
	else if (type == EnemyType::DEMON) {
		if (distance > 300)
			Follow();
		else
			KeepDistance();
	}

	Translate(direction->X() * gameTime, direction->Y() * gameTime);

	if (x < 32)
		MoveTo(32, y);
	if (x > game->Width() - 32)
		MoveTo(game->Width() - 32, y);
	if (y < 64)
		MoveTo(x, 64);
	if (y > game->Height() - 192);
}

void Enemy::OnCollision(Object* obj)
{
	if (obj->Type() == ObjTypes::ENEMY) {
		bool isLeft = (x - obj->X()) < 0;
		bool isTop = (y - obj->Y()) < 0;

		float dx, dy;

		Rect* player = (Rect*)BBox();
		Rect* colli = (Rect*)obj->BBox();

		if (isTop)
			dy = colli->Top() - player->Bottom();
		else
			dy = colli->Bottom() - player->Top();

		if (isLeft)
			dx = colli->Left() - player->Right();
		else
			dx = colli->Right() - player->Left();

		if (abs(dx) <= abs(dy)) {
			Translate(dx, 0);
		}
		else {
			Translate(0, dy);
		}
	}
}

void Enemy::Draw()
{
	spr->Draw(x, y);
}

void Enemy::Follow()
{
	direction->setXY(Principal::player->X() - x, Principal::player->Y() - y);
	direction->ScaleTo(vel);
}

void Enemy::SoftFollow()
{
	Vector v;
	v.setXY(Principal::player->X() - x, Principal::player->Y() - y);
	v.ScaleTo(turnVel);
	*direction = *direction + &v;

	if (direction->Magnitude() > vel)
		direction->ScaleTo(vel);
}

void Enemy::KeepDistance()
{
	direction->setPolar(Line::Angle(Point(x, y), Point(Principal::player->X(), Principal::player->Y())), vel);
	direction->Rotate(180);
}

void Enemy::SoftKeepDistance()
{
	Vector v;
	v.setXY(Principal::player->X() - x, Principal::player->Y() - y);
	v.ScaleTo(turnVel);
	v.Rotate(180);
	*direction = *direction + &v;

	if (direction->Magnitude() > vel)
		direction->ScaleTo(vel);
}

void Enemy::RandomMovement()
{
	if (randMovTime <= 0.0f) {
		RandF r(0.0f, 360.0f);

		direction->RotateTo(r.Rand());

		randMovTime = 1.0f;
	}
	else {
		randMovTime -= gameTime;
	}
}

void Enemy::Attack()
{
}

void Enemy::AttackDistance(int type)
{
}
