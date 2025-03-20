#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*P3287 [SCOI2014] 方伯伯的玉米田 */ //树状数组优化
/*2024.10.15 题解*/ //完全不懂！！！
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll lowbit(ll x){
    return (x & -x);
}
const int N = 1e4+10;
int a[N],dp[N][510],t[510][N],n,k;
//dp[i][j] //j次区间操作，【L（<= i），n】，以i结尾最长LIS
void update(int x,int y,int d){
    for(int i = x; i <= k + 1; i+= lowbit(i)){
        for(int j = y; j <= 5500; j += lowbit(j)){
            t[i][j] = max(t[i][j],d);
        }
    }
}

int query(int x,int y){
    int ans = 0;
    for(int i = x; i > 0; i-=lowbit(i)){
        for(int j = y; j > 0; j -= lowbit(j)){
            ans = max(ans,t[i][j]);
        }
    }
    return ans;
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        for(int j = k; j >= 0; j--){
            dp[i][j] = query(j+1,a[i]+j) + 1; //WHY???
            update(j+1,a[i]+j,dp[i][j]); //HOW TO WORK ???
        }
    }
    cout << query(k+1,5500) << "\n";
    return 0;
}