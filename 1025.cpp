//1025	反转链表
//本题有两个难点，一是对于大量的节点数据，查找超时的问题，二是不一定所有的节点都是有效的节点，无效的节点应该删除
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct node//首先需要定义节点结构体
{
	int address;
	int data;
	int next;
};

void exchange(node &a, node &b)//定义交换两个节点的函数
{
	node temp;
	temp = a;
	a = b;
	b = temp;
	return;
}

class judge//对find_if算法的第三个函数参数的定义
{
private:
	int address;//judge函数是对节点node a进行判断，判断其地址是不是int address
public:
	judge(int add) :address(add){}//必须对该类进行构造函数的定义，由于在find_if中，第三个参数需要传入一个变量add，需要判断该变量与node中的地址是否相同
	bool operator()(node a)//由于find_if第三个参数无法传入自己的node值，因此需要对操作符（）进行重新定义，使其可以使用操作符来间接调用自己的值
	{
		return a.address == address;//判断judge（add）,如果a与node a的address相同返回true
	}
};

int main()
{
	int first, N, K;
	cin >> first >> N >> K;
	//存入第一行的首地址，节点个数，已经每隔K反转的值

	vector<node> L;//定义node数组L
	node temp;//临时存放node的值
	int  data, address, next;//存放每一行的地址，数据，下一个地址
	//将所有数据读取，然后每一行一次存入L中
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &address, &data, &next);
		temp.address = address;
		temp.data = data;
		temp.next = next;
		L.push_back(temp);
	}
	//至此，将所有数组存储完毕

	vector<node>::iterator it;//定义数组指针
	it = find_if(L.begin(), L.end(), judge(first));//找到地址为first的节点使用find_if()函数，注意第三个变量是一个函数，函数的定义在上面，这个函数可以传入参数first
	exchange(*it, L[0]);//将地址为首地址的节点与L数组的第一个交换

  //从第二个元素开始查找，找到最后一个元素,将所有的节点按照节点的顺序进行排序
	for (int i = 1; i < N; i++)
	{
		it = find_if(L.begin() + i, L.end(), judge(L[i - 1].next));//从i的元素开始查找，查找地址为L[i-1]的下一个地址
		if (it != L.end())//如果找到将其与L[i]的后一个节点进行交换
			exchange(*it, L[i]);
		else//如果没有找到，证明i-1节点后面断了，后面的元素需要都删除
		{
			L.erase(L.begin() + i, L.end());
			break;
		}
	}

	//将有效的节点进行题目要求转序
	int count = L.size() / K;//计算需要转序的次数，例如有6个节点，K=4,只需要转序一次，K=2则需要转序3次
	it = L.begin();
	for (int i = 0; i < count; i++)//转序count次,每一次将it与it+K之间的进行转序
	{
		reverse(it, it + K);
		it += K;
	}

	//转序完后将每一个节点的next地址改为下一个节点的地址，并将最后一个节点的next地址设为-1
	for (int i = 0; i < L.size() - 1; i++)
	{
		L[i].next = L[i + 1].address;
	}
	L[L.size() - 1].next = -1;

	//按照要求输出结果
	for (int i = 0; i < L.size() - 1; i++)
	{
		printf("%05d %d %05d\n", L[i].address, L[i].data, L[i].next);
	}
	printf("%05d %d %d\n", (L.end() - 1)->address, (L.end() - 1)->data, (L.end() - 1)->next);

	return 0;
}
