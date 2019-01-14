//1043 输出PATest
#include<iostream>

using namespace std;

int main()
{
	int store[6] = {0};//存放六个字符的个数
	char temp;
	while (cin.peek() != '\n')
	{
		cin >> temp;
		switch (temp)
		{
		case 'P':
			store[0]++;
			break;
		case 'A':
			store[1]++;
			break;
		case 'T':
			store[2]++;
			break;
		case 'e':
			store[3]++;
			break;
		case 's':
			store[4]++;
			break;
		case 't':
			store[5]++;
			break;
		default:
			break;
		}
	}
	while (store[0] != 0 || store[1] != 0 || store[2] != 0 || store[3] != 0 || store[4] != 0 || store[5] != 0)//所有字符个数不为零时候停止
	{
		//按照顺序输出PATest
		if (store[0] != 0)
		{
			cout << 'P';
			store[0]--;
		}
		if (store[1] != 0)
		{
			cout << 'A';
			store[1]--;
		}
		if (store[2] != 0)
		{
			cout << 'T';
			store[2]--;
		}
		if (store[3] != 0)
		{
			cout << 'e';
			store[3]--;
		}
		if (store[4] != 0)
		{
			cout << 's';
			store[4]--;
		}
		if (store[5] != 0)
		{
			cout << 't';
			store[5]--;
		}
	}
	return 0;
}
