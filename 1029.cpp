//1029 旧键盘
#include<iostream>
#include<set>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	set<char> s1, s2;//定义两个集合s1,s2用于存储sen1，sen2中出现过的字符
	string sen1, sen2;//定义两个字符串sen1，sen2
	vector<int> number;
	cin >> sen1 >> sen2;//输入字符串

	char temp;
	for (int i = 0; i < sen1.size(); i++)//将sen1中的每一个字符插入集合s1中
	{
		temp = sen1[i];
		if (temp >= 'a'&&temp <= 'z')temp += 'A' - 'a';//如果是小写字母，转化为大写字母
		s1.insert(temp);
	}
	for (int i = 0; i < sen2.size(); i++)//同上将sen1中的每一个字符插入集合s1中
	{
		temp = sen2[i];
		if (temp >= 'a'&&temp <= 'z')temp += 'A' - 'a';
		s2.insert(temp);
	}

//定义两个迭代器，对s2求差集运算，即对比s2,s1的所有，如果相同，删除s1中的字符，这样留下来的就是有问题的键
	set<char>::iterator it,p;
	for (it = s2.begin(); it != s2.end(); it++)
	{
		for (p = s1.begin(); p != s1.end(); p++)
		{
			if (*it == *p)
			{
				s1.erase(p);
				break;
			}
		}
	}
//其实到这里已经找出了有问题的键，存在了s1中，但是由于set容器的特性，这些字符在其中已经排好了顺序，因此必须找到原来的插入顺序

	for (int i = 0; i < sen1.size(); i++)//首先将sen1中所有的小写字母转化为大写字母
	{
		if (sen1[i] >= 'a'&&sen1[i] <= 'z')sen1[i] += 'A' - 'a';
	}

  int tep;
	for (it = s1.begin(); it != s1.end(); it++)//对s1中剩下的字符一个个在sen1中查找其顺序（使用find函数），将序号存入一个数组number中
	{
		tep = sen1.find(*it);
		number.push_back(tep);
	}
  //将序号排序，从小到大
	sort(number.begin(), number.end());
	for (int i = 0; i < number.size(); i++)//最后输出这些序号代表的字符
	{
		cout << sen1[number[i]];
	}
	return 0;
}
