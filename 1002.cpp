//1002 写出这个数
#include<iostream>

using namespace std;

const char number[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

int main()
{
	char a[10000];
	int sum = 0, i = 0;
	cin.getline(a, 10000);
	while (a[i] != '\0')
	{
		sum += a[i] - '0';
		i++;
	}
	int b[100];
	i = 0;
	while (sum != 0)
	{
		b[i] = sum % 10;
		sum /= 10;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
	{
		printf("%s", number[b[j]]);
		if (j != 0)
		printf(" ");
	}
	printf("\n");
	return 0;
}
