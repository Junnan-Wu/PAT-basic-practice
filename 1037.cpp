//1037 在霍格沃茨找零钱
//本题难度不大，只要将所有的货币转化为knut进行计算即可，最后根据knut的格式输出即可
#include<iostream>

using namespace std;

int gallen_to_knut(int g, int s, int k)//将原货币转化为全部是knut的格式
{
	int sum = 0;
	sum = g * 17 * 29 + s * 29 + k;
	return sum;
}

void knut_to_gallen(int k)//输出knut可兑换的最大的galleon与sickle
{

	bool judge = k >= 0;//首先判断knut是否大于等于0，注意等于零输出应该是0.0.0而不是0，这是最后一个测试用例的坑
	if (!judge) k = -k;//如果是小于零的情况，记录下来同时将knut转化为大于零的数
	//分别计算可兑换的galleon与sickle
	int g = k / 17 / 29;
	int s = (k - g * 17 * 29) / 29;
	k = k - g * 17 * 29 - s * 29;
	if (!judge)cout << '-';//如果小于零记得要输出一个负号
	cout << g << '.' << s << '.' << k;
	return;
}

int main()
{
	int a, b, c, e, d, f;
	scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &d, &e, &f);
	knut_to_gallen(gallen_to_knut(d, e, f) - gallen_to_knut(a, b, c));
	return 0;
}
