//1065 单身狗
#include<iostream>

#define MAX 100000

using namespace std;

struct person
{
	int id;
	bool join = false;//暂定每一个人没有参加派对
	int couple = -1;//一个人的伴侣id暂定为-1
	bool judge = false;//判断是否输出
};

int main()
{
	int N;//已知伴侣对数
	cin >> N;
	person *people=new person[MAX];//存储100000个人的伴侣信息；
	//这里使用指针数组可以将数组容量增大到十万
	int p1, p2;//暂时存储两人信息
	for (int i = 0; i < MAX; i++)
	{
		people[i].id = i;//为每一个人编号
	}
	for (int i = 0; i < N; i++)
	{
		cin >> p1 >> p2;
		people[p1].couple = p2;//将一人的对象指向另一人
		people[p2].couple = p1;
	}
	int M;//参加派对的人数,ji
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> p1;//记录参加派对人的id
		people[p1].join = true;
		people[p1].judge = true;
	}
	int count = 0;//记录非单身狗的个数
	for (int i = 0; i < MAX; i++)
	{
		if (people[i].join&&people[i].couple != -1 && people[people[i].couple].join)//如果该人参加派对且有对象，同时其对象参加派对
		{
			count++;
			people[i].judge = false;
		}
	}
	cout << M-count << endl;//其余人为单身狗人数
	int flag = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (flag==0&&people[i].judge)//如果是第一个，且参加派对，且没有对象
		{
			printf("%05d",i) ;
			flag = 1;
		}
		else if (flag&&people[i].judge)
		{
			printf(" %05d", i);
		}
	}
	return 0;
}
