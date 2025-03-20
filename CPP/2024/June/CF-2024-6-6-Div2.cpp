#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*A. Guess the Maximum*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// const int N = 5e4+10;
// int a[N];
// int main(){
//     int t;cin >> t;
//     while(t--){
//         int n;cin >> n;
//         for(int i = 0; i < n; i++) cin >> a[i];
//         int maxn = 1e9+10;
//         for(int i = 0; i < n-1; i++){
//             int b = max(a[i],a[i+1]);
//             maxn = min(b,maxn);
//         }
//         cout << maxn-1 << "\n";
//     }
// }

/*B. XOR Sequences*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// const int N = 1e5+10;
// //int a[N],b[N];
// int main(){
//     ios::sync_with_stdio(0);
//     int t;cin >> t;
//     while(t--){
//         ll x, y;
//         cin >> x >> y;
//         for (int i = 0; i <= 32; i++)
//         {
//             if ((x & 1) ^ (y & 1))
//             {
//                 cout << (1 << i) << "\n";
//                 break;
//             }
//             x >>= 1,y >>= 1;
//         }
//     }
//     return 0;
// }

/*C. Earning on Bets*/
/*2024.6.8 题解*/ //数学，二分
// //ki*xi > s
// //xi >= s/ki + 1; //化出等号很重要
// //xi和 == s >= s/ki+1和
// //问题：s为什么满足线性? s越大,可供分配的数量就越多，更有可能完成分配
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// const int N = 1e5+10;
// int k[N];
// int main(){
//     ios::sync_with_stdio(0);
//     int t;cin >> t;
//     while(t--){
//         int n;cin >> n;
//         for(int i = 0; i < n; i++){
//             cin >> k[i];
//         }
//         ll l = n,r = 1e12;
//         while(l <= r){
//             ll mid = (l+r) >> 1;
//             ll sum = 0;
//             for(int i = 0; i < n; i++) sum += (mid/k[i] + 1);
//             if(mid > sum){
//                 r = mid - 1;
//             } 
//             else l = mid + 1;
//         }
//         if(r < n || r > 1e9*n) {
//             cout << -1 << "\n";
//             continue;
//         }
//         for(int i = 0; i < n; i++){
//             cout << r/k[i]+1 << " ";
//         }cout << "\n";
//     }
//     return 0;
// }


