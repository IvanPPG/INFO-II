#include <SFML/Graphics.hpp>
#ifndef VIDA_H
#define VIDA_H
using namespace sf;
class Vida{
public:
	Vida(float x_i, float y_i, Texture &thal);
	void dib(RenderWindow &w);
	void perder(RenderWindow &w);
	
private:
Sprite shal;
float x=0;
float y=0;
};

#endif

