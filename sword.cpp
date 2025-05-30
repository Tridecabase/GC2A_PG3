#include "sword.h"
//コンストラクタ
Sword::Sword()
{
	dexterity = 80;
	printf("Weapon get: sword\n");
}

//デストラクタ
Sword::~Sword()
{
	printf("sword is destroyed!\n");
}

void Sword::Equip()
{
	//剣装備成功
	printf("Sword is equiped!\n");
}

void Sword::Attack(int SystemTimeSeed)
{
	//命中判断
	printf("Enemy is Attacked by sword\n");
	if (SystemTimeSeed >= dexterity) {
		printf("Enemy is damaged!\n");
	}
	else {
		printf("miss!\n");
	}
}
