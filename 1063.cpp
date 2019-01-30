//1063 计算谱半径
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int N;//存储个数
	double real, imag, rad=0;//存储实部虚部与谱半径
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> real >> imag;
		rad = rad > sqrt(real*real + imag*imag) ? rad : sqrt(real*real + imag*imag);
	}
	printf("%.2f\n", rad);
	return 0;
}
