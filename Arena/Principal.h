/**********************************************************************************
// Principal (Arquivo de Cabe�alho)
//
// Cria��o:     22 Out 2012
// Atualiza��o: 12 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Desenhando e movimentando um background formado por blocos
//
**********************************************************************************/

#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_

// ------------------------------------------------------------------------------

#include "Resources.h"              // recursos utilizados no jogo (cursor, �cone, etc.) 
#include "Game.h"                   // defini��o da classe jogo
#include "Controller.h"
#include "Scene.h"
#include "Player.h"
#include <sstream>                  // sa�da para strings
#include "Background.h"
#include "Hud.h"
using std::stringstream;    

// ------------------------------------------------------------------------------

enum ObjTypes { PLAYER, SLASH, BOOMERANG };

class Principal : public Game
{
private:
    Background* backg = nullptr;
    Hud* hud = nullptr;

public:
    static Player* player;
    static Scene* scene;
    static bool controllerOn;

    static uint xboxPlayer;          // controle Xbox ativo 
    static Controller* gamepad;     // controle de jogo
    void Init();                    // inicializa jogo
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

// ---------------------------------------------------------------------------------

#endif