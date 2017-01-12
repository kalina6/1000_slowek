#ifndef TRYB1_H
#define TRYB1_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

class Tryb1
{
	public:
		
		std::string polish[201]= {};
   		std::string english[201]= {};
		std::string napis;
		std::string poprawna;
		std::string angielskie;
		std::string polskie;
		int punkty;
		sf::Font font;
		sf::RectangleShape pole1;
		sf::RectangleShape pole2;
		sf::Text sprawdzenie;
		sf::Text text1;
		sf::Text text2;
		sf::Text punkt;
		
		Tryb1();
		~Tryb1();
		void run();
		void losuj();
		void przeslij_pkt();
		
};

#endif
