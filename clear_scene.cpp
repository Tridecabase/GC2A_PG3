#include "clear_scene.h"

void ClearScene::Init()
{
}

void ClearScene::Update(char* keys, char* preKeys)
{
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneNum = TITLE; // クリア後にタイトルシーンへ戻る
	}
}

