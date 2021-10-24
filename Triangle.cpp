#include "Triangle.h"

Triangle::Triangle(sf::Vector2f x, sf::Vector2f y, sf::Vector2f z) 
{
    a1 = x;
    a2 = y;
    a3 = z;

    left = NULL;
    right = NULL;
    bottom = NULL;
}

void Triangle::draw(sf::RenderTarget &target, sf::RenderStates states) const 
{
    sf::Vertex line[] = 
    {
        sf::Vertex(a1),
        sf::Vertex(a2)
    };
    
    target.draw(line, 2, sf::Lines);

    line[0] = sf::Vertex(a2);
    line[1] = sf::Vertex(a3);
    target.draw(line, 2, sf::Lines);

    line[0] = sf::Vertex(a1);
    line[1] = sf::Vertex(a3);
    target.draw(line, 2, sf::Lines);
}
