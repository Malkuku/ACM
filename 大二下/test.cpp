#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N = 5e5 + 10;
int res = 0;
int a[N];
unordered_map<int,int> mp;
void fj(int x){
    for(int i = 1; i * i <= x ; i++){
        if(x % i == 0){
            if(x/i == i) mp[i]++;
            else mp[i]++,mp[x/i]++;
        }
    }
}
void solve(){
    cin >> n;
    for(int i = 1; i <= n ; i++){
        cin >> a[i];
        int cha = abs(a[i] - i);
        if(cha == 0) res++;
        else fj(cha);
    }
    int ans = 0;
    for(int i = 1; i <= n ; i++){
        if(mp[i] + res == n) ans++;
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}