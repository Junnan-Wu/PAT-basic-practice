//1070 结绳
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int N;//绳子个数
	cin >> N;
	double *l = new double[N];
	for (int i = 0; i < N; i++)
		cin >> l[i];
	sort(l, l + N);
	double length = l[0];//计算最后的绳子长,初始长度为最短的
	for (int i = 1; i < N; i++)
	{
		length += l[i];
		length /= 2;
	}
	cout << int(length) << endl;
	return 0;
}
