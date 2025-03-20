#include<iostream>
#include<algorithm>
using namespace std;
const int mod = 1e9+7;
const int N = 2010;
int dp[2010][2010];
int n,k;
int main(){
    ios::sync_with_stdio(0);
    cin >> k >> n;
    for(int i = 1; i <= k; i++){
        dp[1][i] = 1;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= k; j++){
            for(int z = 1; z <= j; z++){
                if(j%z == 0){
                    dp[i][j] = (0LL + dp[i][j] + dp[i-1][j/z]) % mod;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= k; i++){
        ans = (0LL + ans + dp[n][i]) % mod;
    }
    cout << ans << "\n";
    return 0;
}
