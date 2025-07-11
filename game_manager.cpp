#include "game_manager.h"

GameManager::GameManager()
{
	// シーンのインスタンスを初期化
	sceneArray_[TITLE] = std::make_unique<TitleScene>();
	sceneArray_[STAGE] = std::make_unique<StageScene>();
	sceneArray_[CLEAR] = std::make_unique<ClearScene>();

	sceneNum_ = TITLE; // 初期シーンはタイトル
	currentSceneNum_ = sceneNum_;
}

GameManager::~GameManager() {}

int GameManager::Update(char* keys, char* preKeys){

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);


		// シーンのチェック
		prevSceneNum_ = currentSceneNum_;
		currentSceneNum_ = sceneArray_[currentSceneNum_]->GetSceneNum();

		if (prevSceneNum_ != currentSceneNum_) {
			sceneArray_[currentSceneNum_]->Init(); // シーンの初期化
		}
		// シーンの更新
		sceneArray_[currentSceneNum_]->Update(keys, preKeys);

		// シーンの描画
		sceneArray_[currentSceneNum_]->Render();

		Novice::EndFrame();
	}

	// ESCキーが押されたらループを抜ける
	if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
		return -1; // ゲーム終了
	}

	return 0;
}