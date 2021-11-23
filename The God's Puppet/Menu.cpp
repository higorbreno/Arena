#include "Engine.h"
#include "TheGodsPuppet.h"
#include "Principal.h"
#include "Menu.h"

void Menu::Init() {
	//background = new Sprite("Resources/UI/Menu.png");

	mouse = new Mouse();
	play = new Buttons(window->CenterX(), 320.0F, PLAY);
}

void Menu::Update() {
	
	if (!play->MouseOver() && play->MouseOver(mouse->Over(play))) {

	}

	play->MouseOver(mouse->Over(play));

	if (play->MouseOver() && mouse->Clicked()) {
		TheGodsPuppet::NextLevel<Principal>();
	}
	else {
		mouse->Update();
		play->Update();
	}
}

void Menu::Draw() {

	play->Draw();
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


