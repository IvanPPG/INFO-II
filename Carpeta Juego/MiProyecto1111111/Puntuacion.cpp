#include <SFML/Graphics.hpp>
#include "Puntuacion.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include "Puntuacion.h"
#include <fstream>

Puntuacion::Puntuacion() {
	
	if (!font.loadFromFile("arial.ttf")){
		std::cout<<"Error en la fuente"<<std::endl;
	}
	
	puntuacion.setFont(font);
	puntuacion.setFillColor(sf::Color::Red);
	puntuacion.setString("0");
	puntuacion.setPosition(120,0);
	
}

void Puntuacion::draw(sf::RenderWindow &w) {
	w.draw(puntuacion);
}

Puntuacion::~Puntuacion() {
	
}

void Puntuacion::incremento(int score) {
	
	puntuacion.setString(std::to_string(score));
	
}

void Puntuacion::savescore(int score) {
	std::ofstream archive;
	std::ifstream read;
	std::string note=" ",comp=std::to_string(score);
	int x=0;
	
	archive.open("Hightscores.txt",std::ios::app);
	
	if(!archive.is_open()){
		std::cout<<"Error en Hightscores.txt"<<std::endl;
	}
	
	read.open("Hightscores.txt");
	
	if(!read.is_open()){
		std::cout<<"Error en Hightscores.txt"<<std::endl;
	}
	
	while (!read.eof() && x==0){
		std::getline(read,note);
		
		archive<<comp<<std::endl;
		
		x++;
	}
	
	archive.close();
	read.close();
}
		


