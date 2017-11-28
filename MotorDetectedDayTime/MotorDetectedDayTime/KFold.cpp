#include "KFold.h"

Kfold::Kfold() {

}

Kfold::~Kfold() {

}

void Kfold::WriteResult(string fileName, string result, string weight){
	_fileName = fileName;
	//string filename = "Position2.csv";
	fstream fp;
	fp.open(_fileName, ios::app);//�}���ɮ�
	if (!fp) {//�p�G�}���ɮץ��ѡAfp��0�F���\�Afp���D0
		cout << "Fail to open file: " << _fileName << endl;
	}


	ostringstream ostrs;
	ostrs << result << "," << weight;
	string strs = ostrs.str();

	fp << strs << endl;
}