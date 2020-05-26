#include <iostream>
#include "Road.h"

Road::Road()
{
			TexRoad1.loadFromFile("Sprite/Droga.png");
			SprRoad1.setTexture(TexRoad1);
			TexRoad2.loadFromFile("Sprite/Droga.png");
			SprRoad2.setTexture(TexRoad2);
			TexRoad3.loadFromFile("Sprite/Droga.png");
			SprRoad3.setTexture(TexRoad3);
			TexRoad4.loadFromFile("Sprite/Droga.png");
			SprRoad4.setTexture(TexRoad4);
			SprRoad1.setPosition(0, TexRoad1Y);
			SprRoad2.setPosition(0, TexRoad2Y);
			SprRoad3.setPosition(0, TexRoad3Y);
			SprRoad4.setPosition(0, TexRoad4Y);

}
Road::~Road()
{

}
void Road::rollroad()
{
	if (TexRoad1Y>0)
	{
		TexRoad1Y = -200;
		TexRoad2Y = 0;
		TexRoad3Y = 200;
		TexRoad4Y = 400;
	}
	TexRoad1Y += 2;
	SprRoad1.setPosition(0, TexRoad1Y);
	TexRoad2Y += 2;
	SprRoad2.setPosition(0, TexRoad2Y);
	TexRoad3Y += 2;
	SprRoad3.setPosition(0, TexRoad3Y);
	TexRoad4Y += 2;
	SprRoad4.setPosition(0, TexRoad4Y);
}
Sprite Road::getsprite1()
{
	return SprRoad1;
}
Sprite Road::getsprite2()
{
	return SprRoad2;
}
Sprite Road::getsprite3()
{
	return SprRoad3;
}
Sprite Road::getsprite4()
{
	return SprRoad4;
}