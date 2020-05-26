#include "Car.h"

Car::Car()
{

}

Car::~Car()
{

}

Sprite Car::get_Spr_car()
{
	return SprMy_Car;
}

double Car::get_CarX()
{
	return SprMy_Car.getPosition().x;
}

double Car::get_CarY()
{
	return SprMy_Car.getPosition().y;
}

void Car::set_CarX(double x)
{
	SprMy_Car.setPosition(x, SprMy_Car.getPosition().y);
		
}

void Car::set_CarY(double y)
{
	SprMy_Car.setPosition(SprMy_Car.getPosition().x,y);
}

void Car::Car_position(double CarX, double CarY)
{
	SprMy_Car.setPosition(CarX, CarY);
}



void Car::setOtherCarSprite(string &name)
{
	TexMy_Car.loadFromFile(name);
	SprMy_Car.setTexture(TexMy_Car);
	SprMy_Car.setRotation(180.f);
	SprMy_Car.setScale(0.5, 0.5);
}

void Car::setCarScale(int scale)
{
	SprMy_Car.setScale(scale, scale);
}

