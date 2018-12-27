//1022	D进制的A+B
//本题有一个注意点是A，B都为0的情况要予以考虑，有一个测试用例就是对0的结果的输出
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

string tentoD(int number, int D)//根据进制数D将10进制数字转化为字符串
{
	if (number == 0) return "0";
	vector<int> s;
	string n;
	while (number != 0)//进制数的转化，记录余数
	{
		s.push_back(number%D);
		number /= D;
	}
	int temp;
	while (!s.empty())
	{
		temp = *(s.end() - 1);//取最后一位数字，逆序即为转换后的字符串
		n+='0' + temp;
		s.pop_back();
	}
	return n;
}

int Dtoten(string a, int D)//将D进制的字符串a转化为10进制的整型
{
	int number=0;
	for (int i = 0; i < a.size(); i++)
	{

		number += (a[i]-'0') * pow(D, a.size() - 1 - i);
	}
	return number;
}

int main()
{
	int A, B;
	int D;
	cin >> A >> B >> D;
	int temp;
	temp = A + B;
	cout << tentoD(temp, D);
	return 0;
}
