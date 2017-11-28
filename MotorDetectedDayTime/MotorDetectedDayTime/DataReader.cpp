#include "DataReader.h"

DataReader::DataReader(string videoFileName, string lidarFileName) :VideoReader(videoFileName)
{
	_lidarTextFile.open(lidarFileName, ios::in);
}

DataReader::~DataReader()
{
	_lidarTextFile.close();
}

/*!
* �p��Lidar����`�@���X��
*/
int DataReader::GetLidarDataCount()
{
	int count = 0;
	while (!_lidarTextFile.eof())
	{
		string headerText;
		getline(_lidarTextFile, headerText);
		string quantityText = headerText.substr(0, headerText.find(" "));
		int quantity = atoi(quantityText.c_str());
		for (int i = 0; i < quantity; i++)
		{
			string data;
			getline(_lidarTextFile, data);
		}
		if (quantity > 0)
		{
			count++;
		}
	}
	_lidarTextFile.clear();
	_lidarTextFile.seekg(0, ios::beg);
	return count;
}

/*!
* �qtxtŪ��Lidar��ơA�C����ƬO��1�ӶZ����ƥH�Τ@�ӥ��Ϯg�j�׭Ȳզ�
*/
/*void DataReader::RetrieveLidarDataFromText(string &text, string symbol, vector<long>& lidarDistanceData, vector<unsigned short>& lidarSignalData)
{
	int per = 0;
	int beforeValue;
	char *temp = strdup(text.c_str());
	char *garbege;
	strtok_s(temp, symbol.c_str(), &garbege);
	while (temp != NULL && per < 2)
	{
		if (per == 0)
		{
			beforeValue = atoi(temp);
		}
		else if (per == 1)
		{
			lidarDistanceData.push_back(beforeValue);
			lidarSignalData.push_back(atoi(temp));
		}
		temp = strtok_s(NULL, symbol.c_str(), &garbege);
		per++;
	}
	free(temp);
}*/

/*!
* Ū���v����Lidar��ơA�p�v���άOLIDAR���Ū���o�Ͱ��D�h��^���~�T��
* @param videlFileName ��string �����A���n�������v���W��
* @param lidarFileName ��string �����A���n�������v��������Lidar��ƦW��
* @return �^�ǿ��~�T���A�p�L������~�h�^�ǥ]�tframe�ƥH��Lidar��Ƽƪ����\�T��
*/
string DataReader::StartRead()
{
	VideoReader::StartRead();
	if (!_lidarTextFile)
	{
		return "LidarTextFile Error";
	}
	return "File open success, total " + to_string(_dataQuantity) + " frame, " + to_string(GetLidarDataCount()) + " lidar data";
}

/*!
* ���o�@�iframe�H�ι������@��Lidar���
* @param frame ��Mat���A�A����l��J�v��
* @param lidarDistanceData ��vector<ling>���A�A�ΨӦs��C��Lidar��Ƥ��@1521�Ө��ת��Z��
* @param lidarSignalData ��vector<ling>���A�A�ΨӦs��C��Lidar��Ƥ��@1521�Ө��ת��T���j��
* @param lidarHeader ��string���A�A�ΨӤ���Lidar��ƥH�K���o�C����Ƽƶq
*/
/*void DataReader::RequestOneData(Mat &frame, vector<long>& lidarDistanceData, vector<unsigned short>& lidarSignalData, string &lidarHeader)
{
	getline(_lidarTextFile, lidarHeader);
	string quantityText = lidarHeader.substr(0, lidarHeader.find(" "));
	int quantity = atoi(quantityText.c_str());
	for (int i = 0; i < quantity; i++)
	{
		string dataText;
		getline(_lidarTextFile, dataText);
		RetrieveLidarDataFromText(dataText, " ,", lidarDistanceData, lidarSignalData);
	}
	_cameraVideo.read(frame);
}*/