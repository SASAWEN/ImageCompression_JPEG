//#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <iostream>
#include "ImgInfo.h"
#include "PreEncoder.h"

//void Jpegcompress(const cv::Mat& src, cv::Mat& dest, int quality)
//{
//	std::vector<uchar> buff;
//	std::vector<int> params;
//	/*IMWRITE_JPEG_QUALITY For JPEG, it can be a quality from 0 to 100
//	(the higher is the better). Default value is 95 */
//	params.push_back(cv::IMWRITE_JPEG_QUALITY);
//	params.push_back(quality);
//	//��ͼ��ѹ�����뵽����������
//	cv::imencode(".jpg", src, buff, params);
//	//��ѹ����Ļ��������ݽ���ΪMat�����к����Ĵ���
//	dest = cv::imdecode(buff, -1);
//	cv::imshow("src", src);
//	cv::imshow("dst", dest);
//	cv::imwrite("./images/compression.jpg", dest);
//}


int main()
{
	cout << "====" << endl;
	ImgInfo* info = new ImgInfo("./images/lena1.png");

	//std::string fileName = "./images/lena1.png";
	//cv::Mat src = cv::imread(fileName, -1);
	//if (src.empty())
	//{
	//	std::cerr << " image open error!\n";
	//	return 0;
	//}
	//cv::Mat dest;
	////�����ȼ�Ϊ��Ϊ50
	//Jpegcompress(src, dest, 50);
	getchar();
	cvWaitKey(100);
	return 0;
}
