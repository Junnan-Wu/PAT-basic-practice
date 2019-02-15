//1071 小赌怡情
#include<iostream>

using namespace std;

int main()
{
	int T, K;//T是初始筹码，K是游戏次数
	cin >> T >> K;
	int n1, b, t, n2;//系统数字，猜大小，赌注，开的数字
	for (int i = 0; i < K; i++)
	{
		cin >> n1 >> b >> t >> n2;
		if (t > T)//赌注大于筹码
		{
			printf("Not enough tokens.  Total = %d.\n", T);
			continue;
		}
		if (n1 < n2 == b)//如果猜对
		{
			T += t;//增加筹码
			printf("Win %d!  Total = %d.\n", t, T);
		}
		else//否则
		{
			T -= t;//减少筹码
			printf("Lose %d.  Total = %d.\n", t, T);
		}
		if (T == 0)
		{
			printf("Game Over.\n");
			return 0;
		}
	}
	return 0;
}
