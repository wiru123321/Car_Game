#pragma once
#include<SFML/Graphics.hpp>
#include <memory>
#include <string>
using namespace sf;
using namespace std;

class Car
{
public:
	Car();
	~Car();
	Sprite get_Spr_car();
	double get_CarX();
	double get_CarY();
	void set_CarX(double x);
	void set_CarY(double y);
	void Car_position(double CarX, double CarY);
	void setOtherCarSprite(string &name);
	void setCarScale(int scale);
private:
	Texture TexMy_Car;
	Sprite SprMy_Car;
	double CarX, CarY;
};