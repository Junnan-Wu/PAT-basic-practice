//1087 有多少不同的值
#include<iostream>
#include<set>

using namespace std;

int cal(int n)
{
	return n / 2 + n / 3 + n / 5;
}

int main()
{
	int N;//记录N的值
	cin >> N;
	set<int> s;//记录存在过的计算值
	for (int i = 1; i <= N; i++)
	{
		s.insert(cal(i));
	}
	cout << s.size();
	return 0;
}
