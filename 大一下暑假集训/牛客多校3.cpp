#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*A Bridging the Gap 2*/ //数学思维
/*2024.7.26*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll L,R;
int n;const int N = 5e5+10;
ll h[N];
int main(){
    cin >> n >> L >> R;
    ll T = (n-R+R-L+1)/(R-L); //总趟数(要向上取整！)
    ll sum = (1.0*(n-R)/(R-L))*L; //总打工次数
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> h[i];
        ans += min(T,(h[i]-1)/2);
    }
    if(ans >= sum) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

/*B Crash Test*/ //斐蜀定理
/*2024.7.26*/ //由特殊到整体
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll n,d;
// const int N = 1000;
// ll h[N];
// //个例最佳 d%h 或 h - d % h
// int main(){
//     cin >> n >> d;
//     ll hh = 0;
//     for(int i = 0; i < n; i++){
//         cin >> h[i];
//         hh = __gcd(hh,h[i]);
//     }
//     cout << min(d%hh,hh - d%hh);
//     return 0;
// }