#define _CRT_SECURE_NO_WARNINGS 1
//���һЩ��������

/*NC16644 [NOIP2007]�ַ�����չ�� ��WA��*/ //ģ��
////1.��������Ŀ�ֳ��ֳ��ģ�һ�㶼��ģ��
////2.p1:��д�ķ�ʽ p2:��д�Ĵ��� p3:��д��˳��
////3.��������ͬΪ���ֻ���ĸ
////4.�滻���±�ͱ��˸��¸�Ȼ��Ӧ�ԣ�
////5.����ס�ˣ�������֪�����������⣬�Ȳ�����
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<vector>
//#include <algorithm>
//using namespace std;
//int p1, p2, p3;
//const int N = 110;
//string arr;
//vector<int> m;//���ִ��±�
//vector<int> s;//��ĸ��
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
//	for (int i = 1; i < n - 1; i++) if (arr[i] == '-') //����Ҫ�޸ĵ�����
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

/*NC16622 [NOIP2009]����ʽ���*/
////˼·Ҫͨ�����Ҫ�࿼��
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

/*NC16589 [NOIP2010]��������*/
////�е���ģ����У�
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

/*NC16593 [NOIP2011]�̵�̺*/
//ֱ��Ӳ��ֵ���ܻ������,���ݺܴ�
//WA���߽緶Χa+gд����g������д��д��д����
//���벻�����
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
/*�����Ż�������*/
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

/*NC16438 ��������*/
////д��date1-date2��ݵĻ��� //һ������Ӧһ��������
////�жϻ������Ƿ����ڷ�Χ���Ƿ�Ϸ�
////ע��if else if �����ȼ�
//#include<iostream>
//using namespace std;
//int date1, date2;
//int res = 0;
//int year1,year2;
//int tmp;
//int a1[] = {1,3,5,7,8,10,12};//����
//int a2[] = { 2,4,6,9,11,-1,-1 };
//bool isDate(int x)
//{
//	int y = x / 10000;
//	int m = x % 10000 / 100;
//	int d = x % 100;
//	//printf("%d %d %d\n", y, m, d);
//	if (m <= 0 || m > 12 || d > 31) return 0;
//	//����
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

/*NC16649 У�������*/
////ǰ׺�ͼ����С
////��������غ�
////���ˣ�������������̫�٣������ķ�������
//#include<iostream>
//using namespace std;
//int l, m;
//const int N = 1e4 + 10;
//bool g[N]; //��N�±������Ҫ����
//int a, b;
//int main()
//{
//	scanf("%d %d", &l, &m);
//	while (m--)
//	{
//		scanf("%d %d", &a, &b);
//		for (int i = a; i <= b; i++) if (g[i] == 0) g[i] = 1;
//	}
//	int ans = l+1; //0��λ��
//	for (int i = 0; i <= l; i++)
//	{
//		if (g[i]) ans--;
//	}
//	printf("%d\n", ans);
//	return 0;
//}
/*��� ǰ׺������*/
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
//        //���
//        q[x] -= 1;
//        q[y + 1] += 1;//��������
//    }
//    //ǰ׺��
//    s[0] = q[0];
//    for (int i = 1;i <= l;i++) s[i] = s[i - 1] + q[i]; 
//    //��������Ļᱻ��ֵΪ-1��ֱ��������+1�����0
//    //�����ظ�������ᱻ��ֵΪ-n��nΪ�غϵ�������); ÿ��һ�����䣬+1��ֱ��ȫ�������к�Ϊ0
//    for (int i = 0;i <= l; i++) if (s[i] == 0) sum++;
//    cout << sum;
//    return 0;
//}

/*NC24636 ֵ��*/
////������
////ǰ׺�Ͳ���ܳ�����
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
/*��ɢ��д��*/

/*NC19913 [CQOI2009]��λ��ͼ*/
/*TLE*/
////���帺ȨΪ��b С��������ȨΪ��b�����
////���볤��Ϊ������ǰ׺��
////5 7 2 4 3 1 6
////1 2 1 1 0 -1 0
////�������� 4��7 2 4��5 7 2 4 3��5 7 2 4 3 1 6�� ����������Ϊ0
////TLE������������ n^2��ʱ�临�Ӷ�
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
/*��� �м�ֵ����������(����)*/
//#include<iostream>
//using namespace std;
//const int N = 1e5 + 10;
//int n, b;
//int a[N], num[N];//num���ڼ�¼������
//int main()
//{
//	scanf("%d %d", &n, &b);
//	int pos;//��¼�м���λ��                                                                                                        
//	for (int i = 1; i <= n; i++)
//	{
//		int x;scanf("%d", &x);
//		if (x < b) a[i] = -1;
//		else if (x > b) a[i] = 1;
//		else if (x == b) pos = i;
//	}
//	int sum = 0, ans = 1;
//	for (int i = pos - 1; i >= 1; i++) {//������
//		sum += a[i];
//		num[n + sum]++;//������������
//		if (!sum) ans++;
//	}
//	sum = 0;
//	for (int i = pos + 1; i <= n; i++) {
//		sum += a[i];
//		ans += num[n - sum];//�����������
//		if (!sum) ans++;
//	}
//	printf("%d\n", ans);
//	return 0;
//}

/*NC20032 ����ը��*/
////ը����û����
////�ݻ����Ϊ�߳�Ϊr�������� //���Ƶ�x,y x+r,y+r �ڵĴ�С���Դݻ�
//// a > x && b > y && a <= x+r && b <= y+r
////��ô��ը������ //����ֵ�͵�r������
////WA ���Ų���xx��yy�ĳ�ʼ�� //Ӧ������С�ı������r*r
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
//		g[x][y] = c; //+1����Ϊ�����0��0���꿪ʼ��Ϊ�˼�ǰ׺�͵��ƣ���0��0�ճ�
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
/*��� ��άǰ׺��*/
////��ά��ǰ׺���൱�����
//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//
//using namespace std;
//
//const int N = 5010;//���N��ʾ����������
//int g[N][N];
//
//int main() {
//
//    int N, R;//Ϊ�˷���������ˣ�����N������û��ϵ�ģ���Ϊ������ѡ�������
//    cin >> N >> R;
//    int xx = R, yy = R;//xx��yy��ʾ�߽磬��ʼ��Ϊ��С��R
//
//    for (int i = 0, x, y, w; i < N; ++i) {
//        cin >> x >> y >> w;
//        x++; y++;//����x��y��Ҫ��1����Ϊ�����Ŀ�������Ǵ�0��ʼ��
//        g[x][y] = w;
//        xx = max(xx, x);
//        yy = max(yy, y);//������ı߳�
//    }
//
//    for (int i = 1; i <= xx; i++)
//        for (int j = 1; j <= yy; j++)
//            g[i][j] = g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1] + g[i][j];//�����е�ǰ׺��
//
//    int ans = 0;
//    for (int i = R; i <= xx; i++) {
//        for (int j = R; j <= yy; j++) {  //�൱�ڽ������R�����ǰ׺��
//            ans = max(ans, g[i][j] - g[i - R][j] - g[i][j - R] + g[i - R][j - R]);//����ǰ��õ�ǰ׺�ͼ�ȥ���������ٲ��϶�����ǲ���
//        }
//    }
//    printf("%d\n", ans);
//    return 0;
//}

/*NC207053 ����*/ //��ɢ�������
//����ж��ٸ���ȷ�Ļش�
//�����Ĵ𰸼�����Ȩ???
/*��� map������ɢ��*/
////����5 .��5 +1��6+�ǣ�-inf��6-1���������+1����6��inf���������-1
////����mΪ��n����ȷ���ĺ�
////mʵ����Ӧ���ǲ�n����ȷ��������sum+=�Ĳ�������ǰ׺��
//#include<iostream>
//#include<map>
//#include<algorithm>
//#include<limits.h> //inf��-inf
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
//			m[x + 1]--;//??Ϊʲô�أ�����
//			//���ݱ������Ҳ²�����Ϊֻ�в�x����ȷ��+1����x�������ȷ��-1
//			//�����Ǵ�С����������
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

/*NC50937 ����ѡַ*/
////6 2 9 1 -> 1 2 6 9
////4 3+2+2+5 = 12, 3 2+1+3+6 = 12,��ż��ʱ�����м���� 1+4+7=12
////1 2 6
////2 1+4=5��3 2+1+3=6��1 1+5=6�����������м����������2+6��/2 = 4ż��Ҳ������ô����
////���ݽϴ�n2����ȥ���������鲻�������
////��һ�������ϣ�ÿ����Ψһ��//ȷʵ��
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
/*��� �Բ�*/
////1)����,�� 1 2 6 9
////2)�ص�:�������֪�ֿ��ĳ�̼ҿ�����ͬһ����
////3)���۲ֿ⽨������, �ֿ⵽ > ������i������< �Լ��� >������n - i - 1������ < ,
////    �����ξ���ĺ�����ֿ�λ���޹ص�, ���������a[r] - a[l]
////    4)�ɴ�, ����ֻ��Ҫ�����������ͷ��β�������, ��Щ�ԵĲ���ۼƼ�Ϊ��
////    5)��������������, ��ô��Ժ�ʣһ������...
////    ����!!!�ɵڶ���2), ���ǿ��Խ��ֿ⽨�����ʣ���̼ҵ�������, ����ǰ��Ĵ��ǲ���ͻ��
////   ���ǲֿ⵽ʣ�������ľ���Ϊ0
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
//    int ans = 0, l = 0, r = n - 1;//˫ָ�����м俿£
//    while (l < r)
//        ans += a[r--] - a[l++];//����Բ�ĺ�
//    cout << ans;
//    return 0;
//}

/*NC18386 �ַ���*/
////�Ӵ���������
////��������Ŷ
////WA: �������󴰿��������µ�״̬
////WA�� û��ע���󴰿ڸ��º������ı仯
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
  
/*NC207040 ���־� ������*/
////��Ŀ����˳ʱ�룬������ҲҪ������
////@ 1 @ 2 @ 3
///*��� ��ȡ����˫ָ�룩*/
////�������� //�����һ������ڵ����ܳ���һ��
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
//	int cnt = 0;//����
//	for (int i = 0, j = 0;i < n; i++) {//����˳ʱ��˳�򣩴�ÿһ����������ҵ�������Զ�ĵ�
//		while (cnt < x) cnt += a[(j++) % n];//ģ��Ȧ
//		ans = max(ans, min(cnt, sum - cnt));//˳��ʱ��ȡ��С
//		cnt -= a[i];//����ʱ�þ���Ҳ��һ��
//	}
//	printf("%d\n", ans);
//	return 0;
//}

/*NC20241 [SCOI2005]ɨ��MINE*/
//�ڶ��е�i�� ����Ӱ��i-1 i i+1
/*��� dp*/
////map[i] = mine[i-1] + mine[i] + mine[i+1]
////�仯һ��
//// mine[i] = map[i-1] - mine[i-1] - mine[i-2]
////�ؼ��㣺���ƹ�ʽ��Ϊʲô���ֻ�����ַ�����//��Ϊ���ݵ�һ�����ƹ�ʽ
//#include<iostream>
//using namespace std;
//const int N = 1e4 + 10;
//int mine[N], map[N];
//int n;
//int solution()
//{
//	for (int i = 2; i < n; i++) {
//		mine[i] = map[i - 1] - mine[i - 1] - mine[i - 2];
//		if (mine[i] < 0 || mine[i] > 1)return 0;//�жϺϷ��ԣ�һ�������һ�����ף�
//	}
//	if (mine[n - 1] + mine[n - 2] != map[n - 1]) return 0;//���һ������
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
//	else if (map[0] == 1) //�������ֿ��ܵĺ�
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

/*NC235250 ţ���ֵķ�ת��Ϸ*/
////������bfsдд //�о���̫�� //Ҫ���ö��2^1000-1�ֿ��ܣ��ڴ�ᱬ
////WA��������󣬾����������в���
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
/*��� ���� �Ӽ�ö��*/
////��Ϊÿ�η�תֻӰ������һ�е�һ�����ӣ�
////���Զ�����֪��ǰi�е�״̬����ת��������Ҫ��״̬����Ҫ�Ĳ����ǹ̶���
////����ֻ��ö�ٵ�һ�е�����״̬�����Ƽ��ɣ� 
////ͨ���Ե�һ�е������Ӽ���ö�٣����Ǿ��ܵõ���һ�е����г�ʼ����
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<algorithm>
//#define ll long long
//#define ull long long
//using namespace std;
//string s;
//ll n, m, i, j, ans, a, b;
//string c[120], d[120];//����string��
//
//ll get() { //���ٶ��룻 
//    char x;int f = 1;
//    while ((x = getchar()) > '9' || x < '0')
//        if (x == '-') f = -1;
//    ll sum = x - '0';
//    while ((x = getchar()) <= '9' && x >= '0')
//        sum = sum * 10 + x - '0';
//    return sum * f;
//}
//
//void overturn(ll x, ll y) {   //���������������ķ�ת������ 
//    int dx[6] = { 0,0,0,0,1,-1 };
//    int dy[6] = { 0,0,1,-1,0,0 };
//    for (int i = 1;i <= 5;i++) {
//        a = x + dx[i];
//        b = y + dy[i];
//        if (a >= 0 && a < n && b >= 0 && b < m) {  //�ж�δԽ�磻 
//            d[a][b] = ((d[a][b] == '0') ? '1' : '0');
//        }
//    }
//    return;
//}
//
//ll recurrence(ll state, char target) {
//    ll step = 0;
//    for (int i = 0;i < n;i++) {//����ԭ״̬
//        d[i] = c[i];
//    }
//    for (int i = 0;i < m;i++) {//�����һ�У���
//        if (state & (1 << i)) {
//            //??������ôͨ���������2^n�ַ�ת������ȫ���еģ���    //�жϵ�iλ�Ƿ�Ϊ1����ʵ�ж���0��1������ν�� 
//            step++;
//            //printf("%lld %d %d\n", state, i, 1 << i);
//            overturn(0, i);//��ת0 i����
//        }
//    }
//    for (int i = 1;i < n;i++) {//�����i�е���һ��
//        for (j = 0;j < m;j++) {
//            if (d[i - 1][j] != target) { //���i��j��һ�е����Ӳ���������Ҫ��״̬���ͷ�ת�� 
//                step++;
//                overturn(i, j);
//            }
//        }
//    }
//    for (int i = 0;i < m;i++) {
//        if (d[n - 1][i] != target) return 1000; //������һ�в���������������Ԥ������ֵ�� 
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
//    for (i = 0;i < (1 << m);i++) { //1 << m ��Ч��2��m�η�
//        ans = std::min(ans, recurrence(i, '0')); //���ǽ����̷�תΪȫ��0��״̬����Ҫ�Ĳ����� 
//        ans = std::min(ans, recurrence(i, '1')); //ͬ�ϣ� 
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


/*NC23053 ���²黪�����ֻ�*/

/*NC16783 ƴ��*/

/*NC16618 ������*/

/*NC200190 ����������Ϸ*/

/*NC23036 ���������³���*/

/*NC16561 ��������Ϸ*/

/*NC25043 Protecting the Flower*/

/*NC18979 ����xor*/

/*NC20860 ���ӵ���������*/

/*NC17857 �������ۺ�֢*/