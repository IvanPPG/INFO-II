#include <SFML/Graphics.hpp>
#include <iostream>
#include"A4.h"
#include"P_A.h"
#include"Harrier.h"
#include"Proyectil.h"
#include"Arreglo.h"
#include"Puntuacion.h"
#include"Vida.h"
#include "LinkedList.h"

using namespace sf;

int main(int argc, char *argv[]) {
    float y = 550, x = 150, xm = 135, ym = -100, yo = -600, yo1 = 600;
    int score = 0;
    int mun = 5000;

    RenderWindow w(VideoMode(600, 600), "Grupo 7");
    Font font;
    font.loadFromFile("ASSETS/arial.ttf");
    Text text1("SCORE:", font, 30);
//	text1.setColor(sf::Color(255,0,0));
//	Music music;

    Texture t, th, tdest, tp_a, t_oceano, tpr, t_exp, tm, tt, thal;

    thal.loadFromFile("ASSETS/halcon1.png");
    t.loadFromFile("ASSETS/a4Arg.png");
    tdest.loadFromFile("ASSETS/dest.png");
    tp_a.loadFromFile("ASSETS/port_a.png");
    th.loadFromFile("ASSETS/harrier.png");
    t_oceano.loadFromFile("ASSETS/agua.jfif");
    tpr.loadFromFile("ASSETS/bala1.png");
    t_exp.loadFromFile("ASSETS/explosion1.png");
    tm.loadFromFile("ASSETS/misil1.png");
    tt.loadFromFile("ASSETS/torre.png");

//	music.openFromFile("amet.vlc");

    Sprite s, sp_a, sh, shal, s_oceano, s_oceano1, spr, s_exp, sm, ss, ss1, ss2;

    A4 player(300, 450, t, t_exp);

    P_A porta_a(100, -200, tdest);
    P_A porta_a1(300, -800, tp_a);

    Harrier har(120, -800, th, t_exp);
    Harrier har1(240, -600, th, t_exp);
    Harrier har2(360, -400, th, t_exp);
    Harrier har3(20, -200, th, t_exp);

    Vida v1(500, 0, thal);
    Vida v2(530, 0, thal);
    Vida v3(560, 0, thal);

    Puntuacion punt;

    LinkedList<Proyectil *> proy;

    s_oceano1.setTexture(t_oceano);
    s_oceano.setTexture(t_oceano);

    spr.setTexture(tpr);
    s_exp.setTexture(t_exp);
    sm.setTexture(tm);
    ss.setTexture(tt);
    ss1.setTexture(tt);
    ss1.setRotation(180);
    ss2.setTexture(tt);
    ss2.setRotation(180);

    w.setFramerateLimit(150);

    while (w.isOpen()) {

        Event e;

        while (w.pollEvent(e)) {

            switch (e.type) {
                case Event::Closed:
                    w.close();
                    break;

            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            player.mov(-2, 0);
            if (player.getY() > 300) {
                ss.rotate(0.30);
            } else {
                ss1.rotate(-0.30);
                ss2.rotate(-0.30);
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            player.mov(2, 0);
            if (player.getY() > 300) {
                ss.rotate(-0.30);
            } else {
                ss1.rotate(0.30);
                ss2.rotate(0.30);
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            player.mov(0, -2);
            //	if(player.getY()<300){
            //ss.rotate(0.30);}
        }

        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            player.mov(0, 2);
            //if(player.getY()<300){
            //ss.rotate(-0.30);}
        }

        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            if (mun > 0) {
                int i;
//			music.play();
                proy.push_front(new Proyectil(player.getX(), player.getY(), tpr));
                mun--;
            }
        }

        LinkedList<Proyectil *> toDelete;
        for (proy.loopStart(); !proy.loopEnd(); proy.loopNext()) {
            Proyectil *aux = proy.loopGet();
            if (aux->mov()) {
                toDelete.push_front(aux);
            }
        }
        for (toDelete.loopStart(); !toDelete.loopEnd(); toDelete.loopNext()) {
            Proyectil *aux = toDelete.loopGet();
            delete aux;
            proy.remove(toDelete.loopGet());
        }

        static int cont = 0;
        if (cont++ % 300 == 0){
            std::cout << "disparé" <<std::endl;
            proy.push_front(porta_a.disparar(player, tpr));
        }

        punt.incremento(score);
        score++;
//		if(sh.getGlobalBounds().intersects(s.getGlobalBounds())){
//			sh.setColor(sf::Color::Transparent);
//		}

        porta_a.mov(100, y++);
        porta_a1.mov(200, y++);

        yo1 += 0.9;
        if (yo1 > 1200) {
            yo1 = 0;
        }
        yo += 0.9;
        if (yo >= 600) {
            yo = -600;
        }
        if (har.getY() > 700) {
            har.mov(x + 70, -300, spr);
        }
        if (har1.getY() > 800) {
            har1.mov(x + 20, -300, spr);
        }
        if (har2.getY() > 750) {
            har2.mov(x + 100, -300, spr);
        }
        if (har3.getY() > 900) {
            har3.mov(x + 30, -300, spr);
        }


        s_oceano1.setPosition(0, yo1 - 600);
        s_oceano.setPosition(0, yo);

        ss.setPosition(porta_a.getX() + 50, porta_a.getY() + 365);
        ss.setOrigin(ss.getTexture()->getSize().x / 2.f,
                     ss.getTexture()->getSize().y / 2.f);//Tomar el Sprite por el centro (nos sirve para hacerlo rotar).
        ss1.setPosition(porta_a.getX() + 45, porta_a.getY() + 60);
        ss1.setOrigin(ss.getTexture()->getSize().x / 2.f, ss.getTexture()->getSize().y / 2.f);
        ss2.setPosition(porta_a.getX() + 45, porta_a.getY() + 10);
        ss2.setOrigin(ss.getTexture()->getSize().x / 2.f, ss.getTexture()->getSize().y / 2.f);

        w.clear();
        //	w.draw(sm);
        w.draw(s_oceano);
        w.draw(s_oceano1);
        porta_a.dib(w);
        porta_a1.dib(w);
        w.draw(ss);
        w.draw(ss1);
        w.draw(ss2);
        har.dib(w, th);
        har1.dib(w, th);
        har2.dib(w, th);
        har3.dib(w, th);
        player.dib(w);

        punt.draw(w);
        w.draw(text1);
        v1.dib(w);
        v2.dib(w);
        v3.dib(w);


        for (proy.loopStart(); !proy.loopEnd(); proy.loopNext()) {
            proy.loopGet()->dib(w);
        }

        w.display();

    }
    punt.savescore(score);
    return 0;

}
		
