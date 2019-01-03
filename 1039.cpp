//1039 到底买不买
//本题比较简单，采取将字符的个数放在两个整型数组中，最后对比两个数组的差值即可
#include<iostream>
#include<string>

using namespace std;

int main()
{
	int sale[75] = { 0 }, want[75] = { 0 };//定义存放所有0-9，a-z,A-Z的数组个数
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++)//统计出售串中各个字符的个数，放入sale中
	{
		sale[s1[i] - '0']++;
	}
	for (int i = 0; i < s2.length(); i++)//统计要求串中各个字符的个数，放入want中
	{
		want[s2[i] - '0']++;
	}
	bool buy = true;//判断是否购买的bool变量
	int count = 0;//如果不买 计算差多少个珠子
	int temp;
	for (int i = 0; i < 75; i++)//对所有want中大于0的字符进行统计（大于0表示这个颜色有要求）
	{
		if (want[i] > 0)
		{
			temp = sale[i] - want[i];//记录sale中这个颜色的珠子与want中的差值
			if (temp < 0)//如果差值小于零，证明sale中这个颜色少了
			{
				buy = false;//决定不购买
				count += -1 * temp;//统计差了多少
			}
		}
	}
	if (buy)//如果要买，多的珠子的个数就是s1比s2大的长度
	{
		cout << "Yes " << s1.length() - s2.length();
	}
	else//如果不买，输出统计的差值
	{
		cout << "No " << count;
	}
	return 0;
}
