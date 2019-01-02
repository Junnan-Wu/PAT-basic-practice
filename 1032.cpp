//1032 挖掘机技术哪家强
#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int grade[100001] = { 0 };
	int school, temp, maxschool=0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &school, &temp);
		grade[school] += temp;
		maxschool = school > maxschool ? school : maxschool;
	}
	int max = 0;
	int maxcount = 0;
	for (int i = 0; i <= maxschool; i++)
	{
		if (max <= grade[i])
		{
			max = grade[i];
			maxcount = i;
		}
	}
	cout << maxcount << ' ' << max << endl;
	return 0;
}
