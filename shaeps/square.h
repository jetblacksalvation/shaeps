#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
class square {
public:             // Access specifier
    int x;
    int y;          // Attribute (int variable)
    float dial;
    float f;
    float ydil;

    sf::VertexArray lines;
    std::string name;


    square(int xpos, int ypos, float dialation, float fdis, std::string names) {
        x = xpos;
        y = ypos;
        dial = dialation;
        f = fdis;

        name = names;

        ydil = sqrt(dial * pow(f, 2) - pow(f, 2));

        lines.setPrimitiveType(sf::PrimitiveType::Quads);

        lines.append(sf::Vertex(sf::Vector2f(x - f, y - ydil), sf::Color::White));
        lines.append(sf::Vertex(sf::Vector2f(x + f, y - ydil), sf::Color::White));
        lines.append(sf::Vertex(sf::Vector2f(x + f, y + ydil), sf::Color::White));
        lines.append(sf::Vertex(sf::Vector2f(x - f, y + ydil), sf::Color::White));



    }
    void update() {
        lines[0].position = sf::Vector2f(x - f, y - ydil);
        lines[1].position = sf::Vector2f(x + f, y - ydil);
        lines[2].position = sf::Vector2f(x + f, y + ydil);
        lines[3].position = sf::Vector2f(x - f, y + ydil);

    }
    void add(int xs, int ys) {
        x += xs;
        y += ys;

    }
    void setorigin(int xs, int ys) {
        x = xs;
        y = ys;
    }
    void draw(sf::RenderWindow& wind) {
        wind.draw(lines);
    }
    void move() {

    };

};