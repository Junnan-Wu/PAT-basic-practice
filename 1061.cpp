//1061 判断题
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N, M;//存储学生人数与题目数目；
	cin >> N >> M;
	vector<int> score(M), ans(M),stu(N);//存储满分与答案,学生得分
	for (int i = 0; i < M; i++) cin >> score[i];
	for (int i = 0; i < M; i++)cin >> ans[i];
	for (int i = 0; i < N; i++)
	{
		int temp, sum = 0;
		for (int j = 0; j < M; j++)
		{
			cin >> temp;
			if (temp == ans[j])sum += score[j];//与答案进行对比，如果相同分数增加
		}
		cout << sum << endl;
	}
	return 0;
}
