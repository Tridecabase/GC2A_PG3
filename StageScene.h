#pragma once

#include "Novice.h"
#include "IScene.h"
#include "ICommand.h"
#include "player.h"
#include "InputHandler.h"


class StageScene : public IScene {
private:
	InputHandler* inputHandler_;
	Player* player_;
	ICommand* iCommand_;

public:
	StageScene();
	//~StageScene();

	// ステージの初期化
	void Init() override;
	// ステージの更新
	void Update(char* keys, char* preKeys) override;
	// ステージの描画
	void Render() override;
};