#include "VideoReader.h"

VideoReader::VideoReader(string videoFileName)
{
	_cameraVideo.open(videoFileName);
}

VideoReader::~VideoReader()
{

}

/*!
*���o�`Frame��
*/
int VideoReader::GetDataQuantity()
{
	return _dataQuantity;
}

int VideoReader::GetCameraFPS()
{
	return _cameraFPS;
}

/*!
* Ū���v����ơA�p�v�����Ū���o�Ͱ��D�h��^���~�T��
* @param videlFileName ��string �����A���n�������v���W��
* @return �^�ǿ��~�T���A�p�L������~�h�^�ǥ]�tframe�ƥH��Lidar��Ƽƪ����\�T��
*/
string VideoReader::StartRead()
{
	if (!_cameraVideo.isOpened())
	{
		return "Camera Error";
	}
	_dataQuantity = _cameraVideo.get(CV_CAP_PROP_FRAME_COUNT);
	_cameraFPS = _cameraVideo.get(CV_CAP_PROP_FPS);
	return "File open success, total " + to_string(_dataQuantity) + " frame, ";
}

/*!
* ���o�@�iframe�H�ι������@��Lidar���
* @param frame ��Mat���A�A����l��J�v��
*/
void VideoReader::RequestOneData(Mat &frame)
{
	_cameraVideo.read(frame);
}

Size VideoReader::getVideoSize()
{
	return Size(_cameraVideo.get(CV_CAP_PROP_FRAME_WIDTH), _cameraVideo.get(CV_CAP_PROP_FRAME_HEIGHT));
}