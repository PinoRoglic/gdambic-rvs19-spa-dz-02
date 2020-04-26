#include <SFML/Graphics.hpp>
#include <vector>
#include "Celija.h"
#include <time.h>

using namespace std;

int main()
{
	Clock clock;
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(800, 800), "Pino Rogliæ Zadaca 2");
	window.setFramerateLimit(60);
	vector<Celija> celije;
	int n_x = 30;
	int n_y = 30;
	int n2_x = n_x + 2;
	float width = window.getSize().x / n_x;
	float height = window.getSize().y / n_y;
	for (int i = 0; i < n_y + 2; i++) {
		for (int j = 0; j < n_x + 2; j++) {
			bool temp = false;
			if (rand() % 4 == 0) temp = true;
			if (i == 0 || i == n_y + 2 || j == 0 || j == n_x + 2) {
				celije.push_back(Celija(&window, false, -10, -10, 0, 0));
			}
			else {
				celije.push_back(Celija(&window, temp, (j - 1) * width, (i - 1)  * height, width, height));
			}
		}
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		Time t = clock.getElapsedTime();

		if (t.asMilliseconds() > 10) {
			for (int i = 1; i < n_y + 1; i++) {
				for (int j = 1; j < n_x + 1; j++) {
					int k = i * n2_x + j;
					if (true) {
						vector<bool> temp;
						temp.push_back(celije[k - n2_x - 1].get_alive());
						temp.push_back(celije[k - n2_x].get_alive());
						temp.push_back(celije[k - n2_x + 1].get_alive());
						temp.push_back(celije[k - 1].get_alive());
						temp.push_back(celije[k + 1].get_alive());
						temp.push_back(celije[k + n2_x - 1].get_alive());
						temp.push_back(celije[k + n2_x].get_alive());
						temp.push_back(celije[k + n2_x + 1].get_alive());
						celije[k].calculate(temp);
					}
				}
			}
			window.clear();
			for (int i = 0; i < celije.size(); i++) {
				celije[i].draw();
			}
			window.display();
			clock.restart();
		}
	}

	return 0;
}