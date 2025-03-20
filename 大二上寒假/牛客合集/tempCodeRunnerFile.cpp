/*B 能去你家蹭口饭吃吗*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
int a[N];
void solve(){
    int n;cin >> n;
    map<int,int> mp;
    for(int i = 0; i < n; i++){
         cin >> a[i];
         mp[a[i]]++;
    }
    int ans;
    int size = 0;
    for(auto t : mp){
        //cout << t.first << " " << t.second << " " << size << "\n";
        if(size < n / 2) size += t.second;
        else {
            ans = t.first - 1;
            break;
        }
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;//cin >> t;
    while(t--){
        solve();
    }
}