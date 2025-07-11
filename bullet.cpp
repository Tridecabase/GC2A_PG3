#include "bullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::Init(Vector2 enemyPos)
{
	this->bulletData.pos = { enemyPos.x, enemyPos.y };
	this->bulletData.velocity = { 0.0f, 5.0f };
	this->bulletData.radius = 20.0f;
	this->bulletData.angle = 0.0f;
	this->bulletData.color = RED;
	this->bulletData.isActive = true;
}

void Bullet::Update()
{
	// 弾の移動
	if (this->bulletData.isActive) {
		this->bulletData.pos.x += this->bulletData.velocity.x;
		this->bulletData.pos.y += this->bulletData.velocity.y;
		bulletData.angle += 0.1f; // 弾の回転
	}
	else {
		this->bulletData.pos.x = -50.0f;
		this->bulletData.pos.y = -50.0f;
	}

	// 画面外に出たら非アクティブにする
	if (this->bulletData.pos.x > 1280.0f + bulletData.radius || this->bulletData.pos.y > 720.0f + bulletData.radius) {
		this->bulletData.isActive = false;
	}
}

void Bullet::Render()
{
	if (this->bulletData.isActive) {
		Novice::DrawEllipse(
			static_cast<int>(this->bulletData.pos.x),
			static_cast<int>(this->bulletData.pos.y),
			static_cast<int>(this->bulletData.radius),
			static_cast<int>(this->bulletData.radius / 2),
			this->bulletData.angle,
			this->bulletData.color,
			kFillModeSolid);
	}
}
