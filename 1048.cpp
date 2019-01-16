//1048 数字加密
#include<iostream>
#include<string>
#include<stack>

using namespace std;

char cal(char a, char b, int n)//根据奇数偶数位定义不同的运算规则
{
	char c;
	int number;
	if (n % 2 == 0)//如果n是偶数位
	{
		number = (b - '0') - (a - '0');
		number = number >= 0 ? number : number + 10;
		c = '0' + number;
		return c;
	}
	else//如果n是奇数位
	{
		number = (b - '0') + (a - '0');
		number %= 13;
		switch (number)
		{
		case 10:
			c = 'J';
			break;
		case 11:
			c = 'Q';
			break;
		case 12:
			c = 'K';
			break;
		default:
			c = number + '0';
			break;
		}
		return c;
	}
}

int main()
{
	string A, B;
	stack<char> C;
	cin >> A >> B;
	char temp;
	int count = 1;//用于统计奇数位与偶数位
	int dif = B.length() - A.length();//计算B字符串与A字符串的长度差
	if (dif >= 0)//如果B的字符串比A长
	{
		for (int i = B.length() - 1; i >= dif; i--)
		{
			temp = cal(A[i - dif], B[i], count);
			count++;
			C.push(temp);
		}
		for (int i = dif - 1; i >= 0; i--)
		{
			C.push(B[i]);
		}
	}
	else//如果A的字符比B长
	{
		for (int i = B.length() - 1; i >= 0; i--)
		{
			temp = cal(A[i -dif], B[i], count);
			count++;
			C.push(temp);
		}
		for (int i = -dif - 1; i >= 0; i--)//对于B没有的位数，需要补0对其进行计算
		{
			temp = cal(A[i], '0', count);
			count++;
			C.push(temp);
		}
	}
	while (!C.empty())
	{
		cout << C.top();
		C.pop();
	}
	return 0;
}
