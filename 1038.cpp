//1038 统计同成绩学生
//本题简单的可怕...但是一开始没有想到这样的算法导致最后一个运行总是超时，后来换了下面的思路立马就通过了，而且代码也简单了很多
#include<iostream>

using namespace std;

int main()
{
	int N;
	int score[101] = { 0 };//定义一个存放0-100分的的数组，下标0-100代表着得该分的人的个数
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);//根据分数对下标为该分数的人的个数加1
		score[temp]++;
	}
	int K;
	cin >> K;
	for (int i = 0; i < K-1; i++)
	{
		scanf("%d", &temp);//读取下标数据，输出该分数有多少人
		cout << score[temp] << ' ';
	}
	scanf("%d", &temp);
	cout << score[temp] << endl;
	return 0;
}

//附上一开始的思路：
/*#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int find_key(vector<int> a,int key)//定义查找函数对已经排好序的数组进行查找
{
	vector<int>::iterator it;
	it=find(a.begin(),a.end(),key);//找到第一个满足要求的成绩
	if (it == a.end())return 0;//如果没有找到，证明该分数的人为0
	else
	{
		int count = 0;
		for (vector<int> ::iterator p = it; *p == key; p++)//从找到的第一个人开始往后，直到分数不同为止，进行计数
		{
			count++;
		}
		return count;
	}
}

int main()
{
	int N;
	cin >> N;
	vector<int> score;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		score.push_back(temp);
	}
	sort(score.begin(), score.end());
	int K;
	cin >> K;
	vector<int> key;
	for (int i = 0; i < K; i++)
	{
		cin >> temp;
		key.push_back(temp);
	}
	int i;
	for ( i= 0; i < K - 1; i++)
	{
		cout << find_key(score, key[i]) << ' ';
	}
	cout << find_key(score, key[i]) << endl;
}*/
