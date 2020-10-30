#include "Proyectil.h"
#include <SFML/Graphics.hpp>
#ifndef HARRIER_H
#define HARRIER_H
using namespace sf;

class Harrier {
public:
	Harrier(float x_i,float y_i,Texture &th,Texture &t_exp);
	void mov(float x, float y, Sprite &spr);
	void dib(RenderWindow &w, Texture &th);
	void colision(RenderWindow &w);
	float getY(){return y;};
	float getX(){return x;}
private:
	float x;
	float y;
	Sprite sh;
	Sprite sh1;
	Sprite s_exp;
	
};

#endif

