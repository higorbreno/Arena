#include "Boomerang.h"
#include "Principal.h"
#include "Player.h"

Boomerang::Boomerang(Object* p, Vector* v)
{
	damage = 10;
	timeToStop = 1.2f;
	isComingBack = false;
	player = p;
	direction = new Vector();
	direction->setPolar(v->Angle(), 400.0f);
	spr = new Sprite("Resources/Boomerang.png");
	type = BOOMERANG;
	BBox(new Circle(16.0f));
	MoveTo(p->X(), p->Y());
}

Boomerang::~Boomerang()
{
	delete spr;
	delete direction;
}

void Boomerang::Update()
{
	if (timeToStop > 0.0f || isComingBack) {
		if (isComingBack) {
			direction->setXY(player->X() - x, player->Y() - y);
			direction->ScaleTo(800.0f);
		}
		Translate(direction->X() * gameTime, direction->Y() * gameTime);
		timeToStop -= gameTime;
	}
}

void Boomerang::Draw()
{
	spr->Draw(x, y, Layer::FRONT, scale, rotation, Color(1,1,1,1));
}

void Boomerang::OnCollision(Object* obj)
{
	if (obj->Type() == PLAYER && timeToStop < 1.0f) {
		Principal::scene->Delete(this, MOVING);
	}
}

void Boomerang::ComeBack()
{
	isComingBack = true;
	direction->setXY(player->X() - x, player->Y() - y);
	direction->ScaleTo(800.0f);
}
