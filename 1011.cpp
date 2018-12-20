//1011	A+B 和 C
#include<iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	long long A, B, C;//本题的关键在于使用有符号长整型范围更大
	for (int i = 1; i <= T; i++)
	{
		cin >> A >> B >> C;
		cout << "Case #" << i << ": ";
		if (A + B > C)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}
