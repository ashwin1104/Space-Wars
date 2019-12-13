#include "BackgroundObjects.hpp"

// initialize position of object and size
// randomize speed of object
// randomize max amplitude
void BackgroundObjects::setup(float max_object_amplitude, ofImage object_image) {
    pos.x = ofRandom(ofGetWidth());
    pos.y = 0;
    
    img = object_image;
    resize_dimension = 5;
    img.resize(5,5);
    width = img.getWidth();
    
    int min_speed = 1;
    int max_speed = 10;
    speed = ofRandom(min_speed, max_speed);
    amplitude = ofRandom(max_object_amplitude);
}
// change position by sinusoidal movement defined by amplitude
void BackgroundObjects::update() {
    pos.y += speed;
    pos.x += amplitude * sin(ofGetElapsedTimef());
}
// draws image based on current position and width of image
void BackgroundObjects::draw() {
   img.draw(pos.x - width/2, pos.y - width/2);
}
