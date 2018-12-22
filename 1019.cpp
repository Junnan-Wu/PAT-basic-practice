//1019	数字黑洞
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int cal(int a)//对a进行演算
{
	vector<int> N;
	int mul=1000;
	int max=0, min=0;
	for (int i = 0; i < 4; i++)//先将a分为4位存储在vector数组中
	{
		N.push_back(a / mul);
		a = a - a/mul*mul;
		mul /= 10;
	}
	sort(N.begin(), N.end());//对a进行排序，非减序列
	mul = 1;
	for (int i = 3; i >=0 ; i--)//计算a的数组对应的数字
	{
		min += N[i]*mul;
		mul *= 10;
	}
	reverse(N.begin(), N.end());//逆序数组，非增
	mul = 1;
	for (int i = 3; i >= 0; i--)//计算a的数组对应的数字
	{
		max += N[i] * mul;
		mul *= 10;
	}
	printf("%04d - %04d = %04d\n", max, min, max - min);//输出两个数的计算结果
	return max - min;//返回两个数的计算结果
}

int main()
{
	int N;
	cin >> N;
	int temp = cal(N);//计算第一次结果，并输出
	if (temp == 0)return 0;
	while (temp != 6174)//如果不是黑洞数继续
	{
		temp = cal(temp);
	}
	return 0;
}
