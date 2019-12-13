#include "Enemy.hpp"

// initializes starting position, image and its width, random amplitude, random speed
// initializes random shooting time interval and sets start time of shooting timer
void Enemy::setup(float max_enemy_amplitude, float max_enemy_shoot_interval, ofImage enemy_image) {
    pos.x = ofRandom(ofGetWidth());
    pos.y = 0;
    
    img = enemy_image;
    resize_dimension = 25;
    img.resize(resize_dimension,resize_dimension);
    width = img.getWidth();
    
    int min_speed = 1;
    int max_speed = 5;
    speed = ofRandom(min_speed, max_speed);
    amplitude = ofRandom(max_enemy_amplitude);
    
    int min_enemy_shoot_interval = 0.5;
    shoot_interval = ofRandom(min_enemy_shoot_interval, max_enemy_shoot_interval);
    start_shoot = ofGetElapsedTimef();
}
// changes x position based on sine of current time and amplitude
// changes y position based on speed
void Enemy::update() {
    pos.y += speed;
    if (pos.x + amplitude * sin(ofGetElapsedTimef()) >= resize_dimension &&
        pos.x + amplitude * sin(ofGetElapsedTimef()) <= ofGetHeight() - resize_dimension) {
        
        pos.x += amplitude * sin(ofGetElapsedTimef());
    }
}
// draws image based on current position and width of image
void Enemy::draw() {
   img.draw(pos.x - width/2, pos.y - width/2);
}
// checks if the shooting time interval has been reached before it can shoot the laser
bool Enemy::time_to_shoot() {
   if (ofGetElapsedTimef() - start_shoot > shoot_interval) {
       start_shoot = ofGetElapsedTimef();
       return true;
   }
   return false;
}
