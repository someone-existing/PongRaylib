#include "public.h"
#include "ball.h"
#include "paddle.h"
#include "score.h"

int main(int argc, char* argv[])
{
	SetConfigFlags(FLAG_VSYNC_HINT);
	//SetConfigFlags(FLAG_WINDOW_UNDECORATED);
	InitWindow(screenWidth, screenHeight, "Pong");
	SetTargetFPS(60);

	Ball ball;
	Paddle leftPaddle;
	Paddle rightPaddle;
	Score leftScore;
	Score rightScore;
	//SET PADDLE POSITIONS AND COLORS
	leftPaddle.pos.x = 0+leftPaddle.size.x;
	leftPaddle.color = RED;
	rightPaddle.pos.x = screenWidth-rightPaddle.size.x*2;
	rightPaddle.color = BLUE;

	//SET SCORE COUNTER POSITIONS
	leftScore.pos.x = screenWidth/4;
	rightScore.pos.x = screenWidth - screenWidth/4;

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(RAYWHITE);

		leftScore.Draw();
		rightScore.Draw();

		ball.Draw();
		ball.Update();
		ball.Collide(leftPaddle, rightPaddle);

		//IF BALL GOES OFF SCREEN TO THE RIGHT SIDE
		if(ball.pos.x > screenWidth) {
			ball.Reset();
			leftPaddle.Reset();
			rightPaddle.Reset();
			leftScore.score++;
		}
		//IF BALL GOES OFF SCREEN TO THE LEFT SIDE
		if(ball.pos.x < 0) {
			ball.Reset();
			leftPaddle.Reset();
			rightPaddle.Reset();
			rightScore.score++;
		}

		rightPaddle.Draw();
		leftPaddle.Draw();
		rightPaddle.Move();
		leftPaddle.Move();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
