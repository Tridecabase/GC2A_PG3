#include<stdio.h>
#include<iostream>
#include"iShape.h"
#include"circle.h"
#include"rectangle.h"

int main() {

	// Circleとのインスタンスを生成
	IShape* shape1 = new Circle(5.0f);
	// サイズを計算
	shape1->size();
	// サイズを表示
	shape1->draw();
	// Rectangleとのインスタンスを生成
	IShape* shape2 = new Rectangle(4.0f, 6.0f);
	// サイズを計算
	shape2->size();
	// サイズを表示
	shape2->draw();
	// メモリを解放
	delete shape1;
	delete shape2;

return 0;
}