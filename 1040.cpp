//1040 有几个PAT
//本题难度较大，但是不是编程的难度而是算法的难度，一开始想的是用三重循环，一个一个统计pat的个数，但是这样后面的几个测试用例都会超时
//最后实在是想不出来什么好的方法，借鉴别人的，豁然开朗，只要对每一个A的前后进行P与T的计数，用A前P的数量*A后T的数量，即可得到由此A可以构建的所有PAT的数量
//因此最后只用对整个数组进行两次循环即可
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string pat;
	cin >> pat;
	long long count = 0, count_p = 0, count_t = 0;//注意要使用long long类型，不然乘法的时候有可能越界

	for (int i = 0; i < pat.size(); i++)//首先计算总共有多少个T
	{
		if (pat[i] == 'T')count_t++;
	}
	for (int i = 0; i < pat.size(); i++)//对每一个A进行遍历，计算前面多少个P，后面多少个T
	{
		if (pat[i] == 'P')count_p++;//前面有P就增加
		if (pat[i] == 'T')count_t--;//前面有T证明后面的T的个数要减少
		if (pat[i] == 'A')count += count_p*count_t;//A可以构建的所有PAT的计数
	}
	cout << count % 1000000007;//总的个数需要对1000000007取余数
	return 0;
}
