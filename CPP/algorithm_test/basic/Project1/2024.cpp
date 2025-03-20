#define _CRT_SECURE_NO_WARNINGS 1
//解决一些基础问题

/*NC16644 [NOIP2007]字符串的展开 （WA）*/ //模拟
////1.像这种题目又臭又长的，一般都是模拟
////2.p1:填写的方式 p2:填写的次数 p3:填写的顺序
////3.减号两侧同为数字或字母
////4.替换后下标就变了阁下该然后应对？
////5.绷不住了，根本不知道那里有问题，先不做了
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<vector>
//#include <algorithm>
//using namespace std;
//int p1, p2, p3;
//const int N = 110;
//string arr;
//vector<int> m;//数字串下标
//vector<int> s;//字母串
//
//string full(int x)
//{
//	string s;
//	if (p1 == 1)
//	{
//		if (p3 == 1)
//		{
//			for (char i = arr[x - 1] + 1; i < arr[x + 1]; i++) {
//				for (int k = 0; k < p2; k++) {
//					if (i >= 'A' && i <= 'Z') s += i - 'A' + 'a';
//					else s += i;
//				}
//			}
//		}
//		if (p3 == 2)
//		{
//			for (char i = arr[x + 1] - 1; i > arr[x - 1]; i--) {
//				for (int k = 0; k < p2; k++) {
//					if (i >= 'A' && i <= 'Z') s += i - 'A' + 'a';
//					else s += i;
//				}
//			}
//		}
//	}
//	else if (p1 == 2)
//	{
//		if (p3 == 1)
//		{
//			for (char i = arr[x - 1] + 1; i < arr[x + 1]; i++) {
//				for (int k = 0; k < p2; k++) {
//					if (i >= 'a' && i <= 'z') s += i - 'a' + 'A';
//					else s += i;
//				}
//			}
//		}
//		if (p3 == 2)
//		{
//			for (char i = arr[x + 1] - 1; i > arr[x - 1]; i--) {
//				for (int k = 0; k < p2; k++) {
//					if (i >= 'a' && i <= 'z') s += i - 'a' + 'A';
//					else s += i;
//				}
//			}
//		}
//	}
//	else if (p1 == 3)
//	{
//		for (char i = arr[x - 1] + 1; i < arr[x + 1]; i++) {
//			for (int k = 0; k < p2; k++) {
//				s += '*';
//			}
//		}
//	}
//	return s;
//}
//
//bool isS(char x)
//{
//	if (x >= 'a' && x <= 'z') return 1;
//	return 0;
//}
//bool isM(char x)
//{
//	if (x >= '0' && x <= '9') return 1;
//	return 0;
//}
//
//int main()
//{
//	scanf("%d %d %d", &p1, &p2, &p3);
//	cin >> arr;
//	int n = arr.size();
//	for (int i = 1; i < n - 1; i++) if (arr[i] == '-') //放入要修改的坐标
//	{
//		if (isS(arr[i - 1]) && isS(arr[i + 1]) && arr[i - 1] < arr[i + 1]) s.push_back(i);
//		else if (isM(arr[i - 1]) && isM(arr[i + 1]) && arr[i - 1] < arr[i + 1]) m.push_back(i);
//	}
//	int len = 0;
//	for (int i : s)
//	{
//		string tmp = full(i + len);
//		arr.replace(i + len, 1, tmp);
//		len += tmp.size() - 1;
//	}
//	for (int i : m)
//	{
//		string tmp = full(i + len);
//		arr.replace(i + len, 1, tmp);
//		len += tmp.size() - 1;
//	}
//	cout << arr << endl;
//	return 0;
//}

/*NC16622 [NOIP2009]多项式输出*/
////思路要通，情况要多考虑
//#include<iostream>
//#include<string>
//using namespace std;
//string ans;
//int n;
//int arr[110];
//string toString(int x) {
//	string s;
//	if (x < 0) x = -x;
//	int res = 0;
//	while (x) {
//		s += x % 10 + '0';
//		x /= 10;
//	}
//	reverse(s.begin(),s.end());
//	return s;
//}
//
//int main() {
//	scanf("%d", &n);
//	for (int i = n; i >= 0; i--) scanf("%d", &arr[i]);
//	for (int i = n; i >= 0; i--) {
//		if (arr[i] < 0) ans += '-';
//		else if (arr[i] > 0 && i != n) ans += '+';
//		if (arr[i] && i > 0) {
//			if(arr[i] > 1 || arr[i] < -1)ans += toString(arr[i]);
//			ans += 'x';
//			if (i > 1) {
//				ans += '^';
//				ans += toString(i);
//			}
//		}
//		else if (arr[i] && i == 0) {
//			ans += toString(arr[i]);
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}

/*NC16589 [NOIP2010]机器翻译*/
////有点像模拟队列？
//#include<iostream>
//using namespace std;
//const int N = 1e4+10;
//int q[N];
//int hh = 0, tt = 0;
//int m, n;
//int res = 0;
//bool find(int x) {
//	for (int i = hh; i < tt; i++) {
//		if (q[i] == x) return 1;
//	}
//	return 0;
//}
//int main() {
//	memset(q, -1, sizeof q);
//	scanf("%d %d", &m, &n);
//	for (int i = 0; i < n; i++) {
//		int num;scanf("%d", &num);
//		if (!find(num)) {
//			res++;
//			if (tt >= m) hh++;
//			q[tt++] = num;
//		}
//	}
//	printf("%d\n", res);
//	return 0;
//}

/*NC16593 [NOIP2011]铺地毯*/
//直接硬赋值可能会出问题,数据很大
//WA：边界范围a+g写成了g，属于写着写着写忘了
//代码不够简洁
//#include<iostream>
//#include<cstring>
//using namespace std;
//int n, a, b, g, k;
//int x, y;
//int arr[10010][4]; //0 a //1 b //2 g //3 k
//bool isInBox(int a1,int b1,int g1,int k1)
//{
//	if (x >= a1 && y >= b1 && x <= a1+g1 && y <= b1+k1) return 1;
//	else return 0;
//}
//int main()
//{
//	scanf("%d", &n);
//	int j = 1;
//	while (n--)
//	{
//		scanf("%d %d %d %d", &a, &b, &g, &k);
//		arr[j][0] = a;
//		arr[j][1] = b;
//		arr[j][2] = g;
//		arr[j][3] = k;
//		j++;
//	}
//	scanf("%d %d", &x, &y);
//	int ans = -1;
//	for (int i = 1; i < j; i++)
//	{
//		if (isInBox(arr[i][0],arr[i][1],arr[i][2],arr[i][3])) ans = i;
//	}
//	printf("%d\n", ans);
//	return 0;
//}
/*重置优化简洁代码*/
//#include<iostream>
//using namespace std;
//int n;
//const int N = 1e4 + 10;
//int a[N], b[N], g[N], k[N];
//int x, y;
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d %d %d %d", &a[i], &b[i], &g[i], &k[i]);
//	}
//	int ans = -1;
//	scanf("%d %d", &x, &y);
//	for(int i = n; i > 0; i--) 
//		if (x >= a[i] && y >= b[i] && x <= a[i] + g[i] && y <= b[i] + k[i])
//		{
//			ans = i;
//			break;
//		}
//	printf("%d\n", ans);
//	return 0;
//}

/*NC16438 回文日期*/
////写出date1-date2年份的回文 //一年仅会对应一个回文数
////判断回文数是否属于范围，是否合法
////注意if else if 的优先级
//#include<iostream>
//using namespace std;
//int date1, date2;
//int res = 0;
//int year1,year2;
//int tmp;
//int a1[] = {1,3,5,7,8,10,12};//大月
//int a2[] = { 2,4,6,9,11,-1,-1 };
//bool isDate(int x)
//{
//	int y = x / 10000;
//	int m = x % 10000 / 100;
//	int d = x % 100;
//	//printf("%d %d %d\n", y, m, d);
//	if (m <= 0 || m > 12 || d > 31) return 0;
//	//闰年
//	if (y % 400 == 0 || (y % 4 == 0 && y % 100))
//	{
//		for (int i = 0; i < 7; i++)
//		{
//			if (m == a1[i])
//			{
//				if (d >= 0 && d <= 31) return 1;
//			}
//			if (m == a2[i])
//			{
//				if (m == 2) {
//					if (d >= 0 && d <= 29) return 1;
//				}
//				else if (d >= 0 && d <= 30) return 1;
//			}
//		}
//	}
//	else
//	{
//		for (int i = 0; i < 7; i++)
//		{
//			if (m == a1[i])
//			{
//				if (d >= 0 && d <= 31) return 1;
//			}
//			if (m == a2[i])
//			{
//				if (m == 2) {
//					if (d >= 0 && d <= 28) return 1; 
//				}
//				else if (d >= 0 && d <= 30) return 1;
//			}
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	scanf("%d %d", &date1, &date2);
//	year1 = date1 / 10000;
//	year2 = date2 / 10000;
//	for (int i = year1; i <= year2; i++)
//	{
//		tmp = i * 10000 + i / 1000 + i % 1000 / 100 * 10 + i % 100 / 10 * 100 + i % 10 * 1000;
//		//printf("%d\n", tmp);
//		if (isDate(tmp)) res++;
//	}
//	printf("%d\n", res);
//	return 0;
//}

/*NC16649 校门外的树*/
////前缀和计算大小
////区域可能重合
////过了？？？这题数据太少，暴力的方法过了
//#include<iostream>
//using namespace std;
//int l, m;
//const int N = 1e4 + 10;
//bool g[N]; //以N下标的树需要砍掉
//int a, b;
//int main()
//{
//	scanf("%d %d", &l, &m);
//	while (m--)
//	{
//		scanf("%d %d", &a, &b);
//		for (int i = a; i <= b; i++) if (g[i] == 0) g[i] = 1;
//	}
//	int ans = l+1; //0的位置
//	for (int i = 0; i <= l; i++)
//	{
//		if (g[i]) ans--;
//	}
//	printf("%d\n", ans);
//	return 0;
//}
/*题解 前缀和与差分*/
//#include<iostream>
//using namespace std;
//const int N = 10010;
//int l, m, x, y, sum;
//int q[N], s[N];
//int main()
//{
//    cin >> l >> m;
//    while (m--)
//    {
//        cin >> x >> y;
//        //差分
//        q[x] -= 1;
//        q[y + 1] += 1;//划定区间
//    }
//    //前缀和
//    s[0] = q[0];
//    for (int i = 1;i <= l;i++) s[i] = s[i - 1] + q[i]; 
//    //处于区间的会被赋值为-1，直到出区间+1变成了0
//    //对于重复的区间会被赋值为-n（n为重合的区间数); 每出一个区间，+1，直到全部出完中和为0
//    for (int i = 0;i <= l; i++) if (s[i] == 0) sum++;
//    cout << sum;
//    return 0;
//}

/*NC24636 值周*/
////大数据
////前缀和差分跑出来了
//#include<iostream>
//const int N = 1e8 + 10;
//int l, m, x, y;
//int q[N];
//int s[N];
//int ans = 0;
//int main()
//{
//	q[0] = 0;
//	scanf("%d %d", &l, &m);
//	while (m--)
//	{
//		scanf("%d %d", &x, &y);
//		q[x]--;
//		q[y + 1]++;
//	}
//	s[0] = q[0];
//	for (int i = 1; i <= l; i++)  s[i] = s[i - 1] + q[i];
//	for (int i = 0; i <= l; i++) if (s[i] == 0) ans++;
//	printf("%d\n", ans);
//	return 0;
//}
/*离散化写法*/

/*NC19913 [CQOI2009]中位数图*/
/*TLE*/
////定义负权为比b 小的数，正权为比b大的数
////解离长度为奇数的前缀和
////5 7 2 4 3 1 6
////1 2 1 1 0 -1 0
////子序列有 4，7 2 4，5 7 2 4 3，5 7 2 4 3 1 6， 满足区间差分为0
////TLE：计算区间差分 n^2的时间复杂度
//#include<iostream>
//#include<cstring>
//using namespace std;
//int n, b;
//const int N = 1e5 + 10;
//int s[N];
//int ans = 0;
//int x;
//int main()
//{
//	scanf("%d %d", &n, &b);
//	s[0] = 0;
//	for(int i = 1; i <= n; i++)
//	{
//		int num;
//		scanf("%d", &num);
//		if (num < b) s[i] = s[i - 1] - 1;
//		else if (num > b) s[i] = s[i - 1] + 1;
//		else if (num == b) {
//			s[i] = s[i - 1];
//			x = i;
//		}
//	}
//	for (int i = x; i <= n; i++) {
//		for (int j = 1; j <= i; j += 2){
//			if (s[i] - s[i - j] == 0) ans++;
//		}
//	}
//	printf("%d\n", ans);
//	return 0;
//}
/*题解 中间值，左右区间(技巧)*/
//#include<iostream>
//using namespace std;
//const int N = 1e5 + 10;
//int n, b;
//int a[N], num[N];//num用于记录左区间
//int main()
//{
//	scanf("%d %d", &n, &b);
//	int pos;//记录中间数位置                                                                                                        
//	for (int i = 1; i <= n; i++)
//	{
//		int x;scanf("%d", &x);
//		if (x < b) a[i] = -1;
//		else if (x > b) a[i] = 1;
//		else if (x == b) pos = i;
//	}
//	int sum = 0, ans = 1;
//	for (int i = pos - 1; i >= 1; i++) {//左区间
//		sum += a[i];
//		num[n + sum]++;//存入区间数组
//		if (!sum) ans++;
//	}
//	sum = 0;
//	for (int i = pos + 1; i <= n; i++) {
//		sum += a[i];
//		ans += num[n - sum];//左右区间搭配
//		if (!sum) ans++;
//	}
//	printf("%d\n", ans);
//	return 0;
//}

/*NC20032 激光炸弹*/
////炸弹？没看懂
////摧毁面积为边长为r的正方形 //爆破点x,y x+r,y+r 内的大小可以摧毁
//// a > x && b > y && a <= x+r && b <= y+r
////怎么安炸弹？？ //最大价值和的r正方形
////WA 经排查是xx，yy的初始化 //应该是最小的爆破面积r*r
//#include<iostream>
//using namespace std;
//const int N = 5e3 + 10;
//int n, r, x, y, c;
//int g[N][N];
//int xx, yy;
//int main()
//{
//	scanf("%d %d", &n, &r);
//	int xx = r, yy = r;
//	while (n--)
//	{
//		scanf("%d %d %d", &x, &y, &c);
//		x++;y++;
//		xx = max(xx, x);yy = max(yy, y);
//		g[x][y] = c; //+1是因为这题从0，0坐标开始，为了简化前缀和递推，把0，0空出
//	}
//	for (int i = 1; i <= xx; i++) {
//		for (int j = 1; j <= yy; j++) {
//			g[i][j] = g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1] + g[i][j];
//		}
//	}
//	int ans = 0;
//	for (int i = r; i <= xx; i++) {
//		for (int j = r; j <= yy; j++) {
//			ans = max(ans, g[i][j] - g[i - r][j] - g[i][j - r] + g[i - r][j - r]);
//		}
//	}
//	printf("%d\n", ans);
//	return 0;
//}
/*题解 二维前缀和*/
////二维的前缀和相当于面积
//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//
//using namespace std;
//
//const int N = 5010;//这个N表示点最多的数量
//int g[N][N];
//
//int main() {
//
//    int N, R;//为了方便就重名了，两个N重名是没关系的，因为会优先选择函数里的
//    cin >> N >> R;
//    int xx = R, yy = R;//xx和yy表示边界，初始化为最小的R
//
//    for (int i = 0, x, y, w; i < N; ++i) {
//        cin >> x >> y >> w;
//        x++; y++;//坐标x，y都要加1，因为这道题目的坐标是从0开始的
//        g[x][y] = w;
//        xx = max(xx, x);
//        yy = max(yy, y);//求出最大的边长
//    }
//
//    for (int i = 1; i <= xx; i++)
//        for (int j = 1; j <= yy; j++)
//            g[i][j] = g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1] + g[i][j];//求所有的前缀和
//
//    int ans = 0;
//    for (int i = R; i <= xx; i++) {
//        for (int j = R; j <= yy; j++) {  //相当于解离出了R面积的前缀和
//            ans = max(ans, g[i][j] - g[i - R][j] - g[i][j - R] + g[i - R][j - R]);//用提前算好的前缀和减去其他部分再补上多剪的那部分
//        }
//    }
//    printf("%d\n", ans);
//    return 0;
//}

/*NC207053 二分*/ //离散化，差分
//最多有多少个正确的回答？
//把相斥的答案记作负权???
/*题解 map代替离散化*/
////例如5 .是5 +1，6+是（-inf，6-1）这个区间+1，（6，inf）这个区间-1
////定义m为猜n的正确数的和
////m实际上应该是猜n的正确数，后面sum+=的操作才是前缀和
//#include<iostream>
//#include<map>
//#include<algorithm>
//#include<limits.h> //inf与-inf
//using namespace std;
//#define inf INT_MAX
//int n;
//map<int, int> m = {};
//
//int main()
//{
//	int x;char ch;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		cin >> x >> ch;
//		if (ch == '.') {
//			m[x]++;
//			m[x + 1]--;//??为什么呢？？？
//			//根据遍历，我猜测是因为只有猜x的正确性+1，猜x以外的正确性-1
//			//遍历是从小数到大数的
//		}
//		else if (ch == '+') {
//			m[x]--;
//			m[-inf]++;
//		}
//		else if (ch == '-') {
//			m[x + 1]++;
//			m[inf]--;
//		}
//	}
//	int ans = -inf;
//	int sum = 0;
//	for (auto i : m) {
//		sum += i.second;
//		ans = max(ans, sum);
//	}
//	printf("%d\n", ans);
//	return 0;
//}

/*NC50937 货仓选址*/
////6 2 9 1 -> 1 2 6 9
////4 3+2+2+5 = 12, 3 2+1+3+6 = 12,当偶数时建在中间最近 1+4+7=12
////1 2 6
////2 1+4=5，3 2+1+3=6，1 1+5=6，奇数建在中间数最近，（2+6）/2 = 4偶数也可以这么抽象
////数据较大，n2过不去，本身数组不是有序的
////在一条数轴上，每个点唯一？//确实奥
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 1e5+10;
//int arr[N];
//int n;
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
//	sort(arr, arr + n);
//	int begin = n / 2;
//	int ans = 0;
//	for (int i = n / 2-1; i >= 0; i--) {
//		ans += arr[begin] - arr[i];
//	}
//	for (int i = n / 2 + 1; i < n;i++) {
//		ans += arr[i] - arr[begin];
//	}
//	printf("%d\n", ans);
//	return 0;
//}
/*题解 对差*/
////1)排序,得 1 2 6 9
////2)重点:由题意可知仓库和某商家可以在同一坐标
////3)无论仓库建在哪里, 仓库到 > 排序后第i个坐标< 以及到 >排序后第n - i - 1个坐标 < ,
////    这两段距离的和是与仓库位置无关的, 即距离等于a[r] - a[l]
////    4)由此, 我们只需要将数组排序后头和尾两两配对, 这些对的差的累计即为答案
////    5)若数组有奇数个, 那么配对后将剩一个单的...
////    但是!!!由第二点2), 我们可以将仓库建在这个剩余商家的坐标上, 这与前面的答案是不冲突的
////   于是仓库到剩余这个点的距离为0
//#include <iostream>
//#include<algorithm>
//using namespace std;
//const int N = 1e5 + 10;
//int a[N];
//
//int main() {
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++) cin >> a[i];
//    sort(a, a + n);
//    int ans = 0, l = 0, r = n - 1;//双指针向中间靠拢
//    while (l < r)
//        ans += a[r--] - a[l++];//区间对差的和
//    cout << ans;
//    return 0;
//}

/*NC18386 字符串*/
////子串是连续的
////滑动窗口哦
////WA: 忽略了左窗口连续更新的状态
////WA： 没有注意左窗口更新后条件的变化
//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//string s;
//map<char, int>m;
//int main()
//{
//	cin >> s;
//	int len = s.size();
//	int l = 0, r = 0;
//	int ans = len;
//	while (r < len)
//	{
//		m[s[r]]++;
//		while (m[s[l]] > 1) {
//			m[s[l++]]--;
//		}
//		if (m.size() == 'z' - 'a' + 1) ans = min(ans, r - l + 1);
//		r++;
//	}
//	printf("%d\n", ans);
//	return 0;
//}
  
/*NC207040 丢手绢 （精）*/
////题目给了顺时针，而我们也要考虑逆
////@ 1 @ 2 @ 3
///*题解 尺取法（双指针）*/
////计算距离和 //最长距离一定会大于等于周长的一半
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 1e5 + 10;
//int a[N];int sum = 0;
//int main()
//{
//	int n;cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		sum += a[i];
//	}
//	int x = sum / 2;
//	int ans = 0;
//	int cnt = 0;//距离
//	for (int i = 0, j = 0;i < n; i++) {//（以顺时针顺序）从每一个点出发，找到离他最远的点
//		while (cnt < x) cnt += a[(j++) % n];//模拟圈
//		ans = max(ans, min(cnt, sum - cnt));//顺逆时针取最小
//		cnt -= a[i];//换点时让距离也近一格
//	}
//	printf("%d\n", ans);
//	return 0;
//}

/*NC20241 [SCOI2005]扫雷MINE*/
//第二列第i格 可以影响i-1 i i+1
/*题解 dp*/
////map[i] = mine[i-1] + mine[i] + mine[i+1]
////变化一下
//// mine[i] = map[i-1] - mine[i-1] - mine[i-2]
////关键点：递推公式，为什么最多只有两种方案？//因为根据第一个递推公式
//#include<iostream>
//using namespace std;
//const int N = 1e4 + 10;
//int mine[N], map[N];
//int n;
//int solution()
//{
//	for (int i = 2; i < n; i++) {
//		mine[i] = map[i - 1] - mine[i - 1] - mine[i - 2];
//		if (mine[i] < 0 || mine[i] > 1)return 0;//判断合法性（一格最多有一个地雷）
//	}
//	if (mine[n - 1] + mine[n - 2] != map[n - 1]) return 0;//最后一行特判
//	return 1;
//}
//int main()
//{
//	cin >> n;
//	if (n == 1) {
//		printf("%d\n", 1);
//		return 0;
//	}
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &map[i]);
//	}
//	int res = 0;
//	if (map[0] == 0) mine[0] = mine[1] = 0;
//	else if (map[0] == 2) mine[0] = mine[1] = 1;
//	else if (map[0] == 1) //计算两种可能的和
//	{
//		mine[0] = 1;
//		mine[1] = 0;
//		res += solution();
//		mine[0] = 0;
//		mine[1] = 1;
//	}
//	res += solution();
//	printf("%d\n", res);
//	return 0;
//}

/*NC235250 牛可乐的翻转游戏*/
////尝试用bfs写写 //感觉不太行 //要最多枚举2^1000-1种可能，内存会爆
////WA：输入错误，经典弱智行列不分
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<algorithm>
//using namespace std;
//char m1[110][15];
//char m2[110][15];
//int n, m;
//int dx[] = { 0,1,0,-1,0 };
//int dy[] = { 0,0,1,0,-1 };
//const int inf = 0x3f3f3f3f;
//void change(int x,int y) {
//	for (int i = 0; i < 5; i++) {
//		int xx = x + dx[i];
//		int yy = y + dy[i];
//		if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
//		m2[xx][yy] = (m2[xx][yy] == '0') ? '1' : '0';
//	}
// }
//int solution(int x, char target) {
//	int res = 0;
//	for (int i = 0; i < n; i++) strcpy(m2[i], m1[i]);
//	for (int i = 0; i < m; i++) {
// 		if (x & (1 << i)) {
//			res++;
//			change(0,i);
//		}
//	}
//	for (int i = 1; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (m2[i - 1][j] != target) {
//				res++;
//				change(i, j);
//			}
//		}
//	}
//	for (int i = 0; i < m; i++) {
//		if (m2[n - 1][i] != target) return inf;
//	}
//	return res;
//}
//int main() {
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++) {
// 		cin >> m1[i];
//	}
//	int ans = inf;
//	for (int i = 0; i < (1 << m); i++) {
//		ans = min(ans, solution(i, '0'));
//		ans = min(ans, solution(i, '1'));
//	}
//	if (ans == inf) printf("Impossible\n");
//	else printf("%d\n", ans);
//	return 0;
//}
/*题解 递推 子集枚举*/
////因为每次翻转只影响了上一行的一个格子，
////所以对于已知的前i行的状态，翻转至我们想要的状态所需要的步数是固定的
////所以只需枚举第一行的所有状态，递推即可； 
////通过对第一行的所有子集的枚举，我们就能得到第一行的所有初始可能
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<algorithm>
//#define ll long long
//#define ull long long
//using namespace std;
//string s;
//ll n, m, i, j, ans, a, b;
//string c[120], d[120];//用了string啊
//
//ll get() { //快速读入； 
//    char x;int f = 1;
//    while ((x = getchar()) > '9' || x < '0')
//        if (x == '-') f = -1;
//    ll sum = x - '0';
//    while ((x = getchar()) <= '9' && x >= '0')
//        sum = sum * 10 + x - '0';
//    return sum * f;
//}
//
//void overturn(ll x, ll y) {   //进行题中所描述的翻转操作； 
//    int dx[6] = { 0,0,0,0,1,-1 };
//    int dy[6] = { 0,0,1,-1,0,0 };
//    for (int i = 1;i <= 5;i++) {
//        a = x + dx[i];
//        b = y + dy[i];
//        if (a >= 0 && a < n && b >= 0 && b < m) {  //判断未越界； 
//            d[a][b] = ((d[a][b] == '0') ? '1' : '0');
//        }
//    }
//    return;
//}
//
//ll recurrence(ll state, char target) {
//    ll step = 0;
//    for (int i = 0;i < n;i++) {//载入原状态
//        d[i] = c[i];
//    }
//    for (int i = 0;i < m;i++) {//处理第一行？？
//        if (state & (1 << i)) {
//            //??他是怎么通过这个做到2^n种翻转方法的全排列的？？    //判断第i位是否为1，其实判断是0是1都无所谓； 
//            step++;
//            //printf("%lld %d %d\n", state, i, 1 << i);
//            overturn(0, i);//翻转0 i坐标
//        }
//    }
//    for (int i = 1;i < n;i++) {//处理第i行的上一行
//        for (j = 0;j < m;j++) {
//            if (d[i - 1][j] != target) { //如果i，j上一行的棋子不是我们想要的状态，就翻转； 
//                step++;
//                overturn(i, j);
//            }
//        }
//    }
//    for (int i = 0;i < m;i++) {
//        if (d[n - 1][i] != target) return 1000; //如果最后一行不满足条件，返回预设的最大值； 
//    }
//    return step;
//}
//
//int main() {
//    cin >> n >> m;
//    for (i = 0;i < n;i++) {
//        cin >> c[i];
//    }
//    ans = 100 * 10;
//    for (i = 0;i < (1 << m);i++) { //1 << m 等效于2的m次方
//        ans = std::min(ans, recurrence(i, '0')); //考虑将棋盘翻转为全是0的状态所需要的步数； 
//        ans = std::min(ans, recurrence(i, '1')); //同上； 
//    }
//    if (ans == 1000) cout << "Impossible";
//    else cout << ans;
//    //for (int i = 0; i < (1 << m); i++)
//    //{
//    //    for (int j = 0; j < m; j++)
//    //        if (!(i & (1 << j))) printf("%d %d\n", i, 1 << j);
//    //}
//    //if (9 & 8) printf("9&8\n");
//    //if (1 & 1) printf("1&1\n");
//    return 0;
//}


/*NC23053 月月查华华的手机*/

/*NC16783 拼数*/

/*NC16618 排座椅*/

/*NC200190 矩阵消除游戏*/

/*NC23036 华华听月月唱歌*/

/*NC16561 国王的游戏*/

/*NC25043 Protecting the Flower*/

/*NC18979 毒瘤xor*/

/*NC20860 兔子的区间密码*/

/*NC17857 起床困难综合症*/