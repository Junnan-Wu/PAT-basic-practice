//1005	继续(3n+1)猜想
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void calculate(vector<int> &a, int n)//计算数字n的序列并将其存在vector中
{
	while (n != 1)
	{
		a.push_back(n);
		if (n % 2 == 0)n /= 2;
		else
		{
			n = (3 * n + 1) / 2;
		}
	}
}

int main()
{
	int K;//存放K个整数
	cin >> K;
	int *store = new int[K];//存放需要判断的数；
	for (int i = 0; i < K; i++)
	{
		cin >> store[i];
	}
	vector<int> *cal = new vector<int>[K];//计算每一个的数列
	for (int i = 0; i < K; i++)
	{
		calculate(cal[i], store[i]);
	}
	delete[]store;//释放store
	vector<int>::iterator it;
	for (int i = 0; i < K; i++)//对每一个数列与其他数列比较，如果其第一个元素存在其他数列中，清空该数列，并追加首位为0
	{
		for (int j = 0; j < K; j++)
		{
			it = find(cal[j].begin() + 1, cal[j].end(), cal[i][0]);//从i+1行的第二个元素开始找
			if (it != cal[j].end())//如果在j中找到，清除自己
			{
				cal[i].clear();
				cal[i].push_back(0);
				cal[i].push_back(0);
				break;
			}
		}
	}
	vector<int>result;
	for (int i = 0; i < K; i++)
	{
		if (cal[i][0] != 0)
		{
			result.push_back(cal[i][0]);
		}
	}
	sort(result.begin(), result.end());//将结果排序,sort默认从小到大
	reverse(result.begin(), result.end());//排序结果反序

	cout << *result.begin();
	for (it = result.begin()+1; it != result.end(); it++)
	{
		cout <<' ' << *it ;
	}
	return 0;
}
