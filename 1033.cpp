//1033 旧键盘打字
//本题难度不大，但是却花费了我很长的时间调试错误，最后查到原因是由于在主函数外的函数中一个if后面没有else，导致在一些情况下会没有返回值，导致判断程序出错
//这告诉了我要养成良好的编程习惯，对每一个语句都要规划化书写
#include<iostream>
#include<string>

using namespace std;

bool judge(char s1, char s2)//本题的主要思路就是在这个函数，比对两个字符，判断有无坏键，是否要输出，s1代表坏键
{
	if (s1 == s2) return false;//如果相同，代表是坏键，返回false
	if (s1 == '+' && (s2 >= 'A'&&s2 <= 'Z'))return false;//虽然不同，但是上档键坏了，所有大写字符不输出
	else if (s2 >= 'a'&&s2 <= 'z')//如果是小写字母，要判断他的大写字母是否是坏键
	{
		if (s2 + 'A' - 'a' == s1)	return false;
		else return true;//一开始就是这句语句没有写，导致提交的时候三个大的测试点不能通过，以后一定要注意每一个if后面都要加上else
	}
	else return true;
}

int main()

{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	if (s1 == "")//有一个坑是如果没有坏键的情况，直接输出s2,因此前面要用getline函数读取字符串
	{
		cout << s2;
		return 0;
	}
	for (int i = 0; i < s2.size(); i++)//对比s2中的每一个字符，判断是否要输出
	{
		bool temp = true;
		for (int j = 0; j < s1.size(); j++)//将s2的字符与s1中每一个字符进行对比
		{
			temp = temp&&judge(s1[j], s2[i]);//将所有逻辑判断结果求“与”，必须所有的是true最后结果才为true
		}
		if (temp)cout << s2[i];//所有判断都是true，可以输出
	}
	cout << endl;
	return 0;
}
