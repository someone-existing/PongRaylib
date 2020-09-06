#pragma once
#include "public.h"

class Paddle
{
public:
	Vector2 pos;
	Vector2 size;
	Color color;
	int speed;
	void Reset();
	Paddle();
	void Draw();
	void Move();
};
