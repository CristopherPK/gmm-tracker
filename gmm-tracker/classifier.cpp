//
//  classifier.cpp
//  gmm-tracker
//
//  Created by Cristopher Freitas on 4/9/16.
//  Copyright © 2016 Cristopher Freitas. All rights reserved.
//

#include "classifier.hpp"

Classifier::Classifier(){
    
//    pedestrianClassifier = \
//    DPMDetector::create(vector<string>(1, "/Users/cristopher/Workspace/ \
//                                       gmm-tracker/gmm-tracker/dpm-models/inriaperson.xml"));
    
    bicycleClassifier = \
    DPMDetector::create(vector<string>(1, "/Users/cristopher/Workspace/gmm-tracker/gmm-tracker/dpm-models/bicycles.xml"));
    
//    carClassifier = \
//    DPMDetector::create(vector<string>(1, "/Users/cristopher/Workspace/ \
//                                       gmm-tracker/gmm-tracker/dpm-models/car.xml"));
}

bool Classifier::isBike(Mat frame, Rect object){
    // Vector with objects detects in the frame.
    vector<DPMDetector::ObjectDetection> ds;
    
    Rect objectBox = Rect(object);
    
    // Expand size of the rectangle to guarantee a better detection.
    object += object.size();
    object += object.size();
    object = object - Point(object.width/2,object.height/2);
    
    // Create an object mask from its frame.
    Mat frameROI = Mat(frame, object);
    
    // specify fx and fy and let the function compute the destination image size.
    resize(frameROI, frameROI, Size(), 4, 4);
    
    // Detect the object.
    bicycleClassifier->detect(frameROI, ds);
    
    // Verify its score.
    //cout << ds.size();
    
    if(ds.size() > 0){
        vector<DPMDetector::ObjectDetection>::iterator itr = ds.begin();
        while(itr != ds.end()){
            DPMDetector::ObjectDetection detectedObject = *itr;
            Rect detectedRect = detectedObject.rect;
            detectedRect -= (detectedRect.size()*8)/10;
            
            //float ratio = (float)detectedObject.rect.area() / objectBox.area();
            //if(ratio < 1.5 && ratio > 0.7){
            
            // TODO: This is drawing a rectangle according to the crop frame,
            //       not according to the real image,
            //       we have to downscale the rectangle after identifying,
            //       and changing its coordinates. 
                rectangle(frame, detectedRect, Scalar(0,255,255));
                cout << detectedObject.score << endl;
            //}
            
            itr++;
        }
    }
    
    // Return true or false.
    return false;
}

