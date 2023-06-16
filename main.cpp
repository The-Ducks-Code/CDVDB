#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{

    // the inital values for the velocity of the window gotten from the command prompt
    int initxvel;
    int inityvel;
    
    int i;
    std::cout << "Enter the velocity at which the logo moves (1-350, less than one makes it not move and over 350 breaks it and it goes out of bounds):";
    std::cin >> i; 

    initxvel = i;
    inityvel = i;

    int xvel = initxvel;
    int yvel = inityvel;
    


    // render the window
    sf::RenderWindow window(sf::VideoMode(510, 300), "DVD", sf::Style::None);


    sf::Texture dvdtex;
    if (!dvdtex.loadFromFile("src/include/sprites/dvd.png"))
    {
        // error...
    }
    
    sf::Sprite dvd;
    dvd.setTexture(dvdtex);
    dvd.setScale(sf::Vector2f(0.5f, 0.5f));
    
    std::cout << sf::VideoMode::getDesktopMode().width << ", " << sf::VideoMode::getDesktopMode().height;

   // make it so it will place the window where the mouse is unless it is out of bounds which in that case it places it in the center of the screen

    if (sf::Mouse::getPosition().x < sf::VideoMode::getDesktopMode().width - window.getSize().x && sf::Mouse::getPosition().y < sf::VideoMode::getDesktopMode().height - window.getSize().y)
    {
        window.setPosition(sf::Mouse::getPosition());

    }

    // while the window is open
    while (window.isOpen())
    {
                 sf::Event event;
        while (window.pollEvent(event))
        {

            // if the close button is clicked
            if (event.type == sf::Event::Closed)
            // close the program
                window.close();
            

        }
        
        if(window.getPosition().x >= sf::VideoMode::getDesktopMode().width - window.getSize().x)
        {
            xvel = -xvel;
            dvd.setColor(sf::Color(0, 255, 0)); 


        }else if (window.getPosition().x <= 0 )
        {
            xvel = initxvel;
            dvd.setColor(sf::Color(255, 0, 0));
        } 
        
        if(window.getPosition().y >= sf::VideoMode::getDesktopMode().height - window.getSize().y)
        {       
            yvel = -yvel;  // if the window is too high, it will move down.
            dvd.setColor(sf::Color(0, 0, 255));
  
        }else if (window.getPosition().y <= 0)
        {
            yvel = inityvel;
            dvd.setColor(sf::Color(255, 255, 255));
        } 
        
        window.setPosition(window.getPosition() + sf::Vector2i(xvel, yvel)); // move the window

        // clear the window with black color
        window.clear();
        window.draw(dvd);
        window.display();
        
        
    }
    

    return 0;
}