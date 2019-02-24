//1082 射击比赛
#include<iostream>
#include<map>
#include<cmath>

using namespace std;

double dis(double x, double y)
{
	return sqrt(x*x + y*y);
}

int main()
{
	int N;//记录运动员个数
	cin >> N;
	int id; double x, y;
	map<double,int> score;//记录ID与其匹配的成绩
	//将成绩储存在map中一一对应
	for (int i = 0; i < N; i++)
	{
		cin >> id >> x >> y;
		score.insert(pair<double, int>(dis(x, y),id));
	}
	//由于score自动按照first升序排列，直接输出第一个与最后一个元素的id即可
	map<double,int>:: iterator it=score.end();
	it--;
	printf("%04d %04d\n", score.begin()->second, it->second);//注意距离最远的是菜鸟
	return 0;
}
