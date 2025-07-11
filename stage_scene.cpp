#include "stage_scene.h"

void StageScene::Init() {
	// 敵のインスタンスを生成	
	enemy = std::make_unique<Enemy>();
	// 敵の初期化
	enemy->Init();
	//　フェーズの初期化
	phase = 0;
	// フェーズの時間を管理する変数
	phaseTime = 0.0f;
}

void StageScene::Update(char* keys, char* preKeys)
{
	// 敵の更新処理
	enemy->Update(phase);

	// 敵のフェーズを管理する
	phaseTime += 1.0f / 60.0f;
	if (phaseTime > 2.0f) {
		phaseTime = 0.0f;
		phase++;
		// フェーズが3を超えたらリセット
		if (phase > 2) {
			phase = 0;
			// 敵の位置をリセット
			enemy->SetPos({ -50.0f, -50.0f });
		}
	}


	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneNum = CLEAR; // ステージクリア後にクリアシーンへ遷移
	}
}

void StageScene::Render()
{// 敵の描画
	enemy->Render();
	// ステージの情報を表示
	Novice::ScreenPrintf(10, 10, "Stage Scene");
	Novice::ScreenPrintf(10, 30, "Press SPACE to clear the stage");
}
