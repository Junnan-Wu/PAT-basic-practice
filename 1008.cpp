//1008 数组元素循环右移问题
#include<iostream>
#include<deque>

using namespace std;

int main()
{
	int N, M;//N存储数组个数，M是往右移动位置
	cin >> N >> M;
	deque<int> a;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		a.push_back(temp);
	}
	M = M%N;
	for (int i = 0; i < M; i++)
	{
		temp = a.back();
		a.pop_back();
		a.push_front(temp);
	}
	cout << *a.begin();
	for (int i =1; i < N; i++)
	{
		cout << ' ' << a[i];
	}
	return 0;
}
