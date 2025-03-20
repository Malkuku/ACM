#include<bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
int gcd(int a,int b){
    return b ? gcd(b,a%b) : a;
}
void solve(){
    int n;cin >> n;
    for(int i = 1; i <= 10; i++){
        cout << n << " " << bitset<32>(n) << "\n";
       n = sqrt(n);
    } 
}
int main(){
    int t = 1;//cin >> t;
    while(t--){
        solve();
    }
}
