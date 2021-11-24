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

    Sprite* fullHeart = nullptr;
    Sprite* halfHeart = nullptr;
    Sprite* emptyHeart = nullptr;
    Sprite* heart[5];

public:
    Hud();                              // construtor
    ~Hud();                             // destrutor

    void Update();                      // atualização
    void Draw();                        // desenho

    void Health();

};


#endif
