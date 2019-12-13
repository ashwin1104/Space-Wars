#include "Laser.hpp"

// initializes position, speed of laser, width of image, and if the laser came from the player
void Laser::setup(bool f_p, ofPoint p, float s, ofImage laser_image) {
    pos = p;
    from_player = f_p;
    
    int speed_advantage = 3;
    speed = s + speed_advantage;
    
    img = laser_image;
    resize_dimension = 25;
    img.resize(resize_dimension,resize_dimension);
    width = img.getWidth();

}
// change in position depends on if the laser came from enemy or player
void Laser::update() {
    if (from_player) {
        pos.y -= speed;
    }
    else {
        pos.y += speed;
    }
}

// draws image based on position and width
void Laser::draw() {
    img.draw(pos.x - width/2, pos.y - width/2);
}
