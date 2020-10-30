#include <SFML/Graphics.hpp>
#include "Proyectil.h"

using namespace sf;

Proyectil::Proyectil(float x, float y, Texture &t) {
    this->x = x;
    this->y = y;
    this->vx = 0;
    this->vy = -5.4;
    spr.setTexture(t);
}

Proyectil::Proyectil(float x, float y, float vx, float vy, Texture &tpr) {
    this->x = x;
    this->y = y;
    this->vx = vx;
    this->vy = vy;
    spr.setTexture(tpr);
}

Proyectil::~Proyectil() {};

bool Proyectil::mov() {
    this->y += vy;
    this->x += vx;

    // TODO: verificar todos los lados.
    if (this->y < 0) {
        return true;
    } else {
        return false;
    }
}

void Proyectil::dib(RenderWindow &w) {
    spr.setPosition(this->x + 15, this->y -= 2);
    w.draw(spr);
}


