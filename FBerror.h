#ifndef FBERROR_H
#define FBERROR_H

#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

float median(std::vector<float> v);
class FBerror{
private:
	vector<Point2f> pointsFB;
	Size window_size;
	int level;
	vector<uchar> status;
	vector<uchar> FB_status;
	vector<float> similarity;
	vector<float> FB_error;
	float simmed;
	float fbmed;
	TermCriteria term_criteria;
	float lambda;
	void normCrossCorrelation(const Mat& img1,const Mat& img2, vector<Point2f>& points1, vector<Point2f>& points2);
	bool filterPts(vector<Point2f>& points1,vector<Point2f>& points2);
public:
	FBerror();
	void bbPoints(vector<Point2f> &points, const Rect& bb);
	bool trackf2f(const Mat& img1, const Mat& img2,vector<Point2f> &points1, vector<Point2f> &points2);
	float getFB(){return fbmed;}
};

#endif