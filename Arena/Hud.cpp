#include "Hud.h"
#include "Principal.h"
#include "TheGodsPuppet.h"

Hud::Hud()
{
    fullHeart = new Sprite("Resources/UI/Heart/FullHeart.png");
    halfHeart = new Sprite("Resources/UI/Heart/HalfHeart.png");
    emptyHeart = new Sprite("Resources/UI/Heart/EmptyHeart.png");

    for (int i = 0; i < 5; i++) {
        heart[i] = fullHeart;
    }
}

// ------------------------------------------------------------------------------

Hud::~Hud()
{
    delete fullHeart;
    delete halfHeart;
    delete emptyHeart;

}

// -------------------------------------------------------------------------------

void Hud::Update() {
    Health();
}

// -------------------------------------------------------------------------------

void Hud::Health() {

    for (int i = 0; i < 5; i++) {
        heart[i] = emptyHeart;
    }

    int aux = Principal::player->health / 2;

    for (int i = 0; i < aux; i++) {
        heart[i] = fullHeart;
    }

    if (Principal::player->health - aux * 2 == 1){
        heart[aux] = halfHeart;
    }
   
}

// -------------------------------------------------------------------------------

void Hud::Draw()
{
    float auxX, auxY;

    auxX = 45.0f;

    //Corações
    for (int i = 0; i < 5; i++) {
        heart[i]->Draw(game->viewport.left + auxX, game->viewport.top + 25.0f, Layer::FRONT);
        auxX += 35.0f;
    }
}