#ifndef OFFLINE_MODE_H
#define OFFLINE_MODE_H

#include "DataReader.h"
//#include "FusionManager.h"
//#include "Classifier.h"
#include "SvmClassifier.h"
#include <Windows.h>
#include <time.h>
#include "Mode.h"

/*!
* ��class�����o�v���H��Lidar��ƫ�A�ھڳ]�w���Z���b�v���W�i��ROI�����ΥH�Ϊ��󪺰����ΰl��
*/
using cv::Rect;
using cv::Mat;
using cv::waitKey;
using cv::VideoWriter;
using cv::Vec3f;
using cv::destroyAllWindows;
class OfflineMode : public Mode
{
private:
	string _videoFileName;
	int _filterRoiDistance;
	int _waitKeySec;
	int _waitKeyChoosen;
	FusionType _type;
	bool WaitKey();
	void Detect(Mat &frame, Mat &grayFrame,int count);

public:
	OfflineMode(string videoFileName, FusionType type, int currentModelType = 0);
	virtual ~OfflineMode();
	int GetChoiceVideoType();
	void Run();
	Rect adjustROI(Mat, Rect);
};

#endif