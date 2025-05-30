#pragma once
#include"weapon.h"
#include<stdio.h>

//子クラス：剣
class Sword : public Weapon
{
public:
	//コンストラクタとデストラクタ
	Sword();
	~Sword() override;

	//剣を装備する
	void Equip() override;
	//剣で攻撃する
	void Attack(int SystemTimeSeed) override;

private:
	int dexterity;
};