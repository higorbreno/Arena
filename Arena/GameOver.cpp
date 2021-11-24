#include "TheGodsPuppet.h"
#include "Principal.h"
#include "GameOver.h"
#include "Menu.h"

void GameOver::Init() {
	background = new Sprite("Resources/UI/Screens/GameOver.png");

	mouse = new Mouse();

	back = new Buttons(window->CenterX() - 150.0f, 480.0f, BACK);
	restart = new Buttons(window->CenterX() + 150.0f, 480.0f, RESTART);

	TheGodsPuppet::audio->Play(MENU, true);
}

void GameOver::Update() {

	//TOCAR O SOM CASO O MOUSE PASSE POR CIMA
	if (!back->MouseOver() && back->MouseOver(mouse->Over(back))) {
		TheGodsPuppet::audio->Play(BUTTONOVER);
	}

	if (!restart->MouseOver() && restart->MouseOver(mouse->Over(restart))) {
		TheGodsPuppet::audio->Play(BUTTONOVER);
	}

	back->MouseOver(mouse->Over(back));
	restart->MouseOver(mouse->Over(restart));

	//VERIFICAR SE O MOUSE ESTÁ CLICANDO EM ALGUM BOTÃO
	if (back->MouseOver() && mouse->Clicked()) {
		TheGodsPuppet::audio->Stop(MENU);
		TheGodsPuppet::NextLevel<Menu>();
	}
	else if(restart->MouseOver() && mouse->Clicked()) {
		TheGodsPuppet::audio->Stop(MENU);
		Principal::player->score = 0;
		TheGodsPuppet::NextLevel<Principal>();
	}
	else {
		mouse->Update();
		back->Update();
		restart->Update();
	}
}

void GameOver::Draw() {
	background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
	back->Draw();
	restart->Draw();
}

void GameOver::Finalize() {
	delete mouse;
	delete back;
	delete restart;
	delete background;
}
