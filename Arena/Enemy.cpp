#include "Enemy.h"
#include "Random.h"
#include "Principal.h"
#include "Geometry.h"
#include "Projectile.h"

int Enemy::count = 0;

Enemy::Enemy(EnemyType i, float x, float y)
{
	count++;
	type = ObjTypes::ENEMY;
	id = i;

	if (id == EnemyType::ICEZOMBIE) {
		spr = new Sprite("Resources/Enemies/0.png");
		BBox(new Rect(-8.0f, -16.0f, 8.0f, 16.0f));
		vel = 200;
		turnVel = 20;
		health = 10;
	}
	else if (id == EnemyType::GOBLIN) {
		spr = new Sprite("Resources/Enemies/1.png");
		BBox(new Rect(-8.0f, -4.0f, 10.0f, 16.0f));
		vel = 250;
		turnVel = 20;
		health = 5;
	}
	else if (id == EnemyType::GHOST) {
		spr = new Sprite("Resources/Enemies/2.png");
		BBox(new Rect(-10.0f, -18.0f, 13.0f, 23.0f));
		vel = 200;
		turnVel = 20;
		health = 15;
	}
	else if (id == EnemyType::ZOMBIE) {
		spr = new Sprite("Resources/Enemies/3.png");
		BBox(new Rect(-16.0f, -18.0f, 16.0f, 36.0f));
		vel = 100;
		turnVel = 20;
		health = 20;
	}
	else if (id == EnemyType::DEMON) {
		spr = new Sprite("Resources/Enemies/4.png");
		BBox(new Rect(-16.0f, -20.0f, 18.0f, 36.0f));
		vel = 200;
		turnVel = 20;
		health = 10;
	}

	RandF rand(0.0f, 360.0f);

	direction = new Vector();

	MoveTo(x, y);
}

Enemy::~Enemy()
{
	delete spr;
	delete direction;
	--count;
}

void Enemy::Update()
{
	float distance = Point::Distance(Point(x, y), Point(Principal::player->X(), Principal::player->Y()));

	if (id == EnemyType::ICEZOMBIE) {
		if (distance > 350)
			Follow();
		else if (distance > 300)
			direction->setXY(0, 0);
		else
			KeepDistance();

	} else if (id == EnemyType::GOBLIN) {
		Follow();
	}
	else if (id == EnemyType::GHOST) {
		if (distance > 100)
			SoftFollow();
		else
			SoftKeepDistance();
	}
	else if (id == EnemyType::ZOMBIE) {
		Follow();
	}
	else if (id == EnemyType::DEMON) {
		if (distance > 350)
			Follow();
		else if (distance > 300)
			direction->setXY(0, 0);
		else
			KeepDistance();
	}

	Translate(direction->X() * gameTime, direction->Y() * gameTime);

	if (x < 64)
		MoveTo(64, y);
	if (x > game->Width() - 64)
		MoveTo(game->Width() - 64, y);
	if (y < 80)
		MoveTo(x, 80);
	if (y > game->Height() - 200)
		MoveTo(x, game->Height() - 200);

	if (dmgCooldown > 0)
		dmgCooldown -= gameTime;

	if (attackCooldown > 0)
		attackCooldown -= gameTime;
	else if (id == EnemyType::ICEZOMBIE)
		AttackDistance(0);
	else if (id == EnemyType::DEMON)
		AttackDistance(1);

	if (health <= 0) {
		Principal::player->score++;
		Principal::scene->Delete(this, MOVING);
	}
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

	if (obj->Type() == ObjTypes::PLAYER) {
		if (id == EnemyType::GOBLIN || id == EnemyType::ZOMBIE) {
			if (Principal::player->dmgCooldown <= 0.0f) {
				if (Principal::player->weakCooldown > 0)
					Principal::player->health -= 2;
				else
					Principal::player->health--;
			}

			Principal::player->dmgCooldown = 0.5f;
		}
		else if (id == EnemyType::GHOST) {
			Principal::player->weakCooldown = 3.0f;
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

void Enemy::DoPhys(int dmg)
{
	if (dmgCooldown <= 0.0f) {
		if (id == EnemyType::GOBLIN || id == EnemyType::ICEZOMBIE || id == EnemyType::ZOMBIE)
			health -= dmg;
		else if (id == EnemyType::DEMON)
			health -= int(dmg * 1.5f);

		dmgCooldown = 0.5f;
	}
}

void Enemy::DoMagic(int dmg)
{
	if (dmgCooldown <= 0.0f) {
		if (id == EnemyType::GOBLIN || id == EnemyType::ICEZOMBIE || id == EnemyType::ZOMBIE)
			health -= dmg;
		else if (id == EnemyType::DEMON)
			health -= int(dmg * 0.5f);
		else if (id == EnemyType::GHOST)
			health -= 2 * dmg;

		dmgCooldown = 0.5f;
	}
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

void Enemy::AttackDistance(int i)
{
	Vector v;
	v.setXY(Principal::player->X() - x, Principal::player->Y() - y);
	Projectile* p = new Projectile(i, x, y, &v);
	Principal::scene->Add(p, MOVING);

	attackCooldown = 4.0f;
}
