#include "stdafx.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

const int MIN = 0, MAX = 250;

class Test
{
private:
	int r;
	int g;
	int b;

public:
	Test() : r(100), g(100), b(100) {}
	int GetR() const { return r; }
	int GetG() const { return g; }
	int GetB() const { return b; }

	int IncrementR() { return r += 10; }
	int IncrementG() { return g += 10; }
	int IncrementB() { return b += 10; }

	int DecrementR() { return r -= 10; }
	int DecrementG() { return g -= 10; }
	int DecrementB() { return b -= 10; }

	void SetR(int r) { this->r = r; }
	void SetG(int g) { this->g = g; }
	void SetB(int b) { this->b = b; }

};

int main(int argc, char *argv[])
{

	Test * t = new Test;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Sweat's Window");

	sf::Event event;
	sf::CircleShape shape(100);

	shape.setFillColor(sf::Color(t->GetR(), t->GetG(), t->GetB()));

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			else if (event.type == sf::Event::MouseButtonPressed)
			{

				if (event.mouseButton.button == sf::Mouse::Right)
				{
					t->DecrementR();
					t->DecrementG();
					t->DecrementB();

					if (t->GetR() <= MIN || t->GetG() <= MIN || t->GetB() <= MIN)
					{
						t->SetR(MIN);
						t->SetG(MIN);
						t->SetB(MIN);

						std::cout << "ERORR: CAN'T GO LOWER!" << std::endl;
						shape.setFillColor(sf::Color(t->GetR(), t->GetG(), t->GetB()));
					}

					else
					{
						shape.setFillColor(sf::Color(t->GetR(), t->GetG(), t->GetB()));

						std::cout << "Right Mouse Button Pressed: " << std::endl;
						std::cout << "---------------------------" << std::endl;
						std::cout << "RED: " << t->GetR() << "." << std::endl;
						std::cout << "BLUE: " << t->GetB() << "." << std::endl;
						std::cout << "GREEN: " << t->GetG() << "." << std::endl;
						std::cout << "---------------------------" << std::endl;
					}
				}

				else if (event.mouseButton.button == sf::Mouse::Left)
				{
					t->IncrementR();
					t->IncrementG();
					t->IncrementB();

					if (t->GetR() > MAX || t->GetG() > MAX || t->GetB() > MAX)
					{
						t->SetR(MAX);
						t->SetG(MAX);
						t->SetB(MAX);

						std::cout << "ERROR: CAN'T GO HIGHER! " << std::endl;
						shape.setFillColor(sf::Color(t->GetR(), t->GetG(), t->GetB()));
					}

					else
					{
						shape.setFillColor(sf::Color(t->GetR(), t->GetG(), t->GetB()));

						std::cout << "Left Mouse Button Pressed: " << std::endl;
						std::cout << "---------------------------" << std::endl;
						std::cout << "RED: " << t->GetR() << "." << std::endl;
						std::cout << "BLUE: " << t->GetB() << "." << std::endl;
						std::cout << "GREEN: " << t->GetG() << "." << std::endl;
						std::cout << "---------------------------" << std::endl;
					}
				}
			}

			else if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					shape.move(0, -10);
				}

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					shape.move(0, 10);
				}

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					shape.move(10, 0);
				}

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					shape.move(-10, 0);
				}
			}
		}

		window.clear(sf::Color::Black);
		window.draw(shape);
		window.display();
	}
	
	delete t;

	return EXIT_SUCCESS;
}
