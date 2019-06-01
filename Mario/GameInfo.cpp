#include "GameInfo.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HIGHT 512


GameInfo::GameInfo()
{
	if (!font.loadFromFile("../assets/arial.ttf"))
	{
		// handle error
	}
	info[0].setFont(font);
	info[0].setFillColor(sf::Color::White);
	info[0].setCharacterSize(36);
	info[0].setString("Coins: " + std::to_string(coins));


	info[1].setFont(font);
	info[1].setFillColor(sf::Color::White);
	info[1].setCharacterSize(36);
	info[1].setString("Score: " + std::to_string(score));


	info[2].setFont(font);
	info[2].setFillColor(sf::Color::White);
	info[2].setCharacterSize(36);
	info[2].setString("Time");
}


GameInfo::~GameInfo()
{
}
void GameInfo::followMario(int center) {
	info[0].setPosition(sf::Vector2f(center - 430, WINDOW_HIGHT / 20));
	info[1].setPosition(sf::Vector2f(center, WINDOW_HIGHT / 20));
	info[2].setPosition(sf::Vector2f(center + 300, WINDOW_HIGHT / 20));
}


void GameInfo::draw(sf::RenderWindow & window, int center)
{
	//display option to choose
	for (int i = 0; i < NUMBER_OF_ITEMS; i++)
	{
		window.draw(info[i]);
	}

}
void GameInfo::countTime()
{
	finish = std::chrono::high_resolution_clock::now();
	difference = (int)((finish - start).count() / 1000000000);
	if (switcher != difference)
	{
		time++;
		start = std::chrono::high_resolution_clock::now();
	}

	info[2].setString("Time: " + std::to_string(time));
}
void GameInfo::saveResultToFile()
{
	score = score - (time * 5 + 300);
	if (score < 0)
		score = 0;
	std::time(&czas);
	localData = ctime(&czas);

	std::ofstream myfile;
	myfile.open("../results/Results.txt", std::ios::app);
	myfile << localData << "Coins: " << properFormat3(coins) << " Score: " << properFormat4(score) << " Time: " << properFormat3(time) << std::endl << std::endl;
	myfile.close();
}