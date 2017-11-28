#ifndef CLASSIFIER_TYPE_H
#define CLASSIFIER_TYPE_H


using cv::Scalar;
using cv::Mat;
using cv::Rect;
using cv::Size;
/*!
* ��.h�ɴ��ѤF�ϥΪ��������A�A�H�λPLIDAR���X�ɸӨϥέ��չ����Ѽ�
*/
enum ClassiferType
{
	Vehicle,
	Pedestrian,
	Motorbike,
	UnKnown
};

enum FusionType
{
	CarFront,
	CarRightSide,
	CarLeftSide,
	CarBack
};

typedef struct svmDetectParameter 
{	
	Size WINDOW_SIZE;
	Size CELL_SIZE;	
	float hitThreshold;
	Size winStride;
	Size padding;
	double scale;
	double finalThreshold;
	bool useMeanshiftGrouping;
};
#endif;