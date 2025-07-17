#include "game_manager.h"
#include "player.h"

GameManager::GameManager()
{
	// Playerのインスタンスを作成
	player_ = std::make_unique<Player>();
	// Playerの初期化
	player_->Init();
}

GameManager::~GameManager() {}

int GameManager::Update(char* keys, char* preKeys){

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		// プレイヤーの更新
		player_->Update(keys, preKeys);

		// プレイヤーの描画
		player_->Render();


		Novice::EndFrame();
	}

	// ESCキーが押されたらループを抜ける
	if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
		return -1; // ゲーム終了
	}

	return 0;
}