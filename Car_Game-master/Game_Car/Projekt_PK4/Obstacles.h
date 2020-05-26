#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

class Obstacles
{
public:
	Obstacles();
	~Obstacles();
	Sprite getBush();
	void set_Bush_position(double x, double y);
	double getX();
	double getY();
private:
	Texture TexBush;
	Sprite SprBush;
	//double ObsX, ObsY;

};
