#include "ball.h"
void Ball::Reset()
{
	pos.x = screenWidth/2;
	pos.y = screenHeight/2;
	speed = {10, 5};
	radius = 8;
}
Ball::Ball()
{
	Reset();
}
void Ball::Draw()
{
	DrawCircleV(pos, radius, DARKGRAY);
}
void Ball::Update()
{
	//CHANGE POSITION BY SPEED
	pos.x += speed.x;
	pos.y += speed.y;
	//GRADUALLY INCREASE THE BALL'S SPEED
	speed.x = speed.x * 1.0001;
	speed.y = speed.y * 1.0001;
}
void Ball::Collide(Paddle left, Paddle right)
{
	//TOP AND BOTTOM COLLISION
	if(pos.y >= screenHeight || pos.y <= 0) {
		speed.y = speed.y * -1;
	}
	//PADDLE COLLISION
	if((pos.x >= screenWidth - right.size.x*2 && (pos.y > right.pos.y && pos.y < right.pos.y + right.size.y)) || (pos.x <= left.size.x*2 && (pos.y > left.pos.y && pos.y < left.pos.y + left.size.y))) {
		speed.x = speed.x * -1;
	}
}
