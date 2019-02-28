//1075 链表元素分类
#include<iostream>
#include<vector>

using namespace std;

struct node
{
	int address;//存储节点的位置
	int data;//节点存储的数据
	int next;//节点的下一个节点
};

int main()
{
	int first, N, K;//第一个节点的地址，节点个数，区间K
	cin >> first >> N >> K;
	int a, d, n;//临时存储位置，数据，下一节点位置
	vector<node> v(100000);
	for (int i = 0; i < N; i++)
	{
		cin >> a >> d >> n;
		v[a].address = a;
		v[a].data = d;
		v[a].next = n;
	}
	vector<node> p1,p2,p3;//按照链表的顺序，存储小于零的，[0,K]的，大于K的
	for (int i = 0; i < N; i++)
	{
		if (v[first].data < 0)
			p1.push_back(v[first]);
		else if (v[first].data>K)
			p3.push_back(v[first]);
		else
			p2.push_back(v[first]);
		first = v[first].next;
		if (first == -1)break;//注意这里，如果节点下一个位置是-1，证明链表结束，倒数第二个测试点就是这个坑
	}
  //将三类节点合并
	vector<node> p=p1;
  //insert函数的第一个参数时插入位置，第二个参数是被插入的数组的起始位置，第三个参数是被插入的数组的终止位置
	p.insert(p.end(),p2.begin(), p2.end());
	p.insert(p.end(), p3.begin(), p3.end());
  //输出结果
	for (int i = 0; i < p.size()-1; i++)
	{
		printf("%05d %d %05d\n", p[i].address, p[i].data, p[i + 1].address);
	}
	printf("%05d %d -1\n", p[p.size()-1].address,p[p.size()-1].data);
	return 0;
}
