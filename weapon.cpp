#include "weapon.h"

//コンストラクタ
Weapon::Weapon()
{
	dexterity = 50;
}

//デストラクタ
Weapon::~Weapon()
{
}

void Weapon::Equip()
{
	//武器装備成功
	printf("Weapon is equiped!\n");
}

void Weapon::Attack(int SystemTimeSeed)
{
	//命中判断
	if (SystemTimeSeed >= dexterity) {
		printf("Enemy is damaged!\n");
	}
	else {
		printf("miss!\n");
	}
}
