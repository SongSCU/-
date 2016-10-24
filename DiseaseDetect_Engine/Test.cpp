#include "Test.h"
#include <list>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "Utilities.h"
using namespace cv;
using namespace std;
void TestSubblockVariance(const cv::Mat& img) {
	std::list<uint8_t> lst;
	std::cout << "\n�ӿ鷽���\n";
	eng::SubblockVariance(img, lst, 50);
	for each (uint8_t  val in lst) {
		std::cout << (int)val << "  ";
	}
}

void TestSubblockEntropy(const cv::Mat& img) {
	std::list<uint8_t> lst;
	std::cout << "\n�ӿ���Ϣ�ط���\n";
	eng::SubblockEntropy(img, lst, 4.6);
	for each (uint8_t  val in lst) {
		std::cout << (int)val << "  ";
	}
}

void TestWriteResultInfo() {
	std::list<ResultInfo*> lst;
	for (int i = 0; i < 100; i++) {
		bool b = rand() % 2;
		lst.push_back(new ResultInfo(i, b));
	}
	WriteResultInfo(s_finPath + "out.data", lst);
}

void TestReadImageInfo() {
	std::list<ImageInfo*> lst;
	ReadImageInfo(s_foutPath + "in.data", lst);
	for each(ImageInfo* p in lst) {
		std::cout << p->id << "  " << p->path << std::endl;
	}
}

void TestDetect() {
	Mat src = imread(s_imgPath + "lf2.jpg");
	//Mat src = imread("1.jpg");
	Mat dst;

	imshow("ԭʼͼ��", src);

	eng::PreProcess(src, dst);

	TestSubblockVariance(dst);
	TestSubblockEntropy(dst);

	eng::SplitGrid(dst, 255);

	cout << endl;
	imshow("����ָ�", dst);
	waitKey(0);
}

void TestReleaseData() {
	list<ImageInfo*> lst1;
	for (int i = 0; i < 100; i++) {
		lst1.push_back(new ImageInfo(i, "hahaha"));
	}
	list<ResultInfo*> lst2;
	for (int i = 0; i < 100; i++) {
		lst2.push_back(new ResultInfo(i, true));
	}
	cout << lst1.size() << " " << lst2.size() << endl;
	ReleaseData(lst1, lst2);
}

void TestProcessImage() {
	list<ImageInfo*> lstImages;
	list<ResultInfo*> lstResults;
	string src = s_finPath + "in.data";
	string dst = s_foutPath + "out.data";

	ReadImageInfo(src, lstImages);
	cout << lstImages.size() << endl;
	ProcessImages(lstImages, lstResults);
	cout << lstResults.size() << endl;
	WriteResultInfo(dst, lstResults);

	ReleaseData(lstImages, lstResults);
}

void TestAmftSrMethod() {
	Mat src = imread(s_imgPath + "liefeng/2.jpg");
	Mat dst1, dst2, dst3;

	//eng::PreProcess(src, dst1);
	cvtColor(src, dst1, CV_BGR2GRAY);
	eng::EdgeDetection_Sobel(dst1, dst2);

	eng::MaftSrMethod(dst1, dst3);

	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);
	ShowManyImages("�Ҷ�-Ԥ����-��Ե���-������", 4, &IplImage(gray), &IplImage(dst1), &IplImage(dst2), &IplImage(dst3));

	TestSubblockVariance(dst3);
	eng::SplitGrid(dst3, 255);
	imshow("����ָ�", dst3);
	waitKey(0);
}

void TestProjectionAnalysis() {

}

void TestProjection() {
	Mat src = imread(s_imgPath + "liefeng/5.jpg");
	Mat dst1, dst2, dst3, dst4;

	//eng::PreProcess(src, dst1);
	cvtColor(src, dst1, CV_BGR2GRAY);
	eng::EdgeDetection_Sobel(dst1, dst2);

	eng::MaftSrMethod(dst2, dst3);

	eng::Binaryzation(dst3, dst4, 50);
	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);
	ShowManyImages("�Ҷ�-Ԥ����-��Ե���-������-��ֵ��", 5, &IplImage(gray), &IplImage(dst1), &IplImage(dst2), &IplImage(dst3), &IplImage(dst4));

	vector<uint16_t> ver, hor;
	eng::ProjectionStatistic(dst4, hor, ver);
	Mat v, h;
	eng::GenerateProjectionImage(hor, ver, v, h);
	imshow("ˮƽͶӰͼ", h);
	imshow("��ֱͶӰͼ", v);

	float probability;
	list<DiseaseArea> area;
	eng::ProjectionAnalysis(dst4, hor, ver, probability, area);
	cout << "���ѷ�����ԣ�" << probability << endl;
	eng::TagDiseaseArea(gray, area, 255);
	imshow("��������", gray);
	waitKey(0);
}

void TestBinaryzation() {
	Mat src = imread(s_imgPath + "liefeng/5.jpg");
	Mat gray, dst;
	cvtColor(src, gray, CV_BGR2GRAY);
	eng::Binaryzation(gray, dst, 150);
	imshow("ԭͼ", src);
	imshow("�Ҷ�ͼ", gray);
	imshow("��ֵ��", dst);
	waitKey(0);
}

void TestTagDiseaseArea() {
	Mat src = imread(s_imgPath + "liefeng/2.jpg");
	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);
	imshow("�Ҷ�ͼ", gray);
	list<DiseaseArea> area;
	area.push_back(DiseaseArea(10, 100, 10, 100));
	area.push_back(DiseaseArea(110, 200, 10, 100));
	area.push_back(DiseaseArea(10, 200, 120, 200));
	eng::TagDiseaseArea(gray, area, 0);
	imshow("���ͼ��", gray);
	waitKey(0);
}