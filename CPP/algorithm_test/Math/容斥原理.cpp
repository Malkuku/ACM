#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*NC15079 大水题*/
/*2024.3.29*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 2e5 + 10;
////U - 2 - 5 - 11 -13 + 2^5 + 2^11 + 2^13 + 5^11 + 5^13 + 11^13
////WA：漏了一项
//int main() {
//	ll n;
//	while (cin >> n) {
//		ll sum = n / 2 + n / 5 + n / 11 + n / 13 
//			- n / (2 * 5) - n / (2 * 11) - n / (2 * 13)
//			- n / (5 * 13) - n / (5 * 11) - n / (11 * 13)
//			+ n / (2 * 5 * 11) + n / (2 * 5 * 13) + n/(2*11*13) + n / (5 * 11 * 13)
//			- n / (2 * 5 * 11 * 13);
//		cout << n - sum << "\n";
//	}
//	return 0;
//}

/*NC236191 青蛙*/
/*2024.3.29*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 1e4 + 10;
//ll a[N];
//ll cnt[N];
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		int res = a[i];
//		cnt[0]++;
//		while (res % m != 0) {
//			cnt[res % m]++;
//			res += a[i];
//		}
//	}
//	ll ans = 0;
//	cout << ans << "\n";
//	return 0;
//}
/*2024.3.29 题解（存疑）*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//
//int cnt[100010];//记录待加多少次
//vector<int> v;
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    for (int i = 1; i * i < m;i++)
//    {
//        if (m % i == 0)
//        {
//            v.push_back(i);
//            v.push_back(m / i);
//        }
//    }
//    sort(v.begin(), v.end());
//    int num = v.size();
//    for (int i = 0; i < n;i++)
//    {
//        int x;
//        cin >> x;
//        int gcd = __gcd(m, x);
//        for (int j = 0; j < num;j++)
//        {
//            if (v[j] % gcd == 0)
//                cnt[j] = 1;
//        }
//    }
//    ll ans = 0;
//    for (int i = 0; i < num;i++)
//    {
//        ll count = m / v[i];
//        ans += (0 + (count - 1) * v[i]) * count / 2 * cnt[i];
//        for (int j = i + 1; j < num;j++)
//        {
//            if (v[j] % v[i] == 0)
//                cnt[j] -= cnt[i];
//        }
//    }
//    cout << ans;
//}

/*NC19857 最后的晚餐(dinner)*/