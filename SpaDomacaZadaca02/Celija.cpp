#include "Celija.h"

using namespace std;
using namespace sf;

Celija::Celija(RenderWindow* window, bool alive, float x, float y, float width, float height)
{
	this->window = window;
	this->alive = alive;
	this->alive_next = false;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->ticks = 0;
}

void Celija::calculate(vector<bool>& celije)
{
	int n = 0;
	for (int i = 0; i < celije.size(); i++) {
		if (celije[i]) n++;
	}
	neighbours = n;
	if (alive) {
		if (n >= 2 && n <= 3) {
			alive_next = true;
		}
		else {
			alive_next = false;
		}
	}
	else {
		if (n == 3) {
			alive_next = true;
		}
		else {
			alive_next = false;
		}
	}

}

void Celija::draw()
{
	alive = alive_next;
	if (alive) ticks++;
	else ticks = 0;
	RectangleShape celija;
	celija.setSize(Vector2f(width, height));
	celija.setPosition(Vector2f(x, y));
	if (ticks > 10) ticks = 10;
	if (ticks == 0)	celija.setFillColor(Color(0, 0, 0, 255));
	else celija.setFillColor(Color(255, 0, 0, map(ticks, 0, 10, 30, 255)));	
	celija.setOutlineColor(Color(0, 0, 0));
	celija.setOutlineThickness(2);
	window->draw(celija);
}

bool Celija::get_alive()
{
	return alive;
}

bool Celija::hasNeighbours()
{
	if (neighbours == 0) return false;
	return true;
}

int Celija::map(int in, int in_min, int in_max, int out_min, int out_max)
{
	int out;
	if (in < in_min) in = in_min;
	if (in > in_max) in = in_max;
	out = out_min + (out_max - out_min) * in / (in_max - in_min);
	if (out < out_min) out = out_min;
	if (out > out_max) out = out_max;
	return out;
}

