#include "stage_scene.h"

void StageScene::Init() {
	
}

void StageScene::Update(char* keys, char* preKeys)
{
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneNum = CLEAR; // ステージクリア後にクリアシーンへ遷移
	}
}
