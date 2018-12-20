//1012	数字分类
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int temp,N;
	vector<int> A1, A2, A3, A4, A5;
	cin >> N;
	for (int i = 0; i < N;i++)
	{
		cin >> temp;
		switch (temp % 5)
		{
		case 0:// 能被 5 整除的数字中所有偶数才放入数组
			if (temp % 2 == 0)
			A1.push_back(temp);
			break;
		case 1:
			A2.push_back(temp);
			break;
		case 2:
			A3.push_back(temp);
			break;
		case 3:
			A4.push_back(temp);
			break;
		case 4:
			A5.push_back(temp);
			break;
		}
	}
	//能被 5 整除的数字中所有偶数的和；
	if (A1.size() != 0)
	{
		temp = 0;
		for (int i = 0; i < A1.size(); i++)
		{
			temp += A1[i];
		}
		cout << temp;
	}
	else
		cout << 'N';
	//将被 5 除后余 1 的数字按给出顺序进行交错求和
	if (A2.size() != 0)
	{
		temp = 0;
		int mul = 1;//计算符号
		for (int i = 0; i < A2.size(); i++)
		{
			temp += A2[i] * mul;
			mul *= -1;
		}
		cout << ' ' << temp;
	}
	else
		cout << " N";
	//被 5 除后余 2 的数字的个数
	if (A3.size() != 0)
	{
		cout << ' ' << A3.size();
	}
	else
		cout << " N";
	//被 5 除后余 3 的数字的平均数，精确到小数点后 1 位
	if (A4.size() != 0)
	{
		double avg = 0;
		for (int i = 0; i < A4.size(); i++)
		{
			avg += A4[i];
		}
		avg /= A4.size();
		printf(" %.1f", avg);
	}
	else
		cout << " N";
	//被 5 除后余 4 的数字中最大数字
	if (A5.size() != 0)
	{
		int max = A5[0];
		for (int i = 1; i < A5.size(); i++)
		{
			max = max > A5[i] ? max : A5[i];
		}
		cout << ' ' << max;
	}
	else
		cout << " N";

	return 0;
}
