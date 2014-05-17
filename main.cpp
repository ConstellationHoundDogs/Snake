#include <cstdlib>
#include <GLFW/glfw3.h>

#include "SnakeGame.h"

using namespace std;

int main(int argc, char** argv) {

    GameWindow* gameWindow = new GameWindow();
    Snake* snake = new Snake();
    Fruit* fruit = new Fruit(5, 5);
    Dung * dung = new Dung(10, 10);
    
    gameWindow->setSnake(snake);
    gameWindow->setFruit(fruit);
    gameWindow->setDung(dung);
    SnakeGame* snakeGame = new SnakeGame(gameWindow);

    snakeGame->startGame();
    
    return 0;
}

