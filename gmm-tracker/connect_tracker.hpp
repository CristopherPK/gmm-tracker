//
//  connect_tracker.hpp
//  gmm-tracker
//
//  Created by Cristopher Freitas on 2/21/16.
//  Copyright © 2016 Cristopher Freitas. All rights reserved.
//

#ifndef connect_tracker_hpp
#define connect_tracker_hpp

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <stdio.h>

#include "kcftracker/kcftracker.hpp"

using namespace std;
using namespace cv;

class connectTracker {
    vector<KCFTracker> trackers;
    bool isTracking;
    
public:
    connectTracker();
    void init(vector<Rect> objectsWindows, Mat frame);
    Mat update(Mat frame);
};

#endif /* connectTracker_hpp */
