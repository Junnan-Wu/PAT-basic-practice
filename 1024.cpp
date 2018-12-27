//1024	科学计数法
//本题的关键在于对指数大于0的情况进行分类，看需不需要在末尾增加0，以及要不要保留小数点
#include<iostream>
#include<deque>

using namespace std;

int main()
{
  //s是存储字符数组的deque对象
	deque<char> s;
	char temp;
	int n;
	cin >> temp;
	if (temp != '+')cout << temp;
	while (cin.peek() != 'E')
	{
		cin >> temp;
		s.push_back(temp);
	}
	cin.ignore(1);
	cin >> n;
	if (n > 0)
	{
		int number = s.size() - 2;
		if (n < number)
		{
      //小数点的位置是s.begin()+1
			s.insert(s.begin() + 1 + n + 1, '.');//在小数点后的n+1位置增加一个小数点
			s.erase(s.begin() + 1);//删除原来的小数点
		}
		else
		{
			for (int i = 0; i < n - number; i++)
				s.push_back('0');//在后面追加n-number个0
			s.erase(s.begin() + 1);//移除小数点
		}
	}
	else
	{
		s.erase(s.begin() + 1);//移除原来第二位的小数点
		for (int i = 0; i < -n; i++)
			s.push_front('0');//在数组前增加-n个零
		s.insert(s.begin() + 1,'.');//在新的字符数组第二位加上小数点
	}
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i];
	}
	return 0;

}
