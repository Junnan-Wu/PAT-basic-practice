//1062 最简分数
#include<iostream>

using namespace std;

int judge(int a, int b)//使用辗转相除法计算最大公约数
{
	int c;
	if (a>b)
	{
		c = a;
		a = b;
		b = c;
	}
	while (a != 0)//不为零则一直除
	{
		c = b%a;
		b = a;
		a = c;//余数给较小数
	}
	return b;//最后一次余数为零的除数即为最大公因子

}

int main()
{
	int n1, m1,n2,m2, K;//记录分子分母与K
	scanf("%d/%d %d/%d", &n1, &m1,&n2,&m2);
	if (n1*m2 > n2*m1)
	{
		int tep = n1; n1 = n2; n2 = tep;
		tep = m1; m1 = m2; m2 = tep;
	}
	cin >> K;//读取K
	int flag = 0;
	for (int i = int(n1*K/m1) + 1; i < double(n2*K/(m2+0.0)); i++)
	{
		if (flag==0&&judge(i,K)==1)
		{
			printf("%d/%d", i, K);
			flag = 1;
			continue;
		}
		if (judge(i, K) == 1)
		{
			printf(" %d/%d", i, K);
		}
	}
	return 0;
}
