#ifndef P_A_H
#define P_A_H
#include <SFML/Graphics.hpp>
using namespace sf;

class P_A {
public:
	P_A(float x_i,float y_i,Texture &tp_a);
	void mov(float x, float y);
	void dib(RenderWindow &w);
private:
	float x;
	float y;
	Sprite sp_a;
};

#endif

