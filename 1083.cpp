//1083 是否存在相等的差
#include<iostream>
#include<map>
#include<cmath>

using namespace std;

int main()
{
	int N;//N张牌
	cin >> N;
	int n;//记录每一张牌背后的数字
	map<int, int> m;//记录差值出现的次数，前者为差值，后者为次数
	//存储不同差值的数出现的次数
	for (int i = 1; i <= N; i++)
	{
		cin >> n;
		m[abs(n - i)]++;//该差值的个数加1
	}
	//从大到小输出有多少不同值
	map<int, int>::iterator it=m.end();
	it--;
	for (int i = 0; i < m.size(); i++)
	{
		if (it->second == 1){ it--; continue; }//如果该差值只出现了一次，不输出
		cout << it->first << ' ' << it->second << endl;
		it--;
	}
	return 0;
}
