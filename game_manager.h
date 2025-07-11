#pragma once
#include "Novice.h"
#include <memory>
#include "IScene.h"
#include "title_scene.h"
#include "stage_scene.h"
#include "clear_scene.h"
#include "Input.h"

class GameManager {
private:
	// シーンのインスタンスを保持する配列
	std::unique_ptr<IScene> sceneArray_[3];
	// 現在のシーン番号と前のシーン番号
	int currentSceneNum_;
	// 前のシーン番号を保持する変数
	int prevSceneNum_;
	// シーン番号を保持する変数
	int sceneNum_;

public:
	GameManager();
	~GameManager();

	int Update(char* keys, char* preKeys);
};