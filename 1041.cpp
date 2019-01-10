//1041 考试座位号
#include<iostream>
#include<string>

using namespace std;

struct stu
{
	string ID;
	int testseat;
};

int main()
{
	int N;
	cin >> N;
	stu student[1001]//需要定义1001个元素的结构体数组
	int temp,tep;
	string IDtemp;
	for (int i = 0; i < N; i++)//以试机号为下标存储数据
	{
		cin >> IDtemp >> temp >> tep;
		student[temp].ID = IDtemp;
		student[temp].testseat = tep;
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		cout << student[temp].ID << ' ' << student[temp].testseat << endl;
	}
	return 0;
}
