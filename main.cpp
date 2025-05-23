#include <Novice.h>
#include "enemy.h"

const char kWindowTitle[] = "GC2B_05_ジョ_シセイ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// 敵のインスタンスを生成
	Enemy* enemy = new Enemy;
	// 敵の初期化
	enemy->Init();
	//　フェーズの初期化
	size_t phase = 0;
	// フェーズの時間を管理する変数
	float phaseTime = 0.0f;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

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

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		enemy->Render();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			// 敵のインスタンスを解放
			delete enemy;
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
