#include <SFML/Graphics.hpp>
#include"A4.h"
#include"P_A.h"
#include"Harrier.h"
#include"Proyectil.h"
#include"Arreglo.h"

using namespace sf;

int main(int argc, char *argv[]){
	float y=300, x=150;
	float yo=-600, yo1=600;
	RenderWindow w(VideoMode(400,600),"Ejemplo de SFML");
	Texture t,th,tp_a, t_oceano, t_oceano1, tpr, t_exp;
	t.loadFromFile("a4Arg.png");
	tp_a.loadFromFile("dest.png");
	th.loadFromFile("harrier.png");
	t_oceano1.loadFromFile("Ocean1.png");
	t_oceano.loadFromFile("Ocean1.png");
	tpr.loadFromFile("bala1.png");
	t_exp.loadFromFile("explosion1.png");
	Sprite s, sp_a, sh,s_oceano, s_oceano1, spr, s_exp;
	
	
	A4 player(150,300,t);
	P_A porta_a(100,-200,tp_a);
	Harrier har(0,100, th, t_exp);
	
	Arreglo proy;
	for(int i=0; i<proy.getSize();i++){
		proy.setProyectil(i, nullptr);
	}
	
	s_oceano1.setTexture(t_oceano1);
	s_oceano.setTexture(t_oceano);
	s.setTexture(t);
	sp_a.setTexture(tp_a);
	sh.setTexture(th);
	spr.setTexture(tpr);
	s_exp.setTexture(t_exp);
	w.setFramerateLimit (60);

	porta_a.mov(0,100);
	
	while(w.isOpen()) {
		Event e;
		
		while(w.pollEvent(e)) {

			switch(e.type){ 
			case Event::Closed:
				w.close();
			break;}

			
				if(Keyboard::isKeyPressed(Keyboard::Left)){
					player.mov(-9,0);
			    }
				
				if(Keyboard::isKeyPressed(Keyboard::Right)){
					player.mov(9,0);
				}
				
				if(Keyboard::isKeyPressed(Keyboard::Up)){
					player.mov(0,-9);}
				
				if(Keyboard::isKeyPressed(Keyboard::Down)){
					player.mov(0,9);}
				
				if(Keyboard::isKeyPressed(Keyboard::Space)){
					int i;
					
					for(i=0;i<proy.getSize();i++){
						if(proy.getProyectil(i)==nullptr){
						Proyectil *tmp=new Proyectil(player.getX()+2,player.getY(),tpr);
						proy.setProyectil(i,tmp);
						break;
					}
				}
				if(i==proy.getSize()){
					proy.duplicar();
					Proyectil *tmp=new Proyectil(player.getX()+2,player.getY(),tpr);
					proy.setProyectil(i, tmp);
				}
			for(int i=0;i<proy.getSize();i++){
					if(proy.getProyectil(i)!=nullptr){
						if(proy.getProyectil(i)->mov()){
							delete proy.getProyectil(i);
							proy.setProyectil(i,nullptr);
						}
					}
				}
		    }
		}
		//y-=2;
		yo1+=0.8;
		if(yo1>1200){
			yo1=0;
			har.mov(50,0);
		}
		yo+=0.8;
		if(yo>=600){
			yo=-600;
		}

		s_oceano1.setPosition(0, yo1-600);
		s_oceano.setPosition(0, yo);
		w.clear();
		w.draw(s_oceano);
		w.draw(s_oceano1);
		porta_a.dib(w);		
		har.dib(w);
		player.dib(w);
		for(int i=0;i<proy.getSize();i++){
			if(proy.getProyectil(i)!=nullptr){
				proy.getProyectil(i)->dib(w);
			}
		}
		if(spr.getGlobalBounds().intersects(sh.getGlobalBounds())){
			har.colision(w);
			y<0;
		}
		w.display();
	}return 0;
}

