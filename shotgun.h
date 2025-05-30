#pragma once
#include "weapon.h"

//特別武器：shotgun
class Shotgun : public Weapon
{
public:
	//コンストラクタとデストラクタ
	Shotgun();
	Shotgun(const char* name);
	~Shotgun() override;

	//shotgunを装備する
	void Equip() override;
	//shotgunで攻撃する
	void Attack(int SystemTimeSeed) override;

private:
	//武器の名前
	const char* name_;
	int dexterity;
};
