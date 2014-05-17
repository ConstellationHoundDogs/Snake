#include <GLFW/glfw3.h>
#include <iostream>
#include "Fruit.h"

Fruit::Fruit(int x, int y) {
    this->x = x;
    this->y = y;
}

void Fruit::draw() {
    glColor3f(0.8f, 0.2f, 0.f);
    glBegin(GL_QUADS);
    glVertex2d(x * scale, y * scale);
    glVertex2d(x * scale, y * scale + 19);
    glVertex2d(x * scale + 19, y * scale + 19);
    glVertex2d(x * scale + 19, y * scale);
    glEnd();
}

Fruit::~Fruit() {
    
}

