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

/*B. Maximize Mex*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+10;
void solve(){
    int n,k;cin >> n >> k;
    vector<ll> a(n); 
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(),a.end());
    for(int i = 0; i < n-1; i++){
        if(a[i] == a[i+1]){
           
        }
    }
    a.erase(unique(a.begin(),a.end()),a.end());
    ll ans = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == ans) ans++;
        else{
            if(ans + 1 == ji)
        }
    }
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


/*A. Meaning Mean*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll a[55];
// void solve(){
//     int n;cin >> n;
//     for(int i = 0; i < n; i++) cin >> a[i];
//     vector<ll> arr;
//     for(int i = 0; i < n; i++) arr.push_back({a[i]});
//     sort(arr.begin(),arr.end(),greater<int>());
//     while(arr.size() > 1){
//         ll x = arr.back(); arr.pop_back();
//         ll y = arr.back(); arr.pop_back();
//         arr.push_back((x+y)/2);
//     }
//     cout << arr[0] << "\n";
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
