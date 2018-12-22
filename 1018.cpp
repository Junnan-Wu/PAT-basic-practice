//1018	锤子剪刀布
#include<iostream>

using namespace std;

int judge(char a, char b)
{
	if (a == b)return 0;
	if ((a == 'C'&&b == 'J') || (a == 'J'&&b == 'B') || a == 'B'&&b == 'C') return 1;
	//a获胜的三种情况;
	else return -1;
}

void print(int ac, int aj, int ab)//根据三种的胜率情况输出结果
//注意相同胜率的按照字母顺序小的输出
{
	if (ab >= ac&&ab >= aj)
	{
		cout << 'B';
		return;
	}
	if (ac > ab&&ac >= aj)
	{
		cout << 'C';
		return;
	}
	if (aj > ab&&aj > ac)
	{
		cout << 'J';
		return;
	}
}

int main()
{
	int N;
	char a, b;
	int ac = 0, aj = 0, ab = 0;//记录甲胜的情况，分使用不同的策略
	int bc = 0, bj = 0, bb = 0;//记录乙胜的情况
	int equal = 0;//记录平的情况
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		switch(judge(a, b))
		{
		case 1:
			if (a == 'C')ac++;
			if (a == 'J')aj++;
			if (a == 'B')ab++;
			break;
		case -1:
			if (b == 'C')bc++;
			if (b == 'J')bj++;
			if (b == 'B')bb++;
			break;
		default:
			equal++;
			break;
		}
	}
	cout << ac + aj + ab << ' ' << equal << ' ' << bc + bj + bb << endl;
	cout << bc + bj + bb << ' ' << equal << ' ' << ac + aj + ab << endl;
	print(ac, aj, ab); cout << ' '; print(bc, bj, bb);
	return 0;
}
