#include "ofMain.h"
#ifndef Life_hpp
#define Life_hpp

#include <stdio.h>

#endif /* Life_hpp */

class Life {
private:
    // image of bonus
    ofImage img;
    // new height and length of image for object
    int resize_dimension;
    // speed of bonus's movement
    float speed;
    
public:
    // position of the life bonus
    ofPoint pos;
    
    // width of bonus image
    float width;
    
    // intializes attributes
    void setup(ofImage _img);
    // updates position of image during keypresses
    void update();
    // draws image based on current position
    void draw();
};
