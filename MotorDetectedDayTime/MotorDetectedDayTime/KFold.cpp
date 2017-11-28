#include "KFold.h"

Kfold::Kfold() {

}

Kfold::~Kfold() {

}

void Kfold::WriteResult(string fileName, string result, string weight){
	_fileName = fileName;
	//string filename = "Position2.csv";
	fstream fp;
	fp.open(_fileName, ios::app);//開啟檔案
	if (!fp) {//如果開啟檔案失敗，fp為0；成功，fp為非0
		cout << "Fail to open file: " << _fileName << endl;
	}


	ostringstream ostrs;
	ostrs << result << "," << weight;
	string strs = ostrs.str();

	fp << strs << endl;
}