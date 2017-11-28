#ifndef DATA_READER_H
#define DATA_READER_H

#include "VideoReader.h"
#include <string>
#include <vector>
#include <fstream>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace std;



/*!
* ��class�Ψ�Ū���v����Lidar��ơA�ïണ�ѳ�iframe�������浧Lidar���
*/
class DataReader :public VideoReader
{
private:
	ifstream _lidarTextFile;
	int GetLidarDataCount();
	//void RetrieveLidarDataFromText(string &text, string symbol, vector<long>& lidarDistanceData, vector<unsigned short>& lidarSignalData);

public:
	DataReader(string videoFileName, string lidarFileName);
	~DataReader();
	string StartRead();
	//void RequestOneData(Mat &frame, vector<long>& lidarDistanceData, vector<unsigned short>& lidarSignalData, string &lidarHeader);
};

#endif