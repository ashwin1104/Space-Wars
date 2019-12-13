#include "Life.hpp"

// initalizes bonus image and width, set speed of movement, and starting position
void Life::setup(ofImage _img) {
    pos.x = ofRandom(ofGetWidth());
    pos.y = 0;
    
    img = _img;
    resize_dimension = 25;
    img.resize(resize_dimension,resize_dimension);
    width = img.getWidth();
    
    speed = 5;
}
// moves in the vertical direction only by given speed
void Life::update() {
   pos.y += speed;
}
// bonus image drawn based on position and width of image
void Life::draw() {
   img.draw(pos.x - img.getWidth()/2, pos.y - img.getWidth()/2);
}
