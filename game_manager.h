#pragma once
#include "Novice.h"
#include <memory>
#include "Input.h"
#include "Player.h"

class GameManager {
private:
	std::unique_ptr<Player> player_;

public:
	GameManager();
	~GameManager();

	int Update(char* keys, char* preKeys);
};