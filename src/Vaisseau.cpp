#include "Vaisseau.h"
#include "IConstante.h"

#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>

Vaisseau::Vaisseau(const int x, const int y)
:x(x), y(y)
{
    if (!vaisseau_texture.loadFromFile("Images/Avatars/X-Wing.png"))
    {
        std::cout << "ok" << std::endl;
    }

    //Coordonnées de départ du personnage
//    x = 7150;
//    y = 3500;
    sf::IntRect rect(0, 0, 125, 125);
    rectSourceSprite = rect;
    vaisseau_sprite.setTexture(vaisseau_texture);
    vaisseau_sprite.setTextureRect(rectSourceSprite);
    vaisseau_sprite.setPosition(x, y);
    vaisseau_sprite.setOrigin(VAISSEAU_COORDONNEE_ORIGINE, VAISSEAU_COORDONNEE_ORIGINE);
}

Vaisseau::~Vaisseau()
{
    //dtor
}

Vaisseau& Vaisseau::operator=(const Vaisseau& v)
{
    if (this != &v) {
        x = v.x;
        y = v.y;
    } // handle self assignment
    //assignment operator
    return *this;
}

void Vaisseau::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(vaisseau_sprite);
}

int Vaisseau::seDeplacerX(Event event, int x)
{
    if(rectSourceSprite.left == 0)
    {
        rectSourceSprite.left = 125;
        //rectSourceSprite.left += 125;
        cout << "if " + to_string(rectSourceSprite.left) << endl;
    }
    if (rectSourceSprite.left == 125)
    {
        rectSourceSprite.left = 250;
        cout << "if/2 " + to_string(rectSourceSprite.left) << endl;
    }
    else if (rectSourceSprite.left == 250)
    {
        rectSourceSprite.left = 125;
        cout << "else if " + to_string(rectSourceSprite.left) << endl;
    }

//    rectSourceSprite.left = 250;
//    cout << "compteur" + to_string(rectSourceSprite.left) << endl;

    switch (event.key.code)
    {
        case sf::Keyboard::Left:
        {
            if(x>1000)
            {
                x = x - 50;
               //vaisseau_sprite.setRotation(270);
                rectSourceSprite.top = 125;
                //rectSourceSprite.left = 125;
                cout << "X: "<< x << endl;
            }
            else
            {
                rectSourceSprite.top = 375;
                //vaisseau_sprite.setRotation(90);

            }
            break;
        }

        case sf::Keyboard::Right:
        {
            if(x<12000)
            {
                x = x + 50;
                //vaisseau_sprite.setRotation(90);
                rectSourceSprite.top = 375;
                cout << "X: "<< x << endl;
            }
            else
            {
                rectSourceSprite.top = 125;
                //vaisseau_sprite.setRotation(270);
            }
            break;
        }
        default:
        break;
    }
    vaisseau_sprite.setTextureRect(rectSourceSprite);
    return x;
}

int Vaisseau::seDeplacerY(Event event, int y)
{

    if(rectSourceSprite.left == 0)
    {
        rectSourceSprite.left = 125;
        //rectSourceSprite.left += 125;
        cout << "if " + to_string(rectSourceSprite.left) << endl;
    }
    if (rectSourceSprite.left == 125)
    {
        rectSourceSprite.left = 250;
        cout << "if/2 " + to_string(rectSourceSprite.left) << endl;
    }
    else if (rectSourceSprite.left == 250)
    {
        rectSourceSprite.left = 125;
        cout << "else if " + to_string(rectSourceSprite.left) << endl;
    }

    switch (event.key.code)
    {
        case sf::Keyboard::Up:
        {
            if(y>1000)
            {
                y = y - 50;

                rectSourceSprite.top = 0;
                cout << "Y: "<< y << endl;
            }
            else
            {
                rectSourceSprite.top = 250;
            }
            break;
        }

        case sf::Keyboard::Down:
        {
            if(y<6500)
            {
                y = y + 50;
                rectSourceSprite.top = 250;
                cout << "Y: "<< y << endl;
            }
            else
            {

                rectSourceSprite.top = 0;
            }
            break;
        }
        default:
        break;
    }
    vaisseau_sprite.setTextureRect(rectSourceSprite);
    return y;
}

int Vaisseau::getX() const
{
    return x;
}

void Vaisseau::setX(const int &x)
{
    this->x = x;
}

int Vaisseau::getY() const
{
    return y;
}

void Vaisseau::setY(const int &y)
{
    this->y = y;
}
