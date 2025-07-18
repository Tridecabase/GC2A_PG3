#include "game_manager.h"
#include "player.h"

GameManager::GameManager()
{
	// ステージシーンの初期化
	stageScene_ = new StageScene();
	stageScene_->Init();
}

GameManager::~GameManager() {}

int GameManager::Update(char* keys, char* preKeys){

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		// ステージシーンの更新
		stageScene_->Update();

		// ステージシーンの描画
		stageScene_->Render();


		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			delete stageScene_;
			stageScene_ = nullptr;
			return 1; // ゲームを終了する
		}

	}

	return 0;
}