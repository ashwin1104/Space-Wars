#ifndef LevelController_hpp
#define LevelController_hpp
#include "ofMain.h"
#include <stdio.h>

#endif /* LevelController_hpp */
class LevelController {
private:
    // start time of game
    float start_time;
    // wait time needed before spawning an enemy
    float interval_time;
public:
    // intializes attributes
    void setup(float e, float interval_time);
    // checks if another enemy should be spawned on screen based on time elapsed
    bool should_spawn();
};
