#include <SFML/Graphics.hpp>
#include "gameover.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Main Menu");

    Menu menu(window.getSize().x, window.getSize().y);
//tevoorschijn halen van je achtergrond foto
    sf::Texture t1;
    t1.loadFromFile("C:/Users/User/Downloads/my art/illustratorfiles/gameover.png");
	sf::Sprite sBackground(t1);

	//functies voor het gebruiken van up and down keys
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Try Again button has been pressed" << std::endl;
						break;
					
					case 1:
						window.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

        window.clear();
        window.draw(sBackground);
        menu.draw(window);
        window.display();
    }

    return 0;
}