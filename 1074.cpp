//1074 宇宙无敌加法器
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string rule, p1, p2;
	cin >> rule >> p1 >> p2;
	//将相加的字符串补充至与计算规则相同的位数
	int l = rule.length();
	string res(l, '0');
	string p1s(l - p1.length(), '0');
	string p2s(l - p2.length(), '0');
	p1 = p1s + p1;
	p2 = p2s + p2;
	//临时记录结果与进位
	int tep, plus = 0;
	for (int i = l - 1; i >= 0; i--)
	{
		int mod = rule[i]== '0' ? 10 : rule[i] - '0';//记录进制规则
    //计算结果与进位
		tep = ((p1[i] - '0') + (p2[i] - '0') + plus) % mod;
		plus = ((p1[i] - '0') + (p2[i] - '0') + plus) / mod;
		res[i] = tep + '0';
	}
	if (plus != 0)//如果所有位算完还有进位，在前面加上进位
	{
		char c = '0' + plus;
		res = c + res;
	}
	int flag = 0;
	for (int i = 0; i < res.length(); i++)
	{
		if (res[i] != '0'||flag)
		{
			flag = 1;
			cout << res[i];
		}
	}
	if (!flag)cout << 0;
	return 0;
}
