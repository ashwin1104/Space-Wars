#ifndef BackgroundObjects_hpp
#define BackgroundObjects_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* BackgroundObjects_hpp */
class BackgroundObjects {
private:
    // current position of object
    ofPoint pos;
    // image of object
    ofImage img;
    
    // new width and height of image of object
    int resize_dimension;
    // speed of object's movements
    float speed;
    // amplitude of sine wave that describes object motion
    float amplitude;
    // width of enemy image
    float width;
    
public:
    // initializes attributes
    void setup(float max_object_amplitude, ofImage object_image);
    // updates position of object based on sinusoidal movement
    void update();
    // draws object on screen based on position and width
    void draw();
};
