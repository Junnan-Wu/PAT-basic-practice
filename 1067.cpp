//1067 试密码
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string password,temp;//储存正确密码与临时输入
	vector<string> store;//储存输入
	int allow;//存储最大尝试个数
	cin >> password >> allow;
	getchar();//读取第一行最后的回车
	int count = 0;//记录尝试个数
	while (1)
	{
		getline(cin, temp);//注意题目说正确密码不包含空格等，但是没说输入的密码不包含空格！因此这里要用getline读取整行
		if (temp != "#")
			store.push_back(temp);
		else
			break;
	}
	for (auto i = 0; i < allow&&i<store.size(); i++)
	{
		if (store[i] == password)
		{
			printf("Welcome in\n");
			return 0;
		}
		else
		{
			printf("Wrong password: ");
			cout << store[i] << endl;
		}
	}
	if (allow <= store.size())cout << "Account locked" << endl;
	return 0;
}
