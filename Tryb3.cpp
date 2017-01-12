#include "Tryb3.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

Tryb3::Tryb3(){
	
}

Tryb3::~Tryb3(){
	
}

void Tryb3::run(){
	sf::RenderWindow window3(sf::VideoMode(1200,700),"Tryb_3_bijacz-bede slownikiem tematycznym");
	
	tlo.loadFromFile("src/tryb3.png");
	obraz.setTexture(tlo);
	obraz.setPosition(0,0);
				
				while (window3.isOpen())
    			{
        			sf::Event event;
        			while (window3.pollEvent(event))
        			{
            
						if (event.type == sf::Event::Closed){
			    			window3.close();
        				}
				
					}
				
				window3.clear();
				window3.draw(obraz);
				window3.display();
			}
}
