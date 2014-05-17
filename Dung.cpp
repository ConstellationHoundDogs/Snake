#include <GLFW/glfw3.h>
#include "Dung.h"

Dung::Dung(int x, int y) {
    this->x = x;
    this->y = y;
}

Dung::~Dung() {
}

void Dung::draw() {
    glColor3f(0.7f, 0.3f, 0.6f);
    glBegin(GL_QUADS);
    glVertex2d(x * scale, y * scale);
    glVertex2d(x * scale, y * scale + 19);
    glVertex2d(x * scale + 19, y * scale + 19);
    glVertex2d(x * scale + 19, y * scale);
    glEnd();
}

