#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "sqlite3.h"
#include "MainWindow.h"
#include "Tryb1.h"



using namespace std;

int main()
{   
	srand( time( NULL ) );
	


	MainWindow main;  
    main.run();
    
   
    
  	
    return 0;
}
