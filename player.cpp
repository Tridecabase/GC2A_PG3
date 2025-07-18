#include "player.h"

Player::Player(){
	Init();
}

Player::~Player() {}

void Player::Init() {
	
	// プレイヤーの初期化処理
	this->pos_ = { 640.0f, 360.0f };	// 初期位置を画面中央に設定
	this->speed_ = { 2.0f, 2.0f };		// 移動速度を設定	
	this->radius_ = 10.0f;				// 半径を設定
}

void Player::Update() {

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