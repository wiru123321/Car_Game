#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

class Road
{
public:
	Road();
	~Road();
	void rollroad();
	Sprite getsprite1();
	Sprite getsprite2();
	Sprite getsprite3();
	Sprite getsprite4();
private:
	double TexRoad1Y = -200, TexRoad2Y = 0, TexRoad3Y = 200, TexRoad4Y = 400;
	Texture TexRoad1;
	Sprite SprRoad1;
	Texture TexRoad2;
	Sprite SprRoad2;
	Texture TexRoad3;
	Sprite SprRoad3;
	Texture TexRoad4;
	Sprite SprRoad4;

};
