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

    baseA = new Sprite("Resources/MainCharacter/Abilities/BasicAttack.png");
    knock = new Sprite("Resources/MainCharacter/Abilities/KnockBack.png");
    brang = new Sprite("Resources/MainCharacter/Abilities/Boomerang.png");
    speed = new Sprite("Resources/MainCharacter/Abilities/SpeedSpell.png");
    heal = new Sprite("Resources/MainCharacter/Abilities/Heal.png");
    cd = new Sprite("Resources/MainCharacter/Abilities/AbilityCD.png");

    abilities[0] = baseA;
    abilities[1] = speed;
    abilities[2] = knock;
    abilities[3] = brang;
    abilities[4] = heal;


}

// ------------------------------------------------------------------------------

Hud::~Hud()
{

    delete baseA;
    delete knock;
    delete brang;
    delete speed;
    delete heal;
    delete cd;
    delete fullHeart;
    delete halfHeart;
    delete emptyHeart;

}

// -------------------------------------------------------------------------------

void Hud::Update() {
    Health();
    Abilities();
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

void Hud::Abilities() {

    float auxX = 493.0f;

    if (Principal::player->attackCooldown <= 0.0f) {
        abilities[0] = baseA;
    }
    else {
        string aux = std::to_string((int)Principal::player->attackCooldown);
        abilities[0] = cd;
        TheGodsPuppet::arcade15->Draw(auxX, 600.0f, "" + aux, { 1.0f, 1.0f, 1.0f, 1.0f }, Layer::FRONT);
    }

    auxX += 70.0f;

    if (Principal::player->speedCooldown <= 0.0f) {
        abilities[1] = speed;
    }
    else {
        
        string aux = std::to_string((int)Principal::player->speedCooldown);
        abilities[1] = cd;
        TheGodsPuppet::arcade15->Draw(auxX,  600.0f, "" + aux, { 1.0f, 1.0f, 1.0f, 1.0f }, Layer::FRONT);

    }

    auxX += 70.0f;

    if (Principal::player->knockbackCooldown <= 0.0f) {
        abilities[2] = knock;
    }
    else {
        string aux = std::to_string((int)Principal::player->knockbackCooldown);
        abilities[2] = cd;
        TheGodsPuppet::arcade15->Draw(auxX, 600.0f, "" + aux, { 1.0f, 1.0f, 1.0f, 1.0f }, Layer::FRONT);
    }

    auxX += 70.0f;

    if (Principal::player->rangedCooldown <= 0.0f) {
        abilities[3] = brang;
    }
    else {
        string aux = std::to_string((int)Principal::player->rangedCooldown);
        abilities[3] = cd;
        TheGodsPuppet::arcade15->Draw(auxX, 600.0f, "" + aux, { 1.0f, 1.0f, 1.0f, 1.0f }, Layer::FRONT);
    }

    auxX += 70.0f;

    if (Principal::player->healCooldown <= 0.0f) {
       
        abilities[4] = heal;
    }else {
        string aux = std::to_string((int)Principal::player->healCooldown);
        abilities[4] = cd;
        TheGodsPuppet::arcade15->Draw(auxX, 600.0f, "" + aux, { 1.0f, 1.0f, 1.0f, 1.0f }, Layer::FRONT);
    }
}

// -------------------------------------------------------------------------------

void Hud::Draw()
{
    float auxX;

    auxX = 45.0f;

    //Corações
    for (int i = 0; i < 5; i++) {
        heart[i]->Draw(game->viewport.left + auxX, game->viewport.top + 25.0f, Layer::FRONT);
        auxX += 35.0f;
    }

    //Abilities

    auxX = 490.0f;

    for (int i = 0; i < 5; i++) {
        abilities[i]->Draw(game->viewport.left + auxX, game->viewport.bottom - 40.0f, Layer::UPPER);
        auxX += 70.0f;
    }
}