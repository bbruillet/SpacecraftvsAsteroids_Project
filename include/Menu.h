#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu : public sf::Drawable
{
public:
	Menu();

	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
           target.draw(menu_sprite);
    }



private:
	int selectedItemIndex;
	sf::Sprite menu_sprite;
    sf::Texture menu_texture;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};
