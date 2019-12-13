#include "LevelController.hpp"

// initializes start time and time between each enemy spawn
void LevelController::setup(float s, float interval) {
   start_time = s;
   interval_time = interval;
}
// checks if interval time has been reached for spawning another enemy
bool LevelController::should_spawn() {
   if (ofGetElapsedTimeMillis() - start_time > interval_time) {
       start_time = ofGetElapsedTimeMillis();
       return true;
   }
   return false;
}
