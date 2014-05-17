#ifndef SNAKEGAME_H
#define	SNAKEGAME_H

#include "GameWindow.h"


class SnakeGame {

public:
    SnakeGame(GameWindow* window);
    void startGame();
    
private:    
    GameWindow* myMainWindow;
    int gameSpeed = 4;
};

#endif	/* SNAKEGAME_H */

