#include "score.h"

Score::Score()
{
	score = 0;
	fontSize = 50;
	pos.y = 20;
}

void Score::Draw()
{
	//DrawText() TAKES IN A const char *, SO I HAD TO CONVERT THE SCORE COUNTER INTO ONE FROM AN INT
	std::string s = std::to_string(score);
	char const *scoretext = s.c_str();
	DrawText(scoretext, pos.x, pos.y, fontSize, BLACK);
}
