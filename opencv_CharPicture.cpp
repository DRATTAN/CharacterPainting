#include <windows.h>
#include <fstream>
#include <time.h>
#include "Converter.h"

using namespace cv;
using namespace std;

string VideoSrc = "C:\\Users\\RATTAN\\Desktop\\opencv workspace\\resource\\video\\yaorenmaoXyour.mp4";
string PictureSrc = "C:\\Users\\RATTAN\\Desktop\\opencv workspace\\resource\\picture\\jiaran.jpg";
string GrayScale = "@B%8&WM#*oahkbqwmZOQLUYXzcxrjft/()1{}[]?-_+~<>iI;:^. ";
string TxtSrc = "C:\\Users\\RATTAN\\Desktop\\out.txt";
#define ISVIDEO 0

int main()
{
	Converter converter;
	string str;
#if(ISVIDEO == 0)
	str = converter.mat2string(imread(PictureSrc, IMREAD_UNCHANGED), 0.4, 0.3, GrayScale, INTER_LINEAR);
	system("taskkill /f /im \"notepad.exe\"");
	ofstream txt(TxtSrc, ofstream::trunc);
	cout << str;
	txt << str << endl;;
	txt.close();
	system("start C:/Users/RATTAN//Desktop/out.txt");

#endif

#if(ISVIDEO == 1)

	Mat frame;
	VideoCapture video(VideoSrc);
	clock_t time = 0;
	double fps = 0;
	if (video.isOpened() == 0) {
		cout << "could not read this video file..." << endl;
		return -1;
	}
	namedWindow("demo", WINDOW_KEEPRATIO);

	while (1)
	{
		fps = 1.0 / ((double)(clock() - time) / (double)CLOCKS_PER_SEC);
		time = clock();
		if (video.read(frame) == 0) break;
		HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos;
		pos.X = 0;
		pos.Y = 0;
		SetConsoleCursorPosition(hConsoleOutput, pos);
		str = converter.mat2string(frame, 0.3, 0.15, GrayScale, INTER_LINEAR);
		cout << str;
		std::cout << "fps" << fps << std::endl;
		//putText(frame, "fps:" + to_string(fps).substr(0, 5), Point(30, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2);
		imshow("demo", frame);
		char c = waitKey(1);
		if (c > 0) break;
	}
	video.release();
#endif
	return 0;
}
