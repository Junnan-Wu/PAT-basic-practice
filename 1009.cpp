//1009	说反话
#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main()
{
	string a;
	deque<string> sentence;
	while (cin.peek()!='\n')//cin.peek()返回一个char字符，但是其返回值是指针指向的当前字符
	//cin.peek()只是观测，指针停留当前位置，并不后移，如果是文件结束符，返回值是EOF
	{
		cin >> a;
		sentence.push_front(a);
	}
	deque<string> ::iterator it;
	cout << sentence[0];
	for (it = sentence.begin() + 1; it < sentence.end(); it++)
	{
		cout <<' '<< *it;
	}
	return 0;
}
