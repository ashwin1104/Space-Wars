#include "ofMain.h"
#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>

#endif /* Enemy_hpp */

class Enemy {
private:
    // image of enemy onscreen
    ofImage img;
    
    // new height and length of image for object
    int resize_dimension;
    // amplitude of sine wave that describes enemy motion
    float amplitude;
    // time of last laser fired
    float start_shoot;
    // time between each laser fired
    float shoot_interval;
    
public:
    // current position
    ofPoint pos;
    
    // speed of enemy's movements
    float speed;
    // width of enemy image
    float width;
    
    // initializes attributes
    void setup(float max_enemy_amplitude, float max_enemy_shoot_interval, ofImage enemy_image);
    // changes position based on random movements
    void update();
    // updates image based on current position
    void draw();
    // checks if another laser can be fired based on when previous laser was fired
    bool time_to_shoot();
};
