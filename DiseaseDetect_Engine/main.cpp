#include <opencv2/opencv.hpp>
#include "DiseaseDetect.h"
#include "Test.h"
#include <fstream>
#include "DataIO.h"
#include "params.h"
using namespace cv;
using namespace std;
#define _TEST

std::string g_imgOutPath = "";
int s_blurType = 0; //0-��˹�˲��� 1-��ֵ�˲��� 2-�����˲��� 3-��ֵ�˲�
bool s_bMaft = true;
int s_detectType = 0;  //0-�ӿ鷽� 1-�ӿ���Ϣ��
bool s_bProDetect = true;
bool s_bColorDetect = true;
double s_varThreshold = 90;
double s_entThreshold = 4.9;
int s_binThreshold = 50;

#ifdef _TEST
int main() {

	TestProjection();

	return 0;
}
#else
int main(int argc, char ** argv) {
	if ((argc % 2) != 1) {
		cerr << "param error!" << endl;
		exit(0);
	}

	//string inPath = "D:\\workspace_main\\opencv3\\DiseaseDetect\\DiseaseDetect_Engine\\resource\\images\\liefeng\\";
	//string outPath = "D:\\workspace_main\\opencv3\\DiseaseDetect\\DiseaseDetect_Engine\\resource\\files\\out.data";
	//g_imgOutPath = "D:\\workspace_main\\opencv3\\DiseaseDetect\\DiseaseDetect_Engine\\resource\\files\\imgs";
	//string paramPath = "D:\\workspace_main\\opencv3\\DiseaseDetect\\DiseaseDetect_Engine\\resource\\files\\config.json";
	string inPath = "";
	string outPath = "";
	g_imgOutPath = "";
	string paramPath = "";

	for (int i = 1; i < argc; i += 2) {
		char * s1 = argv[i];
		char * s2 = argv[i + 1];

		if (0 == strcmp(s1, "-s")) {
			inPath = s2;
		}
		else if (0 == strcmp(s1, "-d")) {
			outPath = s2;
		}
		else if (0 == strcmp(s1, "-p")) {
			paramPath = s2;
		}
		else if (0 == strcmp(s1, "-i")) {
			g_imgOutPath = s2;
		}
	}

	if (paramPath != "") {
		ReadParams(paramPath);
	}

	list<ImageInfo*> lstImages;
	list<ResultInfo*> lstResults;

	ReadImageInfo(inPath, lstImages);

	ProcessImages(lstImages, lstResults);

	WriteResultInfo(outPath, lstResults);

	ReleaseData(lstImages, lstResults);

	return 0;
}

#endif

