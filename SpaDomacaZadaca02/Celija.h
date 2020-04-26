#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Celija
{
private:
	RenderWindow* window;
	bool alive;
	bool alive_next;
	float x;
	float y;
	float width;
	float height;
	int ticks;
	int neighbours;
	int map(int in, int in_min, int in_max, int out_min, int out_max);

public:
	Celija(RenderWindow* window, bool alive, float x, float y, float width, float height);
	void calculate(vector<bool>& celije);
	void draw();
	bool get_alive();
	bool hasNeighbours();

};

