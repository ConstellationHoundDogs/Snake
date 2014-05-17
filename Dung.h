/* 
 * File:   Dung.h
 * Author: vladimir
 *
 * Created on May 16, 2014, 8:18 PM
 */

#ifndef DUNG_H
#define	DUNG_H

class Dung {
public:
    Dung(int x, int y);
    ~Dung();
    
    void draw();
    
    int getXPosition(){return x;};
    int getYPosition(){return y;};
    
    
    int setXPosition(int x){this->x = x;};
    int setYPosition(int y){this->y = y;};
    
private:
    
    int scale = 640 / 480 * 20; 
    int x = 0 , y = 0;

};

#endif	/* DUNG_H */

