#include "Proyectil.h"
#include <SFML/Graphics.hpp>
#ifndef HARRIER_H
#define HARRIER_H
using namespace sf;

class Harrier {
public:
	Harrier(float x_i,float y_i,Texture &th,Texture &t_exp);
	void mov(float x, float y);
	void dib(RenderWindow &w);
	void colision(RenderWindow &w);

private:
	float x;
	float y;
	Sprite sh;
	Sprite s_exp;
};

#endif

