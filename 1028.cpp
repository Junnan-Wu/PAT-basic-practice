//1028 人口普查
#include<iostream>
#include<string.h>

using namespace std;

struct person
{
	char name[6];
	int birthday;
};


bool judge(int birthday)
{
	if (birthday < 18140906 || birthday>20140906) return false;
	else return true;
}


int main()
{
	int N;
	cin >> N;
	char name[6];
	int year, month, day;
	int birthday;
	person max, min;
	int n = 0;
	int count = 0;
	while (1)
	{
		scanf("%s %d/%d/%d", name, &year, &month, &day);//读取第一个人的名字
		birthday = year * 10000 + month * 100 + day;
		n++;
		if (judge(birthday))//找到一地个日期合理的人的生日
		{
			count++;
			break;
		}
		if (n == N)
		{
			printf("0");
			return 0;
		}
	}
	strcpy(max.name, name);//将其存在max与min中
	max.birthday = birthday;
	strcpy(min.name, name);
	min.birthday = birthday;

	for (int i = n; i < N; i++)
	{
		scanf("%s %d/%d/%d", name, &year, &month, &day);
		birthday = year * 10000 + month * 100 + day;
		if (judge(birthday))//以后一找到一个就计数
		{
			count++;
		}
		else continue;
		if (max.birthday>birthday)
		{
			strcpy(max.name, name);
			max.birthday = birthday;
		}
		if (min.birthday<birthday)
		{
			strcpy(min.name, name);
			min.birthday = birthday;
		}

	}
	printf("%d %s %s", count, max.name, min.name);
	return 0;

}
