#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <string>
#include <regex>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// csvを読み込む、threadでマップチップを表示する
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

int main(int argc, char const* argv[]) {

	// マップチップのデータを格納するベクター
	vector<string> mapData;
	// マップデータへのアクセスを保護するミューテックス
	mutex mutex;
	// 条件変数
	condition_variable condition;
	// キューを使用して読み込んだ行を保持
	queue<string> mapchip;
	// 読み込み完了フラグ
	bool exit = false;
	// ファイルポインタ
	FILE* fp = nullptr;

	// ファイルを開く
    std::thread th1([&mapData, fp, &mutex, &condition, &mapchip, &exit]() {
		ifstream file("map.csv");
		if (!file.is_open()) {
			cerr << "Failed to open file." << endl;
			condition.notify_all();
			return;
		}

		string line;
		while (getline(file, line)) {
			this_thread::sleep_for(chrono::milliseconds(100));

			{
				unique_lock<std::mutex> lock(mutex);
				mapchip.push(line);
			}
			condition.notify_all();

			if (exit) {
				fclose(fp); // ファイルを閉じる
				break;
			}
		}

		{
			unique_lock<std::mutex> lock(mutex);
			exit = true;
		}
		condition.notify_all();
    });

	std::thread th2([&mapData, &mutex, &condition, &exit, &mapchip]() {
		while (true) {
			unique_lock<std::mutex> lock(mutex);
            condition.wait(lock, [&mapchip, &exit] { return !mapchip.empty() || exit; });

			while (!mapchip.empty()) {
				cout << mapchip.front() << endl;
				mapchip.pop();
			}

			if (mapchip.empty()) {
				exit = true; // 読み込み完了フラグを設定
				condition.notify_all(); // 条件変数を通知
				break;
			}
		}
	});

	// メインループ
	while (true)
	{
		// マップチップを読み込む
		thread th1([&mapchip, &condition]() {
			condition.notify_all(); // 条件変数を通知
		});

		// マップチップを表示
		thread th2([&mapchip, &condition]() {
			condition.notify_all(); // 条件変数を通知
		});

		// スレッドの終了を待機
		th1.join();
		th2.join();
	}

	exit = true; // 読み込み完了フラグを設定

	return 0;
}