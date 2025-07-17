#include "InputHandler.h"

// 左移動コマンドをAキーに割り当てる
void InputHandler::AssignMoveLeftCommand2PressKeyA()
{
	ICommand* command = new MoveLeftCommand();
	this->pressKeyA_ = command;
}

// 右移動コマンドをDキーに割り当てる
void InputHandler::AssignMoveRightCommand2PressKeyD()
{
	ICommand* command = new MoveRightCommand();
	this->pressKeyD_ = command;
}

// 入力を処理し、対応するコマンドを返す
ICommand* InputHandler::HandleInput()
{

	if (Novice::CheckHitKey(DIK_D))
	{
		return pressKeyD_;
	}
	if (Novice::CheckHitKey(DIK_A))
	{
		return pressKeyA_;
	}

    return nullptr;
}
