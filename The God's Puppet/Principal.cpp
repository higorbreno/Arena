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

#include "Engine.h"
#include "Principal.h"
#include "Player.h"

// ------------------------------------------------------------------------------

Scene* Principal::scene = nullptr;
bool Principal::controllerOn = false;
Controller* Principal::gamepad = nullptr;
uint Principal::xboxPlayer = PLAYER1;


void Principal::Init()
{
    gamepad = new Controller();

    controllerOn = gamepad->Initialize();

    scene = new Scene();

    Player* player = new Player();
    scene->Add(player, MOVING);
}

// ------------------------------------------------------------------------------

void Principal::Update()
{
    // sai com o pressionamento da tecla ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    scene->Update();
    scene->CollisionDetection();
} 

// ------------------------------------------------------------------------------

void Principal::Draw()
{
    scene->Draw();
    scene->DrawBBox();
} 

// ------------------------------------------------------------------------------

void Principal::Finalize()
{
    delete scene;
    delete gamepad;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                     _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(1280, 640);
    engine->window->Color(0, 0, 0);
    engine->window->Title("The Gods' Puppet");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);

    // inicia o jogo
    engine->Start(new Principal());

    delete engine;
    return 0;
}

// ----------------------------------------------------------------------------

