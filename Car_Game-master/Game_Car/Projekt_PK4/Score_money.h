#pragma once
#include<SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;
class Score_money
{
public:
	Score_money();
	~Score_money();
	void score_counter();
	Text get_score();
	int get_intofScore();
	void setMoney(int Money);
	int getMoney();
	Text get_sMoney();
	void showMoney();
private:
	int Money1=0;
	Font ArialFont;
	Text Score;
	Text Money;
	int points_score=0;
	double pom = 0;
	String str_score,str_Money;
};