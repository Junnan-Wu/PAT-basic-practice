//1045 快速排序
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;//输入元素个数
	int temp, max = 0;//temp用于临时存储数据，max用于存放前面为止的最大数
	vector<int> store, tep, result;
	for (int i = 0; i < N; i++)//将所有元素存在store中
	{
		cin >> temp;
		store.push_back(temp);
	}
	tep = store;
	sort(tep.begin(), tep.end());//对原数组进行排序

	for (int i = 0; i < N; i++)
	//要满足为主元，首先需要该元素的位置为排序后的位置
	//其次，该元素前的最大元素必须比这个元素小
	{
		max = max > store[i] ? max : store[i];//随时存储最大元素
		if (store[i] != tep[i])tep[i] = 0;//如果位置不对，将该元素设为0
		if (max > store[i])tep[i] = 0;//如果前面最大元素比该元素大，将该元素设置为0
		if (tep[i] != 0)result.push_back(tep[i]);//如果该元素没有设为0，证明其是主元，存在result中
	}
	if (result.size() == 0)//如果没有主元，输出0，然后在输出一个空行，这是第三个测试点
	{
		cout << 0 << endl;
		cout << endl;
		return 0;
	}
	else
	{
		cout << result.size() << endl;
		for (unsigned int i = 0; i < result.size() - 1; i++)
		{
			cout << result[i] << ' ';
		}
		cout << result[result.size() - 1] << endl;
	}
	return 0;
}
