#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat img = imread("saltpepperimg.jpg", IMREAD_GRAYSCALE);
	CV_Assert(!img.empty()); //예외처리
	Mat img2 = Mat(size(img), CV_8UC1, Scalar(0)); //단일채널 영상 출력
	Mat img3 = Mat(size(img), CV_8UC1, Scalar(0)); //단일채널 영상 출력
	Mat img4 = Mat(size(img), CV_8UC1, Scalar(0)); //단일채널 영상 출력
	Mat img5 = Mat(size(img), CV_8UC1, Scalar(0)); //단일채널 영상 출력
	Point pt(0, 0);

	medianBlur(img, img2, 3); //openCV제공 메디안 필터링 함수- 3X3 필터링
	medianBlur(img, img3, 13); //openCV제공 메디안 필터링 함수- 13X13 필터링
	
	Size size1(3, 3); //3X3 가우시안 마스크
	double sigMax1 = 0.3*((size1.width - 1)*0.5 - 1) + 0.8; //가로방향 표준편차
	double sigMay1 = 0.3*((size1.height - 1)*0.5 - 1) + 0.8; //세로방향 표준편차

	GaussianBlur(img, img4, size1, sigMax1, sigMay1); //openCV제공 가우시안 스무딩 함수

	Size size2(13, 13); //13X13 가우시안 마스크
	double sigMax2 = 0.3*((size2.width - 1)*0.5 - 1) + 0.8; //가로방향 표준편차
	double sigMay2 = 0.3*((size2.height - 1)*0.5 - 1) + 0.8; //세로방향 표준편차

	GaussianBlur(img, img5, size2, sigMax2, sigMay2); //openCV제공 가우시안 스무딩 함수

	imshow("원본", img);
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);
	imshow("img5", img4);
	waitKey(0);
	return 0;
}