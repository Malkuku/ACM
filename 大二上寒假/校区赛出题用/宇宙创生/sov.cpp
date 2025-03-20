#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1010];
void solve(){
    int n;cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "1 1 4 5 1 4\n" <<  "5 5 0 1 5 0\n" <<  "1 1 4 5 1 4\n" <<
    "1 1 4 5 1 4\n" <<
    "1 1 4 5 1 4\n" <<
    "1 1 4 5 1 4\n";
}
int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    int t = 1;//cin >> t;
    while(t--){
        solve();
    }
}