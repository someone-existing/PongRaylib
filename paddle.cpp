#include "paddle.h"
void Paddle::Reset()
{
	size.x = 10;
	size.y = 100;
	pos.y = screenHeight/2 - size.y/2;
	speed = 15;
}
Paddle::Paddle()
{
	Reset();
}
void Paddle::Draw()
{
	DrawRectangleV(pos, size, color);
}

void Paddle::Move()
{
	if(pos.x > screenWidth/2) {
		//RIGHT PADDLE
		if(IsKeyDown(KEY_UP) && pos.y > 0) {
			pos.y -= speed;
		}
		if(IsKeyDown(KEY_DOWN) && pos.y+size.y < screenHeight) {
			pos.y += speed;
		}
	} else {
		//LEFT PADDLE
		if(IsKeyDown(KEY_W) && pos.y > 0) {
			pos.y -= speed;
		}
		if(IsKeyDown(KEY_S) && pos.y+size.y < screenHeight) {
			pos.y += speed;
		}
	}
}
