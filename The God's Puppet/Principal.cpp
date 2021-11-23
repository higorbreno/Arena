/**********************************************************************************
// Principal (Código Fonte)
//
// Criação:     22 Out 2012
// Atualização: 12 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Desenhando e movimentando um background formado por blocos
//
**********************************************************************************/
#include "Principal.h"
#include "Editor.h"
#include "Player.h"

// ------------------------------------------------------------------------------

Player* Principal::player = nullptr;
Scene* Principal::scene = nullptr;
bool Principal::controllerOn = false;
Controller* Principal::gamepad = nullptr;

void Principal::Init()
{
    game->Size(8960, 5760);
    gamepad = new Controller();

    controllerOn = gamepad->Initialize();

    scene = new Scene();

    player = new Player();
    scene->Add(player, MOVING);

    backg = new Background("Resources/Map.png");

    float difx = (game->Width() - window->Width()) / 2.0f;
    float dify = (game->Height() - window->Height()) / 2.0f;

    viewport.left = difx;
    viewport.right = difx + window->Width();
    viewport.top = dify;
    viewport.bottom = dify + window->Height();

    player->MoveTo(viewport.left + window->CenterX(), viewport.top + 190);
}

// ------------------------------------------------------------------------------

void Principal::Update()
{
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
} 

// ------------------------------------------------------------------------------

void Principal::Draw()
{
    backg->Draw(viewport);

    scene->Draw();
    scene->DrawBBox();
} 

// ------------------------------------------------------------------------------

void Principal::Finalize()
{
    delete scene;
    delete gamepad;
}

