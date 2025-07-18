#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
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

	// CSVからマップデータを読み込むスレッド
	std::thread RecordMapDataFromCsv([&mapData, fp, &mutex, &condition, &mapchip, &exit]() {
		while (!exit) {
			// ファイルを開く
			ifstream file("map.csv");
			if (!file.is_open()) {
				cerr << "Failed to open file." << endl;
				unique_lock<std::mutex> lock(mutex);
				exit = true;
				condition.notify_all();
				return;
			}

			// ファイルから1行ずつ読み込み、キューに追加
			string line;
			while (getline(file, line)) {
				this_thread::sleep_for(chrono::milliseconds(200));

				{
					unique_lock<std::mutex> lock(mutex);
					mapchip.push(line);
				}
				condition.notify_all();
			}
			// ファイルを閉じる
			file.close();
			// 読み込みが完了したらexitフラグを立てる
			{
				unique_lock<std::mutex> lock(mutex);
				exit = true;
			}
			condition.notify_all();
		}
	});

	// メーンループ
	while (true)
	{
		// 条件変数を使用して、mapchipが空でないか、exitフラグが立っているまで待機
		unique_lock<std::mutex> lock(mutex);
		condition.wait(lock, [&mapchip, &exit] { return !mapchip.empty() || exit; });
		if (!mapchip.empty()) {
            // "1"を赤、"0"をグレーで表示する
            cout << "MAP::";
            for (char c : mapchip.front()) {
				if (c == '1') {
					cout << "\033[31;1m" << c << "\033[0m";
				}
				else if(c == '0') {
					cout << "\033[30;1m" << c << "\033[0m";
                } else {
                    cout << c;
                }
            }
            cout << endl;
			mapchip.pop();
			condition.notify_all();
		}
		// exitフラグが立っていて、mapchipが空ならループを抜ける
		if (exit && mapchip.empty()) {
			break;
		}
	}

	// スレッドの終了を待機
	RecordMapDataFromCsv.join();

	return 0;
}