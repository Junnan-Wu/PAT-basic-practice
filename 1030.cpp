//1030 完美数列
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	double p;
	double n[100001];
	cin >> N >> p;
	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &n[i]);
	}
	sort(n, n + N);
  int max = 1;//首先定max=1
  for (int i = 0; i < N; i++)//i从0开始循环
  {
    for (int j = i+max; j < N; j ++)//j从i+max开始判断可以减少很多不必要的判断，大大加快程序的运算速度
    {
      if (n[j] > p*n[i])//找到第一个比p*n[i]大的数的序号j
      {
        max = (j - i)>max ? (j - i) : max;//根据j与i的位置，计算这个数列的个数为j-i（因为j的前一个数字才满足完美数列要求，n[j]并不满足）
        break;
      }
      else if(n[j]==p*n[i]||j==N-1)//如果找到的是第一个等于p*n[i]，计算数列个数的时候要+1
      //当找到最后一个数字都没有满足>=的情况的时候，证明i后面所有的数字都可以组成完美序列，也要停止
      {
        max = (j - i + 1) > max ? (j - i + 1) : max;
        break;
      }
    }
  }
	cout << max;
}
