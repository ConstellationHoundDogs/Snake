#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>

#include "GameWindow.h"

using namespace std;

GameWindow::GameWindow() {
    
    if(!glfwInit()){
        cerr << "[ERROR] Could not init glwf.";
        exit(EXIT_FAILURE);
    }
 
    this->mainWindow = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE, NULL, NULL);
    
    if(!mainWindow){
        cerr << "[ERROR] Could not create mainWindow.";
        exit(EXIT_FAILURE);
    }
    
    glfwMakeContextCurrent(mainWindow);
    
    int width, height;
    glfwGetFramebufferSize(mainWindow, &width, &height);    
    
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.1, 0.0, 0.0, 0.0);    
    
}

Fruit* GameWindow::getFruit() {
    return fruit;
}

void GameWindow::setFruit(Fruit* fruit) {
    this->fruit = fruit;
}


GLFWwindow* GameWindow::getWindow() {
    return mainWindow;
}

void GameWindow::setSnake(Snake* snake) {
    this->snake = snake;
}

Snake* GameWindow::getSnake() {
    return this->snake;
}


const int GameWindow::getHeight() {
    return WINDOW_HEIGHT;
}

const int GameWindow::getWidth() {
    return WINDOW_WIDTH;
}

void GameWindow::render() {
    drawField();
    snake->draw();
    fruit->draw();
    dung->draw();
}

void GameWindow::tick() {
    snake->move();
    checkCollizion();
    
}

void GameWindow::setDung(Dung* dung) {
    this->dung = dung;
}

Dung* GameWindow::getDung() {
    return dung;
}


void GameWindow::checkCollizion() {
    if(snake->snakePositionX() == fruit->getXPosition() && snake->snakePositionY() == fruit->getYPosition()){
        snake->extendSnake();
        fruit->setXPosition((rand() % WINDOW_WIDTH)/scale);
        fruit->setYPosition((rand() % WINDOW_HEIGHT)/scale);
        fruitCounter++;
        score++;
        printf("Your current score is %d", score);
    }
    if(snake->snakePositionX() == dung->getXPosition() && snake->snakePositionY() == dung->getYPosition()){
        snake->shrinkSnake();
        if(snake->getSize() == 0){
            snakeHasDied();
        }
        dung->setXPosition((rand() % WINDOW_WIDTH)/scale);
        dung->setYPosition((rand() % WINDOW_HEIGHT)/scale);
        score++;
    }
    if(snake->snakePositionX() >= WINDOW_WIDTH / scale || snake->snakePositionY() >= WINDOW_HEIGHT / scale){
        snakeHasDied();
    }
    if(snake->snakePositionX() < 0 || snake->snakePositionY() < 0){
        snakeHasDied();
    }
    if(snake->checkSelfCollizion()){
        snakeHasDied();
    }
}

void GameWindow::snakeHasDied() {
    cout << "Game over" << endl;
    exit(EXIT_SUCCESS);
}


void GameWindow::drawField(){
    
    glColor3f(0.3f, 0.0f, 0.0f);
    glBegin(GL_LINES); 
    for(int i = 0; i < WINDOW_WIDTH; i += scale){
        glVertex2f(i, 0);
        glVertex2f(i, WINDOW_HEIGHT);
    }
    for(int i = 0; i < WINDOW_HEIGHT; i += scale){
        glVertex2f(0, i);
        glVertex2f(WINDOW_WIDTH, i);
    }
    glEnd();
    
}

const char* GameWindow::getTitle() {
    return TITLE;
}

GameWindow::~GameWindow(){
    glfwDestroyWindow(mainWindow);
    glfwTerminate();
}
