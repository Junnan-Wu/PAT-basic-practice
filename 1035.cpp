//1035 插入与归并
//本题的难度较大，主要是需要对插入排序与归并排序有一个很好的理解（仅仅通过阅读题干不是很好理解的）
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//首先定义一个单词的插入排序程序
vector<int> insertion(vector<int> a)
{
	vector<int> temp = a;
	vector<int>::iterator find = temp.begin();
	unsigned int i;
	for (i = 0; i < temp.size()-1; i++)//找到需要插入的元素
	{
		if (temp[0] > temp[1])//如果第一个元素就是就是乱序，则需要插入的元素就是这个元素
		{
			find = temp.begin();
			break;
		}
		if (temp[i] > temp[i + 1])//如果后面的元素找到一个乱序，则乱序后一个元素就是需要插入的元素（注意这里是大于号，不是大于等于号，第四个测试点一直没通过就是这里的问题）
		{
			find = temp.begin() + i + 1;
			break;
		}
	}
	if (i == temp.size() - 1)return temp;//如果没找到需要插入的序列证明整个序列有序
	int find_value = *find;//记录需要插入的元素的值
	temp.erase(find);//将这个元素删除

//接来下就是要找到插入的位置，即在有序数列中间进行插入,因此先找到有序数列的最后一个元素的位置
	vector<int>::iterator it;
	for (it = temp.begin(); it < temp.end()-1; it++)//it前是一个有序数列（包括it）
	{
		if (*it > *(it+1))
		{
			break;
		}
	}
	//cout<<*it<<endl;

  //从数列开始到有序数列的最后一个开始查找插入位置
	for (vector<int>::iterator j = temp.begin(); j <= it; j++)
	{
		if (*j > find_value)//若插入的元素小于遍历的值，在这个位置前插入元素
		{
			temp.insert(j, find_value);
			return temp;
		}
	}
  //如果找到最后一个元素还没有找到比需要插入的值大的元素，证明这个要插入的元素比有序数列的最大值还大，需要插入有序数列的尾端
	temp.insert(it + 1, find_value);
	return temp;
}
//至此一次插入排序的过程就写好了（注意的要点就是如何寻找插入的元素与如何寻找插入的位置）

//下面是一次归并排序的过程
int length = 1;//需要定义一个全局变量（每次归并的集合的元素的个数）
vector<int> merge(vector<int> a)
{
	vector<int> temp = a;
	unsigned int i = 0;//定义i为第一个有序数列的开始
	unsigned int j = i + 2 * length;//定义j为需要归并的第二个有序数列的结尾

	if (j >= temp.size())//如果第二个有序数列的结尾超过界限，合并所有
	{
		sort(temp.begin()+i, temp.end());
		return temp;
	}
  //否则依次归并两两相邻的集合，知道最后剩下一个集合位置
	while (1)
	{
		if (j > temp.size())j = temp.size();//如果第二个有序数列的结尾超出界限，将其设置为最大值
		sort(temp.begin() + i, temp.begin() + j);//从第一个有序数列的开始排序到第二个集合的结尾，这样就是归并了两个相邻的有序数列
		i = j;//i位置向后递归
		if(i==temp.size()) break;//直到第一个有序数列的开始到达界限点
		j += 2 * length;//j位置向后递归
	}
	length *= 2;//一次递归结束后下一次的有序数列的长度扩大一倍
	return temp;
}
//至此，一次归并的算法写好（需要注意的是，每次必须把所有的两两相邻的集合归并，例如有7个元素，先分成2,2,2,1，然后归并一次后变为，4,3,然后在归并一次结束）

//定义一个输出序列的函数
void print(vector<int> a)
{
	unsigned int i;
	for (i = 0; i < a.size() - 1; i++)
	{
		cout << a[i] << ' ';
	}
	cout << a[i];
	return;
}

int main()
{
	int N;
	cin >> N;
	vector<int> original;//记录初始序列
	vector<int> middle;//记录需要判断的数列
	vector<int> temp1,temp2;//记录计算的中间数列
	vector<int> end;//记录排序的最终结果
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		original.push_back(n);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		middle.push_back(n);
	}
  //记录一个最后排好序的数列
	end = original;
	sort(end.begin(), end.end());
  //定义两个中间数列
	temp1 = original;
	temp2 = original;

	while (temp1!=middle && temp1 != end && temp2!=middle && temp2!= end)//如果各组的计算中间值不同并且计算没达到末尾
	{
    //对两个数列分别进行一次插入排序与归并排序
		temp1 = insertion(temp1);
		temp2 = merge(temp2);
	}
  //如果是插入排序相同，或者归并排序已经结尾了还没相同证明是插入排序
	if (temp1 == middle || temp2 == end)
	{
		cout << "Insertion Sort" << endl;
		temp1 = insertion(middle);//对中间过程再次执行一次插入排序
		print(temp1); cout << endl;
	}
	else//如果是归并排序相同，或者插入排序已经结尾了还没相同证明是归并排序
	{
		cout << "Merge Sort" << endl;
		temp2 = merge(middle);//对中间过程再次执行一次归并排序
		print(temp2); cout << endl;
	}

  //以下注释是用于检验排序的每一次输出
	/*for (int i = 0; i < N; i++)
	{
		cin >> n;
		original.push_back(n);
	}
	end = original;
	sort(end.begin(), end.end());
	while (original != end)
	{
		original = insertion(original);
		print(original); cout << endl;
	}*/
	return 0;
}
