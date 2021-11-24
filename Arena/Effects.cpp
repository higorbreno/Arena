#include "TheGodsPuppet.h"
#include "Effects.h"
#include "Menu.h"

void Effects::Init() {
	backgrounds[0] = new Sprite("Resources/UI/Screens/Effects/Effects0.png");
	backgrounds[1] = new Sprite("Resources/UI/Screens/Effects/Effects1.png");
	backgrounds[2] = new Sprite("Resources/UI/Screens/Effects/Effects2.png");
	backgrounds[3] = new Sprite("Resources/UI/Screens/Effects/Effects3.png");
	backgrounds[4] = new Sprite("Resources/UI/Screens/Effects/Effects4.png");
	backgrounds[5] = new Sprite("Resources/UI/Screens/Effects/Effects5.png");

	background = backgrounds[0];

	mouse = new Mouse();
	back = new Buttons(100.0f, 600.0f, BACK);
	arrowR = new Buttons(953.0f, window->CenterY() - 50.0f, ARROWR);
	arrowL = new Buttons(315.0f, window->CenterY() - 50.0f, ARROWL);

}

void Effects::Update() {

	//TOCAR O SOM CASO O MOUSE PASSE POR CIMA
	if (!back->MouseOver() && back->MouseOver(mouse->Over(back))) {
		TheGodsPuppet::audio->Play(BUTTONOVER);
	}

	if (!arrowR->MouseOver() && back->MouseOver(mouse->Over(arrowR))) {
		TheGodsPuppet::audio->Play(BUTTONOVER);
	}

	if (!arrowL->MouseOver() && arrowL->MouseOver(mouse->Over(arrowL))) {
		TheGodsPuppet::audio->Play(BUTTONOVER);
	}

	back->MouseOver(mouse->Over(back));
	arrowR->MouseOver(mouse->Over(arrowR));
	arrowL->MouseOver(mouse->Over(arrowL));

	if (arrowR->MouseOver() && mouse->Clicked()) {
		if (contagem != 5) {
			contagem++;
		}
		else {
			contagem = 0;
		}
		
	}

	if (arrowL->MouseOver() && mouse->Clicked()) {
		if (contagem != 0) {
			contagem--;
		}
		else {
			contagem = 5;
		}

	}

	//VERIFICAR SE O MOUSE ESTÁ CLICANDO EM ALGUM BOTÃO
	if (back->MouseOver() && mouse->Clicked()) {
		TheGodsPuppet::NextLevel<Menu>();
	}
	else {
		background = backgrounds[contagem];
		mouse->Update();
		back->Update();
		arrowR->Update();
		arrowL->Update();
	}
}

void Effects::Draw() {
	background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
	back->Draw();
	arrowR->Draw();
	arrowL->Draw();
}

void Effects::Finalize() {
	delete mouse;
	delete back;
	delete arrowR;
	delete arrowL;

	for (int i = 0; i < 6; i++) {
		delete backgrounds[i];
	}
	

}

