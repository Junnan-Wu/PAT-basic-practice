//1015	德才论
//此题对运行时间有要求，需要采用高效的代码
//通过调用<algorithm>库中的sort函数加快运行速度
//通过使用scanf与printf函数进行读写，加快运行速度（速度相差10倍）
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct data//存储学生信息
{
	int id;
	int virtue;
	int gift;
	int total;
};

bool judge(data a, data b)//sort排序比较的第三个参数，true为排序前，false为后
{
	if (a.total > b.total) return true;
	else if (a.total == b.total&&a.virtue > b.virtue) return true;
	else if (a.total == b.total&&a.virtue == b.virtue&&a.id<b.id) return true;
	else return false;
}

void print(vector<data> a)//输出结果
{
	if (a.size() == 0)return;
	for (int i = 0; i < a.size(); i++)
	{
		printf("%d %d %d\n", a[i].id, a[i].virtue, a[i].gift);
	}
}

int main()
{
	int N, L, H;
	cin >> N >> L >> H;
	data temp;
	vector<data> first,second,third,fourth;
	for (int i = 0; i < N; i++)
	{
		//此题由于数据量很大，使用cin读取数据会运行时间超出规定范围，因此使用scanf函数来读取数据，速度是cin的10以上倍
		scanf("%d %d %d", &temp.id, &temp.virtue, &temp.gift);
		temp.total = temp.virtue + temp.gift;
		if (temp.virtue >= H && temp.gift >= H)//第一类人
			first.push_back(temp);
		else if (temp.virtue >= H && temp.gift >= L && temp.gift < H)//第二类人
			second.push_back(temp);
		else if (temp.virtue < H && temp.virtue >= L && temp.gift < H && temp.gift >= L && temp.virtue >= temp.gift)//第三类人
			third.push_back(temp);
		else if (temp.virtue >= L && temp.gift >= L)//最后一类人
			fourth.push_back(temp);
	}
	//使用sort算法的时候第三个参数是一个bool函数，规定排序方式
	sort(first.begin(), first.end(), judge);
	sort(second.begin(), second.end(), judge);
	sort(third.begin(), third.end(), judge);
	sort(fourth.begin(), fourth.end(), judge);
	//输出结果
	printf("%d\n", first.size() + second.size() + third.size() + fourth.size());
	print(first);
	print(second);
	print(third);
	print(fourth);
	return 0;
}
