//1077 互评成绩计算
#include<iostream>
#include<vector>

using namespace std;

int M;//满分

bool judge(int n)//判断分数是否合法
{
	if (n >= 0 && n <= M)return true;
	else return false;
}

int main()
{
	int N;//分组数与满分
	cin >> N >> M;
	vector<int> score(N);
	for (int i = 0; i < N; i++)
	{
		cin >> score[0];
		double G1 = score[0],G2=0,G=0;//老师的分数,学生的分数，最终的分数
		int number = 0;
		double sum = 0,max=0,min=50;//记录改组的最高分与最低分与总分
		//统计学生评分
		for (int j = 1; j < N; j++)
		{
			cin >> score[j];
			if (judge(score[j]))//首先评分合法
			{
				//记录最高最低分
				max = max > score[j] ? max : score[j];
				min = min < score[j] ? min : score[j];
				number++;
				sum += score[j];
			}
		}
		G2 = (sum - max - min) / (number - 2);
		G = (G1 + G2) / 2;
		cout << int(G + 0.5) << endl;//此处四舍五入
	}
	return 0;
}
