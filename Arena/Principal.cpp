/**********************************************************************************
// Principal (C?digo Fonte)
//
// Cria??o:     22 Out 2012
// Atualiza??o: 12 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri??o:   Desenhando e movimentando um background formado por blocos
//
**********************************************************************************/
#include "Principal.h"
#include "Player.h"
#include "Enemy.h"
#include "Random.h"
#include "GameOver.h"
#include "TheGodsPuppet.h"
#include <fstream>
using std::ifstream;

// ------------------------------------------------------------------------------

Player* Principal::player = nullptr;
Scene* Principal::scene = nullptr;
bool Principal::controllerOn = false;
Controller* Principal::gamepad = nullptr;

void Principal::Init()
{
    game->Size(3200, 3200);
    gamepad = new Controller();

    controllerOn = gamepad->Initialize();

    scene = new Scene();

    backg = new Background("Resources/Map.png");

    player = new Player();
    scene->Add(player, MOVING);

    hud = new Hud();
    scene->Add(hud, STATIC);

    float difx = (game->Width() - window->Width()) / 2.0f;
    float dify = (game->Height() - window->Height()) / 2.0f;

    viewport.left = difx;
    viewport.right = difx + window->Width();
    viewport.top = dify;
    viewport.bottom = dify + window->Height();

    player->MoveTo(viewport.left + window->CenterX(), viewport.top);
    TheGodsPuppet::audio->Play(BOSSAREA, true);
}

// ------------------------------------------------------------------------------

void Principal::Update()
{
    if (Enemy::count <= 0) {
        RandI r1(0, 4);
        RandI r(0, 1);
        RandF r2(-1600, -800);
        RandF r3(800, 1600);

        lastWave += int(player->score * 0.1f);

        for (int i = 0; i < lastWave; ++i) {
            Enemy* enemy = new Enemy(EnemyType(r1.Rand()), (r.Rand()) ? r2.Rand() : r3.Rand(), (r.Rand()) ? r2.Rand() : r3.Rand());
            scene->Add(enemy, MOVING);
        }
    }

    // sai com o pressionamento da tecla ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    viewport.left = player->X() - window->CenterX();
    viewport.right = player->X() + window->CenterX();
    viewport.top = player->Y() - window->CenterY();
    viewport.bottom = player->Y() + window->CenterY();

    if (viewport.left < 0) {
        viewport.left = 0;
        viewport.right = window->Width();
    }
    if (viewport.top < 0) {
        viewport.top = 0;
        viewport.bottom = window->Height();
    }
    if (viewport.right > game->Width()) {
        viewport.right = game->Width();
        viewport.left = game->Width() - window->Width();
    }
    if (viewport.bottom > game->Height()) {
        viewport.bottom = game->Height();
        viewport.top = game->Height() - window->Height();
    }

    scene->Update();
    scene->CollisionDetection();

    if (player->health <= 0) {
        TheGodsPuppet::audio->Stop(BOSSAREA);
        TheGodsPuppet::NextLevel<GameOver>();
    }
} 

// ------------------------------------------------------------------------------

void Principal::Draw()
{
    backg->Draw(viewport);

    scene->Draw();
    //scene->DrawBBox();
} 

// ------------------------------------------------------------------------------

void Principal::Finalize()
{
    delete scene;
    delete gamepad;
    delete backg;
}

