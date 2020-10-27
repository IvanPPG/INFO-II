#include <SFML/Graphics.hpp>
#include "A4.h"
using namespace sf;

A4::A4(float x_i,float y_i,Texture &t, Texture &t_exp) {
	x=x_i;
	y=y_i;
	s.setTexture(t);
	s_exp.setTexture(t_exp);
}
void A4::mov(float x, float y){
	this->x+=x;
	this->y+=y;
	if(this->x<0){
		this->x=0;
	}
	if(this->x>600-s.getTexture()->getSize().x){
		this->x=600-s.getTexture()->getSize().x;
	}
	if(this->y<0){
		this->y=0;
	}
	if(this->y>600-s.getTexture()->getSize().y){
		this->y=600-s.getTexture()->getSize().y;
	}
}
void A4::dib(RenderWindow &w){
	s.setPosition(this->x, this->y);
	w.draw(s);
	
}

void A4::colision(RenderWindow &w){
	s=s_exp;
}
