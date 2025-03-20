// gym/104857

#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*G. Streak Manipulation*/ 
/*2024.11.9 题解*/ //二分+dp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N =2e5+10;
int n,m,k;
int dp[N][6][2]; //i,k,0/1
 string s;
int sum[N];
bool check(int x){
    for(int i = 0; i <= n; i++) memset(dp[i],0x3f,sizeof dp[i]);
    dp[0][0][0] = 0; dp[0][0][1] = 0;
    int ans = 0x3f3f3f3f;
    for(int i = 1; i <= n;i++){
        if(s[i] == '0') {
            dp[i][0][0] = 0;
            dp[i][0][1] = 1;
        }
        else dp[i][0][1] = 0;
        for(int j = 1; j <= k; j++){
            dp[i][j][0] = min(dp[i-1][j][0],dp[i-1][j][1]);
            if(i - x >= 0 && j - 1 >= 0 && s[i-x] != '1'){
                dp[i][j][1] = min(dp[i][j][1],dp[i-x][j-1][0] + sum[i] - sum[i-x]);
            }
        }
        ans = min({ans,dp[i][k][0],dp[i][k][1]});
    }
    return ans <= m;
}
int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
   cin >> s;
   s = " " + s;
    for(int i = 1; i < s.size(); i++){
        sum[i] = sum[i-1] + (s[i] == '0');
    }
    int ans = -1;
    int l = 1,r = n; //二分最长长度x
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)) ans = mid, l = mid+1;
        else r = mid - 1;
    } 
    cout << ans << "\n";
    return 0;
}