#pragma once
#include <fstream>
#include <iostream>
#include <sstream>  
using namespace std;

class Kfold {
public:
	Kfold();
	~Kfold();

	void WriteResult(string fileName, string result, string weight);

private:
	string _fileName;
};
