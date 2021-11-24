#include "Boomerang.h"
#include "Principal.h"
#include "Player.h"
#include "Enemy.h"

Boomerang::Boomerang(Vector* v)
{
	damage = 10;
	timeToStop = 1.2f;
	timeToBack = 7.0f;
	isComingBack = false;
	direction = new Vector();
	direction->setPolar(v->Angle(), 400.0f);
	spr = new Sprite("Resources/Boomerang.png");
	type = BOOMERANG;
	BBox(new Circle(16.0f));
	MoveTo(Principal::player->X(), Principal::player->Y());
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
			direction->setXY(Principal::player->X() - x, Principal::player->Y() - y);
			direction->ScaleTo(800.0f);
		}
		Translate(direction->X() * gameTime, direction->Y() * gameTime);
		timeToStop -= gameTime;
	}
	else if (timeToBack <= 0.0f) {
		ComeBack();
		Principal::player->boomerangs.clear();
	}
	timeToBack -= gameTime;
}

void Boomerang::Draw()
{
	spr->Draw(x, y, Layer::FRONT, scale, rotation, Color(1,1,1,1));
}

void Boomerang::OnCollision(Object* obj)
{
	if (obj->Type() == PLAYER && isComingBack) {
		Principal::scene->Delete(this, MOVING);
	}

	if (obj->Type() == ObjTypes::ENEMY) {
		Enemy* e = (Enemy*)obj;
		e->DoMagic(4);
	}
}

void Boomerang::ComeBack()
{
	Principal::player->hasReleased = false;
	isComingBack = true;
	direction->setXY(Principal::player->X() - x, Principal::player->Y() - y);
	direction->ScaleTo(800.0f);
}
