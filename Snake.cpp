#include <iostream>
#include <GLFW/glfw3.h>

#include "Snake.h"

int scale = 640 / 480 * 20; 

Snake::Snake() {
    segments[3].x = 5;
    segments[3].y = 5;
    segments[2].x = 6;
    segments[2].y = 5;
    segments[1].x = 7;
    segments[1].y = 5;
    segments[0].x = 8;
    segments[0].y = 5;
    size = 4;
}

void Snake::draw(){
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    for(int i = 0; i < size; i++){
        glVertex2d(segments[i].x * scale, segments[i].y * scale);
        glVertex2d(segments[i].x * scale, (segments[i].y * scale) + 19);
        glVertex2d(segments[i].x * scale + 19, segments[i].y * scale + 19);
        glVertex2d(segments[i].x * scale + 19, segments[i].y * scale);
    }
    glEnd();
}

void Snake::extendSnake() {
    size++;
}

void Snake::shrinkSnake() {
    size--;
}

bool Snake::checkSelfCollizion() {
    for(int i = 1; i < size; i++){
        if( (segments[0].x == segments[i].x) && (segments[0].y == segments[i].y)){
            return true;
        }
    }
    return false;
}


void Snake::move() {

    for(int i = size; i > 0; i--){
        segments[i].x = segments[i - 1].x;
        segments[i].y = segments[i - 1].y;
    }
    switch(dir){
        case RIGHT: segments[0].x++; break;
        case LEFT : segments[0].x--; break;
        case UP   : segments[0].y--; break;
        case DOWN : segments[0].y++; break;
    }
    
}


Snake::~Snake() {
}

