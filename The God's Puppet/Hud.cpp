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

    stamina = new Sprite("Resources/UI/Stamina/Stamina.png");
    staminaEmpty = new Sprite("Resources/UI/Stamina/StaminaEmpty.png");

    for (int i = 0; i < 20; i++) {
        staminas[i] = stamina;
    }

    staminaBar = new Sprite("Resources/UI/Stamina/StaminaBar.png");

    miniMap = new Sprite("Resources/UI/MiniMap.png");
    point = new Sprite("Resources/UI/Point.png");
}

// ------------------------------------------------------------------------------

Hud::~Hud()
{
    delete miniMap;
    delete point;
    delete staminaBar;
    delete stamina;
    delete staminaEmpty;
    delete fullHeart;
    delete halfHeart;
    delete emptyHeart;

}

// -------------------------------------------------------------------------------

void Hud::Update() {

}

// -------------------------------------------------------------------------------

void Hud::Health() {

    for (int i = 0; i < 5; i++) {
        heart[i] = emptyHeart;
    }

    //Principal::player->health;
    int aux = 10 / 5;

    for (int i = 0; i < aux; i++) {
        heart[i] = fullHeart;
    }

    if (10 - aux * 2 == 1){
        heart[aux + 1] = halfHeart;
    }
   
}

// -------------------------------------------------------------------------------

void Hud::Stamina() {
    for (int i = 0; i < 20; i++) {
        staminas[i] = staminaEmpty;
    }

    //Principal::player->stamina;
    int aux = 10 / 5;

    for (int i = 0; i < aux; i++) {
        staminas[i] = stamina;
    }
}

// -------------------------------------------------------------------------------

void Hud::MoveMiniMap() {
    float auxX = Principal::player->X();
    float auxY = Principal::player->Y();

    point->Draw(game->viewport.right - auxX/192.0f, game->viewport.bottom - auxY/132.0f, Layer::FRONT);
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

    //StaminaBar


    staminaBar->Draw(game->viewport.left + 115.0f, game->viewport.top + 55.0f, Layer::FRONT);

    auxX = 20.0f;
    for (int i = 0; i < 20; i++) {
        staminas[i]->Draw(game->viewport.left + auxX, 55.0f, Layer::UPPER);
        auxX += 10.0f;
    }

    //MiniMap

    miniMap->Draw(game->viewport.right - 192.0f, game->viewport.bottom - 128.0f, Layer::FRONT);
    point->Draw(game->viewport.right - 192.0f, game->viewport.bottom - 132.0f, Layer::FRONT);

}