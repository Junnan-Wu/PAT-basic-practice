//1050 螺旋矩阵
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int cal_m(int N)//计算矩阵的行数
{
	int m;
	m = int(sqrt(N));
	if (m - sqrt(N)==0)return m;
	else m++;
	while (N % m != 0)
	{
		m++;
	}
	return m;
}

int main()
{
	int N;
	cin >> N;
	int m = cal_m(N);
	int n = N / m;
	vector<int> store(N);
	for (int i = 0; i<N; i++)//存储数据
	{
		cin >> store[i];
	}
	sort(store.begin(),store.end());
  //定义m*n的二维数组
  int **matrix=new int *[m];
	for (int i = 0; i < m; i++)
	{
		matrix[i] = new int[n];
	}

  //定义四个边界以及i，j对矩阵进行填充，k来定位储存数据的位置
	int up = -1, down = m, left = -1, right = n;//定义四个边界
	int i = 0, j = 0, k = N-1;
	while (1)
	{
		//----------------------向右填充----------------------------------------------
		for (; j < right; j++)
		{
			matrix[i][j] = store[k];
			k--;
		}
		up++;//向右填充完，上边界增加1
		if (down == i + 1)break;//接下来向下填充，如果下边界只比i大1，证明填充完毕
		else { i++; j--;}//否则将坐标移动到下一个要填充的位置
		//---------------------向下填充-----------------------------------------------
		for (; i < down; i++)
		{
			matrix[i][j] = store[k];
			k--;
		}
		right--;//向下填充完，右边界减少1
		if (left == j-1)break;//接下来向左填充，如果左边界只比j小1，证明填充完毕
		else { j--; i--; }//否则将坐标移动到下一个要填充的位置
		//---------------------向左填充-----------------------------------------------
		for (; j > left; j--)
		{
			matrix[i][j] = store[k];
			k--;
		}
		down--;//向左填充完，下边界减少1
		if (up == i - 1)break;//接下来向上填充，如果上边界只比i小1，证明填充完毕
		else {i--; j++;}//否则将坐标移动到下一个要填充的位置
		//---------------------向上填充-----------------------------------------------
		for (; i > up; i--)//向上填充
		{
			matrix[i][j] = store[k];
			k--;
		}
		left++;//向上填充完，左边界增加1
		if (right == j + 1)break;//接下来向右填充，如果右边界只比j大1，证明填充完毕
		else { j++; i++; }//否则将坐标移动到下一个要填充的位置
	}
  //输出结果
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n-1; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << matrix[i][j] << endl;
	}
	return 0;
}
