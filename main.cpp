#include <stdio.h>
#include <thread>

using namespace std;

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// threadで並行処理、THREAD1とTHREAD2とTHREAD3を文字に出力する
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

void PrintThread1() {
	printf("THREAD1\n");
}

void PrintThread2() {
	printf("THREAD2\n");
}

void PrintThread3() {
	printf("THREAD3\n");
}

int main(int argc, char const* argv[]) {

	std::thread thread1(PrintThread1);
	thread1.join();
	std::thread thread2(PrintThread2);
	thread2.join();
	std::thread thread3(PrintThread3);
	thread3.join();

	return 0;
}