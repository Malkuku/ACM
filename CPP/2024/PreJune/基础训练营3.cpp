#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#define ll long long
using namespace std;
#define PII pair<int,int>
/*A ��������Ŀ��è������ˮĸ���¹���Ϻ */
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>;
//int T;
//int main() {
//	cin >> T;
//	while (T--) {
//		string s1, s2;
//		cin >> s1 >> s2;
//		char ch1 = tolower(s1[0]);
//		char ch2 = tolower(s2[0]);
//		if (ch1 == ch2) printf("Yes\n");
//		else printf("No\n");
//	}
//	return 0;
//}

/*B ���˵������ִ�*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
/*2024.2.17 �����ۻ���*/
////(���Ų���)�ǲ����۵Ĺؼ���
////����ֲ���ѡ�������������һ��һż����ϣ��ܳ�Ϊż����
////��ô������Ӯ����ʼ���Ⱦͱ���������
////�����׿����ӵĽ��˼�����ս���ǲ����۵�˼·
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
//int t, n;
//int a;
//int main() {
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		for (int i = 0; i < n; i++)cin >> a;
//		if (n % 2) printf("qcjj\n");
//		else printf("zn\n");
//	}
//	return 0;
//}
/*NC223888 ��ɫ����ɫ (������)*/
////���������־��жԳ����ʵ���Ŀ�У��Գ��߷����������Ų���
////WA:д���˻�ʤ����������ʱֻ����n
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
//int main() {
//	ll n, m;
//	cin >> n >> m;
//	//printf("%lld\n", (n * m) % 2);
//	if ((n * m) % 2 == 0) printf("yukari\n");
//	else printf("akai\n");
//	return 0;
//}

/*C ���˵�ǰ׺����׺������*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>

///*G ���˵ıȽϺ���(easy version) (WA)*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
//
////ì�ܣ�1 2 1, 2 1 1
////��ì�ܣ�1 2 1,2 1 0
////���ʱ��1 1 0
//int T, n, x, y, z;
//int g[4][4];
//
//int main() {
//	cin >> T;
//	while (T--) {
//		memset(g, -1, sizeof g);
//		bool ans = 1;
//		scanf("%d", &n);
//		scanf("%d %d %d", &x, &y, &z);
//		if (x == y && z == 1) ans = 0;
//		if (x < y) {
//			g[1][2] = z;
//			g[1][3] = z;
//			g[2][3] = z;
//		}
//		else if (x > y) {
//			g[2][1] = z;
//			g[3][1] = z;
//			g[3][2] = z;
//		}
//
//		for (int i = 1; i < n; i++) {
//			scanf("%d %d %d", &x, &y, &z);
//			if (x == y && z == 1) ans = 0;
//			if (g[x][y] == -1) g[x][y] = z;
//			if (g[y][x] == z) ans = 0;
//			if (g[x][y] != z) ans = 0;
//		}
//		if (ans) printf("Yes\n");
//		else printf("No\n");
//	}
//	return 0;
//}

/*L ���˵�36����(easy version) */
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
//int n;
//const int N = 1e5 + 10;
//ll arr[N];
////ll s[N];
//ll head(ll x) {
//	ll tmp = x;
//	while (tmp) {
//		tmp /= 10;
//		x *= 10;
//	}
//	return x;
//}
//
//int main() {
//	cin >> n;
//	//for (int i = 0; i < 20; i++) s[i] = 36 * (i + 1);
//	if (n < 2) {
//		printf("%d\n", 0);
//		return 0;
//	}
//	for (int i = 0; i < n; i++) {
//		scanf("%lld", &arr[i]);
//	}
//	//sort(arr, arr + n);
//	int res = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			ll sum = head(arr[i]) + arr[j];
//			if (sum % 36 == 0)res++;
//		}
//	}
//	printf("%d\n", res);
//	return 0;
//}

/*M ���˵�36����(normal version)*/
/*2024.2.17 ö��+��ѧ (WA)*/ //�Ʋ���a+b��ʱ�򲻶�
////36������һ�����ԣ����۶���λ10000 % 36 == 28
////������ǿ��Ժ�������λ��ֱ��������%36������
////��a+b��% 36 == a%36 + b%36
////��a%36*28��%36 + b%36
////WA: ����С���ݰ汾�ܹ�
////��λ����b��Ӱ�쵽a
////WA:���ǲ��ԣ������ø�����
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
//const int N = 1e5 + 10;
//ll arr[N];
//ll cnt1[37]; //������������i�����ĸ���
//ll cnt2[37];
//int main() {
//	//printf("%d\n", 70 % 36);
//	int n;cin >> n;
//	ll ans = 0;
//	for (int i = 0; i < n; i++) cin >> arr[i];
//	for (int i = 0; i < n; i++) {
//		if (arr[i] > 9)cnt1[arr[i] % 36]++;
//		else cnt2[arr[i] % 36]++;
//	}
//	//ö��a��bƴ��
//	for (int i = 0; i < n; i++) {
//		if (arr[i] % 36 == 0) {
//			ans += cnt1[0];
//		}
//		else if (arr[i] > 9LL) {//��λ�������
//			ll a = (arr[i] % 36 * 28LL) % 36;
//			ans += cnt1[36 - a];
//			ans += cnt2[36 - a];
//		}
//		else {
//			ll a1 = (arr[i] % 36 * 28LL) % 36;
//			ll a2 = (arr[i] * 10LL) % 36;
//			ans += cnt1[36 - a1];
//			ans += cnt2[36 - a2];
//		}
//	}
//	//ȥ���Լ�ƴ�Լ������
//	for (int i = 0; i < n; i++) {
//		if (arr[i] % 36 == 0) {
//			ans--;
//		}
//		else if (arr[i] > 9) {//��λ�������	
//			ll a = (arr[i] % 36 * 28LL) % 36;
//			if ((a + (arr[i] % 36)) == 36) ans--;
//		}
//		else {
//			ll a = (arr[i] * 10LL) % 36;
//			if ((a + (arr[i] % 36)) == 36) ans--;
//		}
//	}
//	printf("%lld\n", ans);
//	return 0;
//}
/*2024.2.18 �ֶ�ö��+��ѧ*/
////�����ĵ���ѧԭ����ͬ
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
//const int N = 1e5 + 10;
//ll a[N];
//ll sum[N] = { 0 };
//int n;
//ll ans = 0;
//void slo() {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < 36; j++) {
//			if (a[i] < 10LL) {
//				if (((j * 10LL) % 36 + a[i]) % 36 == 0) ans += sum[j];
//			}
//			else {
//				if (((j * 28LL) % 36 + a[i]) % 36 == 0) ans += sum[j];
//			}
//		}
//		sum[a[i] % 36]++;
//	}
//}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) cin >> a[i];
// 	slo();
//	reverse(a, a + n);
//	memset(sum, 0, sizeof sum);
//	slo();
//	printf("%lld\n", ans);
//	return 0;
//}

/*D chino's bubble sort and maximum subarray sum(easy version)*/
//WA:printf("%lld");//����ҪС�İ�
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
////dp[i] //��iΪ��β����Ӷκ�
////dp[i][0] dp[i][1] //����k�Σ�
//int n, k;
//const int N = 2e3 + 10;
//ll arr[N];
//ll dp[N][2];
//ll tp[N][2];
//
//int main() {
//	memset(dp, 0, sizeof dp);
//	scanf("%d %d", &n, &k);
//	for (int i = 0; i < n; i++) scanf("%lld\n", &arr[i]);
//	dp[0][0] = arr[0];
//	ll ans = dp[0][0];
//	for (int i = 1; i < n; i++) {
//		if (dp[i - 1][0] < 0) dp[i][0] = arr[i];
//		else dp[i][0] = dp[i - 1][0] + arr[i];
//		ans = max(ans, dp[i][0]);
//	}
//	if (k < 1) {
//		printf("%lld\n", ans);
//		return 0;
//	}
//	//�����ĵ��Ʋ���
//	//if(dp[i][0] < 0) dp[i][1] = dp[i][0] + (Ϊ������ǰһ������dp��);
//	for (int i = 0; i < n-1; i++) {
//		dp[i][1] = dp[i][0] - arr[i] + arr[i + 1];
//		ans = max(ans, dp[i][1]);
//	}
//	memset(tp, 0, sizeof tp); //tp[i] ��iΪ��ͷ�ĺ�
//	tp[n - 1][0] = arr[n - 1];
//	for (int i = n - 2; i >= 0; i--) {
//		if (tp[i + 1][0] < 0) tp[i][0] = arr[i];
//		else tp[i][0] = tp[i + 1][0] + arr[i];
//	}
//	for (int i = n -1; i >= 1; i--) {
//		tp[i][1] = tp[i][0] - arr[i] + arr[i - 1];
//		ans = max(ans, tp[i][1]);
//	}
//
//	printf("%lld\n", ans); //���������
//	return 0;
//}
//
////5 1
////- 10 10 - 1 9 2
