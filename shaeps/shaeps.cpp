
#include <iostream>
#include<SFML\Graphics.hpp>
#include<math.h>
#include<vector>
#include <ctime>
#include "square.h"

//globals
bool keys[] = { false, false, false, false, false };
enum DIRECTIONS { LEFT, RIGHT, UP, DOWN, CLICK }; //left is 0, right is 1, up is 2, down is 3


int vx, vy;
int map[20][20] = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
        1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,
        1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,
        1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,
        1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,
        9,9,9,1,0,1,0,0,0,0,0,0,0,1,0,1,9,9,9,9,
        1,1,1,1,0,1,0,1,1,0,1,1,0,1,0,1,1,1,1,1,
        0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,
        2,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,
        9,9,9,1,0,1,0,0,0,0,0,0,0,1,0,1,9,9,9,9,
        1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
        1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,
        1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
        1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,
        1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

std::vector<square*> colums;
std::vector<square*> rows;


int main()
{
    //setting up the vector of squarety pointers indexes in memory, not pushing anything to them yet
    for (int x = 0; x < 20; x++) {

        for (int y = 0; y < 20; y++) {

        }
    }

    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(800, 800), "Platformer");
    std::cout << "Hello World!\n";
    window.setFramerateLimit(240);
    square bruh(200, 200, 2, 10, "hi");
    while (window.isOpen())
    {
        bruh.draw(window);


        // Process events----------------------------------------------------------------------------------------------------------------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit--------------------------------------------------------------------------------------------------------------------------
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            //key strokes -----------------
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                keys[LEFT] = true;
            }
            else keys[LEFT] = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                keys[RIGHT] = true;
            }
            else keys[RIGHT] = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                keys[UP] = true;
            }
            else keys[UP] = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                keys[DOWN] = true;
            }
            else keys[DOWN] = false;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                keys[CLICK] = true;


            }
            else keys[CLICK] = false;

        }
        if (keys[LEFT] == true) {

            vx = -1;
        }

        else if (keys[RIGHT] == true) {

            vx = 1;
        }

        else vx = 0;

        if (keys[UP] == true) {

            vy = -1;
        }

        else if (keys[DOWN] == true) {

            vy = 1;
        }

        else vy = 0;

        if (keys[CLICK] == true) {
            bruh.setorigin(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            bruh.update();
        }
        else

            //velocity ----
            bruh.x += vx;
        bruh.y += vy;
        bruh.update();
        //end vel start draw



        window.display();
        window.clear();
    }//end event loop---------------------------------------------------------------



}