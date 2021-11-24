#ifndef HUD_H
#define HUD_H

#include "Object.h"
#include "Sprite.h"
#include "Font.h"
#include <sstream>
using std::stringstream;

class Hud : public Object
{
private:

    Sprite* staminaBar = nullptr;         // �rea de informa��es do jogo
    Sprite* stamina = nullptr;
    Sprite* staminaEmpty = nullptr;
    Sprite* staminas[20];
    Sprite* fullHeart = nullptr;
    Sprite* halfHeart = nullptr;
    Sprite* emptyHeart = nullptr;
    Sprite* heart[5];
    Sprite* miniMap = nullptr;          // �rea para teclas de comando
    Sprite* point = nullptr;

    int heartDmg = 4;

public:
    Hud();                              // construtor
    ~Hud();                             // destrutor

    void Update();                      // atualiza��o
    void Draw();                        // desenho

    void Health();
    void Stamina();
    void MoveMiniMap(); 

};


#endif
