//1023	组个最小数
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> s;
	int temp;
	for (int i = 0; i < 10; i++)
	{
		cin >> temp;
		s.push_back(temp);
	}
	for (int i = 1; i < 10; i++)
	{
		if (s[i] > 0)
		{
			cout << i;
			s[i]--;
			break;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < s[i]; j++)
		{
			cout << i;
		}
	}
	return 0;
}
