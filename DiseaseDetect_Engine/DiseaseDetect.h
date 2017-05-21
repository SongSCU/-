#pragma once

#include "opencv2/opencv.hpp"
#include <list>
#include "Defines.h"
#include "BasicStructs.h"
namespace eng {
	//Ԥ����
	void PreProcess(const cv::Mat& src, cv::Mat& dst);

	//��������
	void SplitGrid(cv::Mat& img, uint8_t color);

	//�ӿ鷽�
	void SubblockVariance(const cv::Mat& img, std::list<DiseaseArea> & list, double threshold);
	void SubblockVariance(const cv::Mat& img, std::list<uint16_t> & list, double threshold);
	//�ӿ���Ϣ�ط�
	void SubblockEntropy(const cv::Mat& img, std::list<DiseaseArea> & list, double threshold);
	void SubblockEntropy(const cv::Mat& img, std::list<uint16_t> & list, double threshold);
	//�ӿ�HSV��
	void SubblockHsv(const cv::Mat& img, std::list<uint8_t> & list, float threshold);

	//�ӿ�RGB��
	void SubblockRgb(const cv::Mat& img, std::list<uint8_t> & list, float varThreshold, float rgbThreshold, float rate);

	//sobel���ӱ�Ե����װ
	void EdgeDetection_Sobel(const cv::Mat& src, cv::Mat& dst);

	//scharr���ӱ�Ե����װ
	void EdgeDetection_Scharr(const cv::Mat& src, cv::Mat& dst);

	//�����߱任��װ
	void HoughLine(const cv::Mat& src, cv::Mat& dst);

	//��������Ҷ�任-�����׷���
	void MaftSrMethod(const cv::Mat& src, cv::Mat& dst);

	//��ֵ������
	void Binaryzation(const cv::Mat& src, cv::Mat& dst, uint8_t threshold);

	//ͶӰͳ��--��Զ�ֵͼ��
	void ProjectionStatistic(const cv::Mat& src, std::vector<uint16_t>& horizontal, std::vector<uint16_t>& vertical);

	bool ProjectionDetect();

	bool ColorDetect();

	uint8_t DetectType();
	//ͶӰ����
	void ProjectionAnalysis(const cv::Mat& src, const std::vector<uint16_t>& horizontal, const std::vector<uint16_t>& vertical, float& probability, std::list<DiseaseArea>& area);

	//����ͶӰ�ֲ�ͼ
	void GenerateProjectionImage(const std::vector<uint16_t>& horizontal, const std::vector<uint16_t>& vertical, cv::Mat& imgV, cv::Mat& imgH);

	//��ǲ�������--��Ե�ͨ��ͼ��
	void TagDiseaseArea(cv::Mat& src, const std::list<DiseaseArea>& area, uint8_t color);
	void TagDiseaseArea(cv::Mat& src, const std::list<uint16_t>& area, uint8_t color);
}

void ProcessImages(const std::list<ImageInfo*>& _images, std::list<ResultInfo*>& _results);


