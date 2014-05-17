#ifndef FRUIT_H
#define	FRUIT_H

class Fruit {
public:
    
    Fruit(int x, int y);
    ~Fruit();
    
    void draw();
    
    int getXPosition(){return x;};
    int getYPosition(){return y;};
    
    
    int setXPosition(int x){this->x = x;};
    int setYPosition(int y){this->y = y;};
    
private:
    
    int scale = 640 / 480 * 20; 
    int x = 0 , y = 0;

};

#endif	/* FRUIT_H */

