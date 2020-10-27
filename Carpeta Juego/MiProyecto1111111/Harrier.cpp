#include "Harrier.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Harrier::Harrier(float x_i,float y_i,Texture &th,Texture &t_exp) {
	x=x_i;
	y=y_i;
	sh.setTexture(th);
	sh1.setTexture(th);
	s_exp.setTexture(t_exp);
}
void Harrier::mov(float x, float y){
	this->x+=x+3;
	this->y=y++;
	if(this->x<0){
		this->x=400;
	}
	if(this->x>400){
		this->x=0;
	}
	if(this->y<650){
		this->y-=3;
	}
	if(this->y>650){
		this->y-650;
		this->x+=100;		
	}
	if(this->x<0){
		this->x=450;
	}
	if(this->x>400){
		this->x=100;
	}
}

void Harrier::dib(RenderWindow &w,Texture &th){
	sh.setTexture(th);
	this->y+=0.2;
	sh.setPosition(this->x, this->y++);
	w.draw(sh);
}

void Harrier::colision(RenderWindow &w){
	s_exp=sh;
	w.draw(s_exp);
}
