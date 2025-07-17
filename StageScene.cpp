#include "StageScene.h"

void StageScene::Init()
{
	inputHandler_ = new InputHandler;

	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	inputHandler_->AssignMoveRightCommand2PressKeyD();

	player_ = new Player;
}

void StageScene::Update(char* keys, char* preKeys)
{
	// 入力を処理し、対応するコマンドを取得
	iCommand_ = inputHandler_->HandleInput();

	if (this->iCommand_) {
		// コマンドが存在する場合、プレイヤーに実行させる
		iCommand_->Exec(*player_);
	}
	// コマンドが存在する場合、プレイヤーに実行させる
	if (iCommand_) {
		iCommand_->Exec(*player_);
	}
	// プレイヤーの更新
	player_->Update(keys, preKeys);
}
