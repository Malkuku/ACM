/*G Jump Sort*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+10;
int cnt = 0;
ll primes[N];
bool isprime[N];
void init(){
    for(int i = 2; i < N; i++){
        if(!isprime[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= N / i; j++) { //枚举质数
    		isprime[primes[j] * i] = 1;
            if (i % primes[j] == 0) break; //这个数的最小质因子
        }
    }
}
void solve(){
    int n;cin >> n;
    vector<int> a(n+1);
    for(int i = 1;i <= n; i++){
        cin >> a[i];
    }
    map<int,int> mp;
    int res = 0;
    for(int i = 1; i <= n; i++){
        int x = a[i] - i;
        for(int j = 0; j < cnt; j++){
            if(x == 0) res++;
            else if(x % primes[j] == 0){
                mp[primes[j]]++;
                if(x/primes[j] != primes[j])mp[x/primes[j]]++;
            }
            if(x < primes[j]) break;
        }
    }
    int ans = 1;
    for(int i = 2; i <= n; i++){
        if(mp[i] + res == n) ans++;
        else break;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;//cin >> t;
    init();
    while(t--){
        solve();
    }
}