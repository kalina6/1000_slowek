#include "Tryb2.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include <sstream>

Tryb2::Tryb2(){
	
}

Tryb2::~Tryb2(){
	
}

void Tryb2::przeslij_pkt(){
	
	int counter = 0;

    sqlite3 *db;
    sqlite3_stmt * stmt;
    std::stringstream ss;
    ss << punkty;
    
	std::string sqlstatement = "INSERT INTO POINTS ( 'PKT' ) VALUES('"+ss.str()+"');";
	
   if (sqlite3_open("verbs.db", &db) == SQLITE_OK)
    {
    sqlite3_prepare( db, sqlstatement.c_str(), -1, &stmt, NULL );//preparing the statement
    sqlite3_step( stmt );//executing the statement
    std::cout<<"poszlo\n";
        }
    else
    {
        std::cout << "Failed to open db\n";
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
	
}

void Tryb2::losuj(){
	
	
	int out1;
	int out2;
	int out4;
	int out3;
	int reszta;
	int min = 1;
	int max = 201;
	int maxo = 4;
	out1 = min + (rand() * (int)(max - min) / RAND_MAX);
	out2 = min + (rand() * (int)(max - min) / RAND_MAX);
	out3 = min + (rand() * (int)(max - min) / RAND_MAX);
	out4 = min + (rand() * (int)(max - min) / RAND_MAX);
	reszta = min + (rand() * (int)(maxo - min) / RAND_MAX);
	wylosowane = english[out1];
	
	if (reszta == 1){
		napis1 = ("src/tryb/"+english[out1]+".png");
		napis2 = ("src/tryb/"+english[out2]+".png");
		napis3 = ("src/tryb/"+english[out3]+".png");
		napis4 = ("src/tryb/"+english[out4]+".png");
		jeden = english[out1];
		dwa = english[out2];
		trzy = english[out3];
		cztery = english[out4];
	}
	else if(reszta == 2){
		napis1 = ("src/tryb/"+english[out2]+".png");
		napis2 = ("src/tryb/"+english[out1]+".png");
		napis3 = ("src/tryb/"+english[out3]+".png");
		napis4 = ("src/tryb/"+english[out4]+".png");
		jeden = english[out2];
		dwa = english[out1];
		trzy = english[out3];
		cztery = english[out4];
	}
	else if(reszta == 3){
		napis1 = ("src/tryb/"+english[out3]+".png");
		napis2 = ("src/tryb/"+english[out2]+".png");
		napis3 = ("src/tryb/"+english[out1]+".png");
		napis4 = ("src/tryb/"+english[out4]+".png");
		jeden = english[out3];
		dwa = english[out2];
		trzy = english[out1];
		cztery = english[out4];
	}
	else if(reszta == 4){
		napis1 = ("src/tryb/"+english[out4]+".png");
		napis2 = ("src/tryb/"+english[out2]+".png");
		napis3 = ("src/tryb/"+english[out3]+".png");
		napis4 = ("src/tryb/"+english[out1]+".png");
		jeden = english[out4];
		dwa = english[out2];
		trzy = english[out3];
		cztery = english[out1];
	}
	
}

void Tryb2::run(){
	
	sqlite3_stmt *stmt;
	sqlite3 *db;
   	int rc; // This line
   	int i = 0 ;
   	char *zErrMsg = 0;
   	rc = sqlite3_open("verbs.db", &db);
	
	const char *sql = "SELECT ID, ENGLISH, POLISH FROM WORDS";  
	int rd = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (rd != SQLITE_OK) {
   		printf("error: ", sqlite3_errmsg(db));
	}
    while ((rd = sqlite3_step(stmt)) == SQLITE_ROW) {
        i = i+1;
		std::string en = (const char*) (sqlite3_column_text(stmt, 1));
    
		english[i] = en;
	}
	if (rd != SQLITE_DONE) {
    	printf("error: ", sqlite3_errmsg(db));
    }
	sqlite3_finalize(stmt); 
   
    sqlite3_close(db);


		
	sf::RenderWindow window2(sf::VideoMode(700,700),"Tryb_2_bijacz- bede sprawdzal czy jedno z 3 zdjec zosalo dopasowane do slowka");
	
	losuj();
	
	punkty = 0;
	punkty1 = "Punkty: ";
			
	sf::Texture zegar;
	zegar.loadFromFile("src/zeg.jpg");
	
	texture1.loadFromFile(napis1);
	texture2.loadFromFile(napis2);
	texture3.loadFromFile(napis3);
	texture4.loadFromFile(napis4);
		
	obrazek1.setTexture(texture1);
	obrazek2.setTexture(texture2);
	obrazek3.setTexture(texture3);
	obrazek4.setTexture(texture4);
	
	obrazek1.setPosition(190,240);
	obrazek2.setPosition(390,240);
	obrazek3.setPosition(190,440);
	obrazek4.setPosition(390,440);
	
	sf::Font font;
	font.loadFromFile("src/arial.ttf");
	
	los.setCharacterSize(30);
	los.setFont(font);
	los.setString(wylosowane);
	los.setStyle(sf::Text::Bold);
	los.setColor(sf::Color::Green);
	los.setPosition(110,105);
	
	punkt.setCharacterSize(30);
			punkt.setString(punkty1);
			punkt.setFont(font);
			punkt.setStyle(sf::Text::Bold);
			punkt.setColor(sf::Color::Red);
			punkt.setPosition(150,600);
	
	sf::Sprite zeg;
	zeg.setTexture(zegar);
	zeg.setPosition(0,0);
				
				while (window2.isOpen())
    			{
        			sf::Event event;
        			while (window2.pollEvent(event))
        			{
            
						if (event.type == sf::Event::Closed){
			    			window2.close();
			    			przeslij_pkt();
        				}
        				sf::Vector2i position = sf::Mouse::getPosition(window2);
        				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.x>=190 && position.x<=290 && position.y>=240 && position.y<=340)
        				{
        					if (jeden == wylosowane){
							
		    					punkty = punkty +1;
                  					std::stringstream ss;
        							ss << punkty;
        							punkt.setString(punkty1+ss.str());
        							losuj();
        							texture1.loadFromFile(napis1);
									texture2.loadFromFile(napis2);
									texture3.loadFromFile(napis3);
									texture4.loadFromFile(napis4);
		
									obrazek1.setTexture(texture1);
									obrazek2.setTexture(texture2);
									obrazek3.setTexture(texture3);
									obrazek4.setTexture(texture4);
									los.setString(wylosowane);
        				}
        				else{
        					losuj();
        							texture1.loadFromFile(napis1);
									texture2.loadFromFile(napis2);
									texture3.loadFromFile(napis3);
									texture4.loadFromFile(napis4);
		
									obrazek1.setTexture(texture1);
									obrazek2.setTexture(texture2);
									obrazek3.setTexture(texture3);
									obrazek4.setTexture(texture4);
									los.setString(wylosowane);
						}
				
				
        				}	
        				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.x>=390 && position.x<=490 && position.y>=240 && position.y<=340)
        				{
        					if(dwa == wylosowane){
		    						punkty = punkty +1;
                  					std::stringstream ss;
        							ss << punkty;
        							punkt.setString(punkty1+ss.str());
									losuj();
        							texture1.loadFromFile(napis1);
									texture2.loadFromFile(napis2);
									texture3.loadFromFile(napis3);
									texture4.loadFromFile(napis4);
		
									obrazek1.setTexture(texture1);
									obrazek2.setTexture(texture2);
									obrazek3.setTexture(texture3);
									obrazek4.setTexture(texture4);
									los.setString(wylosowane);
						}else{
							losuj();
        							texture1.loadFromFile(napis1);
									texture2.loadFromFile(napis2);
									texture3.loadFromFile(napis3);
									texture4.loadFromFile(napis4);
		
									obrazek1.setTexture(texture1);
									obrazek2.setTexture(texture2);
									obrazek3.setTexture(texture3);
									obrazek4.setTexture(texture4);
									los.setString(wylosowane);
						}
        				}
        				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.x>=190 && position.x<=290 && position.y>=440 && position.y<=540)
        				{
        					if (trzy == wylosowane){
		    				punkty = punkty +1;
                  					std::stringstream ss;
        							ss << punkty;
        							punkt.setString(punkty1+ss.str());
        							losuj();
        							texture1.loadFromFile(napis1);
									texture2.loadFromFile(napis2);
									texture3.loadFromFile(napis3);
									texture4.loadFromFile(napis4);
		
									obrazek1.setTexture(texture1);
									obrazek2.setTexture(texture2);
									obrazek3.setTexture(texture3);
									obrazek4.setTexture(texture4);
									los.setString(wylosowane);
        						}else{
        							losuj();
        							texture1.loadFromFile(napis1);
									texture2.loadFromFile(napis2);
									texture3.loadFromFile(napis3);
									texture4.loadFromFile(napis4);
		
									obrazek1.setTexture(texture1);
									obrazek2.setTexture(texture2);
									obrazek3.setTexture(texture3);
									obrazek4.setTexture(texture4);
									los.setString(wylosowane);
								}
				
				
        				}
        				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.x>=390 && position.x<=490 && position.y>=440 && position.y<=540)
        				{
		    				if(cztery == wylosowane){
							
								punkty = punkty +1;
                  					std::stringstream ss;
        							ss << punkty;
        							punkt.setString(punkty1+ss.str());
        							losuj();
        							texture1.loadFromFile(napis1);
									texture2.loadFromFile(napis2);
									texture3.loadFromFile(napis3);
									texture4.loadFromFile(napis4);
		
									obrazek1.setTexture(texture1);
									obrazek2.setTexture(texture2);
									obrazek3.setTexture(texture3);
									obrazek4.setTexture(texture4);
									los.setString(wylosowane);
								}else{
									losuj();
        							texture1.loadFromFile(napis1);
									texture2.loadFromFile(napis2);
									texture3.loadFromFile(napis3);
									texture4.loadFromFile(napis4);
		
									obrazek1.setTexture(texture1);
									obrazek2.setTexture(texture2);
									obrazek3.setTexture(texture3);
									obrazek4.setTexture(texture4);
									los.setString(wylosowane);
								}
				
				
        				}
				
					}
			
				window2.clear();
				window2.draw(zeg);
				window2.draw(obrazek1);
				window2.draw(obrazek2);
				window2.draw(obrazek3);
				window2.draw(obrazek4);
				window2.draw(los);
				window2.draw(punkt);
				window2.display();
			}
				
	
}
