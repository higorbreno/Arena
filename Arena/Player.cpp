#include "Player.h"
#include "Principal.h"
#include "Slash.h"

int Player::score = 0;

void Player::Attack()
{
	if (attackCooldown <= 0.0f) {
		Slash* slash = new Slash(x, y, pointerVector->Angle(), 7);
		Principal::scene->Add(slash, STATIC);

		attackCooldown = ATTACK_COOLDOWN;
	}
}

void Player::Speed()
{
	if (speedCooldown <= 0.0f) {
		isSpeed = true;

		speedCooldown = SPEED_COOLDOWN;
	}
}

void Player::KnockBack()
{
	if (knockbackCooldown <= 0.0f) {
		Slash* slash = new Slash(x, y, pointerVector->Angle());
		Principal::scene->Add(slash, STATIC);
		slash = new Slash(x, y, pointerVector->Angle() + 45);
		Principal::scene->Add(slash, STATIC);
		slash = new Slash(x, y, pointerVector->Angle() + 90);
		Principal::scene->Add(slash, STATIC);
		slash = new Slash(x, y, pointerVector->Angle() + 135);
		Principal::scene->Add(slash, STATIC);
		slash = new Slash(x, y, pointerVector->Angle() + 180);
		Principal::scene->Add(slash, STATIC);
		slash = new Slash(x, y, pointerVector->Angle() + 225);
		Principal::scene->Add(slash, STATIC);
		slash = new Slash(x, y, pointerVector->Angle() + 270);
		Principal::scene->Add(slash, STATIC);
		slash = new Slash(x, y, pointerVector->Angle() + 315);
		Principal::scene->Add(slash, STATIC);

		knockbackCooldown = KNOCKBACK_COOLDOWN;
	}
}

void Player::RangedAbility()
{
	if (rangedCooldown <= 0.0f && !hasReleased) {
		pointerVector->Rotate(10);
		Boomerang* b = new Boomerang(pointerVector);
		Principal::scene->Add(b, MOVING);
		boomerangs.push_back(b);
		pointerVector->Rotate(-20);
		b = new Boomerang(pointerVector);
		Principal::scene->Add(b, MOVING);
		boomerangs.push_back(b);
		pointerVector->Rotate(10);
		b = new Boomerang(pointerVector);
		Principal::scene->Add(b, MOVING);
		boomerangs.push_back(b);

		hasReleased = true;
		rangedCooldown = RANGED_COOLDOWN;
	}
	else if (hasReleased && rangedCooldown <= RANGED_COOLDOWN - 1.0f) {
		if (!boomerangs.empty()) {
			for (Boomerang* b : boomerangs) {
				b->ComeBack();
			}
			boomerangs.clear();
		}
		hasReleased = false;
	}
}

void Player::Heal()
{
	if (healCooldown <= 0.0f && health < MaxHealth) {
		health += 3;
		if (health > MaxHealth)
			health = MaxHealth;

		healCooldown = HEAL_COOLDOWN;
	}
}

Player::Player()
{
	hasReleased = false;

	horizontalL = 0.0f;
	horizontalM = 0.0f;
	verticalL = 0.0f;
	verticalM = 0.0f;

	pointer = new Sprite("Resources/Sword.png");
	speed = new Vector();
	pointerVector = new Vector();

	ts[0] = new TileSet("Resources/MainCharacter/NinjaFrog/Run-Right.png", 32, 32, 11, 11);
	as[0] = new Animation(ts[0], 0.1f, true);
	ts[1] = new TileSet("Resources/MainCharacter/NinjaFrog/Run-Left.png", 32, 32, 11, 11);
	as[1] = new Animation(ts[1], 0.1f, true);

	atual = as[0];

	BBox(new Rect(-32.0f, -32.0f, 32.0f, 32.0f));
	type = PLAYER;

	MoveTo(200.0f, 200.0f);
}

Player::~Player()
{
	delete ts[0];
	delete as[0];
	delete ts[1];
	delete as[1];
	delete pointer;
	delete speed;
	delete pointerVector;
}

void Player::Update()
{
	color = { 1,1,1,1 };
	horizontalM = 0.0f;
	verticalM = 0.0f;

	if (attackCooldown > 0.0f)
		attackCooldown -= gameTime;
	if (speedCooldown > 0.0f)
		speedCooldown -= gameTime;
	if (rangedCooldown > 0.0f)
		rangedCooldown -= gameTime;
	if (knockbackCooldown > 0.0f)
		knockbackCooldown -= gameTime;
	if (healCooldown > 0.0f)
		healCooldown -= gameTime;

	if (weakCooldown > 0.0f)
		weakCooldown -= gameTime;
	if (burnCooldown > 0.0f)
		burnCooldown -= gameTime;
	if (slowCooldown > 0.0f)
		slowCooldown -= gameTime;
	if (dmgCooldown > 0.0f)
		dmgCooldown -= gameTime;

	if (Principal::controllerOn) {
		Principal::gamepad->UpdateState();
		horizontalM = Principal::gamepad->Axis(AxisX);
		verticalM = Principal::gamepad->Axis(AxisY);
		if(Principal::gamepad->Axis(AxisRX))
			horizontalL = Principal::gamepad->Axis(AxisRX);
		if(Principal::gamepad->Axis(AxisRY))
			verticalL = Principal::gamepad->Axis(AxisRY);

		pointerVector->setXY(horizontalL, verticalL);

		if (Principal::gamepad->Axis(AxisZ) < 0)
			Attack();
		if (Principal::gamepad->ButtonPress(5))
			Speed();
		if (Principal::gamepad->Axis(AxisZ) > 0)
			RangedAbility();
		if (Principal::gamepad->ButtonPress(4))
			KnockBack();
		if (Principal::gamepad->ButtonPress(3))
			Heal();
	}
	else {
		if (window->KeyDown('W'))
			verticalM = -1.0f;
		if (window->KeyDown('S'))
			verticalM = 1.0f;
		if (window->KeyDown('D'))
			horizontalM = 1.0f;
		if (window->KeyDown('A'))
			horizontalM = -1.0f;

		pointerVector->setXY(game->viewport.left + window->MouseX() - x,game->viewport.top + window->MouseY() - y);

		if (window->KeyPress(VK_LBUTTON))
			Attack();
		if (window->KeyPress(VK_SHIFT))
			Speed();
		if (window->KeyPress('Q'))
			RangedAbility();
		if (window->KeyPress('E'))
			KnockBack();
		if (window->KeyPress('F'))
			Heal();
	}

	pointerVector->Rotate(60.0f);

	speed->setXY(horizontalM, verticalM);
	if(horizontalM || verticalM)
		speed->ScaleTo(300.0f);

	if (slowCooldown > 0.0f) {
		speed->Scale(0.75f);
		color.b = 10;
	}

	if (burnCooldown > 0.0f && burnCooldown < 1.5f && !hasBurnFirst) {
		health--;
		hasBurnFirst = true;
	}
	else if (burnCooldown <= 0.0f && hasBurnFirst) {
		health--;
		hasBurnFirst = false;
	}

	if (isSpeed) {
		speed->Scale(2);
		if (speedCooldown < SPEED_COOLDOWN - 1.0f)
			isSpeed = false;
	}

	Translate(speed->X() * gameTime, speed->Y() * gameTime);

	if (horizontalM < 0) {
		atual = as[1];
	}

	if (horizontalM > 0) {
		atual = as[0];
	}

	atual->NextFrame();

	if (x < 64)
		MoveTo(64, y);
	if (x > game->Width() - 64)
		MoveTo(game->Width() - 64, y);
	if (y < 80)
		MoveTo(x, 80);
	if (y > game->Height() - 200)
		MoveTo(x, game->Height() - 200);
}

void Player::OnCollision(Object* obj)
{
	
}

void Player::Draw()
{
	atual->Draw(x, y, Layer::MIDDLE, scale, rotation, color);
	pointer->Draw(x, y, 
		(pointerVector->Angle() >= 180 && pointerVector->Angle() < 360) ? Layer::LOWER : Layer::MIDDLE, 
		scale, pointerVector->Angle(), 
		Color(1, 1, 1, 1));
}
