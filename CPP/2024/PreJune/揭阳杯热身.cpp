/*
#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
*/

/*#A. Tianyi and her contest */
// #include <bits/stdc++.h>
// using namespace std;
// #define PII pair<int, int>
// #define ll long long
//
// int main(){
//     string s;
//     getline(cin,s,'\n');
//     for (int i = 0; i < 3; i++){
//         cout << s << "\n";
//     }
//     return 0;
// }

/*#B. 01超级背包 WA*/
//#include <bits/stdc++.h>
// using namespace std;
// #define PII pair<int, int>
// #define ll long long
// ll n, k;
// ll arr[50];
// bool st[50];
// ll ans;
// void dfs(int s,ll x){
//     if(s > n){
//         return;
//     }
//     if(ans == 0)
//        return;
//     for (int i = 1; i <= n; i++){
//         if(st[i])
//             continue;
//         st[i] = 1;
//         x += arr[i];
//         ans = min(ans, abs(x - k));
//         //cout << x << " " << n << " " << ans << " "<< abs(x-k) << "\n";
//         dfs(s + 1, x);
//         st[i] = 0;
//         x -= arr[i];
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n >> k;
//     for (int i = 1; i <= n; i++){
//         cin >> arr[i];
//     }
//     sort(arr + 1, arr + n + 1);
//     ans = min(abs(arr[1] - k),abs(arr[n] - k));
//     if(k <= arr[1] || k >= arr[n]){
//         cout << ans << "\n";
//     }
//     else{
//         dfs(1, 0);
//         ans = min(ans, abs(k));
//         cout << ans << "\n";
//     }
//     return 0;
// }

/* #D. 重复的字符串 WA */
// #include <bits/stdc++.h>
// using namespace std;
// #define PII pair<int, int>
// #define ll long long
// map<string, bool> g;
// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         g.clear();
//         string s;
//         cin >> s;
//         if(s.size() < 5){
//             int ans = s[0] == s[3] ? 1 : 2;
//             cout << ans << "\n";
//             continue;
//         }
//         for (int i = 0; i <= s.size() - 5; i++){
//             string s1 = s.substr(i,5);
//             g[s1] = 1;
//         }
//         string s1;
//         s1 = s1 + s[3] + s[0] + s[1] + s[2] + s[4];
//         g[s1] = 1;
//         //cout << s1 << "\n";
//         int len = s.size();
//         s1.clear();
//         s1 = s1 + s[len - 5] + s[len - 1] + s[len - 2] + s[len - 3] + s[len - 4];
//         //cout << s1 << "\n";
//         g[s1] = 1;
//         for(auto t : g){
//             cout << t.first << " ";
//         }
//         cout << g.size() << "\n";
//     }
// }
/* 对于s[i] == s[i+3] 无论取谁结果都一样 */
// #include <bits/stdc++.h>
// using namespace std;
// #define PII pair<int, int>
// #define ll long long
// int main(){
//     int t;
//     cin >> t;
//     while (t--) {
//         string s;
//         cin >> s;
//         int ans = s.size() - 2;
//         for (int i = 0; i < s.size()-3; i++) {
//             if (s[i] == s[i + 3]) ans--;
//         }
//         cout << ans << "\n";
//     }
//     return 0;
// }

/* #F. 小鸡农场 */
// #include <bits/stdc++.h>
// using namespace std;
// #define PII pair<int, int>
// #define ll long long
// int n, m;
// const int N = 5010;
// ll arr[N];
// ll w[N];
// ll find(ll x){
//     ll sum = 0;
//     for (int i = 2; i <= x / i; i++){
//         if(i*i == x)
//             sum += i;
//         else{
//             if(x % i == 0){
//                 sum += i;
//                 sum += x / i;
//             }
//         }
//     }
//     sum += 1 + x;
//     return sum;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n >> m;
//     for (int i = 0; i < n; i++){
//         cin >> arr[i];
//         w[i] = find(arr[i]);
//     }
//     ll ans = 0;
//     int maxn = 1e7;
//     sort(w, w + n);
//     //for(auto i : w)
//     //    cout << i << " ";
//     for (int i = 0; i < n; i++){
//         if(w[i] < maxn && m){
//             ans += maxn;
//             m--;
//         }
//         else
//             ans += w[i];
//     }
//     cout << ans << "\n";
//     return 0;
// }

/*#G. 血压高的天依 */
 //#include <bits/stdc++.h>
 //using namespace std;
 //#define PII pair<int, int>
 //#define ll long long
 //int s[6] = {11, 51, 19, 81, 100, 85};
 //int arr[1100];
 //int main(){
 //    int m;
 //    cin >> m;
 //    for (int i = 0; i < m;i++){
 //        cin >> arr[i];
 //    }
 //    for (int i = 0; i < m; i++){
 //        int res = 0;
 //        for (int j = 0; j < 6; j++){
 //            if(arr[i] <= s[j])
 //                res++;
 //        }
 //        cout << res << "\n";
 //    }
 //    return 0;
 //}

/* #H. 天依的干饭路 */ //忘记填平沟壑之后的处理
//#include <bits/stdc++.h>
//using namespace std;
//#define PII pair<int, int>
//#define ll long long
//const int N = 1010;
//vector<ll> arr;
//ll b, n;
//map<ll, int> g;
//int main(){
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        ll a;
//        cin >> a;
//        arr.push_back(a);
//        g[arr[i]]++;
//    }
//    cin >> b;
//    sort(arr.begin(), arr.end());
//    //arr.push_back(arr[arr.size() - 1]);
//    arr.erase(unique(arr.begin(), arr.end()),arr.end());
//    //cout << arr.size() << " ";
//    ll shu = 0;
//    ll ans = arr[0];
//    bool flag = 1;
//    for (int i = 0; i < arr.size()-1; i++){
//        ll cha = arr[i + 1] - arr[i];
//        shu += g[arr[i]];
//        ll x = shu * cha;
//        if(x <= b){
//            ans = arr[i + 1];
//            b -= x;
//        }
//        else{
//            ll cnt = b / shu;
//            b -= cnt * shu;
//            ans += cnt;
//            break;
//        }
//    }
//    //填平沟壑后
//    ll cnt = b / n;
//    ans += cnt;
//    
//    cout << ans*n << "\n";
//    return 0;
//}

/* #I. 斐波那契游戏 */
//#include<iostream>
//using namespace std;
//#define ll long long
//const int N = 1e5 + 7;
//int arr[N];
//int s[N];
//int f[N];
//int main() {
//	ios::sync_with_stdio(0);
//	const int mod = 1e9 + 7;
//	f[1] = 0;
//	f[2] = 1;
//	for (int i = 3; i < N; i++) {
//		f[i] = (0LL + f[i - 1] + f[i - 2]) % mod;
//	}
//	s[1] = f[1];
//	for (int i = 2; i < N; i++) {
//		s[i] = (0LL + s[i - 1] + f[i]) % mod;
//	}
//	int t; cin >> t;
//	while (t--) {
//		ll a, b, x;
//		cin >> a >> b >> x;
//		ll ans = a * (s[x - 1]+1) % mod + b * (s[x]) % mod;
//		ans %= mod;
//		cout << ans << "\n";
//	}
//	return 0;
//}

/* #J. 璃塘的超级计算器 WA*/ //高精度//用double读数
//#include<iostream>
//#include<cmath>
//using namespace std;
//int main() {
//	long double x;cin >> x;
//	long double ans = 1.0 / (sqrtl(x+1) + sqrtl(x));
//	int cnt = 0;
//	while (ans < 1) {
//		ans *= 10;
//		cnt++;
//	}
//	cnt = -cnt;
//	int anss = ans;
//	cout << anss << "e" << cnt << "\n";
//	return 0;
//}
/*题解*/
//#include <bits/stdc++.h>
//using namespace std;
//int main() {
//	long double x;
//	long double i = 1, t = 1, s = 10;
//	cin >> x;
//	long double a = 1.0 / (sqrt(x + 1) + sqrt(x));
//	//a = t / a;
//
//	while (i) {
//		if (a > 1) {
//			break;
//		}
//		else {
//			a *= s;
//			i++;
//		}
//	}
//	a = a / t;
//	int j = a;
//	cout << j << "e-" << i - 1 << endl;
//	return 0;
//}

/* #K. 快逃 */
//#include<iostream>
//using namespace std;
//int main() {
//	cout << 28 << "\n";
//	return 0;
//}

/* #M. 暮色大师喵赛克 */
//#include<bits/stdc++.h>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//
//int main() {
//	int n; cin >> n;
//	int a[1010];
//	for (int i = 0; i < n; i++) {
//		int x;
//		cin >> x;
//		a[i] = abs(x);
//	}
//	double combo = 0;
//	double maxCB = 0;
//	double fen = 0;
//	for (int i = 0; i < n; i++) {
//		combo++;
//		if (a[i] <= 1) {
//			fen += 115;
//		}
//		else if (a[i] <= 45) {
//			fen += 105;
//		}
//		else if (a[i] <= 90) {
//			fen += 100;
//		}
//		else if (a[i] <= 150) {
//			fen += 75;
//		}
//		else if (a[i] <= 250) {
//			fen += 40;
//		}
//		else {
//			combo = 0;
//		}
//		maxCB = max(maxCB, combo);
//	}
//	double ans = maxCB*100 / n / 10 + fen / n;
//	printf("%.2f", ans);
//	return 0;
//}

/* #E. 捉虫记 */
////ans k - p
//#include<iostream>
//#include<cstring>
//using namespace std;
//#define ll long long
//const int N = 5e5 + 10;
//ll n, p, k;
//int s[N];
//int arr[N] = { 0 };
//int tmp[N] = { 0 };
//pair<int, int> node[N];
//bool find(int x) {
//	memset(tmp, 0, sizeof tmp);
//	for (int i = k; i <= x; i++) {
//		auto t = node[i];
//		tmp[t.first] ++;
//		tmp[t.second + 1] --;
//	}
//	for (int i = 1; i <= n; i++) {
//		s[i] = arr[i] + tmp[i] + s[i-1];
//		if (s[i] >= k) return 0; //大了
//	}
//	return 1; //小了
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> p;
//	for (int i = 1; i <= p; i++) {
//		int l, r;
//		cin >> l >> r;
//		node[i] = { l,r };
//	}
//	cin >> k;
//	if (k-1 >= p) cout << -1 << "\n";
//	else {
//		for (int i = 1; i <= k - 1; i++) {
//			auto t = node[i];
//			arr[t.first] ++;
//			arr[t.second + 1] --;
//		}
//		ll l = k;
//		ll r = p;
//		while (l <= r) {
//			ll mid = (l + r) >> 1;
//			if (find(mid) == 0) {
//				r = mid - 1;
//			}
//			else {
//				l = mid + 1;
//			}
//		}
//		if (l > p) cout << -1 << "\n";
//		else cout << l << "\n";
//	}
//	return 0;
//}
/*test1  
10 7
1 4
3 6
6 10
1 10
1 3
5 7
7 10
5
*/
/*test2
10 7
1 1
1 1
1 1
1 10
1 3
1 1
1 1
4
*/
/*test3
10 7
1 1
1 1
1 1
1 10
1 3
1 1
1 1
8
*/



