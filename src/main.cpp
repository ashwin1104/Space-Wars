#include "ofMain.h"
#include "ofApp.h"

#define DISPLAY_MODE OF_WINDOW

int main() {
    // set up display
    int screen_width = 1024;
    int screen_height = 768;
	ofSetupOpenGL(screen_width, screen_height, DISPLAY_MODE);
    
    // run new app with screen dimensions
    ofApp *current_app = new ofApp();
    current_app -> setDimensions(screen_width, screen_height);
    ofRunApp(current_app);
}
