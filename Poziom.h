#ifndef POZIOM_H
#define POZIOM_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"


class Poziom
{
	public:
		
		sf::Texture tlo;
		sf::Sprite obraz;
		int punkty[1300] = {};
		sf::Text punkt;
		std::string napis;
		int zlicz;
		sf::Font font;
		
		Poziom();
		~Poziom();
		void run();
};

#endif
