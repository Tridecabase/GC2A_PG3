#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// 学生番号を読み込み、ソートして表示する
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

int main(int argc, char const* argv[]) {

	// 学生番号を格納するための配列
	vector<string> students;
	// 学生番号を読み込むファイル
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "students.txt", "r");
	if (err != 0 || fp == nullptr) {
		cerr << "fail to open file\r\n";
		return 1;
	}
	// 学生番号の読み込み
	char buf[256];
	while (fscanf_s(fp, " \"%255[^\"]\"%*[,] ", buf, (unsigned)sizeof(buf)) == 1){
		if (buf[0] == '\0') {
			continue;
		}
		students.push_back(buf);
	}

    fclose(fp);


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
		cout << student << string(10, ' ') << "\033[31m" << sorted_student << "\033[0m" << "\r\n";
	}

	// 学生の総数
	cout << "\r\n学生の総数: " << max_count << "\r\n";

	return 0;
}