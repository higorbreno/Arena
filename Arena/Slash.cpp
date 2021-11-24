#include "Slash.h"
#include "Principal.h"

Slash::Slash(float px, float py, float rot, int dmg)
{
	timeLeft = 0.2f;
	damage = dmg;
	ts = new TileSet("Resources/Slash.png", 1, 4);
	anim = new Animation(ts, 0.05f, false);

	MoveTo(px, py);
	RotateTo(rot);
}

Slash::~Slash()
{
	delete anim;
	delete ts;
}

void Slash::Update()
{
	timeLeft -= gameTime;

	anim->NextFrame();

	if (timeLeft < 0.0f)
		Principal::scene->Delete();
}

void Slash::Draw()
{
	anim->Draw(x, y, Layer::FRONT, scale, rotation, Color(1,1,1,1));
}
