//1016	部分A+B
#include<iostream>

using namespace std;

int cal_p(char *a, int b)//将字符串a与da进行对比计算pa
{
	int i = 0, count = 0;
	while (a[i] != '\0')//循环读取字符串中的数字
	{
		count = (a[i] - '0') == b ? count+1:count;//数字相同则增加count
		i++;
	}
	int cal = 0;//计算pa
	for (int i = 0; i < count; i++)
	{
		cal += b;
		b *= 10;
	}
	return cal;
}

int main()
{
	char a[11], b[11];
	int da, db;
	scanf("%s %d %s %d", a, &da, b, &db);
	cout << cal_p(a, da)+cal_p(b,db);
	return 0;
}
