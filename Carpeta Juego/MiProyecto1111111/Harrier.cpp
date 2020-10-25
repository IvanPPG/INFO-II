#include "Harrier.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Harrier::Harrier(float x_i,float y_i,Texture &th,Texture &t_exp) {
	x=x_i;
	y=y_i;
	sh.setTexture(th);
	s_exp.setTexture(t_exp);
}
void Harrier::mov(float x, float y){
	this->x+=x;
	this->y=y++;
	if(this->x<0){
		this->x=400;
	}
	if(this->x>400-sh.getTexture()->getSize().x){
		this->x=0;
		this->x+=0.5;
	}
	if(this->y<600){
		this->y-=2;
	}
	if(this->y>600-sh.getTexture()->getSize().y){
		this->y=-600-sh.getTexture()->getSize().y;
		this->x+=100;
	}
}
void Harrier::dib(RenderWindow &w){
	sh.setPosition(this->x, this->y++);
	//sh=s_exp;
	w.draw(sh);
}
void Harrier::colision(RenderWindow &w){
  sh.setPosition(this->x, this->y++);
	sh=s_exp;
	sh.rotate(0.03);
	w.draw(sh);
	s_exp.setPosition(this->x, this->y++);
	w.draw(s_exp);
}
