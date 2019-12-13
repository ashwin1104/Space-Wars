#include "ofMain.h"


#ifndef Laser_hpp
#define Laser_hpp

#include <stdio.h>

#endif /* Laser_hpp */

class Laser {
private:
    // image of laser
    ofImage img;
    // new height and length of image for object
    int resize_dimension;
    // speed of laser movement
    float speed;
    
    
public:
    // position of laser
    ofPoint pos;
    
    // width of laser image
    float width;
    
    // if laser has been fired by player or enemy
    bool from_player;
    
    // intializes attributes
    void setup(bool from_player, ofPoint p, float s, ofImage bullet_image);
    // updates position of laser
    void update();
    // updates image based on current position
    void draw();
};
