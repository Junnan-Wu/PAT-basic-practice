//1051 复数乘法
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double R1, P1, R2, P2, R, P;//存储复数
	cin >> R1 >> P1 >> R2 >> P2;
	//计算复数的乘积
	R = R1*R2;
	P = P1 + P2;
	double real, img;
	real = R*cos(P);
	img = R*sin(P);
	//本题最坑的点在于-0.005到0的小数如果四舍五入按理说应该为0.00但是按照printf的方法输出的是-0.00，因此需要特殊考虑
	if (real<0 && real > -0.005)printf("0.00");
	else printf("%.2f", real);
	if (img >=0)printf("+%.2fi\n",img);
	else if (img > -0.005)printf("+0.00i");
	else printf("-%.2fi\n",-img);
	return 0;
}
