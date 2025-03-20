#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4+10;
float a[N];
void solve(){
    int n;cin >> n;
    int max_x = 0;
    float max_rks = 0;
    float sum = 0;
    for(int i = 0; i < n; i++){
        int x;float y; cin >> x >> y;
        float rks;
        if(y >= 0.7)rks = ((y*100 - 55)/45)*((y*100 - 55)/45)*x;
        else rks = 0;
        a[i] = rks;
        if(x > max_x && y == 1){
            max_x = x;
            max_rks = rks;
        }
    }
    sort(a,a+n,[](auto x,auto y){
        return x > y;
    });
    for(int i = 0; i < min(n,19);i++){
        sum += a[i];
    }
    sum += max_rks;
    cout << setprecision(3) << (sum ) / 20 << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;//cin >> t;
    for(int _  = 1; _ <= t; _++){
        solve();
    }
    return 0;
}