#include <GLFW/glfw3.h>
#include <iostream>
#include <unistd.h>
#include "SnakeGame.h"

SnakeGame::SnakeGame(GameWindow* window) {
    myMainWindow = window;
}

void SnakeGame::startGame() {
    double last = glfwGetTime();
    double delta = 1.0 / 60;
    double now =  glfwGetTime();
    int frameCount = 0;
    while(!glfwWindowShouldClose(myMainWindow->getWindow())){
        now = glfwGetTime();
        while((now - last) > delta * 6){
            glClear(GL_COLOR_BUFFER_BIT);
            last = glfwGetTime();
            
            if(frameCount > gameSpeed){
                myMainWindow->tick();
                frameCount = 0;
            }
            
            if(myMainWindow->getFruitCount() > 3){
                gameSpeed--;
                myMainWindow->setFruitCount(0);
                std::cout << "New level : " << gameSpeed << " speed." << std::endl;
            }
            myMainWindow->render();
            frameCount++;
            if(glfwGetKey(myMainWindow->getWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS){
                myMainWindow->getSnake()->moveRIGHT();
            }
            if(glfwGetKey(myMainWindow->getWindow(), GLFW_KEY_LEFT) == GLFW_PRESS){
                myMainWindow->getSnake()->moveLEFT();
            }
            if(glfwGetKey(myMainWindow->getWindow(), GLFW_KEY_UP) == GLFW_PRESS){
                myMainWindow->getSnake()->moveUP();
            }
            if(glfwGetKey(myMainWindow->getWindow(), GLFW_KEY_DOWN) == GLFW_PRESS){
                myMainWindow->getSnake()->moveDOWN();
            }
            glfwSwapBuffers(myMainWindow->getWindow());
            glfwPollEvents();
        }
    }
}
