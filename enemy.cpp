#include "enemy.h"
#include <cmath>

Enemy::Enemy()
{
	// 弾丸の初期化
	bullet = new Bullet;
	Init();
}

Enemy::~Enemy()
{
	delete bullet;
}

// 敵のアクション関数テーブル
void (Enemy::*Enemy::actionFuncTable[])() = {
	&Enemy::GetInFunc,
	&Enemy::AttackFunc,
	&Enemy::GetOutFunc
};

// 敵の初期化
void Enemy::Init()
{
	this->enemyData.pos = { -50.0f, -50.0f };
	this->enemyData.velocity = { 0.0f, 0.0f };
	this->enemyData.acceleration = { 0.0f, 0.0f };
	this->enemyData.radius = 30.0f;
	this->enemyData.color = RED;
	isFiring = false;
}

// 敵の更新
void Enemy::Update(size_t phase)
{
	// 敵のフェーズを管理する
	phase_ = phase;

	// 敵のアクション関数を呼び出す
	if (phase < sizeof(actionFuncTable) / sizeof(actionFuncTable[0])) {
		(this->*actionFuncTable[phase_])();
	}
	else {
		return;
	}

	bullet->Update();
}

// 敵の描画
void Enemy::Render()
{
	// 弾丸の描画
	bullet->Render();
	Novice::DrawEllipse(
		static_cast<int>(this->enemyData.pos.x),
		static_cast<int>(this->enemyData.pos.y),
		static_cast<int>(this->enemyData.radius),
		static_cast<int>(this->enemyData.radius),
		0.0f,
		this->enemyData.color,
		kFillModeSolid);
}

// 敵の接近関数
void Enemy::GetInFunc()
{
	// 目標座標
	const Vector2 target = { 640.0f, 360.0f };
	// 目標座標に向かう力を計算
	const float damping = 0.95f;
	// 目標座標に向かう力の強さ
	const float attractStrength = 0.5f;

	// 目標座標に向かうベクトルを計算
	Vector2 toTarget = { target.x - this->enemyData.pos.x, target.y - this->enemyData.pos.y };
	this->enemyData.acceleration.x = attractStrength * toTarget.x / (std::abs(toTarget.x) + 1.0f);
	this->enemyData.acceleration.y = attractStrength * toTarget.y / (std::abs(toTarget.y) + 1.0f);

	// 速度を更新
	this->enemyData.velocity.x = (this->enemyData.velocity.x + this->enemyData.acceleration.x) * damping;
	this->enemyData.velocity.y = (this->enemyData.velocity.y + this->enemyData.acceleration.y) * damping;

	// 位置を更新
	this->enemyData.pos.x += this->enemyData.velocity.x;
	this->enemyData.pos.y += this->enemyData.velocity.y;

	if (std::abs(this->enemyData.pos.x - target.x) < 10.0f && std::abs(this->enemyData.pos.y - target.y) < 10.0f) {
		this->enemyData.pos = target;
	}
}

// 敵の攻撃関数
void Enemy::AttackFunc()
{
	if(!isFiring){
		bullet->Init(this->enemyData.pos);
		isFiring = true;
	}
	if (bullet->GetPos().y > 720.0f + 20.0f) {
		isFiring = false;
	}
}

//　 敵の退却関数
void Enemy::GetOutFunc()
{
	isFiring = false;
	// 目標座標
	const Vector2 target = { 1320.0f, -50.0f };
	// 目標座標に向かう力を計算
	const float damping = 0.95f;
	// 目標座標に向かう力の強さ
	const float attractStrength = 0.5f;
	// 目標座標に向かうベクトルを計算
	Vector2 toTarget = { target.x - this->enemyData.pos.x, target.y - this->enemyData.pos.y };
	// 目標座標に向かう力を計算
	this->enemyData.acceleration.x = attractStrength * toTarget.x / (std::abs(toTarget.x) + 1.0f);
	this->enemyData.acceleration.y = attractStrength * toTarget.y / (std::abs(toTarget.y) + 1.0f);

	// 速度を更新
	this->enemyData.velocity.x = (this->enemyData.velocity.x + this->enemyData.acceleration.x) * damping;
	this->enemyData.velocity.y = (this->enemyData.velocity.y + this->enemyData.acceleration.y) * damping;

	// 位置を更新
	this->enemyData.pos.x += this->enemyData.velocity.x;
	this->enemyData.pos.y += this->enemyData.velocity.y;

	if (std::abs(this->enemyData.pos.x - target.x) < 10.0f && std::abs(this->enemyData.pos.y - target.y) < 10.0f) {
		this->enemyData.pos = target;
	}
}
