#pragma once
#include "public.h"
#include "paddle.h"

class Ball
{
public:
	Vector2 pos, speed;
	void Reset();
	Ball();
	int radius;
	void Draw();
	void Update();
	void Collide(Paddle left, Paddle right);
};
