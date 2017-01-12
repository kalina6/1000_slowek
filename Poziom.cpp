#include "Poziom.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "sqlite3.h"

Poziom::Poziom(){
	
}
Poziom::~Poziom(){
	
}
void Poziom::run(){
	
	sqlite3_stmt *stmt;
	sqlite3 *db;
   	int rc; // This line
   	int i = 0 ;
   	char *zErrMsg = 0;
   	
	
   	
   	
	   
	
   	
   	rc = sqlite3_open("verbs.db", &db);
	

	const char *sql = "SELECT ID, PKT FROM POINTS";  
	int rd = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (rd != SQLITE_OK) {
   		printf("error: ", sqlite3_errmsg(db));
	}
    while ((rd = sqlite3_step(stmt)) == SQLITE_ROW) {
        i = i+1;
		int id           = sqlite3_column_int (stmt, 0);
		int pkt = sqlite3_column_int(stmt, 1);
       
    	punkty[i] = pkt; 
   		std::cout<<punkty[i]<<std::endl;
		
	  
    	
    }
    
    
   	
    if (rd != SQLITE_DONE) {
    	printf("error: ", sqlite3_errmsg(db));
    }
	sqlite3_finalize(stmt); 
   
    sqlite3_close(db);
	
	
	
	
	
	
	
	
	sf::RenderWindow window4(sf::VideoMode(700,500),"Twoj_poziom_bijacz- bede zapisywal twoje punkty");
	
	tlo.loadFromFile("src/poziom.png");
	obraz.setTexture(tlo);
	obraz.setPosition(0,0);
	font.loadFromFile("src/arial.ttf");
	zlicz = 0;
	napis = "Zdobyte punkty: ";
	
	punkt.setCharacterSize(50);
	punkt.setFont(font);
	punkt.setStyle(sf::Text::Bold);
	punkt.setColor(sf::Color::Green);
	punkt.setPosition(50,200);
	
	for (int i = 0; i<1300; i++){
		zlicz = zlicz + punkty[i];
	}
	
	std::stringstream ss;
    ss << zlicz;
    punkt.setString(napis+ss.str());
				
				while (window4.isOpen())
    			{
        			sf::Event event;
        			while (window4.pollEvent(event))
        			{
            
						if (event.type == sf::Event::Closed){
			    			window4.close();
        				}
				
					}
				
				window4.clear();
				window4.draw(obraz);
				window4.draw(punkt);
				window4.display();
			}
	
}
