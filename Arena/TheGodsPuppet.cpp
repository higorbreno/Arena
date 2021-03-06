#include "Engine.h"
#include "TheGodsPuppet.h"
#include "Menu.h"

Audio* TheGodsPuppet::audio = nullptr;
Audio* TheGodsPuppet::inimigosAudio = nullptr;
bool TheGodsPuppet::viewBBox = false;
Game* TheGodsPuppet::level = nullptr;
Font* TheGodsPuppet::arcade15 = nullptr;
Font* TheGodsPuppet::arcade30 = nullptr;
Font* TheGodsPuppet::arcade55 = nullptr;

void TheGodsPuppet::Init() {
	audio = new Audio();
    inimigosAudio = new Audio();

	audio->Add(BUTTONOVER, "Resources/Sounds/ButtonDown.wav");
    audio->Add(MENU, "Resources/Sounds/Menu.wav");
    audio->Add(BOSSAREA, "Resources/Sounds/Areas/BossArea.wav");
    audio->Add(BASICATTACK, "Resources/Sounds/Abilities/BasicAttack.wav");
    audio->Add(BRANG, "Resources/Sounds/Abilities/Boomerang.wav", 10);
    audio->Add(KBACK, "Resources/Sounds/Abilities/KnockBack.wav");
    audio->Add(HEAL, "Resources/Sounds/Abilities/Heal.wav");
    audio->Add(SPEED, "Resources/Sounds/Abilities/SpeedSpell.wav");

    inimigosAudio->Add(DEMON1, "Resources/Sounds/Enemies/Demon/Demon1.wav");
    inimigosAudio->Add(DEMON2, "Resources/Sounds/Enemies/Demon/Demon2.wav");
    inimigosAudio->Add(DEMON3, "Resources/Sounds/Enemies/Demon/Demon3.wav");
    inimigosAudio->Add(GHOST1, "Resources/Sounds/Enemies/Ghost/Ghost1.wav");
    inimigosAudio->Add(GHOST2, "Resources/Sounds/Enemies/Ghost/Ghost2.wav");
    inimigosAudio->Add(GOBLIN1, "Resources/Sounds/Enemies/Goblin/Goblin1.wav");
    inimigosAudio->Add(GOBLIN2, "Resources/Sounds/Enemies/Goblin/Goblin2.wav");
    inimigosAudio->Add(GOBLIN3, "Resources/Sounds/Enemies/Goblin/Goblin3.wav");
    inimigosAudio->Add(GOBLIN4, "Resources/Sounds/Enemies/Goblin/Goblin4.wav");
    inimigosAudio->Add(GOBLIN5, "Resources/Sounds/Enemies/Goblin/Goblin5.wav");
    inimigosAudio->Add(ZOMBIE1, "Resources/Sounds/Enemies/Zombie/Zombie1.wav");
    inimigosAudio->Add(ZOMBIE2, "Resources/Sounds/Enemies/Zombie/Zombie2.wav");
    inimigosAudio->Add(ZOMBIE3, "Resources/Sounds/Enemies/Zombie/Zombie3.wav");
    inimigosAudio->Add(DEMONATTACK, "Resources/Sounds/Enemies/DemonAttack.wav", 20);
    inimigosAudio->Add(ICEZOMBIEATTACK, "Resources/Sounds/Enemies/IceZombieAttack.wav", 20);
    inimigosAudio->Add(MELEEATTACK, "Resources/Sounds/Enemies/MeleeAttack.wav");

    arcade15 = new Font("Resources/Fonts/Arcade15.png");
    arcade15->Spacing("Resources/Fonts/Arcade15.dat");

    arcade30 = new Font("Resources/Fonts/Arcade30.png");
    arcade30->Spacing("Resources/Fonts/Arcade30.dat");

    arcade55 = new Font("Resources/Fonts/Arcade55.png");
    arcade55->Spacing("Resources/Fonts/Arcade55.dat");

	viewBBox = false;
	level = new Menu();
	level->Init();
}

void TheGodsPuppet::Update() {
	level->Update();
    viewport = level->viewport;
}

void TheGodsPuppet::Draw() {
	level->Draw();
}

void TheGodsPuppet::Finalize() {
	level->Finalize();
	delete level;
    delete audio;
    delete inimigosAudio;
    delete arcade15;
    delete arcade30;
    delete arcade55;

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

    game->Size(8960, 5760);

    // inicia o jogo
    engine->Start(game);

    delete engine;
    return 0;
}

// ----------------------------------------------------------------------------

