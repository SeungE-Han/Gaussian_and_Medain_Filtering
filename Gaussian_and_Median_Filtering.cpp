#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat img = imread("saltpepperimg.jpg", IMREAD_GRAYSCALE);
	CV_Assert(!img.empty()); //����ó��
	Mat img2 = Mat(size(img), CV_8UC1, Scalar(0)); //����ä�� ���� ���
	Mat img3 = Mat(size(img), CV_8UC1, Scalar(0)); //����ä�� ���� ���
	Mat img4 = Mat(size(img), CV_8UC1, Scalar(0)); //����ä�� ���� ���
	Mat img5 = Mat(size(img), CV_8UC1, Scalar(0)); //����ä�� ���� ���
	Point pt(0, 0);

	medianBlur(img, img2, 3); //openCV���� �޵�� ���͸� �Լ�- 3X3 ���͸�
	medianBlur(img, img3, 13); //openCV���� �޵�� ���͸� �Լ�- 13X13 ���͸�
	
	Size size1(3, 3); //3X3 ����þ� ����ũ
	double sigMax1 = 0.3*((size1.width - 1)*0.5 - 1) + 0.8; //���ι��� ǥ������
	double sigMay1 = 0.3*((size1.height - 1)*0.5 - 1) + 0.8; //���ι��� ǥ������

	GaussianBlur(img, img4, size1, sigMax1, sigMay1); //openCV���� ����þ� ������ �Լ�

	Size size2(13, 13); //13X13 ����þ� ����ũ
	double sigMax2 = 0.3*((size2.width - 1)*0.5 - 1) + 0.8; //���ι��� ǥ������
	double sigMay2 = 0.3*((size2.height - 1)*0.5 - 1) + 0.8; //���ι��� ǥ������

	GaussianBlur(img, img5, size2, sigMax2, sigMay2); //openCV���� ����þ� ������ �Լ�

	imshow("����", img);
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);
	imshow("img5", img4);
	waitKey(0);
	return 0;
}