#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "FBerror.h"

using namespace std;
using namespace cv;


int main(int argc, char* argv[]){

  Mat img1 = imread("000000.png");
  Mat img2 = imread("000003.png");
  Mat preGray,curGray;
  cvtColor(img1,preGray,CV_RGB2GRAY);
  cvtColor(img2,curGray,CV_RGB2GRAY);
  Rect box(685.957942,188.300055,(795.011372-685.957942),(287.419861-188.300055));


  FBerror fberror;
  vector<Point2f> pts1,pts2;
  fberror.bbPoints(pts1, box);
  pts2 = pts1;
  bool tracked = fberror.trackf2f(preGray,curGray,pts1,pts2);
  cout<< tracked<<endl;


}
set args 0021 Pedestrian00005.ann
b FBerror.cpp:138
