#pragma once
#include<SFML/Graphics.hpp>
#include "Road.h"
#include "Score_money.h"
#include "Car.h"
#include "Intro.h"
#include "List.h"
#include "ListEl.h"
#include "Obstacles.h"
#include<cstdlib>
#include<time.h>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <memory>
#include <list>

using namespace sf;
using namespace std;

class GameLoop {
public:
	GameLoop();
	~GameLoop();
	void start();
	void inicial();
	void OponentCarsMovement();
	void spawnBush();
	void inicialBush();
private:
	int getRandomNumber(int a, int b);
	Intro intro;
	Road Road1;
	Car My_Car;
	Car Ambulance;
	Car Black_viper;
	Car Car1;
	Car Mini_van;
	Car taxi;
	int pom = 255;
	void game_speed();
	RenderWindow window;
	void checkCollisions();
	void checkCollisionsBush();
	string  SAmbulance = "Sprite/Ambulance.png", SAudi = "Sprite/Audi.png",
		SBlack_viper = "Sprite/Black_viper.png", SCar = "Sprite/Car.png",
		SMini_van = "Sprite/Mini_van.png", Staxi = "Sprite/taxi.png";
	double car_speed = 2.5;
	void gameend();
	void startgame();
	Obstacles obstacles1;
	Obstacles obstacles2;
	Obstacles obstacles3;
	Obstacles obstacles4;
	Obstacles obstacles5;
	Obstacles obstacles6;
	List list1;
	Score_money Score;
	list<Car> Carlist;
	list<Car>::iterator CarIT=Carlist.begin();
};
