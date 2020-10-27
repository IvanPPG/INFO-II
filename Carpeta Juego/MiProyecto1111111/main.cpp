#include <SFML/Graphics.hpp>
#include"A4.h"
#include"P_A.h"
#include"Harrier.h"
#include"Proyectil.h"
#include"Arreglo.h"

using namespace sf;

int main(int argc, char *argv[]){
	float y=550, x=150, xm=135, ym=-100, yo=-600, yo1=600;

	RenderWindow w(VideoMode(600,600),"Ejemplo de SFML");

	Texture t,th,th1,tp_a, t_oceano, t_oceano1, tpr, t_exp, tm,tt;
	
	t.loadFromFile("a4Arg.png");
	tp_a.loadFromFile("dest.png");
	th.loadFromFile("harrier.png");
	t_oceano.loadFromFile("agua.jfif");
	tpr.loadFromFile("bala1.png");
	t_exp.loadFromFile("explosion1.png");
	tm.loadFromFile("misil1.png");
	tt.loadFromFile("torre.png");
	
	Sprite s, sp_a, sh, sh1, sh2, s_oceano, s_oceano1, spr, s_exp, sm,ss;
	
	A4 player(150,300,t,t_exp);
	P_A porta_a(100,-200,tp_a);
	Harrier har(0,-200, th, t_exp);
	
	Arreglo proy;
	
	for(int i=0; i<proy.getSize();i++){
		proy.setProyectil(i, nullptr);
	}
	
	s_oceano1.setTexture(t_oceano);
	s_oceano.setTexture(t_oceano);
	s.setTexture(t);
	sp_a.setTexture(tp_a);
	sh.setTexture(th);
	sh1.setTexture(th);
	sh2.setTexture(th);
	spr.setTexture(tpr);
	s_exp.setTexture(t_exp);
	sm.setTexture(tm);
	ss.setTexture(tt);
	

	
	w.setFramerateLimit(100);
	
	while(w.isOpen()) {
		porta_a.mov(100,y++);
	
		Event e;

		while(w.pollEvent(e)) {
			
			switch(e.type){ 
			case Event::Closed:
				w.close();
			break;
			
			}
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Left)){
			player.mov(-2,0);
			ss.rotate(0.30);
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Right)){
			player.mov(2,0);
			ss.rotate(-0.30);
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Up)){
			player.mov(0,-2);
			if(player.getY()<300){
				ss.rotate(0.30);}
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Down)){
			player.mov(0,2);
			if(player.getY()<300){
				ss.rotate(-0.30);}
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Space)){
			int i;
			for(i=0;i<proy.getSize();i++){
				if(proy.getProyectil(i)==nullptr){
					Proyectil *tmp=new Proyectil(player.getX(),player.getY(),tpr);
					proy.setProyectil(i,tmp);
					break;
				}
			}
			
			if(i==proy.getSize()){
				proy.duplicar();
				Proyectil *tmp=new Proyectil(player.getX(),player.getY(),tpr);
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
		if(spr.getGlobalBounds().intersects(sh.getGlobalBounds())){
			har.colision(w);
		}
		sm.setColor(sf::Color(255,0,0));	
		sm.setPosition(xm=har.getX()-200,ym=har.getY()+70);
		sh2.setColor(sf::Color(0,0,255));
		sh1.setPosition(har.getX()+140,ym=har.getY()+150);
		sh2.setPosition(har.getX()+320,ym=har.getY()+75);
		if(har.getY()>50){
			ym!=har.getY();
			ym+=2.5;
			xm!=har.getX();
			xm=player.getX();
		}
		yo1+=1.2;
//		xm=player.getX();
		if(yo1>1200){
			yo1=0;
//			w.draw(sm);
		
		}
		
		if(har.getY()>800){
	//		har.dib(w, th);
			har.mov(50,-300);
		}
		
		yo+=1.2;
		if(yo>=600){
			yo=-600;
//			w.draw(sm);
		}
		
		xm=20+player.getX(); //MISIL SIGUE AL PLAYER FUNCIONA MEJORAR
//		if(ym<player.getY()-200){
//			ym++;
//		}
//		
//		if(xm<0){
//			xm=82;
//			xm+=100;
//		}
//		
//		if(xm>400){
//			xm=10;
//			xm+=100;
//		}
//		
		s_oceano1.setPosition(0, yo1-600);
		s_oceano.setPosition(0, yo);
		
		ss.setPosition(porta_a.getX()+50,porta_a.getY()+365);
		ss.setOrigin(ss.getTexture()->getSize().x/2.f,ss.getTexture()->getSize().y/2.f);//Tomar el Sprite por el centro (nos sirve para hacerlo rotar).
		
		
		w.clear();
		w.draw(s_oceano);
		w.draw(s_oceano1);
		porta_a.dib(w);	
		w.draw(ss);
		w.draw(sh1);
		w.draw(sh2);
		player.dib(w);
		w.draw(sm);
		har.dib(w, th);
		//w.draw(s_exp);
		
		for(int i=0;i<proy.getSize();i++){
			if(proy.getProyectil(i)!=nullptr){
				proy.getProyectil(i)->dib(w);
			}
		}
		
		w.display();
		
	}return 0;
	
}
		
