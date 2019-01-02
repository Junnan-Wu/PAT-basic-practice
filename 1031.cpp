//1031 查验身份证
//此题比较简单，对前17个数字进行判断加权判断即可，注意还要判断是否前17位全为数字
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int weight[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };

char M[] = { '1','0','X','9','8','7','6','5','4','3','2'};

bool judge(string a)//判断一个字符串是否合理
{
	int sum = 0;
	for (int i = 0; i < 17; i++)
	{
		if (a[i]<'0' || a[i]>'9') return false;//注意要检查是否前17位全是数字
		sum += (a[i] - '0')*weight[i];//对前17位进行加权求和
	}
	sum = sum % 11;
	char last = M[sum];
	if (last == a[17])return true;
	else return false;
}

int main()
{
	int N;
	vector<string> store_error;
	string temp;
	cin >> N;
	for (int i = 0; i < N; i++)//对所有字符进行判断，对于不符合的情况要将其存放在string数组中
	{
		cin >> temp;
		if (!judge(temp))
		{
			store_error.push_back(temp);
		}
	}
	if (store_error.size() != 0)//如果数组个数不为零，输出每个错误的人的身份证信息
	{
		for (int i = 0; i < store_error.size(); i++)
		{
			cout << store_error[i] << endl;
		}
	}
	else//如果数组个数为0，证明所有人通过；
	{
		cout << "All passed" << endl;
	}
	return 0;
}
