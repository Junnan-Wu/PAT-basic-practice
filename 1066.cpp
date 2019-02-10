//1066 图像过滤
#include<iostream>

using namespace std;

int main()
{
	int M, N, A, B, G;//存储M行，点个数N，替换区间AB，替换值G
	cin >> M >> N >> A >> B >> G;
	int temp;//临时储存像素
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &temp);//此处使用scanf加快数据的读取，不然最后一个测试用例会超时
			if (temp >= A&&temp <= B)//在区间的替换
			{
				temp = G;
			}
			if (j == 0)//保证最后没有多余空格
			{
				printf("%03d", temp);
			}
			else
			{
				printf(" %03d", temp);
			}
		}
		printf("\n");
	}
	return 0;
}
