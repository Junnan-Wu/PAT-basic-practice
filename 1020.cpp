//1020	月饼
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct mooncake//注意此题并未说库存跟总价也是整数！！有一个测试用例就是使用非整数
//因此定义库存，总价的时候应该使用double类型
{
	double stocks;//月饼库存
	double total;//月饼总价
	double price;//月饼单价
};

bool compare(mooncake a, mooncake b)//对sort函数定义比较方法
{
	return a.price > b.price;
}

int main()
{
	int N, D;
	cin >> N >> D;
	vector<mooncake> a;
	mooncake temp;
	for (int i = 0; i < N; i++)//读取库存数据
	{
		scanf("%lf",&temp.stocks);
		a.push_back(temp);
	}
	for (int i = 0; i < N; i++)//读取总价数据并计算单价
	{
		scanf("%lf",&temp.total);//读取总价的数据
		a[i].total = temp.total;
		temp.price = (a[i].total)/a[i].stocks;//计算单价
		a[i].price = temp.price;
	}
	sort(a.begin(), a.end(), compare);//按照单价大小对mooncake数组进行降序排列
	double money = 0;
	int i = 0;
	while (D != 0 && i!=N)//如果最后全部都取完了但是D还没变为0，也要结束计算
	{
		if (D >= a[i].stocks)//如果D大于库存，这一类型的月饼全部取出
		{
			money += a[i].total;
			D -= a[i].stocks;
		}
		else//否则只取D大小的月饼量
		{
			money += a[i].price*D;
			D -= D;
		}
		i++;
	}
	printf("%.2lf", money);
	return 0;
}
