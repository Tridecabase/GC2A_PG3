#include "StageScene.h"

StageScene::StageScene()
{
}

void StageScene::Init()
{
	// ステージの初期化
	inputHandler_ = new InputHandler;

	// 入力ハンドラーにコマンドを割り当てる
	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	inputHandler_->AssignMoveRightCommand2PressKeyD();

	// プレイヤーの初期化
	player_ = new Player;
}

void StageScene::Update()
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
	player_->Update();
}

void StageScene::Render()
{
// プレイヤーの描画
	player_->Render();
}
