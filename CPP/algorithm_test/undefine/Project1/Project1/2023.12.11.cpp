#define _CRT_SECURE_NO_WARNINGS 1

/*����  С������������ ��ϣ*/
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<unordered_map>
//using namespace std;
//
//const int N = 1e5 + 10;
//int n;
//int arr[N];
//unordered_map<int, int> h;
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &arr[i]);
//		h[arr[i]] += 1;
//	}
//	int sum = 0;
//	sort(arr, arr + n + 1);
//	int j = unique(arr, arr + n + 1) - arr;
//	for (int i = 1; i < j; i++)
//	{
//		if (h[arr[i]] < arr[i]) sum += h[arr[i]];
//		else sum += h[arr[i]] - arr[i];
//	}
//	printf("%d\n", sum);
//	return 0;
//}


/*���� С�����᷿ ö��*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<unordered_map>
//const int N = 1e4 + 10;
//int arr[N];
//int n,k;
//int max = -1;
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d %d", &n, &k);
//		for (int i = 1; i <= n; i++)
//		{
//			scanf("%d", &arr[i]);
//			max = max > arr[i] ? max : arr[i];//��¼�������֣����Խ�ʡö�ٵ�ʱ��
//		}
//		int ans = 2e9;//��¼��
//		for (int i = 1; i <= max; i++)//��1ö�ٵ���������ֱ����������Ҫˢ������
//		{
//			int cnt = 0;
//			for (int j = 1; j <= n;)//ö����������
//			{
//				if (arr[j] != i)//��ͬɫ����һ��
//				{
//					cnt++;
//					j += k;//��Ϊ��һ��һ���ᱻ�̳���ͬɫ�ģ����Կ���ֱ��������һ��
//				}
//				else j++;
//			}
//			ans = ans < cnt ? ans : cnt;//��¼��С����
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}


/*���� С����С�ŵ���ս*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 1e3 + 10;
//int n;
//int arr[N];
////��ֵ�Ļ���Ϊ0������������û��0
////��ֵ�ĺͲ�Ϊ0
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//
//		int cnt = 0;
//		int neg = 0;
//		int min_neg = 1;
//		int sum = 0;
//		cin >> n;
//		for (int i = 1; i <= n; i++)
//		{
//			cin >> arr[i];
//			if (n == 1 && arr[1] == -1)//����һ���������
//			{
//				cnt = 2;
//				sum = 2;
//				break;
//			}
//			if (arr[i] == 0)
//			{
//				sum++;
//				cnt++;
//			}
//			sum += arr[i];
//		}
//
//		if (sum == 0)
//		{
//			cnt++;
//		}
//		
//		printf("%d\n", cnt);
//
//	}
//	return 0;
//}


/*���� DNA�������� ģ��*/
//#include<iostream>   
//#include<unordered_map>
//#include<cstring>
//using namespace std;
/////*test data
//8
//AGTGCTCA
//ATCGATCG
//ans:6
//
//6
//ATCCGT
//GCCTAT
//ans:4
//
//5
//ATCGA
//CTTGA
//ans:4
//*/
//
//const int N = 1e3 + 10;
//string arr1;
//string arr2;
//int n;
//bool st[N] = { 0 };//���ڲ������ģ����Ǽ�¼Ϊ1
//int cnt = 0;
//
//bool check1(int x)//�Ǽ������
//{
//	if (arr1[x] == 'A' && arr2[x] != 'T')return 0;
//	else if (arr1[x] == 'T' && arr2[x] != 'A')return 0;
//	else if (arr1[x] == 'G' && arr2[x] != 'C')return 0;
//	else if (arr1[x] == 'C' && arr2[x] != 'G')return 0;
//	return 1;
//}
//
//char check2(char x)//��Ӧ�ļ��
//{
//	if (x == 'A') return 'T';
//	else if (x == 'T') return 'A';
//	else if (x == 'G') return 'C';
//	else if (x == 'C') return 'G';
//	return -1;
//}
//
//bool myswap(int i)
//{
//	for (int j = 0; j < n; j++)
//	{
//		if (j == i) continue;
//
//		if (!st[j] && arr1[i] == check2(arr2[j]) && arr2[i] == check2(arr1[j]) )
//		{
//			st[i] = 1;
//			st[j] = 1;
//			cnt++;
//			swap(arr2[i], arr2[j]);
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	scanf("%d", &n);
//	cin >> arr1;
//	cin >> arr2;
//	for (int i = 0; i < n; i++)
//	{
//		if (st[i]) continue;
//		if (!check1(i))//�ж��Ƿ���ͬ
//		{
//			bool is = myswap(i);
//
//			if(!is)
//			{
//				arr2[i] = check2(arr2[i]);
//				st[i] = 1;
//				cnt++;
//			}
//		}
//	}
//	printf("%d\n", cnt);
//
//	return 0;
//}


/*���� �޾���ʯͷ ģ��*/
////1 2 3 4
////1+1=2;  2+2=4; 4+4=8; 3;
////������ǰ׺��
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 1e5+10;
//int n;
//int fix[N];
//
//int my_find(int x)
//{
//	int l = 0, r = 1e5 + 1;
//	while (l + 1 < r)
//	{
//		int mid = (l + r) / 2;
//		if (fix[mid] > x) r = mid;
//		else l = mid;
//	}
//	if (fix[r] == x)return r;
//	else if (fix[l] == x)return l;
//	else return -1;
//}
//
//int to_x(int x)//����x
//{
//	int sum = 0;
//	while (x)
//	{
//		sum += x % 10;
//		x /= 10;
//	}
//	return sum;
//}
//
//int main()
//{
//	fix[0] = 1;
//	for (int i = 1; i <= (int)1e5; i++)//��1e5���Ҿͱ�n�ķ�Χ���ˣ������Ŀ��Կ����
//	{
//		fix[i] = fix[i - 1] + to_x(fix[i - 1]); //1 + 1  2 + 2  4 + 4  8 + 8    
//	}
//	int t;
//	cin >> t;
//	while(t--)
//	{
//		fix[0] = 0;
//		cin >> n;
//		int res = my_find(n);//�ö�����
//		printf("%d\n", res);
//	}
//	return 0;
//}


/*D.string to double*/
//#include<iostream>
//#include<cstring>
//double strToDouble(char s[]) {
//
//	double a = 0, d = 0;
//	int k = 0, n = strlen(s);
//	for (int i = 0; i < n; i++) {
//
//		if ((s[i] >= 48) && (s[i] <= 57)) {
//
//			d = 10 * d + ((double)s[i] - '0');
//		}
//		else if (s[i] == '.') {
//			k = i;
//			break;
//		}
//
//	}for (; n - 1 > k; n--) {
//		if ((s[n - 1] >= 48) && (s[n - 1] <= 57)) {
//			a = 0.1 * a + ((double)s[n - 1] - '0');
//		}
//	}
//	a = 0.1 * a;
//	d += a;
//
//
//	if (s[0] == '-') {
//		d = -1 * d;
//	}
//	return d;
//
//}
//int main() {
//	double te = 0;
//	te = te / 0;
//	printf("%g", te);
//	char s[11] = { 0 };
//	while (scanf("%s", &s) != EOF) 
//	{
//		double d = strToDouble(s);
//		printf("%g\n", d);
//	}
//
//	return 0;
//}



/*12.15*/
//#include <stdio.h>
//#include <string.h>
//#define SIZE 10
////�벹��itostr������ʵ��
//void itostr(int num, char str[])
//{
//    while (*str != 0) *str++ = 0;
//    if (num < 0)
//    {
//        num = -num;
//        *str = '-';
//        str++;
//    }
//    if(num) itostr(num/10 ,str);
//    while (*str != 0) str++;
//    if(num) *str = num % 10 + '0';
//    return;
//
//}
//
//int main()
//{
//    int t, num;
//    char str[SIZE];
//    scanf("%d", &t);
//    while (t--)
//    {
//        scanf("%d", &num);
//        itostr(num, str);
//        printf("%s\n", str);
//    }
//}
