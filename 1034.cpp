//1034 有理数四则运算
#include<iostream>

using namespace std;

class fraction
{
private:
	long long a, b;//原始的分子分母
	long long mol;//分子
	long long den;//分母
	long long gcd;//最大公约数
	long long integer;//整数部分
	bool judge;//记录是否为负数,false为负数
	bool legal=true;//判断这个分数是否合法（分母为零不合法）
public:
	fraction(){};
	fraction(long long a, long long b) :a(a), b(b)
	{
		judge = true;//记录是否为负数
		if (a < 0)
		{
			a = -a;
			judge = false;//false代表是负数
		}
		//int g = 1;
		//for (int i = 2; i <= a && i <= b; i++)//计算最大公约数
		//{
		//	if ((b%i == 0) && (a%i == 0))g = i;
		//}
		long long max = a >= b ? a : b;
		long long min = a < b ? a : b;
		long long temp;
		while (min != 0)
		{
			temp = max % min;
			max = min;
			min = temp;
		}
		gcd = max;
		integer = a / b;
		mol = (a-integer * b)/gcd;
		den = b / gcd;
	};
	void set(long long a, long long b)
	{
		if (b == 0)
		{
			legal = false;
			return;
		}
		this->a = a;
		this->b = b;
		judge = true;//记录是否为负数
		if (a < 0)
		{
			a = -a;
			judge = false;//false代表是负数
		}
    //一开始使用从2开始循环判断是否能整除来查找最大公约数，后来运行超时，说明该算法不合适
		//int g = 1;
		//for (int i = 2; i <= a && i <= b ; i++)//计算最大公约数
		//{
		//	if ((b%i == 0) && (a%i == 0))g = i;
		//}
    //后来使用辗转相除法来寻找最大公约数
	  //先找两个数中的较大的数
		long long max = a >= b ? a : b;
		long long min = a < b ? a : b;
		long long temp;
		while (min != 0)//计算max % min =c
    //然后max=min，min=c；继续计算，直到min等于0为止，max就是最大公约数
		{
			temp = max % min;
			max = min;
			min = temp;
		}
		gcd = max;
		integer = a / b;//记录整数部分
		mol = (a - integer * b) / gcd;//记录去掉整数部分的分数部分
		den = b / gcd;//记录分母
	}
	void print();
	fraction plus(fraction a);
	fraction sub(fraction a);
	fraction mul(fraction a);
	fraction div(fraction a);
};

void fraction::print()
{
	if (!legal)//首先判断是否合法，不合法的话输出Inf
	{
		cout << "Inf";
		return;
	}
	if (mol == 0 && integer == 0)//如果分子与整数部分都为零输出0
	{
		cout << 0;
		return;
	}
	if (judge)//如果不是负数不需要加括号
	{
		if (integer != 0)//如果整数部分不为零需要输出整数部分
		{
			if (mol == 0)//如果分子为零，输出完整数部分直接结束
			{
				cout << integer;
				return;
			}
			else//否则需要多输出一个空格
			{
				cout << integer << ' ';
			}
		}
    //输出分子与分母
		cout << mol << '/' << den;
		return;
	}
	else//是负数同上，只是在开始前需要加上'（'与'-'号，最后return前需要加')'
	{
		cout << "(-";
		if (integer != 0)
		{
			if (mol == 0)
			{
				cout << integer << ')';
				return;
			}
			else
			{
				cout << integer << ' ';
			}

		}
		cout << mol << '/' << den << ')';
		return;
	}
}

fraction fraction::plus(fraction a)
{
	fraction temp;
	long long mol, den;
	mol = this->a * a.b + a.a*this->b;
	den = this->b * a.b;
	temp.set(mol, den);
	return temp;
}

fraction fraction::sub(fraction a)
{
	fraction temp;
	long long mol, den;
	mol = this->a * a.b - a.a*this->b;
	den = this->b * a.b;
	temp.set(mol, den);
	return temp;
}

fraction fraction::mul(fraction a)
{
	fraction temp;
	long long mol, den;
	mol = this->a * a.a;
	den = this->b * a.b;
	temp.set(mol, den);
	return temp;
}

fraction fraction::div(fraction a)//由于除法其实是乘倒数，因此要分除数是正数还是负数分别考虑（颠倒以后负号会跑到分母）
{
	fraction temp;
	long long mol, den;
	if (a.judge)
	{
		mol = this->a * a.b;
		den = this->b * a.a;
	}

	else
	{
		mol = -1* this->a * a.b;
		den = -1* this->b * a.a;
	}
	temp.set(mol, den);
	return temp;
}

int main()
{
	long long a1, b1, a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	fraction a(a1, b1);
	fraction b(a2, b2);
	a.print(); cout << " + "; b.print(); cout << " = "; a.plus(b).print(); cout << endl;
	a.print(); cout << " - "; b.print(); cout << " = "; a.sub(b).print(); cout << endl;
	a.print(); cout << " * "; b.print(); cout << " = "; a.mul(b).print(); cout << endl;
	a.print(); cout << " / "; b.print(); cout << " = "; a.div(b).print(); cout << endl;
	return 0;
}
