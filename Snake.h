#ifndef SNAKE_H
#define	SNAKE_H

class Snake {

public:
    
     Snake();
    ~Snake();
    
    void draw();
    void move();
    
    int snakePositionX(){return segments[0].x;};
    int snakePositionY(){return segments[0].y;};
    
    bool checkSelfCollizion();
    
    void extendSnake();
    void shrinkSnake();
    
    void moveUP(){ dir = UP; };
    void moveRIGHT(){ dir = RIGHT; };
    void moveLEFT(){ dir = LEFT; };
    void moveDOWN(){ dir = DOWN; };
    
    int getSize(){return size;};
    
private:
    struct {
        int x;
        int y;
    } segments[100];

    enum direction{
        LEFT, RIGHT, UP, DOWN
    };
    int dir = UP;
    
    int size;
};

#endif	/* SNAKE_H */

