//1073 多选题常见计分法
#include<iostream>
#include<vector>
#include<set>

using namespace std;

struct que//定义储存题目答案的结构体
{
	int id;//题目序号
	double score;//题目满分
	set<char> ans;
};

struct student//储存单个学生答题情况的结构体
{
	double score = 0;//储存学生得分
	vector<set<char>> ans;//学生选项
};

int judge(set<char> a, set<char> b)//判断两个选项是否正确，a是正确，b是学生答
{
	if (a.size() < b.size())return 0;//如果学生选的个数超出，肯定错,记为0
	for (set<char>::iterator it = b.begin(); it != b.end(); it++)
	{
		if (a.find(*it) == a.end()) return 0;//如果学生的选项不在正确里面
	}
	if (a.size() == b.size())return 2;//学生所有选项均在正确选项里且个数相同记为2
	else return 1;//尽管都对，但是没有选全，记为1。
}

int main()
{
	int N, M;//学生人数，多选题个数；
	cin >> N >> M;
	vector<que> v(M);//储存题目信息
	double score; int nc, rn; char c;//储存每个题的分数，总选项个数，正确选项个数，字符
	for (int i = 0; i < M; i++)//储存答案信息
	{
		cin >> score >> nc >> rn;
		v[i].id = i + 1;
		v[i].score = score;
		for (int j = 0; j < rn; j++)
		{
			cin >> c;
			v[i].ans.insert(c);
		}
	}
	vector<student> stu(N);//储存学生答题情况
	for (int i = 0; i < N; i++)
	{
		stu[i].ans.resize(M);
		for (int j = 0; j < M; j++)
		{
			int temp; char cp;//读取学生选的个数与选项
			while (getchar() != '(');//读取第一个空格
			cin >> temp;
			for (int k = 0; k < temp; k++)
			{
				cin >> cp;
				stu[i].ans[j].insert(cp);//i学生的j题的第k个选项
			}
			while (getchar() != ')');//读取第二个空格
		}
		while (getchar() != '\n');//读取回车
	}
	//记录M个题的错误选项的次数的二维数组，长5，对应abcde选项，高M对应M个题,初始值设为0
	vector<vector<int>> wr(M,vector<int>(5,0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int flag = judge(v[j].ans, stu[i].ans[j]);//记录判断情况
			double plus;//记录学生该题的得分
			if (flag == 0)plus = 0;
			else if (flag == 1)plus = v[j].score / 2;
			else plus = v[j].score;
			stu[i].score += plus;
			//如果此题学生没完全答对
			if ( flag== 0||flag==1)
			{
				//记录错误答案
				for (set<char>::iterator it = stu[i].ans[j].begin(); it != stu[i].ans[j].end(); it++)//先从学生的答案找出不是正确的
				{
					if (v[j].ans.find(*it) == v[j].ans.end())//如果不是正确答案
					{
						wr[j][(*it) - 'a']++;//第j题的该选项错误次数加1
					}
				}
				for (set<char>::iterator it = v[j].ans.begin(); it != v[j].ans.end(); it++)//在从正确的答案找出学生没答的
				{
					if (stu[i].ans[j].find(*it) == stu[i].ans[j].end())//如果不是正确答案
					{
						wr[j][(*it) - 'a']++;
					}
				}
			}
		}
	}
	//首先输出所有人的分数
	for (int i = 0; i < N; i++)
	{
		printf("%.1f\n", stu[i].score);
	}
	//查找错误最多的选项的个数
	int max = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < 5; j++)
			max = max>wr[i][j] ? max : wr[i][j];
	}
	if (max == 0)printf("Too simple\n");
	else
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (max == wr[i][j])
				{
					printf("%d %d-%c\n", max, i+1, 'a' + j);
				}
			}
		}
	}
	return 0;
}
