#include<iostream>
using namespace std;
#define ll long long

/*I Fight Against the Monster*/
/*2024.8.7*/ //公式法处理t
// #include<iostream>
// using namespace std;
// #define ll long long
// ll m,k,h;
// bool check(ll x){
//     if(x < m && x < h) return 0; //(x-m)可能产生的负数！ 
//     if(x >= h) return 1;
//     ll t = ((x-m) / (m-k)) + 1; 
//     if(t*k+x >= h) return 1;
//     else return 0;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     int t;cin >> t;
//     while(t--){
//         cin >> m>>k>>h;
//         if(m == k || m >= h){
//             cout << min(h,m) << "\n";
//             continue;
//         }
//         ll l = 0,r = 1e9+10;
//         while(l <= r){
//             ll mid = (l + r) >> 1;
//             if(check(mid)) r = mid - 1;
//             else l = mid + 1;
//         }
//         cout << l << "\n";
//     }
//     return 0;
// }

/*2024.8.7*/ //二分枚举t
// #include<bits/stdc++.h>
// #define int long long
// #define endl '\n'
// using namespace std;
// int m,k,h; 
// int cnt;
// bool check(int x){
// 	int l = 0, r = 1e9+10;
// 	while(l <= r){
// 		int mid = (l + r) >> 1;
// 		if(x - mid*m + mid*k >= m) l = mid + 1;
// 		else r = mid - 1; 
// 	}
// 	int t = r+1;
// 	if(x+t*k >= h) return 1;
// 	else return 0;
// }
// void solve(){
//      cin >> m >> k >> h;
//      if(k == m || h <= m){
//      	cout << min(h,m) << endl;
// 		 return; 
// 	 }
//      int l = 0,r = 1e9 + 10;
// 	 while(l <= r){
// 	 	cnt = 0;
// 	 	int mid = (l + r) >> 1;
// 	 	if(check(mid)) r = mid - 1;
// 	 	else l = mid + 1;
// 	 } 
//      cout << l << endl;
// } 
// signed main(){
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	int t ;
// 	cin >> t;
// 	while(t--) solve();
// 	return 0;
// }