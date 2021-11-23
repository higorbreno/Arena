#include "Engine.h"
#include "TheGodsPuppet.h"
#include "Principal.h"
#include "Menu.h"

void Menu::Init() {
	//background = new Sprite("Resources/UI/Menu.png");

	mouse = new Mouse();
	play = new Buttons(window->CenterX(), 320.0f, PLAY);
	controls = new Buttons(window->CenterX(), 380.0f, CONTROLS);
	effects = new Buttons(window->CenterX(), 440.0f, EFFECTS);
	quit = new Buttons(window->CenterX(), 500.0f, QUIT);
}

void Menu::Update() {
	
	//TOCAR O SOM CASO O MOUSE PASSE POR CIMA
	if (!play->MouseOver() && play->MouseOver(mouse->Over(play))) {
		TheGodsPuppet::audio->Play(BUTTONOVER);
	}

	if (!controls->MouseOver() && controls->MouseOver(mouse->Over(controls))) {
		TheGodsPuppet::audio->Play(BUTTONOVER);
	}

	if (!effects->MouseOver() && effects->MouseOver(mouse->Over(effects))) {
		TheGodsPuppet::audio->Play(BUTTONOVER);
	}

	if (!quit->MouseOver() && quit->MouseOver(mouse->Over(quit))) {
		TheGodsPuppet::audio->Play(BUTTONOVER);
	}

	//VERFICAR SE O MOUSE TA EM CIMA
	play->MouseOver(mouse->Over(play));

	controls->MouseOver(mouse->Over(controls));

	effects->MouseOver(mouse->Over(effects));

	quit->MouseOver(mouse->Over(quit));

	//VERIFICAR SE O MOUSE ESTÁ CLICANDO EM ALGUM BOTÃO
	if (play->MouseOver() && mouse->Clicked()) {
		TheGodsPuppet::NextLevel<Principal>();
	} else if (controls->MouseOver() && mouse->Clicked()) {
		//TheGodsPuppet::NextLevel<Principal>();
	}
	else if (effects->MouseOver() && mouse->Clicked()) {
		//TheGodsPuppet::NextLevel<Principal>();
	}
	else if (quit->MouseOver() && mouse->Clicked()) {
		window->Close();
	}
	else {
		mouse->Update();
		play->Update();
		controls->Update();
		effects->Update();
		quit->Update();
	}
}

void Menu::Draw() {

	play->Draw();
	controls->Draw();
	effects->Draw();
	quit->Draw();
	/*Engine::renderer->BeginPixels();

	ulong magenta = (255 << 24) + (255 << 16) + (0 << 8) + 255;

	
	Engine::renderer->Draw(mouse->BBox(), magenta);
	


	Engine::renderer->EndPixels();*/
}

void Menu::Finalize() {
	delete mouse;
	delete play;
	delete animacao;
	delete tileset;
	delete background;
}


