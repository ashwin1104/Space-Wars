#pragma once

#include "Enemy.hpp"
#include "Life.hpp"
#include "Player.hpp"
#include "Laser.hpp"
#include "LevelController.hpp"
#include "ofMain.h"
#include "ofxGui.h"
#include "BackgroundObjects.hpp"

class ofApp : public ofBaseApp {
private:
    // player of game
    Player this_player;
    // lasers coming from player and enemy
    Laser player_laser, enemy_laser;
    // control spawning of enemies, background objects, and life bonuses
    LevelController level_controller, background_controller, bonus_controller;
    
    // images of players
    ofImage player_image, enemy_image;
    // images of lasers, bonus, and background objects
    ofImage player_laser_image, enemy_laser_image, life_image, asteroid_image, star_image, red_image, green_image;
    
    // stores all lasers on screen
    std::vector<Laser> lasers;
    // stores all enemies on screen
    std::vector<Enemy> enemies;
    // stores all bonus lives on screen
    std::vector<Life> bonuses;
    // stores all background objects on screen
    std::vector<BackgroundObjects> background_objects;
        
    // defines if game has just started, in gameplay, or is ended
    std::string game_state;
    
    // number of enemies shot, score gained per enemy shot
    int current_score, score_increment;
    // dimensions of screen
    int screen_width, screen_height;
    // text positioning shift required for centering
    int shift_text;
    // defines the maximum change that an enemy's sine-based motion can have for each movement
    float max_enemy_amplitude;
    // defines the maximum position change that a background object's sine-based motion can have for each keypress
    float max_object_amplitude;
    // defines the maximum wait time between enemy laser firings
    float max_enemy_shoot_interval;
    
public:
    // initializes attributes
    void setup();
    // updates positions of all features on screen
    void update();
    // updates the laser positions
    void update_lasers();
    // updates the positions of the bonuses
    void update_bonuses();
    // checks if the laser has hit a player or enemy, and updates score/player lives
    void check_laser_collisions();
    // draws images of all features on screen
    void draw();
    // checks what key is being pressed and updates player booleans of keys pressed
    void keyPressed(int key);
    // updates the player booleans of keys pressed if the keys have been released
    void keyReleased(int key);
    // Initializes screen dimensions
    void setDimensions(int x, int y);
};
