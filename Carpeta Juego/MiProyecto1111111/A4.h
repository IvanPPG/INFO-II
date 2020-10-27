#include <SFML/Graphics.hpp>
#ifndef A4_H
#define A4_H
using namespace sf;
class A4 {
public:
	A4(float x_i,float y_i,Texture &t,Texture &t_exp);
	void mov(float x, float y);
	void dib(RenderWindow &w);
	void colision(RenderWindow &w);
	float getX(){return x;};
	float getY(){return y;};
	
private:
	float x;
	float y;
	Sprite s;
	Sprite s_exp;
};

#endif

