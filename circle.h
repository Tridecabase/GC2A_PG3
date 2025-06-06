#pragma once

#include "iShape.h"

class Circle : public IShape
{
public:
	Circle(float radius);
	~Circle();

	// サイズを計算するメソッド
	void size() override;
	// サイズを表示するメソッド
	void draw() override;

private:
	float radius_; // 半径
	float area;   // 面積

};
