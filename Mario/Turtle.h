#pragma once

#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"entity.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HIGHT 512

	using namespace sf;
class Turtle : public Entity
{
private:

public:
	Turtle();
	~Turtle();

//	void update();
};