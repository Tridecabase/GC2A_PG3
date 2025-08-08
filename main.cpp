#include <iostream>
#include <string>
#include <chrono>

using namespace std;

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// 右辺値参照を使って、1000000文字のstringのコピー
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

class HandleString {
public:
    std::string data;

    // 通常のコンストラクタ（文字列から）
    HandleString(const std::string& str) : data(str) {}

    // コピーコンストラクタ（明示的に定義）
    HandleString(const HandleString& right) : data(right.data) {}

    // ムーブコンストラクタ
    HandleString(HandleString&& right) noexcept {
        data = std::move(right.data);
    }

    // ムーブ代入演算子
    HandleString& operator=(HandleString&& right) noexcept {
        if (this != &right) {
            data = std::move(right.data);
        }
        return *this;
    }
};



int main(int argc, char const* argv[]) {
    // 100,000文字の文字列を用意
    std::string raw(100000, 'a');
    HandleString string1(raw);  // コピーコンストラクタを使用して初期化

    // 説明を表示
    std::cout << "100,000文字のstringの処理\n";

    // コピー処理の計測
    auto start_copy = std::chrono::high_resolution_clock::now();
    HandleString string2 = string1;  // コピー
    auto end_copy = std::chrono::high_resolution_clock::now();
    auto copy_us = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();

    // ムーブ処理の計測
    auto start_move = std::chrono::high_resolution_clock::now();
    HandleString t3 = std::move(string2);  // ムーブコンストラクタが呼ばれる
    auto end_move = std::chrono::high_resolution_clock::now();
    auto move_us = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();

    // 結果を表示
    std::cout << "コピー: " << copy_us << "μs\n";
    std::cout << "ムーブ: " << move_us << "μs\n";

    return 0;
}