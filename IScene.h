#pragma once
#include "Novice.h"

class IScene {
protected:

public:

	virtual ~IScene();
	// シーンの初期化
	virtual void Init() = 0;
	// シーンの更新
	virtual void Update() = 0;
	// シーンの描画
	virtual void Render() = 0;
};