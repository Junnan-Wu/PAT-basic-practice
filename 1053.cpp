//1053 住房空置率
#include<iostream>

using namespace std;

int main()
{
	int N;//住房总数
	double e;//低电量阈值
	int D;//观察阈值
	cin >> N >> e >> D;
	int possible = 0, empty = 0;
	for (int i = 0; i < N; i++)
	{
		int J,count=0;//观察天数
		cin >> J;
		double ele;//用电量
		for (int j = 0; j < J; j++)
		{
			cin >> ele;
			if (ele < e)count++;
		}
		if (count > J / 2 && J > D)
			empty++;
		else if (count > J / 2)
			possible++;
	}
	double ratio_p,ratio_e;
	ratio_p = possible / (N + 0.0)*100;
	ratio_e = empty / (N + 0.0) * 100;
	printf("%.1f%% %.1f%%\n", ratio_p, ratio_e);
	return 0;
}
