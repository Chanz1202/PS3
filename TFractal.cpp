/*
NAME: Hanuman Sai Chanukya Srinivas Chilamkuri
Course: COMP 2040
Instructor: Dr Rykalova
PS3 assignment
Due date: 10/18/2021
*/

#include "Triangle.h"
#include <iostream>
#include <vector>
#include <math.h>

#define win_h 500
#define win_w 500

void fTree(Triangle tria, int depth, int height, sf::RenderWindow *win)
{
    if(depth <= 0)
        return;
    
    std::cout << "calculating depth for sub-triangles: " << depth << std::endl;

    tria.bottom = new Triangle(sf::Vector2f(tria.a3.x - height, tria.a3.y), tria.a3, sf::Vector2f(tria.a3.x - height/2, tria.a3.y + (height * sqrt(3)/2)));
    
    tria.left = new Triangle(sf::Vector2f(tria.a1.x - height/2, tria.a1.y - height), sf::Vector2f(tria.a1.x + height/2, tria.a1.y - height), tria.a1);
    
    tria.right = new Triangle(tria.a2, sf::Vector2f(tria.a2.x + height, tria.a2.y), sf::Vector2f(tria.a2.x + height/2, tria.a2.y + height));

    win -> draw(*tria.bottom);
    win -> draw(*tria.left);
    win -> draw(*tria.right);

    depth--;

    fTree(*tria.left, depth, height/2, win);
    fTree(*tria.right, depth, height/2, win);
    fTree(*tria.bottom, depth, height/2, win);
}

int main(int argc, char* argv[]) 
{

    if (argc!= 3) 
    {
        std::cout << "\n\nUse only two command line arguments i.e; ./TFractal [height] [depth]\n\n";
        return -1;
    }

    sf::RenderWindow win(sf::VideoMode(win_w, win_h), "Triangle Fractal");
    win.setFramerateLimit(60);

    int height = atoi(argv[1]);
    int depth = atoi(argv[2]);

    float x = win_w/2 - height/2;
    float y = win_h/2 - height/2;


    Triangle initialTriangle(sf::Vector2f(x, y), sf::Vector2f(x + height, y), sf::Vector2f(x + height/2, y + (height * sqrt(3)/2)));

    win.draw(initialTriangle);
    fTree(initialTriangle, depth, height/2, &win);

    std::cout << "End of Rendering" << std::endl;

    sf::Vector2u winSize = win.getSize();
    sf::Texture texture;
    texture.create(winSize.x, winSize.y);
    texture.update(win);
    sf::Image capture = texture.copyToImage();

    sf::Texture fix;
    fix.loadFromImage(capture);
    sf::Sprite f;
    f.setTexture(fix);
    
     int frames = 0;
    
    while (win.isOpen())
    {
	sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
        }

        win.clear(sf::Color::Blue);
        
        frames++;

        if (frames % 10 == 0)   
            f.setColor(sf::Color(rand() , rand() , rand() ));

        win.draw(f);
        
        win.display();
    }
}
