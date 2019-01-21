//1052 卖个萌
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string s;
	vector<string> hand, eye, mouth;
  //分三段读取手，眼，嘴的表情字符
	getline(cin,s);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '[')//找到第一个'['符号
		{
			int j;
			for (j = i + 1; s[j] != ']'; j++);//找到第二个']'符号
			hand.push_back(s.substr(i + 1, j - i - 1));//将中间的字符存在字符串数组中
			i = j;
		}
	}
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '[')
		{
			int j;
			for (j = i + 1; s[j] != ']'; j++);
			eye.push_back(s.substr(i + 1, j - i - 1));
			i = j;
		}
	}
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '[')
		{
			int j;
			for (j = i + 1; s[j] != ']'; j++);
			mouth.push_back(s.substr(i + 1, j - i - 1));
			i = j;
		}
	}
  //读取需要输出的表情符号
	int K;
	cin >> K;
	int lh, le, m, re, rh;
	for (int i = 0; i < K; i++)
	{
		cin >> lh >> le >> m >> re >> rh;
    //注意如果数字的范围不在其中，输出"Are you kidding me? @\\/@"，其中\需要打两个才能表示，这是转义符
    //另外一开始只定了上界，没有规定不能<=0，所以导致第二个测试用例一直不能通过，猜测第二个测试用例中有数字0
		if (lh > hand.size() || lh <= 0 || le>eye.size() || le <= 0 || m > mouth.size() || m <= 0 || re > eye.size() || re <= 0 || rh > hand.size() || rh <= 0)
		{
			cout << "Are you kidding me? @\\/@" << endl;
		}
		else
		{
			cout << hand[lh-1] << '('<<eye[le-1] << mouth[m-1] << eye[re-1] <<')'<< hand[rh-1] << endl;
		}
	}
	return 0;
}
