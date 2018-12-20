//1010	一元多项式求导
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> coefficient;//存放系数
	vector<int> index;//存放指数
	int temp;
	while (cin.peek() != '\n')//读取系数与指数
	{
		cin >> temp;
		coefficient.push_back(temp);
		cin >> temp;
		index.push_back(temp);
	}
	for (int i = 0; i < coefficient.size(); i++)
	{
		if (index[i] != 0)//指数大于1的求导
		{
			coefficient[i] *= index[i];
			index[i]--;
		}
		else//常数项求导
		{
			coefficient[i] *= index[i];
		}
	}
	cout << coefficient[0] << ' ' << index[0];
	for (int i = 1; i < coefficient.size(); i++)//输出
	{
		if (index[i] != 0||coefficient[i]!=0)
		{
			cout << ' ' << coefficient[i] << ' ' << index[i];
		}
	}
	return 0;
}
