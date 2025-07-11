#pragma once

#include "Novice.h"
#include "IScene.h"
#include "enemy.h"

class StageScene : public IScene
{
public:
	// シーンの初期化
	void Init() override;
	// シーンの更新
	void Update(char* keys, char* preKeys)override;
	// シーンの描画
	void Render() override;

private:
	Enemy* enemy; // 敵のインスタンス
	// 敵のフェーズを管理する変数
	size_t phase;
	float phaseTime;
};