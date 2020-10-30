#ifndef PUNTUACION_H
#define PUNTUACION_H
#include <SFML/Graphics.hpp>
#include <string>

class Puntuacion {
private:
	
	sf::Font font;
	
	sf::Text puntuacion;
	
public:
	Puntuacion();
	
	~Puntuacion();
	
	void draw(sf::RenderWindow &w);
	
	void incremento(int score);
	
	void savescore(int);
};


#endif //PUNTUACION_H
