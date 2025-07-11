#pragma once
#include "Novice.h"

enum Scene {
	TITLE,
	STAGE,
	CLEAR,
};

class IScene {
protected:
	static int sceneNum;
public:

	virtual ~IScene();
	// シーンの初期化
	virtual void Init() = 0;
	// シーンの更新
	virtual void Update(char* keys, char* preKeys) = 0;
	// シーンの描画
	virtual void Render();

	int GetSceneNum() const;
};