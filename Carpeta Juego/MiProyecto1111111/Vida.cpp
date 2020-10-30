#include <SFML/Graphics.hpp>
#include "Vida.h"
using namespace sf;
Vida::Vida(float x_i,float y_i,Texture &thal) {
	x=x_i;
	y=y_i;
	shal.setTexture(thal);
}

void Vida::dib(RenderWindow &w){
	shal.setPosition(this->x, this->y);
	w.draw(shal);
}
//void Vida::perder(RenderWindow &w){
//	shal.setColor(color::Transparents);
//}
