#include<stdio.h>
#include<iostream>
#include<array>
#include<functional>
#include<vector>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

//　gotoマクロ　xとy
#define GOTO(x, y) goto __LINE__##x##y

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// 学生番号を読み込み、ソートして表示する
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

int main(int argc, char const *argv[]) {

	// 学生番号を格納するための配列
	vector<string> students;
	// 学生番号を読み込むファイル
	string line;
	ifstream file("students.txt");
	// 学生番号を抽出する
	if (file.is_open()) {
		while (getline(file, line)) {
			regex re("\"([^\"]*)\"");
			auto words_begin = sregex_iterator(line.begin(), line.end(), re);
			auto words_end = sregex_iterator();
			// 各学生番号を抽出してstudentsに追加
			for (auto it = words_begin; it != words_end; ++it) {
				string student = (*it)[1].str();
				student.erase(0, student.find_first_not_of(" \t\n\r"));
				student.erase(student.find_last_not_of(" \t\n\r") + 1);
				if (!student.empty()) {
					students.push_back(student);
				}
			}
		}
		file.close();
	}
	else {
		cout << "Unable to open file";
		return 1;
	}

	cout << "元の学生番号" << string(20, ' ') << "ソート後の学生番号" << "\r\n";
	// 学生番号の最大数
	size_t max_count = students.size();
	// ソート後の学生番号を格納するための配列
	vector<string> sorted_students = students;
	// 学生番号をソート
	sort(sorted_students.begin(), sorted_students.end());

	// 学生番号を表示（左：元、右：ソート後）
	for (size_t i = 0; i < max_count; ++i) {
		string student = students[i];
		string sorted_student = sorted_students[i];
		cout << student << string(10, ' ') << sorted_student << "\r\n";
	}

	// 学生の総数
	cout << "\r\n学生の総数: " << max_count << "\r\n";

	return 0;
}