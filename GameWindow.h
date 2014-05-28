#ifndef GAMEWINDOW_H
#define	GAMEWINDOW_H

#include <GLFW/glfw3.h>
#include "Snake.h"
#include "Fruit.h"
#include "Dung.h"
//ANTOXA PEETOOX
class GameWindow {
public:
    GameWindow();
    ~GameWindow();
    
    void setSnake(Snake* snake);
    Snake * getSnake();
    
    void setFruit(Fruit* fruit);
    Fruit* getFruit();
    
    void setDung(Dung* dung);
    Dung* getDung();
    
    GLFWwindow* getWindow();
    const char* getTitle();
    
    void render();
    void tick();
    
    void checkCollizion();
    
    const int getWidth();
    const int getHeight();
    
    int getFruitCount(){return fruitCounter;};
    void setFruitCount(int count){fruitCounter =  count;};
private:

    const int WINDOW_HEIGHT = 480;
    const int WINDOW_WIDTH = 640;
    const int scale = 640 / 480 * 20;
    
    const char* TITLE = "Snake";
    
    Snake* snake;
    Fruit* fruit;
    Dung* dung;
    GLFWwindow* mainWindow;
    
    void snakeHasDied();
    void drawField();
    
    int fruitCounter = 0;
    int score = 0;
    
};

#endif	/* GAMEWINDOW_H */

