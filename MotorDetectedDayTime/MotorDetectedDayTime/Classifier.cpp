#include "Classifier.h"

/*!
* �]�w�����������H�ήت��C��
* @param type ��ClassiferType �����A������������
* @param rectangleColor ��Scalar �����A����������������ɨϥΪ��ت��C��
* @param threshold ��float �����A�����������e�ȡA�ȶV�C�N�V�e�P�A�ȶV���N�V�Y��
*/
Classifier::Classifier(ClassiferType type, Scalar rectangleColor)
{
	_type = type;
	_rectangleColor = rectangleColor;	
}

Classifier::~Classifier()
{
}

/*!
* ���otracker���Q�R�����ϰ�A�ðO���Ӱ϶���index�A����o���϶���index�P��eframe��
* �t�Z��]�w�d��ɡA�R���Ӱ϶��C
*/
void Classifier::setRestROI()
{
	_restroi = new RestROI;
	if (_tracker._restTrackingObjs.size() > 0)
	{
		for (int i = 0; i < _tracker._restTrackingObjs.size(); i++)
		{
			_restroi->_trackingroi.push_back(_tracker._restTrackingObjs[i]);
		}
		_restroi->_index = _count;
		_recordlist.push_back(_restroi);

		_tracker._restTrackingObjs.clear();
	}
	for (int j = 0; j < _recordlist.size(); j++)
	{
		if (_count - _recordlist[j]->_index >= 3)
		{
			RestROI* temp = _recordlist[j];
			cout << "delete ROI! " << temp->_index << endl;
			_recordlist.erase(find(_recordlist.begin(), _recordlist.end(), temp));
			delete temp;
		}
	}
	_count++;
}

/*!
* �ˬdtracker���O�_���Q�R�����ϰ�
*/
bool Classifier::IsRestROI()
{
	if (_recordlist.size()>0)return true;
	else return false;
}

/*!
* �N�b���������Q�R�����l�ܰϰ�^��
*/
vector<Classifier::RestROI*> Classifier::getRestROI()
{
	return _recordlist;
}

void Classifier::Classify(Mat & frame)
{
}

/*!
* Tracker�i���s����ܩ��J�v���W
* @param frame ��Mat���A�A����J���v��
*/
bool Classifier::Update(Mat &frame)
{	
	 _tracker.update(frame, _result, _rectangleColor);	
	 _tracker.draw(frame, _rectangleColor);
	return 0;
}

