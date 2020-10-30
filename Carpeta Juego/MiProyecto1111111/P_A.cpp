#include <SFML/Graphics.hpp>
#include <cmath>
#include "P_A.h"
#include "A4.h"

using namespace sf;

P_A::P_A(float x_p, float y_p, Texture &t) {
    x = x_p;
    y = y_p;
    sp_a.setTexture(t);

}

void P_A::mov(float x, float y) {
    this->x;
    this->y += 0.00001;
    if (this->x < 0) {
        this->x = 50;
    }
    if (this->x > 600) {
        this->x = 0;
        this->x += 0.05;
    }
    if (this->y < 600) {
        this->y += 0.00001;
        this->y += 0.08;
    }
    if (this->y > 600) {
        this->y = -800;
        this->x += 100;
    }
}

void P_A::dib(RenderWindow &w) {
    sp_a.setPosition(this->x, this->y - 100);
    w.draw(sp_a);
}

Proyectil *P_A::disparar(A4 &p, Texture &tpr) {
    float vel = 5;
    float dx = (this->x - p.getX());
    float dy = (this->y - p.getY());
    float hipo = sqrt(dx*dx + dy*dy);

    float vx = -vel * dx / hipo;
    float vy = -vel * dy / hipo;


    return new Proyectil(this->x, this->y, vx, vy, tpr);
}
