#include <SFML/Graphics.hpp>
#ifndef PROYECTIL_H
#define PROYECTIL_H
using namespace sf;

class Proyectil {
public:
	Proyectil(float x,float y,Texture &tpr);
	~Proyectil();
	bool mov();
	void dib(RenderWindow &w);
private:
	float x;
	float y;
	Sprite spr;
};

#endif

