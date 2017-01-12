#ifndef TRYB2_H
#define TRYB2_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

class Tryb2
{
	public:
		
		std::string wylosowane;
		std::string english[201]= {};
		std::string napis1;
		std::string napis2;
		std::string napis3;
		std::string napis4;
		sf::Texture texture1;
		sf::Texture texture2;
		sf::Texture texture3;
		sf::Texture texture4;
		sf::Sprite obrazek1;
		sf::Sprite obrazek2;
		sf::Sprite obrazek3;
		sf::Sprite obrazek4;
		sf::Text los;
		sf::Text punkt;
		std::string punkty1;
		int punkty;
		std::string jeden;
		std::string dwa;
		std::string trzy;
		std::string cztery;
		
		Tryb2();
		~Tryb2();
		void run();
		void losuj();
		void przeslij_pkt();
	
};

#endif
