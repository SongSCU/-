#pragma once
#include "opencv2/opencv.hpp"
#include "DiseaseDetect.h"
#include "DataIO.h"

//�ӿ鷽�����
void TestSubblockVariance(const cv::Mat& img);
//�ӿ���Ϣ�ز���
void TestSubblockEntropy(const cv::Mat& img);
//д��������Ϣ����
void TestWriteResultInfo();
//����ͼ����Ϣ����
void TestReadImageInfo();
//����������
void TestDetect();
//�ͷ���Դ����
void TestReleaseData();
//ͼ�������
void TestProcessImage();
//�����׷�������
void TestAmftSrMethod();
//ͶӰ��������
void TestProjectionAnalysis();
//ͶӰ����
void TestProjection();
//��ֵ������
void TestBinaryzation();
//��ǲ����������
void TestTagDiseaseArea();