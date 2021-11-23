#include "Engine.h"
#include "TheGodsPuppet.h"
#include "Menu.h"

Audio* TheGodsPuppet::audio = nullptr;
bool TheGodsPuppet::viewBBox = false;
Game* TheGodsPuppet::level = nullptr;

void TheGodsPuppet::Init() {
	audio = new Audio();
	//audio->Add(GAMESTART, "Resources/Sounds/Menu.wav");

	viewBBox = false;
	level = new Menu();
	level->Init();
}

void TheGodsPuppet::Update() {
	level->Update();
}

void TheGodsPuppet::Draw() {
	level->Draw();
}

void TheGodsPuppet::Finalize() {
	level->Finalize();
	delete level;

}

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine* engine = new Engine();

    // configura motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(1280, 640);
    engine->window->Color(0, 0, 0);
    engine->window->Title("The Gods' Puppet");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);

    Game* game = new TheGodsPuppet();

    //game->Size(8960, 5760);

    // inicia o jogo
    engine->Start(game);

    delete engine;
    return 0;
}

// ----------------------------------------------------------------------------

