//1026 程序运行时间
//本题很简单，只要注意输出的格式即可，注意不足两位的要用0补充，同时秒还要四舍五入
#include<iostream>

using namespace std;

int main()
{
	int C1, C2;
	cin >> C1 >> C2;
	int CLK_TCK = 100;
	double t = (C2 - C1)/(CLK_TCK+0.0);
	int hour, minute, second;
	hour = t / 60 / 60;
	minute = (t - hour * 3600) / 60;
	second = (t - hour * 3600 - minute * 60) + 0.5;
	printf("%02d:%02d:%02d", hour, minute, second);
	return 0;
}
