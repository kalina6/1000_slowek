#include "Tryb1.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "sqlite3.h"
#include <sstream>

Tryb1::Tryb1(){
	
}

Tryb1::~Tryb1(){
	
}

void Tryb1::losuj(){
	
	
	int out1;
	int out2;
	int min = 1;
	int max = 201;
	out1 = min + (rand() * (int)(max - min) / RAND_MAX);
	
	angielskie = english[out1];
	poprawna = polish[out1];
}

void Tryb1::przeslij_pkt(){
	
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


void Tryb1::run(){
	
	sf::RenderWindow window1(sf::VideoMode(500,500),"Tryb_1_bijacz-bede sprawdzal i losowal slowka");
		    
    sqlite3_stmt *stmt;
	sqlite3 *db;
   	int rc; // This line
   	int i = 0 ;
   	char *zErrMsg = 0;
   	const char* data = "Callback function called";
	int identify[201] = {};
   	
   	
	   
	
   	
   	rc = sqlite3_open("verbs.db", &db);
	

	const char *sql = "SELECT ID, ENGLISH, POLISH FROM WORDS";  
	int rd = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (rd != SQLITE_OK) {
   		printf("error: ", sqlite3_errmsg(db));
	}
    while ((rd = sqlite3_step(stmt)) == SQLITE_ROW) {
        i = i+1;
		int id           = sqlite3_column_int (stmt, 0);
		std::string en = (const char*) (sqlite3_column_text(stmt, 1));
       	std::string pl = (const char*)(sqlite3_column_text(stmt, 2));
    
   
		identify[i] = id;
		english[i] = en;
		polish[i] = pl;
	  
    	
    }
    
    
   	
    if (rd != SQLITE_DONE) {
    	printf("error: ", sqlite3_errmsg(db));
    }
	sqlite3_finalize(stmt); 
   
    sqlite3_close(db);
    
	
    
    
    
    
    
    		punkty = 0;
			napis = "";
			poprawna = "";
		    polskie  = "";
		    angielskie = "";
		    std::string punkty1 = ""; 
			punkty1 = "Punkty: ";
		    losuj();
		    
			sf::Texture tloTryb;
            tloTryb.loadFromFile("src/autob.jpg");
    
            sf::Sprite tlo12;
            tlo12.setTexture(tloTryb);
            tlo12.setPosition(0,0);
            
            pole1.setSize(sf::Vector2f(300, 50));
			pole1.setOutlineColor(sf::Color::Red);
			pole1.setOutlineThickness(5);
			pole1.setPosition(100, 100);
			
			pole2.setSize(sf::Vector2f(300, 50));
			pole2.setOutlineColor(sf::Color::Red);
			pole2.setOutlineThickness(5);
			pole2.setPosition(100, 200);
			
			
			font.loadFromFile("src/arial.ttf");

			sf::Text text("Losuj slowko - Enter", font);
			text.setCharacterSize(30);
			text.setStyle(sf::Text::Bold);
			text.setColor(sf::Color::Red);
			text.setPosition(100,10);
			
			
			sprawdzenie.setCharacterSize(35);
			sprawdzenie.setString(napis);
			sprawdzenie.setFont(font);
			sprawdzenie.setStyle(sf::Text::Bold);
			sprawdzenie.setColor(sf::Color::Red);
			sprawdzenie.setPosition(50,400);
			
			punkt.setCharacterSize(30);
			punkt.setString(punkty1);
			punkt.setFont(font);
			punkt.setStyle(sf::Text::Bold);
			punkt.setColor(sf::Color::Red);
			punkt.setPosition(150,45);
			
			text1.setCharacterSize(30);
			text1.setString(angielskie);
			text1.setFont(font);
			text1.setStyle(sf::Text::Bold);
			text1.setColor(sf::Color::Black);
			text1.setPosition(110,105);
		
			text2.setCharacterSize(30);
			text2.setString(polskie);
			text2.setFont(font);
			text2.setStyle(sf::Text::Bold);
			text2.setColor(sf::Color::Black);
			text2.setPosition(110,205);
				
				while (window1.isOpen())
    			{
        			sf::Event event;
        			while (window1.pollEvent(event))
        			{
            
						if (event.type == sf::Event::Closed){
			    			window1.close();
			    			przeslij_pkt();
        				}
        				
        				if(event.type==sf::Event::TextEntered  && polskie.size()<=12 )
            			{
							char code=static_cast<char>(event.text.unicode);
		
							if(event.text.unicode==13 && polskie.size()!=0)//enter
							{
                  				if(polskie == poprawna){
                  					napis = "Dobrze ! + 1 Pkt";
                  					sprawdzenie.setString(napis);
                  					punkty = punkty +1;
                  					std::stringstream ss;
        							ss << punkty;
        							punkt.setString(punkty1+ss.str());
                  				}
								else{
									napis = "Zle, poprawna : "+poprawna;
									sprawdzenie.setString(napis);
								}
                   				polskie = "";
                   				napis = "";
                   				text2.setString(polskie);
                   				losuj();
                   				text1.setString(angielskie);
                   				
							}

							else if(code!='\b'){
								napis = "";
								sprawdzenie.setString(napis);
								polskie.push_back(code);
           			           	text2.setString(polskie);}
							else if(code=='\b')
							{
								if(polskie.size()>0){
							//	polskie.pop_back();
                                text2.setString(polskie);
                           		 }
                                
							}
               				 else text2.setString(polskie);
           				 }
				
					}
				
				
				window1.clear();
				window1.draw(tlo12);
				window1.draw(pole1);
				window1.draw(pole2);
				window1.draw(text);
				window1.draw(sprawdzenie);
				window1.draw(text1);
				window1.draw(text2);
				window1.draw(punkt);
				window1.display();
		}
}
