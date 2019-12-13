#include "Player.hpp"

// sets initial position to (0,0)
// sets width and height based on passed image of player
// initializes starting lives to 3
// initializes shooting interval between lasers
// marks start time for shooting
// initializes pixels moved by each key press (speed)
void Player::setup(ofImage player_image) {
    img = player_image;
    resize_dimension = 25;
    img.resize(resize_dimension,resize_dimension);
    width = img.getWidth();
    height = img.getHeight();
    
    pos.x = int(ofGetWidth()/2);
    pos.y = ofGetHeight() - resize_dimension;
    
    speed = 5;
    lives = 3;
    shoot_interval = 1;
    start_shoot = ofGetElapsedTimef();
}

// called on by ofApp's update function to move player
void Player::update() {
    calculate_movement();
}
// draws image at current location
void Player::draw() {
    img.draw(pos.x - width/2, pos.y - width/2);
}
// checks if shooting time interval has been reached in order to shoot again
bool Player::check_can_shoot() {
    if (ofGetElapsedTimef() - start_shoot > shoot_interval) {
        start_shoot = ofGetElapsedTimef();
        return true;
    }
    return false;
}
// changes position of player by key pressed and speed constant
void Player::calculate_movement() {
    if (is_left_pressed && pos.x >= resize_dimension + speed) {
        pos.x -= speed;
    }
    if (is_right_pressed && pos.x <= ofGetWidth() - resize_dimension - speed) {
        pos.x += speed;
    }
    if (is_up_pressed && pos.y >= resize_dimension + speed) {
        pos.y -= speed;
    }
    if (is_down_pressed && pos.y <= ofGetHeight() - resize_dimension - speed) {
        pos.y += speed;
    }
}

