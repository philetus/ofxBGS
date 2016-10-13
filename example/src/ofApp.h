#pragma once

#include "ofxBGS.h"
#include "ofMain.h"

#define GRABBER_WIDTH 640
#define GRABBER_HEIGHT 480

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();

        void keyPressed  (int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);

        ofVideoGrabber grabber;
        ofxBGS bgs;

        void setCam(ofVideoGrabber *grabber, std::string camName) {
            vector<ofVideoDevice> devices = grabber->listDevices();
            int useCam = 0;
            for(int i = 0; i < devices.size(); i++){
                if(devices[i].bAvailable){
                    ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - available ";
                    if (devices[i].deviceName.find(camName) != std::string::npos) {
                        ofLogNotice() << "found " << camName << "!\n";
                        useCam = i;
                    }
                }else{
                    ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
                }
            }
            grabber->setDeviceID(useCam);
        }     

};
