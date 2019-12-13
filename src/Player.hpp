#include "ofMain.h"

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>

#endif /* Player_hpp */

class Player {
private:
    // image of player onscreen
    ofImage img;

    // time between each laser fired
    float shoot_interval;
    // time of last laser fired
    float start_shoot;
    // new height and length of image for object
    int resize_dimension;
    
public:
    // current position
    ofPoint pos;
    
    // speed of player's movements
    float speed;
    // current dimensions
    float width, height;
    // number of lives left
    int lives;
    
    // if keys are pressed for movement purposes
    bool is_left_pressed, is_right_pressed, is_down_pressed, is_up_pressed;
    
    // intializes attributes
    void setup(ofImage _img);
    // calls on calculate_movement
    void update();
    // updates image based on current position
    void draw();
    // updates movement
    void calculate_movement();
    // checks if another laser can be fired based on when previous laser was fired
    bool check_can_shoot();
};


