#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
using namespace std;

/*A DFS����*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;
//int T, n;
//string s;
//int ans1, ans2;
//string q1 = "dfs"; int hh1 = 0, tt1 = 0;
//string q2 = "DFS"; int hh2 = 0, tt2 = 0;
//int main() {
//	cin >> T;
//	while (T--) {
//		ans1 = ans2 = 0;
//		hh1 = hh2 = 0;
//		cin >> n >> s;
//		for (int i = 0; i < n; i++) {
//			if (s[i] == q1[hh1] && hh1 < 3) hh1++;
//			if (s[i] == q2[hh2] && hh2 < 3) hh2++;
//        }
//		if (hh1 == 3) ans1 = 1;
//		if (hh2 == 3) ans2 = 1;
//		printf("%d %d\n", ans2, ans1);
//	}
//	return 0;
//}

/*B �ؼ�*/
/*WA*/
////����ȥ����� ���� 1 1��1 -1��2 0 ����Ҫ3��
////��סһ�� ������=1 ���3��
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;
//int T, n;
//#define PII pair<int,int>
//PII a[] = { {1,1}, {1,-1}, {2,0} };
//const int N = 1e5 + 10;
//PII arr[N];
//int main() {
//	cin >> T;
//	while (T--) {
//		cin >> n;
//		memset(arr, 0, sizeof arr);
//		for (int i = 0; i < n; i++) {
//			int r, c;
//			scanf("%d %d", &r, &c);
//			arr[i] = { r,c };
//		}
//	}
//	return 0;
//}
/*2024.2.4 ��̫��ʲô���ɵ�ģ��(WA)*/ //д����������������Ĵ��� //������ //������
////���У�1��-1������2��0������1��1������ֻ��Ҫ������
////�������Ĳ��ô���
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<algorithm>
//using namespace std;
//int T, n;
//#define ll long long
//#define PII pair<int,int>
//const int N = 1e5 + 10;
//PII arr[N];
////Ϊ�˷������򣬽�x,y�滻��
//int main() {
//	scanf("%d", &T);
//	while (T--) {
//		scanf("%d", &n);
//		int r, c;
//		for (int i = 0; i < n; i++) {
//			scanf("%d %d", &r, &c);
//			arr[i] = { c,r };
//		}
//		sort(arr, arr + n);
//		bool r1 = 0, r2 = 0, l1 = 0, l2 = 0;//1 ��סһ�� 2 ��ס����
//		bool s1 = 0, s2 = 0, s3 = 0;//��¼�����ĸ���
//		int ans = 3;
//		for (int i = 0; i < n; i++) {
//			int x = arr[i].second;
//			int y = arr[i].first;
//			if ((x == 2 && y == 0)) s1 = 1;
//			if (x == 1 && y == -1) s2 = 1;
//			if (x == 1 && y == 1)s3 = 1;
//			if (y < 0) {
//				l1 = 1;
//				for (int j = i; j < n && j < i + 4; j++) {
//					int xx = arr[j].second;
//					int yy = arr[j].first;
//					if (x + xx == 3) {
//						if(abs(y - yy) <= 1) l2 = 1;//�ų�0��
//					}
//				}
//			}
//			if (y >= 0) {
//				r1 = 1;
//				for (int j = i; j < n && j < i + 4; j++) {
//					int xx = arr[j].second;
//					int yy = arr[j].first;
//					if (x + xx == 3) {
//						if (abs(y - yy) <= 1) r2 = 1;
//					}
//				}
//			}
//		}
//		if (r2){
//			ans -= 2;
//			if (s2 && s1) ans--;
//		}
//		if (l2) {
//			ans -= 2;
//			if (s3 && s1)ans--;
//		}
//		if (s2) {
//			ans--;
//		}
//		if (s3) {
//			ans--;
//		}
//		if (s1) ans--;
//		if (ans < 0) printf("%d\n", 0);
//		else printf("%d\n", ans);
//	}
//	return 0;
//}

/*C ���ַ���*/
/*WA/TLE*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;
//#define ll long long
//int n, Q;
//ll tc;
//const int N = 1e6 + 10;
//ll arr[N];
//ll s[N];
//ll sc[N];
//ll st[N];
//int main() {
//	scanf("%lld %lld %lld", &n, &Q, &tc);
//	for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
//	sort(arr, arr + n);
//	s[0] = arr[0];
//	ll sum = s[0];
//	for (int i = 1; i < n; i++) {
//		s[i] = s[i - 1] + arr[i];
//		sum += s[i];
//	}
//	//���������i������Ҫ�ĵȴ�ʱ��
//	//�ܵ�ʱ��仯��sum+=tc*���������n - i)
//	sc[0] = tc;
//	st[0] = sum + tc * (n);
//	ll msum = st[0];
//	for (int i = 1; i <= n; i++) {
//		sc[i] = s[i-1] + tc;
//		st[i] = sum + tc * (n - i);
//		//msum = min(msum, st[i]);
//	}
//	while (Q--) {
//		ll M;scanf("%lld", &M);
//		bool out = 0;
//		for (int i = 0; i <= n; i++) {
//			if (st[i] - sum <= M) {
//				printf("%lld\n", sc[i]);
//				break;
//			}
//		}
//	}
//	return 0;
//}
/*2024.2.4 ǰ׺��+��ѧ����*/
//���嵽ĳ�˺��棬��֮�����ʱ�䶼�Ƴ�tc���ܲ����������tc*���ڼ������ m = tc*des
//���ڸ�������������M����ôM/tc �������ڼ�����������
//WA: û�����des�����壬�ж���������
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//#define ll long long
//int n, Q, tc;
//const int N = 1e6 + 10;
//ll arr[N];
//ll s[N];
//int main() {
//	cin >> n >> Q >> tc;
//	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
//	sort(arr, arr + n);
//	s[0] = arr[0];
//	for (int i = 1; i < n; i++) s[i] = s[i - 1] + arr[i];
//	while (Q--) {
//		ll m; cin >> m;
//		ll des = m / tc;
//		ll ans;
//		if (n - des - 1 >= 0) ans = s[n - des - 1] + tc;
//		else ans = tc;
//		printf("%lld\n", ans);
//	}
//}

/*D ����ɼ�*/
/*WA*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;

/*E ��������Ҫ������̰��*/
/*WA*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;
////��1��һֱӮ�������ȶ���䣬�ٵ�Ӯ��һ�����ƽ / һ��һӮ
/*2024.2.4 ��ƭ�� ��dfs*/ //�����ݷ�Χ�³�����
////���ǻ��治֪����ô��
////ö���������
////WA: ����Сֵ��ɱȴ�ֵ
////WA��ans�ĳ�ʼ������
////WA: ans�ĳ�ʼ��λ�ã�res�����ļ��㶼����
////WA: ��������Ӧ���ڱ���������
////WA: md �������ſ�ʼ���������ʼ����ʱ���Ŵ���
//#include<iostream>
//#include<cstring>
//#include<string>
//using namespace std;
//int T, n, m;
////�����ǿ������ȵ�
//int arr[20];
//int b[20];int c[20];
//int dx[] = { 0,1,3 };
//int dy[] = { 3,1,0 };
//int ans = 0;
//
////int mySort() {
////	int res = 1;
////	for (int i = 2; i <= n; i++) {
////		if (arr[i] > arr[1]) res++;
////	}
////	//for (int j = 1; j <= n; j++) {
////	//	printf("%d ", arr[j]);
////	//}printf("\n");
////	return res;
////}
//
//void dfs(int x) {
//	if (x > m)
//	{
//		int cnt = 1;
//		for (int i = 2; i <= n; i++)
//		{
//			if (arr[i] > arr[1])
//				cnt++;
//		}
//		ans = min(ans, cnt);
//		return;
//	}
//	for (int i = 0; i < 3; i++) {
//		arr[b[x]] += dx[i];
//		arr[c[x]] += dy[i];
//		dfs(x + 1);
//		arr[b[x]] -= dx[i];
//		arr[c[x]] -= dy[i];
//	}
//}
//
//int main() {
//	scanf("%d", &T);
//	while (T--) {
//		scanf("%d %d", &n, &m);
//		for (int i = 1; i <= n; i++) {
//			scanf("%d", &arr[i]);
//		}
//		ans = n;
//		for (int i = 1; i <= m; i++) {
//			scanf("%d %d", &b[i], &c[i]);
//		}
//		dfs(1);
//		printf("%d\n", ans);
//	}
//	return 0;
//}

/*F ������*/ //�ڶ���˹������ //�������������

/*G why������*/
/*AC*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;
//int T, n, m;
//const int N = 1e5 + 10;
//#define ll long long 
//map<int, ll> g;
//int s[N];
//int main() {
//	cin >> T;
//	while (T--) {
//		scanf("%d %d",&n,&m);
//		g.clear();
//		memset(s, 0, sizeof s);
//		for (int i = 0; i < n; i++) {
//			int a, b;
//			scanf("%d %d", &a, &b);
//			s[i] = a;
//			g[a] += b;
//		}
//		sort(s, s + n);
//		for (int i = 1; i < n; i++) {
//			if (s[i] > s[i - 1])g[s[i]] += g[s[i - 1]];
//		}
//		ll ans = m;
//		for (auto t : g) {
//			if (t.second + m >= t.first) ans = max(ans, t.second + m);
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}

/*H 01����������bit*/
//���ƴӣ�����ʼ
/*2024.2.4 ��� ������˼��һbit���������*/
//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//#define N 1000005
//const ll mod=998244353;
//ll t,n,m;
//ll w[N],v[N];
//
//int main()
//{
//    scanf("%lld",&t);
//    while(t--){
//        ll maxx=0;
//        scanf("%lld%lld",&n,&m);
//        for(int i=1;i<=n;i++)scanf("%lld%lld",&v[i],&w[i]);
//        for(int p=1;p<=m;p=(p<<1)){//ö��bit 1 10 100 ... ��m�����λ��ͬ
//            if((m|p)>m)continue;//���������� |m ��m�󣬲�ȡ����ȡ��m��ÿλ1bit��
//            ll mm=0;
//            //printf("%lld\n",p);
//            for(int i=1;i<=n;i++){//��pС��������ϣ���p���ȡw���Ӽ���//== p����
//                if(w[i]<p)mm+=v[i]; //��pС����pͬλ��bit�϶�Ϊ0
//                if(w[i]>p&&w[i]<=m){ //��p��ģ�����p=100�� w=101 p|w=101�������>w������𣿣�//p=100��w=1010 
//                                     //���һ������m����Ȼ����m���Ӽ�
//                    if(((w[i]/p*p)|m)==m&&(w[i]|p)>w[i])mm+=v[i]; //��������/p*p����//
//                                                                   //w|p>w˵��p����w���Ӽ� //��w�е�ĳλbit mû�У�w|m>m
//                }
//            }
//            maxx=max(maxx,mm);
//        }
//        ll mm=0;
//        for(int i=1;i<=n;i++)if((w[i]|m)==m)mm+=v[i]; //w������m��bit���Ӽ���
//        maxx=max(maxx,mm);
//        printf("%lld\n",maxx);
//    }
//}

/*I It's bertrand paradox. Again!*/ //����ѧϰ ������ ������

/*J ����֮����*/

/*M ţ���Ϸ۲�֪��������*/
/*AC*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;
//
//int T, n;
//int main() {
//	scanf("%d", &T);
//	while (T--) {
//		scanf("%d", &n);
//		if (n % 6) printf("%d\n", (n / 6) * 2);
//		else printf("%d\n", n / 6);
//		
//	}
//	return 0;
//}

/*L Ҫ�й� �����Σ�*/
/*2024.2.4 ������*/ //�ü��εķ�������
////�� x0y����������ص����
////WA: ���죬û�� \n
//#include<iostream>
//using namespace std;
//int T;
//int main() {
//	cin >> T;
//	int c, d, h, w;
//	while (T--) {
//		cin >> c >> d >> h >> w;
//		printf("%.6f",3*w*c);
//	}
//	return 0;
//}