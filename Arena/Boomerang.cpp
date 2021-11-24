#include "Boomerang.h"
#include "TheGodsPuppet.h"
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

	ts = new TileSet ("Resources/MainCharacter/Abilities/Animations/BoomerangAnimation.png", 32, 32, 4, 4);
	animation = new Animation(ts, 0.1, true);

	type = BOOMERANG;
	BBox(new Circle(16.0f));
	MoveTo(Principal::player->X(), Principal::player->Y());

	TheGodsPuppet::audio->Play(BRANG, true);
}

Boomerang::~Boomerang()
{
	TheGodsPuppet::audio->Stop(BRANG);
	delete ts;
	delete animation;
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
	animation->NextFrame();
}

void Boomerang::Draw()
{
	animation->Draw(x, y, Layer::FRONT, scale, rotation, Color(1,1,1,1));
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
