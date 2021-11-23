#include "Tree.h"
#include "Principal.h"

Tree::Tree(int id, float x, float y)
{
	color = { 1,1,1,1 };
	BBox(new Rect(-48.0f, -48.0f, 48.0f, 48.0f));

	spr = new Sprite("Resources/Objects/" + std::to_string(id) + ".png");
	MoveTo(x, y);
}

Tree::~Tree()
{
	delete spr;
}

void Tree::Update()
{
	color = { 1,1,1,1 };
}

void Tree::OnCollision(Object* obj)
{
	if (obj->Type() == ObjTypes::PLAYER)
		color = { 1,1,1,0.6f };
}

void Tree::Draw()
{
	spr->Draw(x, y, Layer::UPPER, scale, rotation, color);
}
