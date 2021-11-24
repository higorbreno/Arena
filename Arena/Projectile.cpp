#include "Projectile.h"
#include "Principal.h"
#include "TheGodsPuppet.h"

Projectile::Projectile(int i, float px, float py, Vector* dir)
{
	id = i;
	if (id == 0) {
		spr = new Sprite("Resources/Enemies/Attacks/Ice.png");
		TheGodsPuppet::inimigosAudio->Play(ICEZOMBIEATTACK);
	}
	else if (id == 1) {
		spr = new Sprite("Resources/Enemies/Attacks/Fire.png");
		TheGodsPuppet::inimigosAudio->Play(DEMONATTACK);
	}

	BBox(new Circle(16.0f));

	direction = new Vector();

	direction->setXY(dir->X(), dir->Y());
	direction->ScaleTo(600.0f);

	RotateTo(direction->Angle());
	MoveTo(px, py);
}

Projectile::~Projectile()
{
	delete spr;
}

void Projectile::Update()
{
	Translate(direction->X() * gameTime, direction->Y() * gameTime);
}

void Projectile::OnCollision(Object* obj)
{
	if (obj->Type() == ObjTypes::PLAYER) {
		if (id == 0) {
			if (Principal::player->dmgCooldown <= 0.0f) {
				if (Principal::player->weakCooldown > 0.0f)
					Principal::player->health -= 2;
				else
					Principal::player->health--;
			}
			Principal::player->slowCooldown = 3.0f;
		}
		else if (id == 1) {
			Principal::player->burnCooldown = 3.0f;
		}

		Principal::player->dmgCooldown = 0.5f;
	}
}

void Projectile::Draw()
{
	spr->Draw(x, y, Layer::UPPER, scale, rotation);
}
