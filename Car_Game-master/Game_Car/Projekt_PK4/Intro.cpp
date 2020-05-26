#include "Intro.h"

Intro::Intro()
{
	Title1.loadFromFile("Sprite/Title.png");
	STitle1.setTexture(Title1);
	STitle1.setColor(Color(255, 255, 255, 255));
	STitle1.setPosition(150, 300);
	Title2.loadFromFile("Sprite/Title2.png");
	STitle2.setTexture(Title2);
	STitle2.setColor(Color(255, 255, 255, 255));
	STitle2.setPosition(100, 300);
	Title3.loadFromFile("Sprite/Title3.png");
	STitle3.setTexture(Title3);
	STitle3.setColor(Color(255, 255, 255, 255));
	STitle3.setPosition(300, 300);
	Gameover.loadFromFile("Sprite/Gameover.png");
	SGameover.setTexture(Gameover);
	SGameover.setColor(Color(255, 255, 255, 255));
	SGameover.setPosition(310, 300);
	AudiSc.loadFromFile("Sprite/AudiScreen.png");
	SAudiSc.setTexture(AudiSc);
	SAudiSc.setColor(Color(255, 255, 255, 255));
	SAudiSc.setPosition(-220, 200);
	AudiSc1.loadFromFile("Sprite/AudiScreen1.png");
	SAudiSc1.setTexture(AudiSc1);
	SAudiSc1.setColor(Color(255, 255, 255, 255));
	SAudiSc1.setPosition(200, 200);
}

Intro::~Intro()
{

}

Sprite Intro::get_Intro()
{
	return STitle1;
}
Sprite Intro::get_Intro2()
{
	return STitle2;
}
Sprite Intro::get_Intro3()
{
	return STitle3;
}

Sprite Intro::get_gameover()
{
	return SGameover;
}

Sprite Intro::get_audi()
{
	return SAudiSc;
}

Sprite Intro::get_audi1()
{
	return SAudiSc1;
}

void Intro::audi_position(double x)
{
	SAudiSc.setPosition(x, 200);
}
void Intro::audi1_position(double x)
{
	SAudiSc1.setPosition(x, 200);
}


