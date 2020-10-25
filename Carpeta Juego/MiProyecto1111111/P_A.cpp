#include "P_A.h"
using namespace sf;

P_A::P_A(float x_p,float y_p,Texture &tp_a) {
	x=x_p;
	y=y_p;
	sp_a.setTexture(tp_a);
}
void P_A::mov(float x, float y){
	this->x+=x;
	this->y=y++;
	if(this->x<0){
		this->x=400;
	}
	if(this->x>400-sp_a.getTexture()->getSize().x){
		this->x=0;
		this->x+=0.5;
	}
	if(this->y<60){
		this->y+=2;
	}
	if(this->y>60-sp_a.getTexture()->getSize().y){
		this->y=-60-sp_a.getTexture()->getSize().y;
		this->x+=100;
	}
	/*this->x+=x;
	this->y=y++;
	//this->y-=0.5;
	if(this->x<0){
		this->x=0;
	}
	if(this->x>200-sp_a.getTexture()->getSize().x){
		this->x=200-sp_a.getTexture()->getSize().x;
	}
	if(this->y<0){
		this->y=0;
	}
	if(this->y>200-sp_a.getTexture()->getSize().y){
		this->y=200-sp_a.getTexture()->getSize().y;
	}*/
}
void P_A::dib(RenderWindow &w){
	sp_a.setPosition(this->x, this->y++  );
	w.draw(sp_a);
	
}


