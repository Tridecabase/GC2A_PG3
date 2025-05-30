#include "shotgun.h"

//デフォルトコンストラクタ
Shotgun::Shotgun()
{
	name_ = NULL;
	dexterity = 30;
	printf("shotgun get!\n");
}

//コンストラクタ
Shotgun::Shotgun(const char* name)
{
	//名前と命中率を代入する
	name_ = name;
	dexterity = 50;
	printf("shotgun <%s> get!\n", name_);
}

//デストラクタ
Shotgun::~Shotgun()
{
	printf("shotgun <%s> is destroyed!\n", name_);
	name_ = NULL;
}

void Shotgun::Equip()
{
	//shotgunを装備する
	printf("Shotgun %s is equiped!\n", name_);
}

void Shotgun::Attack(int SystemTimeSeed)
{
	//命中判断
	printf("Enemy is Attacked by shotgun %s!\n",name_);
	if (SystemTimeSeed >= dexterity) {
		printf("Enemy is damaged!\n");
	}
	else {
		printf("miss!\n");
	}
}
