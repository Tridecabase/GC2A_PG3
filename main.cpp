#include <Novice.h>
#include "game_manager.h"

const char kWindowTitle[] = "GC2B_05_ジョ_シセイ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	GameManager* gameManager = new GameManager;

	// ゲームループ
	gameManager->Update(keys, preKeys);

	// ライブラリの終了
	delete gameManager; // GameManagerのインスタンスを削除
	Novice::Finalize();
	return 0;
}
