#include "Collider.h"
#include "Principal.h"

Collider::Collider(int id, float px, float py)
{
	type = ObjTypes::COLLI;
	if (id == 0)
		BBox(new Rect(-32.0f, -32.0f, 32.0f, 32.0f));
	else
		BBox(new Rect(-16.0f, -16.0f, 16.0f, 16.0f));
	
	MoveTo(px, py);
}

Collider::~Collider()
{
}

void Collider::Update()
{
}

void Collider::Draw()
{
}
