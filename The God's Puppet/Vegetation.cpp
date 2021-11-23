#include "Vegetation.h"

Vegetation::Vegetation(int id, float px, float py)
{
	spr = new Sprite("Resources/Objects/" + std::to_string(id) + ".png");
	MoveTo(px, py);
}

Vegetation::~Vegetation()
{
	delete spr;
}

void Vegetation::Update()
{
}

void Vegetation::Draw()
{
	spr->Draw(x, y, Layer::LOWER);
}
