#include <iostream>
#include "GameLoop.h"


GameLoop::GameLoop()
{
	window.create(VideoMode(800, 600), "Car Game");
	window.setFramerateLimit(60);
	startgame();
}

GameLoop::~GameLoop()
{

}

void GameLoop::start()
{

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
	
		}
		try
		{
			if (Keyboard::isKeyPressed(Keyboard::Key::Left))
			{
				if (((*Carlist.begin()).get_CarX() < 250 && (*Carlist.begin()).get_CarX() > 50) || ((*Carlist.begin()).get_CarX() < 800 && (*Carlist.begin()).get_CarX() > 600))
				{
					(*Carlist.begin()).set_CarX((*Carlist.begin()).get_CarX() - 1);
				}
				else if ((*Carlist.begin()).get_CarX() >= 250)
				{
					(*Carlist.begin()).set_CarX((*Carlist.begin()).get_CarX() - 3);
				}
				else
					throw runtime_error("Twoj samochod wypadl z drogi");
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Right))
			{
				if (((*Carlist.begin()).get_CarX() < 800 && (*Carlist.begin()).get_CarX() > 600) || ((*Carlist.begin()).get_CarX() < 250 && (*Carlist.begin()).get_CarX() > 50))
				{
					(*Carlist.begin()).set_CarX((*Carlist.begin()).get_CarX() + 1);
				}
				else if ((*Carlist.begin()).get_CarX() <= 600)
				{
					(*Carlist.begin()).set_CarX((*Carlist.begin()).get_CarX() + 3);
				}
				else
					throw runtime_error("Twoj samochod wypadl z drogi");
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Up))
			{
				if ((*Carlist.begin()).get_CarY() > 100 && (*Carlist.begin()).get_CarX() <= 600 && (*Carlist.begin()).get_CarX() >= 250)
				{
					(*Carlist.begin()).set_CarY((*Carlist.begin()).get_CarY() - car_speed);
				}
				else if ((*Carlist.begin()).get_CarY() > 100)
					(*Carlist.begin()).set_CarY((*Carlist.begin()).get_CarY() - 1);
				else
					throw runtime_error("Twoj samochod wypadl z drogi");
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Down))
			{
				if ((*Carlist.begin()).get_CarY() < 600 && (*Carlist.begin()).get_CarX() <= 60 && (*Carlist.begin()).get_CarX() >= 250)
				{
					(*Carlist.begin()).set_CarY((*Carlist.begin()).get_CarY() + car_speed);
				}
				else if ((*Carlist.begin()).get_CarY() < 600)
					(*Carlist.begin()).set_CarY((*Carlist.begin()).get_CarY() + 1);
				else
					throw runtime_error("Twoj samochod wypadl z drogi");
			}

			Road1.rollroad();
			Score.score_counter();
			Score.showMoney();
			game_speed();
			spawnBush();
			checkCollisions();
			checkCollisionsBush();

			OponentCarsMovement();
			window.draw(Road1.getsprite1());
			window.draw(Road1.getsprite2());
			window.draw(Road1.getsprite3());
			window.draw(Road1.getsprite4());
			window.draw((*CarIT).get_Spr_car());
			++CarIT;
			window.draw((*CarIT).get_Spr_car());
			++CarIT;
			window.draw((*CarIT).get_Spr_car());
			++CarIT;
			window.draw((*CarIT).get_Spr_car());
			++CarIT;
			window.draw((*CarIT).get_Spr_car());
			++CarIT;
			window.draw((*CarIT).get_Spr_car());
			CarIT=Carlist.begin();
			window.draw(obstacles1.getBush());
			window.draw(obstacles2.getBush());
			window.draw(obstacles3.getBush());
			window.draw(obstacles4.getBush());
			window.draw(obstacles5.getBush());
			window.draw(obstacles6.getBush());
			window.draw(Score.get_score());
			window.draw(Score.get_sMoney());
		}
			catch (std::runtime_error & e)
			{
				cout << "Runtime error: " << e.what() << endl;;
				gameend();
			}
			window.display();
	}
}

int GameLoop::getRandomNumber(int a, int b)
{
	static bool first = true; if (first) { srand(time(NULL)); first = false; }
	int result = a + rand() % ((b + 1) - a);
	result = (result / 10) * 10;
	return result;
}

void GameLoop::inicial()
{
	Ambulance.setOtherCarSprite(SAmbulance);
	Ambulance.Car_position(getRandomNumber(290,550), 0);
	Carlist.push_back(Ambulance);
	Black_viper.setOtherCarSprite(SBlack_viper);
	Black_viper.Car_position(getRandomNumber(290, 550), -150);
	Carlist.push_back(Black_viper);
	Car1.setOtherCarSprite(SCar);
	Car1.Car_position(getRandomNumber(290, 550), -300);
	Carlist.push_back(Car1);
	Mini_van.setOtherCarSprite(SMini_van);
	Mini_van.Car_position(getRandomNumber(290, 550), -450);
	Carlist.push_back(Mini_van);
	taxi.setOtherCarSprite(Staxi);
	taxi.Car_position(getRandomNumber(290, 550), -600);
	Carlist.push_back(taxi);
}
void GameLoop::OponentCarsMovement()
{
	++CarIT;
	if((*CarIT).get_CarY() >690 )
	{

		(*CarIT).set_CarY(0);
		(*CarIT).set_CarX(getRandomNumber(290, 550));
		Score.setMoney(Score.getMoney() + 5);
		++CarIT;
	}
	else {
		(*CarIT).set_CarY((*CarIT).get_CarY() + car_speed);
	++CarIT;
	}
	if ((*CarIT).get_CarY() >690)
	{
		(*CarIT).set_CarY(0);
		(*CarIT).set_CarX(getRandomNumber(290, 550));
		Score.setMoney(Score.getMoney() + 5);
		++CarIT;
	}
	else {
		(*CarIT).set_CarY((*CarIT).get_CarY() + car_speed);
	++CarIT;
	}
	if ((*CarIT).get_CarY() >690)
	{
		(*CarIT).set_CarY(0);
		(*CarIT).set_CarX(getRandomNumber(290, 550));
		Score.setMoney(Score.getMoney() + 5);
		++CarIT;
	}
	else {
		((*CarIT).get_CarY() + car_speed);
	++CarIT;
	}
	if ((*CarIT).get_CarY() >690)
	{
		(*CarIT).set_CarY(0);
		(*CarIT).set_CarX(getRandomNumber(290, 550));
		Score.setMoney(Score.getMoney() + 5);
		++CarIT;
	}
	else {
		(*CarIT).set_CarY((*CarIT).get_CarY() + car_speed);
		++CarIT;
	}
	if ((*CarIT).get_CarY() >690)
	{
		(*CarIT).set_CarY(0);
		(*CarIT).set_CarX(getRandomNumber(290, 550));
		Score.setMoney(Score.getMoney() + 5);
		CarIT = Carlist.begin();
	}
	else {
		(*CarIT).set_CarY((*CarIT).get_CarY() + car_speed);
	CarIT = Carlist.begin();}
}

void GameLoop::game_speed()
{
	if (Score.get_intofScore() > 20 && Score.get_intofScore() < 30)
		car_speed = 3;
	if (Score.get_intofScore() > 31 && Score.get_intofScore() < 40)
		car_speed = 4;
	if (Score.get_intofScore() > 41)
		car_speed = 5;
}

void GameLoop::checkCollisions()
{
	++CarIT;
	if ((*Carlist.begin()).get_Spr_car().getGlobalBounds().intersects((*CarIT).get_Spr_car().getGlobalBounds()))
	{
		gameend();
	}
	++CarIT;
	if ((*Carlist.begin()).get_Spr_car().getGlobalBounds().intersects((*CarIT).get_Spr_car().getGlobalBounds()))
	{
		gameend();
		
	}
	++CarIT;
	if ((*Carlist.begin()).get_Spr_car().getGlobalBounds().intersects((*CarIT).get_Spr_car().getGlobalBounds()))
	{
		gameend();
		
	}
	++CarIT;
	if ((*Carlist.begin()).get_Spr_car().getGlobalBounds().intersects((*CarIT).get_Spr_car().getGlobalBounds()))
	{
		gameend();
		
	}
	++CarIT;
	if ((*Carlist.begin()).get_Spr_car().getGlobalBounds().intersects((*CarIT).get_Spr_car().getGlobalBounds()))
	{
		gameend();
		
	}
	CarIT = Carlist.begin();
}

void GameLoop::checkCollisionsBush()
{
	if ((*Carlist.begin()).get_Spr_car().getGlobalBounds().intersects(obstacles1.getBush().getGlobalBounds()))
	{
		gameend();
	}
	if ((*Carlist.begin()).get_Spr_car().getGlobalBounds().intersects(obstacles2.getBush().getGlobalBounds()))
	{
		gameend();
	}
	if ((*Carlist.begin()).get_Spr_car().getGlobalBounds().intersects(obstacles3.getBush().getGlobalBounds()))
	{
		gameend();
	}
	if ((*Carlist.begin()).get_Spr_car().getGlobalBounds().intersects(obstacles4.getBush().getGlobalBounds()))
	{
		gameend();
	}
	if ((*Carlist.begin()).get_Spr_car().getGlobalBounds().intersects(obstacles5.getBush().getGlobalBounds()))
	{
		gameend();
	}
	if ((*Carlist.begin()).get_Spr_car().getGlobalBounds().intersects(obstacles6.getBush().getGlobalBounds()))
	{
		gameend();
	}
}
	

void GameLoop::startgame()
{
	
	for (double i = -220; i < 1020; i = i + 5)
	{
		window.clear(Color::Black);
		window.draw(intro.get_Intro());
		window.draw(intro.get_audi());
		intro.audi_position(i);
		window.display();
	}
	for (double i = 0; i >-1020 ; i = i - 5)
	{
		window.clear(Color::Black);
		window.draw(intro.get_Intro2());
		window.draw(intro.get_audi1());
		intro.audi1_position(i);
		window.display();
	}
	for (double i = -220; i < 1020; i = i + 5)
	{
		window.clear(Color::Black);
		window.draw(intro.get_Intro3());
		window.draw(intro.get_audi());
		intro.audi_position(i);
		window.display();
	}

	inicialBush();
	My_Car.setOtherCarSprite(SAudi);
	My_Car.Car_position(360, 550);
	Carlist.push_back(My_Car);
	inicial();
	CarIT = Carlist.begin();
	window.display();
}

void GameLoop::inicialBush()
{
	obstacles1.set_Bush_position(getRandomNumber(-50, 120),200 );
	list1.add(obstacles1);
	obstacles2.set_Bush_position(getRandomNumber(590, 750),150 );
	list1.add(obstacles2);
	obstacles3.set_Bush_position(getRandomNumber(-50, 120), -20);
	list1.add(obstacles3);
	obstacles4.set_Bush_position(getRandomNumber(590, 750),-150 );
	list1.add(obstacles4);
	obstacles5.set_Bush_position(getRandomNumber(-50,120 ),-275 );
	list1.add(obstacles5);
	obstacles6.set_Bush_position(getRandomNumber(590, 750),-300 );
	list1.add(obstacles6);
}
void GameLoop::spawnBush()
{

	if (obstacles1.getY()>600)
	{
		obstacles1.set_Bush_position(getRandomNumber(-50, 120),-100);
	}
	else 
	{ 
		obstacles1.set_Bush_position(obstacles1.getX(), obstacles1.getY()+2);
	}
	if (obstacles2.getY()>600)
	{
		obstacles2.set_Bush_position(getRandomNumber(590, 750), -100);
	}
	else
	{
		obstacles2.set_Bush_position(obstacles2.getX(), obstacles2.getY() + 2);
	}
	if (obstacles3.getY()>600)
	{
		obstacles3.set_Bush_position(getRandomNumber(-50, 120), -100);
	}
	else
	{
		obstacles3.set_Bush_position(obstacles3.getX(), obstacles3.getY() + 2);
	}
	if (obstacles4.getY()>600)
	{
		obstacles4.set_Bush_position(getRandomNumber(590, 750), -100);
	}
	else
	{
		obstacles4.set_Bush_position(obstacles4.getX(), obstacles4.getY() + 2);
	}
	if (obstacles5.getY()>600)
	{
		obstacles5.set_Bush_position(getRandomNumber(-50, 120), -100);
	}
	else
	{
		obstacles5.set_Bush_position(obstacles5.getX(), obstacles5.getY() + 2);
	}
	if (obstacles6.getY()>600)
	{
		obstacles6.set_Bush_position(getRandomNumber(590, 750), -100);
	}
	else
	{
		obstacles6.set_Bush_position(obstacles6.getX(), obstacles6.getY() + 2);
	}
}

void GameLoop::gameend()
{
		for (double i = 0; i >-1020; i = i - 5)
		{
			window.clear(Color::Black);
			window.draw(intro.get_gameover());
			window.draw(intro.get_audi1());
			intro.audi1_position(i);
			window.display();
			
		}
	Sleep(2500);
		list1.remove(list1.head->next);
		Sleep(2500);
	window.close();
}
