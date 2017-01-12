#ifndef TRYB3_H
#define TRYB3_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

class Tryb3
{
	public:
		sf::Texture tlo;
		sf::Sprite obraz;
		
		
		Tryb3();
		~Tryb3();
		void run();
		
};
#endif
