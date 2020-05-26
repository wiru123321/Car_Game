#include <iostream>
#include "Obstacles.h"

Obstacles::Obstacles()
{
	TexBush.loadFromFile("Sprite/Krzak.png");
	SprBush.setTexture(TexBush);
	SprBush.setScale(0.7, 0.7);
	//SprBush.setPosition(ObsX, ObsY);
}

Obstacles::~Obstacles()
{
}

Sprite Obstacles::getBush()
{
	return SprBush;
}

void Obstacles::set_Bush_position(double x, double y)
{
	SprBush.setPosition(x, y);
}

double Obstacles::getX()
{
	return SprBush.getPosition().x;
}
double Obstacles::getY()
{
	return SprBush.getPosition().y;
}


