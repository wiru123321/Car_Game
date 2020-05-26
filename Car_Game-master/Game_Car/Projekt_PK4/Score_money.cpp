#include "Score_money.h"

Score_money::Score_money()
{
	ArialFont.loadFromFile("Sprite/arial.ttf");
	Score.setFont(ArialFont);
	Score.setCharacterSize(20);
	Score.setPosition(650, 15);
	Money.setFont(ArialFont);
	Money.setCharacterSize(20);
	Money.setPosition(650, 50);
}

Score_money::~Score_money()
{

}
void Score_money::score_counter()
{
	if (pom > 150)
	{
		points_score = points_score + 1;
		pom = 0;
	}
	pom = pom + 1;
	str_score = "SCORE:" + to_string(points_score);
	Score.setString(str_score);
}

Text Score_money::get_score()
{
	return Score;
}

int Score_money::get_intofScore()
{
	return points_score;
}

void Score_money::setMoney(int Money2)
{
	this->Money1 = Money2;
}

int Score_money::getMoney()
{
	return Money1;
}

Text Score_money::get_sMoney()
{
	return Money;
}

void Score_money::showMoney()
{
	str_Money = "Money:" + to_string(Money1);
	Money.setString(str_Money);
}
