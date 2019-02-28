//1093 字符串A+B
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	//记录两个字符串
	string a, b,s;
	getline(cin, a);
	getline(cin, b);
	s = a + b;
	vector<char> v;
	for (int i = 0; i <s.length(); i++)
	{
		//如果v中没有s[i]，往里面加入
		if (find(v.begin(), v.end(), s[i]) == v.end())
			v.push_back(s[i]);
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cout << endl;
	return 0;
}
