#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Intro
{
public:
	Intro();
	~Intro();
	Sprite get_Intro();
	Sprite get_Intro2();
	Sprite get_Intro3();
	Sprite get_gameover();
	Sprite get_audi();
	Sprite get_audi1();
	void audi_position(double x);
	void audi1_position(double x);

private:
	Texture Title1;
	Sprite STitle1;
	Texture Title2;
	Sprite STitle2;
	Texture Title3;
	Sprite STitle3;
	Texture Gameover;
	Sprite SGameover;
	Texture AudiSc;
	Sprite SAudiSc;
	Texture AudiSc1;
	Sprite SAudiSc1;
	
};
