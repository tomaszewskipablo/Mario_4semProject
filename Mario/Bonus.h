#pragma once

#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include"entity.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HIGHT 512

using namespace sf;
class Bonus : public Entity
{
private:

public:
	Bonus() {};
	Bonus(sf::Vector2f startingPosition);
	~Bonus();

	void repair();

	//	void update();
};