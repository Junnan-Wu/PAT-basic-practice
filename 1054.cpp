//1054 求平均值
#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

bool judge(string a)
{
	int point = 0, pos = -1, sub = 0;
	//先判断第一个字符是否是数字与负号
	if (!(a[0] == '-' || (a[0] >= '0'&&a[0] <= '9'))) return false;
	for (unsigned int i = 1; i < a.length(); i++)//判断后面是否全是数字或者只有一个小数点
	{
		if (a[i] >= '0'&&a[i] <= '9')
		{
			continue;
		}
		else if (point == 0 && a[i] == '.')
		{
			point++;
			pos = i;//记录小数点位置
			continue;
		}
		else
			return false;
	}
	//判断有没有超出两位小数
	unsigned length = a.length() - pos - 1;//计算小数点到最后一位的长度
	if (pos!=-1&&length>2)return false;
	else return true;
}


int main()
{
	int N;
	int legal = 0;
	string store;
	double avg = 0, temp;
	stringstream ss;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> store;
		if (judge(store))//先判断是否是合法数字
		{
			ss << store;
			ss >> temp;
			ss.clear();
			if (temp >= -1000 && temp <= 1000)//如果是合法数字，将其转化为double后判断是否在[-1000,1000]的范围内
			{
				avg += temp;
				legal++;
			}
			else
			{
				cout << "ERROR: " << store << " is not a legal number" << endl;
			}
		}
		else
		{
			cout << "ERROR: " << store << " is not a legal number" << endl;
		}
	}
	avg /= legal;
	if (legal == 0)
	{
		cout << "The average of 0 numbers is Undefined" << endl;
	}
	else if (legal==1)//注意k=1的时候，number没有s！
	{
		cout << "The average of " << legal << " number is ";
		printf("%.2f\n", avg);
	}
	else
	{
		cout << "The average of " << legal << " numbers is ";
		printf("%.2f\n", avg);
	}
	return 0;
}
