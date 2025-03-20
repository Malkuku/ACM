#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*高精度模板 2024.5.8*/
//复杂度 :加，减，低精除o(n) 
//		乘o(n^2) 
//		高精除o(n*10)(每一位最多操作10次)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

const int N = 1e5 + 10;
int a[N];

//数据的接受和读取 *数组默认从1下标开始
void init(int a[], string& s) {
	for (int i = 1; i <= s.size(); i++) {
		a[i] = s[s.size() - i] - '0'; //倒叙将字符串存为数组
	}//即，以下标表示位置
}

int b[N], c[N];

//加法
void add_h(int a[], int b[], int c[], int lena, int lenb) {
	int tmp = 0; //记录进位
	int lenc = 1;//记录位置
	while (lenc <= lena || lenc <= lenb) {
		c[lenc] = a[lenc] + b[lenc] + tmp;
		tmp = c[lenc] / 10;
		c[lenc] %= 10;
		lenc++;
	}
	c[lenc] = tmp;
	while (c[lenc] == 0 && lenc > 1) lenc--; //首位为0

	//输出
	for (int i = lenc; i >= 1; i--) {
		cout << c[i];
	}cout << "\n";
}

//减法
void del_h(int a[], int b[], int c[], int lena, int lenb) {
	int tmp = 0;
	int lenc = 1;
	while (lenc <= lena || lenc <= lenb) {
		if (a[lenc] < b[lenc]) {
			c[lenc] = a[lenc] + 10 - b[lenc];
			a[lenc + 1]--;//借位处理
		}
		else c[lenc] = a[lenc] - b[lenc];
		lenc++;
	}
	while (c[lenc] == 0 && lenc > 1) lenc--;

	//输出
	for (int i = lenc; i >= 1; i--) cout << c[i];
	cout << "\n";
}

//乘法
void multi_h(int a[], int b[], int c[], int lena, int lenb) {
	//核心 c[i + j - 1] = a[i] * b[j] + x + c[i + j - 1];
	int lenc = 1;
	int tmp = 0;

	for (int i = 1; i <= lena; i++) {
		tmp = 0;
		for (int j = 1; j <= lenb; j++) {
			c[i + j - 1] = c[i + j - 1] + tmp + a[i] * b[j];
			tmp = c[i + j - 1] / 10; //进位
			c[i + j - 1] %= 10; //剩余
		}
		c[i + lenb] = tmp;//最高的一位 //每次乘法可能多出一位
	}
	lenc = lena + lenb;//可能的最高位
	while (c[lenc] == 0 && lenc > 1) lenc--;

	for (int i = lenc; i >= 1; i--) cout << c[i];
	cout << "\n";
}

//除法 高精/低精
void divi_l(int a[], int b, int c[], int lena) {
	int tmp = 0;
	//因为除法从高位借位，所以这里逆序操作
	for (int i = lena; i >= 1; i--) {
		c[i] = a[i] + tmp * 10;
		tmp = c[i] % b; //借位操作
		c[i] /= b;
	}
	int lenc = lena;
	while (c[lenc] == 0 && lenc > 1) lenc--;
	for (int i = lenc; i >= 1; i--) cout << c[i];
	cout << "\n";
}

//除法 高精/高精 //本质上是通过减法模拟
//对比 
bool cmp(int a[], int b[], int len, int cha) {
	for (int i = len; i >= 1; i--) {
		if (a[i] > b[i - cha]) return 1;
		else if (a[i] < b[i - cha]) return 0;
	}
	return 1;
}
//高精度减法
void del(int a[], int b[], int len, int cha) {
	for (int i = 1; i <= len; i++) {
		if (i - cha < 1) continue;
		if (a[i] < b[i - cha]) {
			a[i + 1]--;
			a[i] += 10;
		}
		a[i] -= b[i - cha];
	}
}
void divi_h(int a[], int b[], int c[], int lena, int lenb) {
	int lenc = lena - lenb + 1;
	if (lenc <= 0) {
		cout << 0 << "\n";
		return;
	}
	for (int i = lena; i >= 1; i--) {
		int cha = i - 1;//把整个b数组看作是一个数，在b的后面补对应位数的0
		if (lenb + cha > lena) continue;
		while (cmp(a, b, lena, cha)) { //以补0后的b进行对比
			c[i]++; //如果此时a > 补0 b 说明该位上有商
			del(a, b, lena, cha);
		}
	}

	while (c[lenc] == 0 && lenc > 1) lenc--;
	for (int i = lenc; i >= 1; i--)cout << c[i];
	cout << "\n";
}


int main() {
	ios::sync_with_stdio(0);
	string s1, s2;cin >> s1 >> s2;
	init(a, s1);
	init(b, s2);
	//add_h(a, b, c,s1.size(),s2.size());
	//del_h(a, b, c, s1.size(), s2.size());
	//multi_h(a, b, c, s1.size(), s2.size());
	//int bb = stoi(s2);
	//divi_l(a, bb, c, s1.size());
	divi_h(a, b, c, s1.size(), s2.size());

	return 0;
}

/*luogu P2142 高精度减法*/
/*2024.5.8*/
////WA :字符串重载对比只适用于长度相同的情况
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 10100;
//int a[N], b[N], c[N];
//void init(int a[], string& s) {
//	for (int i = 1; i <= s.size(); i++) {
//		a[i] = s[s.size() - i] - '0';
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	string s1, s2;
//	cin >> s1 >> s2;
//	//先对比
//	bool flag = 0;
//	if (s1.size() == s2.size() && s1 < s2) flag = 1;
//	else if (s1.size() < s2.size()) flag = 1;
//	int lena, lenb;
//	int lenc = 1;
//	if (flag) {
//		cout << "-";
//		init(a, s2);
//		init(b, s1);
//		lena = s2.size();
//		lenb = s1.size();
//	}
//	else {
//		init(a, s1);
//		init(b, s2);
//		lena = s1.size();
//		lenb = s2.size();
//	}
//	//for (int i = lena; i >= 1; i--) cout << a[i];
//	//cout << "\n";
//	//for (int i = lenb; i >= 1; i--) cout << b[i];
//	//cout << "\n";
//	int tmp = 0;
//	while (lenc <= lena || lenc <= lenb) {
//		if (a[lenc] < b[lenc]) {
//			c[lenc] = 10 + a[lenc] - b[lenc];
//			a[lenc + 1]--;
//		}
//		else c[lenc] = a[lenc] - b[lenc];
//		lenc++;
//	}
//	while (c[lenc] == 0 && lenc > 1) lenc--;
//	
//	for (int i = lenc; i >= 1; i--) cout << c[i];
//	cout << "\n";
//	return 0;
//}

/*luogu P1601 A+B Problem（高精） */
/*2024.5.8 */
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 1e5 + 10;
//int a[N], b[N], c[N];
//void init(int a[], string& s) {
//	for (int i = 1; i <= s.size(); i++) {
//		a[i] = s[s.size() - i] - '0';
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	string s1, s2;
//	cin >> s1 >> s2;
//	init(a, s1);
//	init(b, s2);
//	int lena = s1.size();
//	int lenb = s2.size();
//	int lenc = 1;
//	int tmp = 0;
//	while (lenc <= lena || lenc <= lenb) {
//		c[lenc] = tmp + a[lenc] + b[lenc];
//		tmp = c[lenc] / 10;
//		c[lenc] %= 10;
//		lenc++;
//	}
//	c[lenc] = tmp;
//	while (c[lenc] == 0 && lenc > 1) lenc--;
//
//	for (int i = lenc; i >= 1; i--) cout << c[i];
//	cout << "\n";
//	return 0;
//}

/*luogu P1480 A/B Problem */
/*2024.5.8*/
////WA: 卡int了
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 1e5 + 10;
//ll a[N], c[N];
//int main() {
//	ios::sync_with_stdio(0);
//	string s;cin >> s;
//	ll b;cin >> b;
//	for (int i = 1;i <= s.size(); i++) {
//		a[i] = s[s.size() - i] - '0';
//	}
//	int lena = s.size();
//	ll tmp = 0;
//	for (int i = lena; i >= 1; i--) {
//		c[i] = a[i] + tmp * 10;
//		tmp = c[i] % b;
//		c[i] /= b;
//	}
//
//	while (c[lena] == 0 && lena > 1) {
//		lena--;
//	}
//
//	for (int i = lena; i >= 1; i--) cout << c[i];
//	cout << "\n";
//	return 0;
//}

/*NC226358 【模板】高精度乘法 */
/*2024.5.8*/ 
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 1e7 + 10;
//int a[N], b[N], c[N];
//void init(int a[], string& s) {
//	for (int i = 1; i <= s.size(); i++) {
//		a[i] = s[s.size() - i] - '0';
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	string s1, s2;
//	cin >> s1 >> s2;
//	init(a, s1);
//	init(b, s2);
//	int lena = s1.size();
//	int lenb = s2.size();
//	int tmp = 0;
//	for (int i = 1; i <= lena; i++) {
//		tmp = 0;
//		for (int j = 1; j <= lenb; j++) {
//			c[i + j - 1] = c[i + j - 1] + a[i]*b[j] + tmp;
//			tmp = c[i + j - 1] / 10;
//			c[i + j - 1] %= 10;
//		}
//		c[i + lenb] = tmp;
//	}
//	int lenc = lena + lenb;
//	while (c[lenc] == 0 && lenc > 1) lenc--;
//
//	for (int i = lenc; i >= 1; i--) cout << c[i];
//	cout << "\n";
//
//	return 0;
//}

/*#*/
//#include <cstdio>
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//int a[50005], b[50005], c[50005], d;
//
////正序的初始化 //用0号位储存位数 天才！
//void init(int a[]) {
//	char s[50005];
//	cin >> s;
//	a[0] = strlen(s);		// 字符串存储，表示位数	
//	for (int i = 1; i <= a[0]; i++) {
//		a[i] = s[a[0] - i] - 48;	// 正序储存
//	}
//}
//
////打印
//void print(int a[]) {
//	if (a[0] == 0) {
//		cout << 0 << endl;
//		return;  // 位数为0，输出0
//	}
//	for (int i = a[0]; i >= 1; i--) {
//		cout << a[i];  // 输出函数
//	}
//	cout << endl;
//	return;
//}
//
//int compare(int a[], int b[]) {
//	if (a[0] > b[0]) {
//		return 1; // 被减数大于减数
//	}
//	if (a[0] < b[0]) {
//		return -1; // 被减数小于减数
//	}
//	for (int i = a[0]; i >= 1; i--) {
//		if (a[i] > b[i]) {
//			return 1;
//		}
//		if (a[i] < b[i]) {
//			return -1;
//		}   // 位数相同，找到第一位不同的进行比较
//	}
//	return 0;
//}
//
//void numcpy(int p[], int q[], int det) {
//	for (int i = 1; i <= p[0]; i++) {
//		q[i + det - 1] = p[i]; //复制p数组到q数组从det开始的地方
//	}
//	q[0] = p[0] + det - 1;
//}
//
//void jian(int a[], int b[]) {
//	int flag = compare(a, b);
//	if (flag == 0) {
//		a[0] = 0;
//		return;
//	}
//	if (flag == 1) {
//		for (int i = 1; i <= a[0]; i++) {
//			if (a[i] < b[i]) {
//				a[i + 1]--;
//				a[i] += 10;
//			}
//			a[i] -= b[i];
//		}
//		while (a[0] > 0 && a[a[0]] == 0) {
//			a[0]--;
//		}
//		return;
//	}
//}  // 高精减法
//
//void chugao(int a[], int b[], int c[]) {
//	int tmp[50005];
//	c[0] = a[0] - b[0] + 1;
//	for (int i = c[0]; i > 0; i--) {
//		memset(tmp, 0, sizeof(tmp));
//		numcpy(b, tmp, i);// 清零
//		while (compare(a, tmp) >= 0) {
//			c[i]++;
//			jian(a, tmp);	// 用减法模拟		
//		}
//	}
//	while (c[0] > 0 && c[c[0]] == 0) {
//		c[0]--;
//	}
//	return;
//}
//
//int main() {
//	memset(a, 0, sizeof(a));
//	memset(b, 0, sizeof(b));
//	memset(c, 0, sizeof(c));
//
//	init(a);
//	init(b);
//	chugao(a, b, c);
//	print(c);
//
//	return 0;
//}