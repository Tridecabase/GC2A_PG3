#define _USE_MATH_DEFINES
#include "circle.h"

Circle::Circle(float radius)
{
	// 半径を設定
	radius_ = radius;
	// 面積を初期化
	area = 0.0f;
}

Circle::~Circle()
{
	std::cout << "円を削除しました。" << std::endl;
}

void Circle::size()
{
	// 面積を計算
	area = static_cast<float>(M_PI * radius_ * radius_);
}

void Circle::draw()
{
	// 面積を表示
	std::cout << "円の半径： " << radius_ << ", 円の面積： " << area << std::endl;
}
