//1042 字符统计
#include<iostream>

using namespace std;

int main()
{
	int number[26] = {0};//定义一个数组存放每一个字母出现的次数
	char temp;
	while (cin.peek() != '\n')//将字母的字符的个数统计出来
	{
		cin >> temp;
		if (temp >= 'a'&&temp <= 'z')
		{
			number[temp - 'a']++;
		}
		else if (temp >= 'A'&&temp <= 'Z')
		{
			number[temp - 'A']++;
		}
	}
	int max = 0, n = 0;
	for (int i = 0; i < 26; i++)
	{
		if (max < number[i])
		{
			max = number[i];
			n = i;
		}
	}
	temp = 'a' + n;
	cout << temp << ' ' << number[n] << endl;
	return 0;
}
