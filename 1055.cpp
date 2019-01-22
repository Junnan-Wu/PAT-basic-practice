//1055 集体照
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

struct person//定义person的变量，包括名字与身高
{
	string name;
	int height;
};

bool compare(person a, person b)//规定排序方法
{
	//一开始是只想着比较名字的第一个字母，发现后两个测试点不过，后来想起来string可以直接进行大小的比较，是按照字符序的
	return a.height != b.height ? a.height < b.height : a.name > b.name;
}

int main()
{
	int N,K;//总人数
	cin >> N >> K;
	vector<person> store(N);//存储原始数据
	for (int i = 0; i < N; i++)
	{
		cin >> store[i].name >> store[i].height;
	}
	sort(store.begin(), store.end(), compare);
	deque<string> *que = new deque<string>[K];//定义二维数组
	int k,flag=1;//k定位，flag控制左右
	for (int i = 0; i < K - 1; i++)//对前K-1行的处理
	{
		k = (i + 1)*(N / K) - 1;//定位到每一行最高的人的位置
		que[i].push_back(store[k--].name);//先将最高的人放在数组中
		for (int j = 0; j < N / K - 1; j++)
		{
			if (flag==1)
			{
				que[i].push_front(store[k--].name);//从前面插入
				flag *= -1;//改变下一次方向
			}
			else
			{
				que[i].push_back(store[k--].name);//从后面插入
				flag *= -1;
			}
		}
		flag = 1;//注意！这里一定要将flag改为1，不然之后会出错，第三个测试点就是这里一开始一直没法通过
	}
	//最后一行的插入元素个数是N-(K-1)*(N/K)个
	k = store.size() - 1;
	que[K - 1].push_back(store[k--].name);
	for (int j = 0; j < N-(K-1)*(N/K)-1; j++)
	{
		if (flag==1)
		{
			que[K-1].push_front(store[k--].name);//从前面插入
			flag *= -1;//改变下一次方向
		}
		else
		{
			que[K-1].push_back(store[k--].name);//从后面插入
			flag *= -1;
		}
	}
	//最后输出站队结果
	for (int i = K-1; i >=0; i--)
	{
		for (int j = 0; j < que[i].size() - 1; j++)
		{
			cout << que[i][j] << ' ';
		}
		cout << que[i][que[i].size() - 1] << endl;
	}
	return 0;
}
