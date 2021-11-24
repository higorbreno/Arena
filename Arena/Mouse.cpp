#include "TheGodsPuppet.h"
#include "Mouse.h"

Mouse::Mouse() {
	MoveTo(window->MouseX(), window->MouseY());
	BBox(new Point(x, y));
}

Mouse::~Mouse() {

}

void Mouse::Update() {
	MoveTo(window->MouseX(), window->MouseY());
}

bool Mouse::Clicked() {
	if (window->KeyPress(VK_LBUTTON)) {
		return true;
	}
	return false;
}

bool Mouse::Over(Object* obj) {
	Rect* aux = (Rect*)obj->BBox();
	bool eixoY = (Y() >= aux->Top() && Y() <= aux->Bottom());
	bool eixoX = (X() >= aux->Left() && X() <= aux->Right());

	return eixoX && eixoY;
}

void Mouse::Draw() {

}