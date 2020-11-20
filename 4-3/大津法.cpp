#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat srcMat = imread("C:/Users/DELL/Desktop/5.jpg",0);
	if (srcMat.empty())
	{
		cout << "fail to read pic!" << endl;
		return 0;
	}
	srcMat = 255 - srcMat;

	Mat stats;
	Mat centroids;
	Mat labels;
	Mat thresh_Mat;
	Mat erode_Mat;
	  
	threshold(srcMat, thresh_Mat, 100, 255, THRESH_OTSU);
	Mat element = getStructuringElement(MORPH_RECT, Size(5, 5), Point(-1, -1));
	erode(thresh_Mat, erode_Mat, element, Point(-1, -1), 8);
	int nComp = connectedComponentsWithStats(erode_Mat, labels, stats, centroids, 8, CV_32S);
	cout << "原点个数为：" << nComp - 1 << endl;
	

	waitKey(0);
	return 0;


}