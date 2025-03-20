#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>

#ifdef TEST
离散化的应用

题目：
假定有一个无限长的数轴，数轴上个坐标上的数都是0。
现在，我们首先进行n次操作，每次操作将某一位置x上的数加c。
接下来，进行m次询问，每个询问包含两个整数l和r, 你要求出在区间r]之间的所有数的和。

输入格式：
第一行包含两个整数n和m
接下来n行，每行包含两个整数x和c
再接下来m行，行包含两个整数r和l

输出格式：
共m行，每行输出一个询问中所求的区间内数字和。
#endif

const int N = 3 * 1e5 + 10;
int a[N]; //储存对应坐标插入的值
int s[N];//a的前缀和
std::vector<int> alls;//储存了与操作相关的所有坐标
std::vector<std::pair<int, int>> add, query;

int find(int x)//二分查找
{
	int l = 0;
	int r = alls.size() - 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (alls[mid] == x)return mid + 1;//S从1开始，映射位置前提一位
		else if (alls[mid] < x)
		{
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return -1;
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)//输入的行数n
	{
		int x, c;
		std::cin >> x >> c;//操作：x位置的值+c
		add.push_back({ x, c });//记录+操作和位置
		alls.push_back(x);//记录位置
	}

	for (int i = 0; i < m; i++)//查询的次数m
	{
		int l, r;
		std::cin >> l >> r;//范围
		query.push_back({ l, r });//记录范围[l, r]
		alls.push_back(l);
		alls.push_back(r);//也放进alls?
	}

	std::sort(alls.begin(), alls.end());//排序
	alls.erase(unique(alls.begin(), alls.end()), alls.end());//删重

	for (auto& item : add)
	{
		int x = find(item.first);//从alls中找到对应的x位置
		a[x] += item.second;//记录x对应的数+C
	}

	for (int i = 1; i <= alls.size(); i++) 
		s[i] = s[i - 1] + a[i];//前缀和

	for (auto& item : query)
	{
		int l = find(item.first);//从alls找到l
		int r = find(item.second);
		std::cout << s[r] - s[l - 1] << std::endl;
	}

	return 0;
}
