//1021	个位数统计
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string number;
	vector<int> store;
	cin >> number;
	for (int i = 0; i < 10; i++)//对字符串进行查找，查找0-9
	{
		int j = 0;
		int count = 0;
		while (j < number.size())
		{
			if (number[j] == '0' + i)
			{
				count++;//如果查找到i则计数
			}
			j++;
		}
		store.push_back(count);
	}
	for (int i = 0; i < 10; i++)//如果计数不为0则输出
	{
		if (store[i] != 0)
		{
			cout << i << ':' << store[i] << endl;
		}
	}
	return 0;
}
