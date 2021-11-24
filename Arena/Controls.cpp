#include "TheGodsPuppet.h"
#include "Controls.h"
#include "Menu.h"

void Controls::Init() {
	background = new Sprite("Resources/UI/Screens/Controls.png");

	mouse = new Mouse();
	back = new Buttons(100.0f, 600.0f, BACK);
}

void Controls::Update() {

	//TOCAR O SOM CASO O MOUSE PASSE POR CIMA
	if (!back->MouseOver() && back->MouseOver(mouse->Over(back))) {
		TheGodsPuppet::audio->Play(BUTTONOVER);
	}

	back->MouseOver(mouse->Over(back));

	//VERIFICAR SE O MOUSE ESTÁ CLICANDO EM ALGUM BOTÃO
	if (back->MouseOver() && mouse->Clicked()) {
		TheGodsPuppet::NextLevel<Menu>();
	}
	else {
		mouse->Update();
		back->Update();
	}
}

void Controls::Draw() {
	background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
	back->Draw();
}

void Controls::Finalize() {
	delete mouse;
	delete back;
	delete background;
}

