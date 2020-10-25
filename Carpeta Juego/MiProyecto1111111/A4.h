#include <SFML/Graphics.hpp>
#ifndef A4_H
#define A4_H
using namespace sf;
class A4 {
public:
	A4(float x_i,float y_i,Texture &t);
	void mov(float x, float y);
	void dib(RenderWindow &w);
	int getX(){return x;};
	int getY(){return y;};
private:
	float x;
	float y;
	Sprite s;
};

#endif

