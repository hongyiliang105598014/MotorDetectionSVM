#include "OfflineMode.h"
#include <Windows.h>
#include <time.h>
int main()
{
	time_t nStart = time(NULL);	
	//string path = "Test Video\\1117新機車影片1.MOV";
	//string path = "Test Video\\1117新機車影片4.MOV";
	//string path = "Test Video\\1117新機車影片3.MOV";
	//string path = "Test Video\\0823_motorside1.mp4";
	//string path = "Test Video\\0823_motorside3.mp4";
	string path = "D:\\UserFolder\\Desktop\\機車\\3-fold機車正背面\\cate3\\";
	//string path = "Test Video\\0817_carrear.mp4";
	
	Mode *mode = new OfflineMode(path, FusionType::CarFront, 1);
		
	mode->Run();
	((OfflineMode *)mode)->GetChoiceVideoType();
	delete mode;
	
	time_t nEnd = time(NULL);
	cout << nEnd - nStart << endl;
	system("PAUSE");
	return 0;
}