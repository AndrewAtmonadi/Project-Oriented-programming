#include "gameover.hpp"

//hier selecteer de font family die je tevoorschijn wilt halen
Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("C:/Users/User/OneDrive/adek/semester 2/OOP/sfml/Project1/Project1/ingame/INGAME.ttf"))
	{
		// handle error
	}
	//geeft de properties van je try again button aan
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Try Again");
	menu[0].setPosition(820, 640);
	menu[0].setCharacterSize(70);
	//geeft de properties van je exit button aan 
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString("Exit");
	menu[1].setPosition(900, 810);
	menu[1].setCharacterSize(70);



	selectedItemIndex = 0;
}

//functie bij openen van de nieuwe window 
Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}
//functie bij het bij het gebruiken van je boven key
void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
//functie bij het bij het gebruiken van je beneden key
void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}