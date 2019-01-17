//1049 数列的片段和
#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	double sum = 0,temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		sum += temp*(i + 1)*(N - i);
	}
	printf("%.2f\n", sum);
	return 0;
}
