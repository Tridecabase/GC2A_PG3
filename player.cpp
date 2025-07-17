#include "player.h"

Player::Player(){

}

Player::~Player() {}

void Player::Init() {
	
	this->pos_ = { 640.0f, 360.0f };
	this->speed_ = { 2.0f, 2.0f };
	this->radius_ = 10.0f;
}

void Player::Update(char* keys, char* preKeys) {
	// プレイヤーの更新処理
	if (keys[DIK_D] || preKeys[DIK_D]) {
		MoveRight();
	}
	if (keys[DIK_A] || preKeys[DIK_A]) {
		MoveLeft();
	}
}

void Player::Render() {
	Novice::DrawBox(
		static_cast<int>(this->pos_.x - this->radius_),
		static_cast<int>(this->pos_.y - this->radius_),
		static_cast<int>(this->radius_ * 2),
		static_cast<int>(this->radius_ * 2),
		0.0f,
		0xFFFFFFFF,
		kFillModeSolid
	);
}

void Player::MoveRight()
{
	this->pos_.x += this->speed_.x;
}

void Player::MoveLeft()
{
	this->pos_.x -= this->speed_.x;
}