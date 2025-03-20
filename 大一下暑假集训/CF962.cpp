#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*A. Legs*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int main(){
//     int t;cin >> t;
//     while(t--){
//         int n;cin >> n;
//         int a = n/4;
//         int b = (n%4)/2;
//         cout << a+b << "\n";
//     }
//     return 0;
// }

/*B. Scale*/
//#include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1010;
// char g[N][N];
// int main(){
//     ios::sync_with_stdio(0);
//     int t;cin >> t;
//     while(t--){
//         int n,k;
//         cin >> n >> k;
//         for(int i = 1; i <= n; i++){
//             for(int j = 1; j <= n; j++){
//                 cin >> g[i][j];
//             }
//         }
//         for(int i = 1; i <= n; i+=k){
//             for(int j = 1; j <= n; j+=k){
//                 cout << g[i][j];
//             }cout << "\n";
//         }
//     }
//     return 0;
// }

/*C. Sort*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+10;
// int sa[N]['z' - 'a'+3];
// int sb[N]['z' - 'a'+3];
// int main(){
//     ios::sync_with_stdio(0);
//     int t;cin >> t;
//     while(t--){
//         int n,q;cin >> n >> q;
//         string a,b;
//         cin >> a >> b;
//         a = " " + a;
//         b = " " + b;
//         for(int i = 1; i <= n; i++){
//             for(int j = 0; j <= 'z' - 'a'; j++){
//                 sa[i][j] = sa[i - 1][j];
//                 sb[i][j] = sb[i - 1][j];
//             }
//             sa[i][a[i] - 'a']++;
//             sb[i][b[i] - 'a']++;
//         }
//         while(q--){
//             int l,r;cin >> l >> r;
//             int res = 0;
//             for(int i = 0; i <= 'z' - 'a'; i++){
//                 res += abs((sa[r][i]-sa[l-1][i]) - (sb[r][i] - sb[l-1][i]));
//             }
//             cout << res / 2 << "\n";
//         }
//     }
//     return 0;
// }

/*D. Fun*/
/*2024.8.7 题解*/ //纸老虎-- 最大枚举次数可以用调和级数证明
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int main(){
//     int t;cin >> t;
//     while(t--){
//         int n,x;cin >> n >> x;
//         ll ans = 0;
//         for(int a = 1; a <= n; a++){ //用条件控制枚举次数
//             for(int b = 1; b*a <= n && a + b <= x; b++){ //由b*a<=n 得枚举次数是调和级数
//                 int res = (n - a*b) / (a+b); //c的最大枚举次数
//                 res = min(res,(x - a - b));
//                 ans += res;
//             }
//         }
//         cout << ans << "\n";
//     }
//     return 0;
// }
