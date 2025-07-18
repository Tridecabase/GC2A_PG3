#include "ICommand.h"
#include "Player.h"

ICommand::~ICommand()
{

}

// 右に移動するコマンド
void MoveRightCommand::Exec(Player& player)
{
	player.MoveRight();
}

// 左に移動するコマンド
void MoveLeftCommand::Exec(Player& player)
{
	player.MoveLeft();
}
