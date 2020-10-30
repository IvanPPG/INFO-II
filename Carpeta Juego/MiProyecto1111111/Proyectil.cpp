#include <SFML/Graphics.hpp>
#include "Proyectil.h"

using namespace sf;

Proyectil::Proyectil(float x,float y,Texture &t) {
	this->x=x;
	this->y=y;
	spr.setTexture(t);
}
Proyectil::~Proyectil(){};
bool Proyectil::mov(){
	this->y-=55;
	this->y;
	if(this->y<0){
		return true;
	}else{
		return false;
	}
}
void Proyectil::dib(RenderWindow &w){
	spr.setPosition(this->x+15, this->y-=2);
	w.draw(spr);
}	

