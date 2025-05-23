#pragma once

#include "Novice.h"
#include "Vector2.h"
#include "bullet.h"

typedef struct EnemyData
{
	Vector2 pos;
	Vector2 velocity;
	Vector2 acceleration;
	float radius;
	unsigned int color;
} EnemyData;

class Enemy
{
public:
	Enemy();
	~Enemy();
	
	void Init();
	void Update(size_t phase);
	void Render();

	void GetInFunc();
	void AttackFunc();
	void GetOutFunc();

	Vector2 GetPos() const { return enemyData.pos; }
	VOID SetPos(Vector2 pos) { enemyData.pos = pos; }

private:
	static void (Enemy::* actionFuncTable[])();
	EnemyData enemyData;
	size_t phase_ = 0;
	Bullet* bullet;
	bool isFiring = false;
};