#include "ofApp.h"
#include <iostream>
#include <string>
#include <vector>

// initializes game_state, starting score, movement amplitudes, shoot interval, text shift dimension
// loads in all required images for objects in the game
// sets up player
void ofApp::setup(){
    game_state = "start";
    
    current_score = 0;
    score_increment = 10;
    shift_text = 80;
    
    max_enemy_amplitude = 3.0;
    max_object_amplitude = 5.0;
    
    max_enemy_shoot_interval = 1.5;
    
    // loads images
    processImages();
    
    // setup player with image
    this_player.setup(player_image);
}

// loading all images
void ofApp::processImages() {
    life_image.load("../../life.png");
    enemy_image.load("../../enemy.png");
    player_image.load("../../player.png");
    enemy_laser_image.load("../../enemy_laser.png");
    player_laser_image.load("../../player_laser.png");
    asteroid_image.load("../../asteroid.png");
    star_image.load("../../star.png");
    green_image.load("../../green.png");
    red_image.load("../../red.png");
}

// changes player's key booleans based on what keys they are pressing
// spacebar shoots lasers
void ofApp::keyPressed(int key_pressed){
   if (game_state == "game") {
       if (key_pressed == OF_KEY_LEFT) {
           this_player.is_left_pressed = true;
       }

       if (key_pressed == OF_KEY_RIGHT) {
           this_player.is_right_pressed = true;
       }

       if (key_pressed == OF_KEY_UP) {
           this_player.is_up_pressed = true;
       }

       if (key_pressed == OF_KEY_DOWN) {
           this_player.is_down_pressed = true;
       }
       
       if (key_pressed == ' ') {
           if (this_player.check_can_shoot()) {
               Laser new_laser;
               new_laser.setup(true, this_player.pos, this_player.speed, player_laser_image);
               lasers.push_back(new_laser);
           }
       }
   }
}

// resets player's key booleans based on what keys they have released
void ofApp::keyReleased(int key_released){
   if (game_state == "start") {
       game_state = "game";
       controllerSetups();
   }
   else if (game_state == "game") {
       if (key_released == OF_KEY_LEFT) {
           this_player.is_left_pressed = false;
       }

       if (key_released == OF_KEY_RIGHT) {
           this_player.is_right_pressed = false;
       }

       if (key_released == OF_KEY_UP) {
           this_player.is_up_pressed = false;
       }

       if (key_released == OF_KEY_DOWN) {
           this_player.is_down_pressed = false;
       }
   }
}

void ofApp::controllerSetups() {
    int enemy_spawn_time = 2000;
    int background_spawn_time = 1100;
    int bonus_spawn_time = 15000;
    
    level_controller.setup(ofGetElapsedTimeMillis(), enemy_spawn_time);
    background_controller.setup(ofGetElapsedTimeMillis(), background_spawn_time);
    bonus_controller.setup(ofGetElapsedTimeMillis(), bonus_spawn_time);
}

void ofApp::update() {
    if (game_state == "game") {
        // update all objects on screen
        this_player.update();
        update_lasers();
        update_bonuses();
        
        for (int enemy_index = 0; enemy_index < enemies.size(); enemy_index++) {
            enemies.at(enemy_index).update();
            if (enemies.at(enemy_index).time_to_shoot()) {
                Laser new_laser;
                new_laser.setup(false, enemies.at(enemy_index).pos, enemies.at(enemy_index).speed, enemy_laser_image);
                lasers.push_back(new_laser);
            }
        }
        
        for (int background_index = 0; background_index < background_objects.size(); background_index++) {
            background_objects.at(background_index).update();
        }
    
        // add new spawns
        addSpawns();
    }
}

void ofApp::addSpawns() {
    
    if (level_controller.should_spawn()) {
        Enemy new_enemy;
        new_enemy.setup(max_enemy_amplitude, max_enemy_shoot_interval, enemy_image);
        enemies.push_back(new_enemy);
    }
    
    if (background_controller.should_spawn()) {
        
        BackgroundObjects first_bg_obj;
        first_bg_obj.setup(max_object_amplitude, asteroid_image);
        
        BackgroundObjects second_bg_obj;
        second_bg_obj.setup(max_object_amplitude, star_image);
        
        BackgroundObjects third_bg_obj;
        third_bg_obj.setup(max_object_amplitude, red_image);
        
        BackgroundObjects fourth_bg_obj;
        fourth_bg_obj.setup(max_object_amplitude, green_image);
        
        background_objects.push_back(first_bg_obj);
        background_objects.push_back(second_bg_obj);
        background_objects.push_back(third_bg_obj);
        background_objects.push_back(fourth_bg_obj);
    }
    
    if (bonus_controller.should_spawn()) {
        Life new_life;
        new_life.setup(life_image);
        bonuses.push_back(new_life);
    }
}

// updates positions of lasers
void ofApp::update_lasers() {
    for (int laser_index = 0; laser_index < lasers.size(); laser_index++) {
        lasers.at(laser_index).update();
        if (lasers.at(laser_index).pos.y - lasers.at(laser_index).width/2 < 0 ||
            lasers.at(laser_index).pos.y + lasers.at(laser_index).width/2 > screen_height) {
            
            lasers.erase(lasers.begin() + laser_index);
        }
    }
    check_laser_collisions();
}

// draws all objects on screen
void ofApp::draw() {
    if (game_state == "start") {
        std::string starting_text = "Press SPACE to start!";
        ofDrawBitmapString(starting_text, screen_width/2 - shift_text, screen_height/2);
    }
    else if (game_state == "game") {
        ofBackground(0, 0, 0); // black background
        this_player.draw();
        
        // redraw all enemies, background objects, lasers, and bonuses
        for (int enemy_index = 0; enemy_index < enemies.size(); enemy_index++) {
            enemies.at(enemy_index).draw();
        }
        for (int bg_obj_index = 0; bg_obj_index < background_objects.size(); bg_obj_index++) {
            background_objects.at(bg_obj_index).draw();
        }
        for (int laser_index = 0; laser_index < lasers.size(); laser_index++) {
            lasers.at(laser_index).draw();
        }
        for (int bonus_index = 0; bonus_index < bonuses.size(); bonus_index++) {
            bonuses.at(bonus_index).draw();
        }
    }
    else if (game_state == "end") {
        // show final score
        std::string final_score = "Your final score is: " + to_string(current_score);
        ofDrawBitmapString(final_score, screen_width/2 - shift_text, screen_height/2 - shift_text);
    }
}

// deletes laser if it has collided with either an enemy or player
// deletes laser when it leaves screen
void ofApp::check_laser_collisions() {
    for (int laser_index = lasers.size() - 1; laser_index >= 0; laser_index--) {
        
       if (lasers.at(laser_index).from_player) {
            for (int enemy_index = enemies.size()-1; enemy_index >= 0; enemy_index--) {
                if (ofDist(lasers.at(laser_index).pos.x, lasers.at(laser_index).pos.y, enemies.at(enemy_index).pos.x, enemies.at(enemy_index).pos.y) < (enemies.at(enemy_index).width + lasers.at(laser_index).width)/2) {
                    
                    enemies.erase(enemies.begin() + enemy_index);
                    lasers.erase(lasers.begin() + laser_index);
                    current_score += score_increment;
                    break;
                }
            }
        }
        else if (ofDist(lasers.at(laser_index).pos.x, lasers.at(laser_index).pos.y, this_player.pos.x, this_player.pos.y) < (lasers.at(laser_index).width+this_player.width)/2) {
                
            lasers.erase(lasers.begin() + laser_index);
            this_player.lives--;

            if (this_player.lives <= 0) {
                game_state = "end";
            }
        }
    }
}

// upates positions of bonuses onscreen
void ofApp::update_bonuses() {
   for (int bonus_index = bonuses.size()-1; bonus_index >= 0; bonus_index--) {
       bonuses.at(bonus_index).update();
       if (ofDist(this_player.pos.x, this_player.pos.y, bonuses.at(bonus_index).pos.x, bonuses.at(bonus_index).pos.y) < (this_player.width + bonuses.at(bonus_index).width)/2) {
           
           this_player.lives++;
           bonuses.erase(bonuses.begin() + bonus_index);
           break;
       }

       if (bonuses.at(bonus_index).pos.y + bonuses.at(bonus_index).width/2 > screen_height) {
           bonuses.erase(bonuses.begin() + bonus_index);
       }
   }
}

// sets screen dimensions
void ofApp::setDimensions(int x, int y) {
    screen_width = x;
    screen_height = y;
}
