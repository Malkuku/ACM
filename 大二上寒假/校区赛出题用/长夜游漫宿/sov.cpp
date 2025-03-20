#include<bits/stdc++.h>
using namespace std;
#define ll long long
//G->E->L->G
void solve(){
    int g,e,l;cin >> g >> e >> l;
    string s;cin >> s;
    int g2 = 0,e2 = 0,l2 = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'G') g2++;
        else if(s[i] == 'E') e2++;
        else if(s[i] == 'L') l2++;
    }
   
    int ans = 0;
    int tmp = min(g,e2);
    ans += tmp;
    g -= tmp;
    e2 -= tmp;
    tmp = min(e,l2);
    ans += tmp;
    e -= tmp;
    l2 -= tmp;
    tmp = min(l,g2);
    ans += tmp;
    l -= tmp;
    g2 -= tmp;

    tmp = min(g,g2);
    g -= tmp;
    g2 -= tmp;
    tmp = min(e,e2);
    e -= tmp;
    e2 -= tmp;
    tmp = min(l,l2);
    l -= tmp;
    l2 -= tmp;

    ans -= (l+e+g);

    cout << ans << "\n"; 
}
int main(){
    ios::sync_with_stdio(0);
    int t = 1;cin >> t;
    while(t--){
        solve();
    }
}