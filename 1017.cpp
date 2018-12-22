//1017	A除以B
#include<iostream>

using namespace std;

int div(char *a, int b)//a是被除数，b是除数,div是余数
//使用指针变量可以返回除数的字符数组，同时还返回了余数
{
	int i = 0;
	int div = 0;
	int temp;
	while (a[i] != '\0')
	{
		temp = (a[i] - '0' + div*10) % b;//记录余数，如果前面有余数，需要加上借位
		a[i] = '0' + (a[i] - '0'+div*10) / b;//记录除数
		div = temp;
		i++;
	}
	return div;
}

int main()
{
	char A[1001];
	int B;
	int R;
	cin >> A >> B;
	R = div(A, B);
	if (A[0] != '0'||A[1]=='\0')cout << A[0];//注意除数为零或者首位为0的情况
	//如果除数为0 输出0；如果除数不为零，但是首位为0，首位0不输出
	int i = 1;
	while (A[i] != '\0')//从第二位开始输出
	{
		cout << A[i];
		i++;
	}
	cout << ' ' << R << endl;
	return 0;
}
