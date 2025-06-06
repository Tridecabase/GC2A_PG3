#pragma once
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>

class IShape
{
public:
	// コンストラクタとデストラクタ
	IShape() = default;
	~IShape() = default;

	// サイズを計算するメソッド
	virtual void size() = 0;
	// サイズを表示するメソッド
	virtual void draw() = 0;

private:

};
