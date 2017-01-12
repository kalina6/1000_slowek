#include "MainWindow.h"
#include "Tryb1.h"
#include "Tryb2.h"
#include "Tryb3.h"
#include "Poziom.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

MainWindow::MainWindow(){
	
}

MainWindow::~MainWindow(){
	
}

void MainWindow::run() {
	
	std::cout<<"Start"<<std::endl;	
    //g³ówne t³o
    sf::RenderWindow window(sf::VideoMode(764, 448), "1000");
    sf::Texture tlo;
    tlo.loadFromFile("src/flag-uk.jpg");
    
    sf::Sprite tlo1;
    tlo1.setTexture(tlo);
    tlo1.setPosition(0,0);
    
    //przycisk 1
    sf::Texture przycisk_1;
    przycisk_1.loadFromFile("src/t1.png");
    
    sf::Sprite p1;
	p1.setTexture(przycisk_1);
	p1.setPosition(150,200);  
	
	//przycisk 2
	sf::Texture przycisk_2;
	przycisk_2.loadFromFile("src/t2.png");
	
	sf::Sprite p2;
	p2.setTexture(przycisk_2);
	p2.setPosition(500,200);
	
	//przycisk 3
	sf::Texture przycisk_3;
	przycisk_3.loadFromFile("src/t3.png");
	
	sf::Sprite p3;
	p3.setTexture(przycisk_3);
	p3.setPosition(317,270);
  
    //przycisk4
    sf::Texture przycisk_4;
    przycisk_4.loadFromFile("src/t4.png");
    
    sf::Sprite p4;
    p4.setTexture(przycisk_4);
    p4.setPosition(300,200);
    
    //przycisk5
    sf::Texture przycisk_5;
    przycisk_5.loadFromFile("src/t5.png");
    
    sf::Sprite p5;
    p5.setTexture(przycisk_5);
    p5.setPosition(265,350);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            
			if (event.type == sf::Event::Closed){
			    window.close();
        	}
			
			sf::Vector2i position = sf::Mouse::getPosition(window);
    		//std::cout<<position.x<<std::endl;
            
        	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.x>=150 && position.x<=266 && position.y>=200 && position.y<=257)
        	{
		    
				Tryb1 tryb1;
				tryb1.run();
				
        	}	
        	
        	
        	
        	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.x>=500 && position.x<=622 && position.y>=200 && position.y<=257)
        	{
				Tryb2 tryb2;
				tryb2.run();
				
        	}	
        	
        	
        	
        	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.x>=317 && position.x<=445 && position.y>=270 && position.y<=327)
        	{
				Tryb3 tryb3;
				tryb3.run();
				
        	}	
        	
        	
        	
        	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.x>=300 && position.x<=462 && position.y>=200 && position.y<=240)
        	{
				Poziom poziom;
				poziom.run();
				
        	}	
    }

        window.clear();
       	window.draw(tlo1);
       	window.draw(p1);
       	window.draw(p2);
       	window.draw(p3);
       	window.draw(p4);
       	window.draw(p5);
        window.display();
    }
    
}
