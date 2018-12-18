//1006	换个格式输出整数
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int hundred, ten, unit;
	hundred = n / 100;
	ten = (n - 100 * hundred) / 10;
	unit = n - 100 * hundred - 10 * ten;
	for (int i = 0; i < hundred; i++)
	{
		cout << 'B';
	}
	for (int i = 0; i < ten; i++)
	{
		cout << 'S';
	}
	for (int i = 1; i <= unit; i++)
	{
		cout << i;
	}
	return 0;
}
