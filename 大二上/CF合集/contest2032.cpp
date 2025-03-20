// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }

/*D. Genokraken*/ //构造
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define flush cout.flush();
const int N = 1e4+10;
int fa[N];
void solve(){
    int n;cin >> n;
    
    //确定第一层
    vector<int> last_fa;
    last_fa.push_back(1);
    fa[1] = 0;
    int cnt = 1;
    while(cnt++){
        flush
            cout << "? " << 1 << " " << 1 + cnt << "\n";  
        flush
        bool ans;cin >> ans;
        if(ans){
            fa[1 + cnt] = 0;
            last_fa.push_back(1+cnt);
        }
        else break;
    }

    //
        
       
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    for(int _  = 1; _ <= t; _++){
        solve();
    }
    return 0;
}


/*C. Trinity*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+10;
// int a[N];
// void solve(){
//     int ans = 1e9+10;
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     sort(a+1,a+1+n);
//     //for(int i = 1; i <= n;i++) cout << a[i] << " " ;
//     //cout << "\n";
//     for(int i = 1; i <= n-1; i++){
//         ll tofind = a[i] + a[i+1];
//         int up = lower_bound(a+1,a+1+n,tofind) - a;
//         int low = lower_bound(a+1,a+1+n,a[i+1]) - a;
//         //cout << "? " << up << " " << low << "\n";
//         if(a[i] != a[i+1]) low--;
//         ans = min(ans,n - (up - low));
//     }
//     ans = max(ans,0);
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }


/*B. Medians*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,k;cin >> n >> k;
//     if(k*2-1 == n){
//         cout << 1 << "\n";
//         cout << 1 << "\n";
//         return;
//     }
//     if(k == 1 || k == n){
//         cout << -1 << "\n";
//         return;
//     }
//     if(k % 2 == 0){
//         cout << 3 << "\n";
//         cout << 1 << " " << k << " " << k+1<<"\n";
//     }
//     else{
//         cout << 5 << "\n";
//         cout << 1 << " " << k-1 << " " << k << " " << k+1 << " "<< k+2<<"\n";
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }


/*A. Circuit*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     int sum1 = 0,sum0 = 0;
//     for(int i = 0; i < 2*n; i++){
//         int x;cin >> x;
//         if(x) sum1++;
//         else sum0++;
//     }
//     int ans1 = min(min(sum1,sum0),n);
//     int ans0 = max(sum1%2,0);
//     cout << ans0 << " " << ans1 << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }
