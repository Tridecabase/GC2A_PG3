#pragma once
#include "Novice.h"
#include <memory>
#include "Input.h"
#include "Player.h"
#include "StageScene.h"


class GameManager {
private:
	
	StageScene* stageScene_;

public:
	GameManager();
	~GameManager();

	int Update(char* keys, char* preKeys);
};