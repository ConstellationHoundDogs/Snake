#include <cstdlib>
#include <GLFW/glfw3.h>

#include "SnakeGame.h"

using namespace std;

int main(int argc, char** argv) {

    GameWindow gameWindow;
    Snake* snake = new Snake();            //create player snake
    Fruit* fruit = new Fruit(5, 5);         // create initial fruit
    Dung * dung = new Dung(10, 10);             // create initial dung
    
    gameWindow.setSnake(snake);         //adding snake to the field etc.
    gameWindow.setFruit(fruit);
    gameWindow.setDung(dung);
    SnakeGame* snakeGame = new SnakeGame(&gameWindow);

    snakeGame->startGame();
    
    return 0;
}

