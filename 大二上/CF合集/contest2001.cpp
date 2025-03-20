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

/*B. Generate Permutation*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+10;
int a[N];
void solve(){
    int n; cin >> n;
    if(n % 2== 0){
        cout << -1 << "\n";
        return;
    }
    int pos = n / 2;
    a[pos] = 1;
    int ou = 2,ji = 3;
    for(int i = pos+1; i < n; i++){
        a[i] = ou;
        ou += 2;
    }
    for(int i = pos - 1; i >= 0; i--){
        a[i] = ji;
        ji += 2;
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }cout << "\n";
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

/*A. Make All Equal*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     map<int,int> mp;
//     for(int i = 0; i < n; i++){
//         int x;cin >> x;
//         mp[x]++;
//     }
//     int res = 0;
//     for(auto t : mp){
//         res = max(res,t.second);
//     }
//     cout << n - res << "\n";
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