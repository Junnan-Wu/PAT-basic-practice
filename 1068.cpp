//1068 万绿丛中一点红
#include<iostream>
#include<map>
#include<vector>
#include<cmath>

using namespace std;

struct node
{
	int color;//储存颜色
	int x, y;//储存坐标
};

int M, N;//记录像素
int TOL;//记录阈值
vector<vector<int>> v;//记录像素信息

bool judge(int a, int b)
{
	int p[8][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 },
	{ -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } };
	//从一个坐标变到另一个，分别为上，下，左，右，左上，右上，左下，右下
	for (int i = 0; i < 8; i++)
	{
		//记录相邻点的横纵坐标
		int ac = a + p[i][0];
		int bc = b + p[i][1];
		if (ac >= 0 && ac < N && bc >= 0 && bc < M)//相邻坐标存在
		{
			if (abs(v[a][b] - v[ac][bc])>TOL)continue;
			else return false;
		}
	}
	return true;
}

int main()
{
	cin >> M >> N >> TOL;
	//存储像素点颜色信息；
	v.resize(N);
	map<int, int> store;//储存每一个点出现次数，first是颜色，second是次数
	int temp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> temp;
			v[i].push_back(temp);//储存像素点信息
			store[v[i][j]]++;//记录每一个颜色的出现的次数
		}
	}
	vector<node> result;//储存只出现一次且满足色差足够大的点
	node tep;
	//查找只出现一次且满足色差要求的点
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (store[v[i][j]] == 1 && judge(i, j))//只出现过一次的颜色，且判断色差足够大
			{
				tep.color = v[i][j];
				tep.x = j + 1;//注意x是列的位置，y是行的位置
				tep.y = i + 1;
				result.push_back(tep);
			}
		}
	}
	if (result.size() == 0)//并没有只出现一次且色差足够大的点
	{
		cout << "Not Exist" << endl;
	}
	else if (result.size() == 1)//只有一个出现过一次且色差足够大的点
	{
		printf("(%d, %d): %d\n", tep.x, tep.y, tep.color);
	}
	else//有很多出现过一次且色差足够大的点
	{
		cout << "Not Unique" << endl;
	}
	return 0;
}
