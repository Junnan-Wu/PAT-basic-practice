//1076 Wifi密码
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int N;//题目个数
	cin >> N; getchar();
	vector<string> s(N);
	for (int i = 0; i < N; i++)
	{
		getline(cin, s[i]);
	}
	vector<int> pass;//记录wifi密码
  //查询密码
	for (int i = 0; i < N; i++)
	{
		int p = 2;//查询题目答案
		for (int j = 0; j < 4; j++)
		{
			if (s[i][p] == 'T')
			{
				pass.push_back(s[i][p-2]-'A'+1);
				break;
			}
			else
			{
				p += 4;
			}
		}
	}
  //输出wifi密码
	for (int i = 0; i < pass.size(); i++)
		cout << pass[i];
	cout << endl;
	return 0;
}
