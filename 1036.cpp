//1036 跟奥巴马一起编程
#include<iostream>

using namespace std;

int main()
{
	int n;
	char c;
	cin >> n >> c;
	int row = n / 2.0 + 0.5;
	for (int i = 0; i < n; i++)
		cout << c;
	cout << endl;
	for (int i = 0; i < row - 2; i++)
	{
		cout << c;
		for (int i = 0; i < n - 2; i++)
			cout << ' ';
		cout << c;
		cout << endl;
	}
	for (int i = 0; i < n; i++)
		cout << c;
	cout << endl;
	return 0;
}
