#include<bits/stdc++.h>
using namespace std;
/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m[310];
int s[310];
int dp[310][310]; //dp[i][j] i开头j结尾的一堆石头最小花费
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> m[i];
    for(int i = 1; i <= n; i++){
        s[i] = s[i-1] + m[i];
    }
    memset(dp,0x3f,sizeof dp);
    for(int i = 1; i <= n; i++) dp[i][i] = 0;
    for(int len = 2; len <= n; len++){//枚举区间长度
        for(int i = 1; i <= n - len + 1; i++){
            int j = i + len - 1;//区间终点
            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + s[j] - s[i-1]);
            }
        }
    }
    cout << dp[1][n] << "\n";
    return 0;
}

/**/
// const int N = 2e5+10;
// string s_arr[N];
// int arr[N];
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     while(t--){
//         int n;cin >> n;
//         for(int i = 0; i < n; i++) cin >> arr[i];
//         int m;cin >> m;
//         for(int i = 0; i < m; i++) cin >> s_arr[i];
//         for(int i = 0; i < m; i++){
//             if(s_arr[i].size()!=n){
//                 cout << "No\n";
//                 continue;
//             }
//             map<char,int> mp1;
//             map<int,char> mp2;
//             bool flag = 0;
//             for(int j = 0;j < n; j++){
//                 if(!mp1.count(s_arr[i][j]) && !mp2.count(arr[j])){
//                     mp1[s_arr[i][j]] = arr[j];
//                     mp2[arr[j]] = s_arr[i][j];
//                 }
//                 else{
//                     if(mp1[s_arr[i][j]] != arr[j] || mp2[arr[j]] != s_arr[i][j]){
//                         flag = 1;
//                         break;
//                     }
//                 }
//             }
//             if(flag) {
//                 cout << "No\n";
//             }
//             else cout << "Yes\n";
//         }
//     }
// }

/**/
// int main(){
//     int t;cin >>t;
//     while(t--){
//         int c[30] = { 0 };
//         int n;cin >> n;
//         string s;cin >> s;
//         int maxsize = 0;
//         for(int i = 0; i < n; i++){
//             c[s[i]-'a']++;
//             maxsize = max(c[s[i]-'a'],maxsize);
//         }
//         for(int i = 1; i <= maxsize; i++){
//             for(int j = 0; j < 30; j++){
//                 if(c[j] == i) {
//                     for(int k = 0; k < i; k++){
//                         cout << (char)('a'+j);
//                     }
//                 }
//             }
//         }cout << "\n";
//     }
//}