#include "Slash.h"
#include "Principal.h"
#include "Enemy.h"

Slash::Slash(float px, float py, float rot, int dmg)
{
	timeLeft = 0.2f;
	damage = dmg;
	ts = new TileSet("Resources/Slash.png", 1, 4);
	anim = new Animation(ts, 0.05f, false);

	Point points[9] = {
		Point(20, -32),
		Point(52, -22),
		Point(64, -5),
		Point(64, 5),
		Point(52, 22),
		Point(20, -32),
		Point(40, 22),
		Point(44, 0),
		Point(40, -22)
	};

	BBox(new Poly(points, 9));

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

void Slash::OnCollision(Object* obj)
{
	if (obj->Type() == ObjTypes::ENEMY) {
		Enemy* e = (Enemy*)obj;
		e->DoPhys(6);
	}
}

void Slash::Draw()
{
	anim->Draw(x, y, Layer::FRONT, scale, rotation, Color(1,1,1,1));
}
