#include "rectangle.h"

Rectangle::Rectangle(float width, float height)
{
	// 幅と高さを設定
	width_ = width;
	height_ = height;
	// 面積を初期化
	area = 0.0f;
}

Rectangle::~Rectangle()
{
	std::cout << "長方形を削除しました。" << std::endl;
}

void Rectangle::size()
{
	// 面積を計算
	area = static_cast<float>(width_ * height_);
}

void Rectangle::draw()
{
	// 面積を表示
	std::cout << "長方形の幅： " << width_ << ", 高さ： " << height_ << ", 面積： " << area << std::endl;
}
