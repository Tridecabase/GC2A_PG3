#include<stdio.h>
#include<iostream>
#include<list>
using namespace std;

int main() {

	// 70年代山手線の駅名をリストに格納
	list <const char*> eki_list{
		"Tokyo", "Kanda", "Akihabara", "Okachimachi", 
		"Ueno", "Uguisudani", "Nippori", "Tabata", 
		"Komagome", "Sugamo", "Otsuka", "Ikebukuro", 
		"Mejiro", "Takadanobaba", "Sin-Okubo", "Shinjuku", 
		"Yoyogi", "Harajuku", "Shibuya", "Ebisu", 
		"Meguro", "Gotanda", "Osaki", "Sinagawa",
		"Tamachi", "Hamamatsucho", "Shimbashi", "Yurakucho"
	};

	// リストの要素を順に出力
	cout << "1970年山手線の駅名リスト:" << endl;
	for (auto eki : eki_list) {
		cout << eki << endl;
	}

	// 西日暮里駅を田端と日暮里の間に挿入
	auto it = find(eki_list.begin(), eki_list.end(), "Tabata");
	if (it != eki_list.end()) {
		eki_list.insert(it, "Nishi-Nippori");
	}

	// リストの要素を順に出力
	cout << "\n2019年山手線の駅名リスト:" << endl;
	for (auto eki : eki_list) {
		if (eki == "Nishi-Nippori") {
			// 西日暮里駅を青色で表示
			cout << "\033[34m" << eki << "\033[0m" << endl;
		}
		else {
			cout << eki << endl;
		}
	}

	// 高輪ゲートウェイ駅を田町と品川の間に挿入
	eki_list.insert(find(eki_list.begin(), eki_list.end(), "Tamachi"), "Takanawa Gateway");

	// リストの要素を順に出力
	cout << "\n2021年山手線の駅名リスト:" << endl;
	for (auto eki : eki_list) {
		if (eki == "Takanawa Gateway") {
			// 高輪ゲートウェイ駅を青色で表示
			cout << "\033[34m" << eki << "\033[0m" << endl;
		}
		else {
			cout << eki << endl;
		}
	}

return 0;
}