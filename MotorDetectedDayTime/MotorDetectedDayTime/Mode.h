#ifndef MODE_H
#define MODE_H

#include "Classifier.h"

/*!
* ��class�i�ΨӤ����ާ@�Ҧ�
*/
class Mode
{
private:

protected:
	//FusionManager _fusionManager;
	vector<Classifier*> _classifierList;

public:
	Mode();
	virtual ~Mode();
	virtual void Run() = 0;
};

#endif 