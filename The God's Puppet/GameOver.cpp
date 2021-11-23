#include "TheGodsPuppet.h"
#include "Principal.h"
#include "GameOver.h"
#include "Menu.h"

void GameOver::Init() {
	background = new Sprite("Resources/UI/Screens/GameOver.png");

	mouse = new Mouse();
	restart = new Buttons(window->CenterX(), 480.0f, RESTART);
	back = new Buttons(window->CenterX() - 150.0f, 480.0f, BACK);
	continuar = new Buttons(window->CenterX() + 150.0f, 480.0f, CONTINUE);
}

void GameOver::Update() {

	//TOCAR O SOM CASO O MOUSE PASSE POR CIMA
	if (!back->MouseOver() && back->MouseOver(mouse->Over(back))) {
		TheGodsPuppet::audio->Play(BUTTONOVER);
	}

	if (!continuar->MouseOver() && continuar->MouseOver(mouse->Over(continuar))) {
		TheGodsPuppet::audio->Play(BUTTONOVER);
	}

	if (!restart->MouseOver() && restart->MouseOver(mouse->Over(restart))) {
		TheGodsPuppet::audio->Play(BUTTONOVER);
	}

	back->MouseOver(mouse->Over(back));
	restart->MouseOver(mouse->Over(restart));
	continuar->MouseOver(mouse->Over(continuar));

	//VERIFICAR SE O MOUSE ESTÁ CLICANDO EM ALGUM BOTÃO
	if (back->MouseOver() && mouse->Clicked()) {
		TheGodsPuppet::NextLevel<Menu>();
	}
	else if(restart->MouseOver() && mouse->Clicked()) {
		//TheGodsPuppet::NextLevel<Menu>();
	}
	else if (continuar->MouseOver() && mouse->Clicked()) {
		//TheGodsPuppet::NextLevel<Menu>();
	}
	else {
		mouse->Update();
		back->Update();
		continuar->Update();
		restart->Update();
	}
}

void GameOver::Draw() {
	background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
	back->Draw();
	restart->Draw();
	continuar->Draw();
}

void GameOver::Finalize() {
	delete mouse;
	delete back;
	delete restart;
	delete continuar;
	delete background;
}
