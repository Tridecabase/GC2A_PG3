#pragma once

#include "Novice.h"
#include "Vector2.h"

class Player {
private:
	// プレイヤーの位置、速度
	Vector2 pos_;
	Vector2 speed_;
	float radius_;

public:
	Player();
	~Player();
	// 初期化
	void Init();
	// 更新
	void Update(char* keys, char* preKeys);
	// 描画
	void Render();

	// プレイヤーの移動メソッド
	void MoveRight();
	void MoveLeft();
};
