#include "Principal.h"
#include "Buttons.h"

Buttons::Buttons(float posx, float posy, uint tipo) {

	if (tipo == ARROWL) {
		button = new Sprite("Resources/UI/Buttons/ArrowLeftUp.png");
		sobre = new Sprite("Resources/UI/Buttons/ArrowLeftDown.png");
		BBox(new Rect(-24, -24, 24, 24));
	}

	if (tipo == ARROWR) {
		button = new Sprite("Resources/UI/Buttons/ArrowRightUp.png");
		sobre = new Sprite("Resources/UI/Buttons/ArrowRightDown.png");
		BBox(new Rect(-24, -24, 24, 24));
	}

	if (tipo == BACK) {
		button = new Sprite("Resources/UI/Buttons/BackUp.png");
		sobre = new Sprite("Resources/UI/Buttons/BackDown.png");
		BBox(new Rect(-50, -30, 50, 30));
	}

	if (tipo == CONTINUE) {
		button = new Sprite("Resources/UI/Buttons/ContinueUp.png");
		sobre = new Sprite("Resources/UI/Buttons/ContinueDown.png");
		BBox(new Rect(-50, -30, 50, 30));
	}

	if (tipo == CONTROLS) {
		button = new Sprite("Resources/UI/Buttons/ControlsUp.png");
		sobre = new Sprite("Resources/UI/Buttons/ControlsDown.png");
		BBox(new Rect(-50, -30, 50, 30));
	}

	if (tipo == EFFECTS) {
		button = new Sprite("Resources/UI/Buttons/EffectsUp.png");
		sobre = new Sprite("Resources/UI/Buttons/EffectsDown.png");
		BBox(new Rect(-50, -30, 50, 30));
	}

	if (tipo == PLAY) {
		button = new Sprite("Resources/UI/Buttons/PlayUp.png");
		sobre = new Sprite("Resources/UI/Buttons/PlayDown.png");
		BBox(new Rect(-50, -30, 50, 30));
	}

	if (tipo == QUIT) {
		button = new Sprite("Resources/UI/Buttons/QuitUp.png");
		sobre = new Sprite("Resources/UI/Buttons/QuitDown.png");
		BBox(new Rect(-50, -30, 50, 30));
	}

	if (tipo == RESTART) {
		button = new Sprite("Resources/UI/Buttons/RestartUp.png");
		sobre = new Sprite("Resources/UI/Buttons/RestartDown.png");
		BBox(new Rect(-50, -30, 50, 30));
	}

	if (tipo == START) {
		button = new Sprite("Resources/UI/Buttons/StartUp.png");
		sobre = new Sprite("Resources/UI/Buttons/StartDown.png");
		BBox(new Rect(-50, -30, 50, 30));
	}

	atual = button;

	MoveTo(posx, posy);

}

Buttons::~Buttons() {
	delete button;
	delete sobre;
}

void Buttons::Update() {

	if (mouseOver) {
		atual = sobre;
	}
	else if (!mouseOver) {
		atual = button;
	}
}

void Buttons::Draw() {
	atual->Draw(x, y, Layer::FRONT);
}

bool Buttons::MouseOver(bool aux) {
	mouseOver = aux;
	return mouseOver;
}

bool Buttons::MouseOver() {
	return mouseOver;
}