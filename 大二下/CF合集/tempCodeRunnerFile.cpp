/*C. Superultra's Favorite Permutation*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;cin >> n;
    vector<int> a;
    if(n <= 6){
        cout << -1 << "\n"; 
        return;
    } 
    for(int i = 1; i <= n; i+=2){
        a.push_back(i);
    }
    for(int i = 2; i <= n; i+=2){
        a.push_back(i);
    }
    int pos = (n-1)/2;
    swap(a[2],a[pos]);
    swap(a[pos+1],a[pos+2]);
    for(auto t : a)cout << t << " ";
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;cin >> t;
    while(t--){
        solve();
    }
}