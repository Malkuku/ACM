#include<bits/stdc++.h>
using namespace std;
void solve(){
    int k,x;
    cin >> k >> x;
    int tol = 0;
    vector<int> base(k+1,0);
    for(int i = 10 - k ; i < 9 ; i++) base[++tol] = i;
    base[0] = 9;
    int b = k,m = 1;
    vector<int> ans;
    bool f = 0;
    while(x > 0){
        int p = x % k;
        int c = ceil((1.0 * p)/m);
        if(c == b) c = 0;
        x -= k;
        k *= b;
        m *= b;
        ans.push_back(base[c]);
    }
    for(int i = ans.size() - 1; i >= 0 ; i--) cout << ans[i];
    cout << endl;
}
int main(){
    int t;
    for(cin>>t;t;t--) solve();
    return 0;
}