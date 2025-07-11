#include "title_scene.h"

void TitleScene::Init()
{
}

void TitleScene::Update(char* keys, char* preKeys)
{
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneNum = STAGE;
	}

}
