#include "IScene.h"

int IScene::sceneNum = TITLE;

IScene::~IScene() {

}

void IScene::Render()
{
	Novice::ScreenPrintf(10, 10, "Scene Number: %d", sceneNum);
	Novice::ScreenPrintf(10, 30, "Scene Name: %s",
		sceneNum == TITLE ? "Title" :
		sceneNum == STAGE ? "Stage" :
		sceneNum == CLEAR ? "Clear" : "Unknown");
}

int IScene::GetSceneNum() const {
	return sceneNum;
}