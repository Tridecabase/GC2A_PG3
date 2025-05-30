#include<stdio.h>
#include<iostream>
#include<time.h>
#include"weapon.h"
#include"shotgun.h"
#include"sword.h"

int main() {

	//乱数シード
	srand(time(NULL));

	//武器の生成
	Weapon* weapons[3];

	for (int i = 0; i < 3; i++)
	{
		if (i < 1) {
			weapons[i] = new Shotgun("Manhunter");
		}
		else {
			weapons[i] = new Sword();
		}
	}

	for (int i = 0; i < 3; i++)
	{
		weapons[i]->Equip();
        int seed = rand() % 100 + 1;
		weapons[i]->Attack(seed);
	}

	for (int i = 0; i < 3; i++)
	{
		delete weapons[i];
	}

return 0;
}