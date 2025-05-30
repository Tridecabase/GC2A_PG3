#pragma once
#include <stdio.h>

// 基底クラス：武器
class Weapon
{
public:
	//コンストラクタとデストラクタ
	Weapon();
	virtual ~Weapon();

	//武器を装備する
	virtual void Equip();
	//武器で攻撃する(命中乱数)
	virtual void Attack(int SystemTimeSeed);

private:
	// 命中率
	int dexterity;
};
