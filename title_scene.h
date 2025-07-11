#pragma once

#include "Novice.h"
#include "IScene.h"

class TitleScene : public IScene
{
public:
	// シーンの初期化
	void Init() override;
	// シーンの更新
	void Update(char* keys, char* preKeys) override;
};
