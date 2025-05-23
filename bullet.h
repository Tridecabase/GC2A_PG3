#pragma once
#include "Novice.h"
#include "Vector2.h"

typedef struct BulletData
{
	Vector2 pos;
	Vector2 velocity;
	float radius;
	float angle;
	unsigned int color;
	bool isActive;
} BulletData;

class Bullet
{
public:
	Bullet();
	~Bullet();

	void Init(Vector2 enemyPos);
	void Update();
	void Render();

	bool IsActive() const { return bulletData.isActive; }
	void SetActive(bool active) { bulletData.isActive = active; }

	Vector2 GetPos() const { return bulletData.pos; }
	void SetPos(Vector2 pos) { bulletData.pos = pos; }

private:
	BulletData bulletData;
};