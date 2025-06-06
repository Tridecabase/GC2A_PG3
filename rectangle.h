#pragma once

#include "iShape.h"

class Rectangle : public IShape
{
public:
	// コンストラクタとデストラクタ
	Rectangle(float width, float height);
	~Rectangle();

	// サイズを計算するメソッド
	void size() override;
	// サイズを表示するメソッド
	void draw() override;

private:
	float width_;  // 幅
	float height_; // 高さ
	float area;    // 面積
};
