// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;
//     cin >> t;
//     for(int i = 1; i <= t; i++){
//         solve();
//     }
//     return 0;
// }

/*D2. Asesino (Hard Version)*/
/*2024.10.17*/
// #include<bits/stdc++.h>                               
// using namespace std;
// #define ll long long
// int ask(int i,int j){
//     cout << "? " << i << " " << j << endl;
//     int res;cin >> res;
//     return res;
// }
// void ans(int i){
//     cout << "! " << i << endl;
// }
// void solve(){
//     int n;cin >> n;
//     if(n == 3){
//         if(ask(1,2) == ask(2,1)){
//             ans(3);
//         }
//         else{
//             if(ask(1,3) == ask(3,1)){
//                 ans(2);
//             }
//             else ans(1);
//         }
//         return;
//     }
//     if(n & 1){ //奇数，通过1->2->3->1的询问链处理，加起来为偶数说明有内鬼
//         int a = ask(n - 2,n - 1);
//         int b = ask(n - 1,n);
//         int c = ask(n,n - 2);
//         if((a+c+b) % 2== 0){
//             if(ask(n,n-1) == b){
//                 ans(n - 2);
//             }
//             else if(ask(n - 1,n-2) == a){
//                 ans(n);
//             }
//             else ans(n - 1);
//             return;
//         }
//         n -= 3;
//     }
//     //作为偶数处理【n-3，3】
//     for(int i = n-1;i >= 3; i-=2){
//         if(ask(i,i+1) != ask(i+1,i)){
//             if(ask(i,1) == ask(1,i)){
//                 ans(i+1);
//             }
//             else{
//                 ans(i);
//             }
//             return;
//         }
//     }
//     if(ask(1,3) == ask(3,1)){
//         ans(2);
//     }
//     else{
//         ans(1);
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;
//     cin >> t;
//     for(int i = 1; i <= t; i++){
//         solve();
//     }
//     return 0;
// }

/*D1. Asesino (Easy Version)*/
/*2024.10.16*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i+=2){
//         if(i+1 > n) break;
//         cout << "? " << i << " " << i+1 <<endl;
//         bool flag1;cin >> flag1;
//         cout << "? " << i+1 << " " << i <<endl;
//         bool flag2;cin >> flag2;
//         if(flag1 ^ flag2) {
//             //i 或者 i+1是骗子
//             if(i <= n-2){
//                 cout << "? " << i+2 << " " << i+1 <<endl;
//                 bool flag3;cin >> flag3;
//                 cout << "? " << i+1 << " " << i+2 <<endl;
//                 bool flag4;cin >> flag4;
//                 if(flag3 ^ flag4){
//                     cout << "! " << i+1 << endl;
//                     return;
//                 }
//                 else{
//                     cout << "! " << i << endl;
//                     return;
//                 }
//             }
//             else{
//                 cout << "? " << i-1 << " " << i <<endl;
//                  bool flag3;cin >> flag3;
//                  cout << "? " << i << " " << i-1 <<endl;
//                  bool flag4;cin >> flag4;
//                 if(flag3 ^ flag4){
//                     cout << "! " << i << endl;
//                     return;
//                 }
//                 else{
//                     cout << "! " << i+1 << endl;
//                     return;
//                 }
//             }
//         }
//     }
//     cout << "! " << n << endl;
//     return;
// }
// int main(){
//     int t = 1;
//     cin >> t;
//     for(int i = 1; i <= t; i++){
//         solve();
//     }
//     return 0;
// }

/*C. Gerrymandering*/ //动态规划--转移
/*2024.10.16 (精)*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// ll dp[2][N];
// bool check(char a,char b,char c){
//     int p=(a=='A'),q=(b=='A'),r=(c=='A');
// 	return (p+q+r>=2);
// }
// void solve(){
//     memset(dp,-0x3f,sizeof dp);
//     int n;cin >> n;
//     string s[2];
//     cin >> s[0] >> s[1];
//     dp[0][0] = 0;
//     for(int i = 0; i < n; i++){
//         if(i % 3 == 0){
// 			dp[0][i+3]=max(dp[0][i+3],
//                            dp[0][i]+check(s[0][i],s[0][i+1],s[0][i+2])	//###
//                            +check(s[1][i],s[1][i+1],s[1][i+2]));		//###
// 			dp[0][i+1]=max(dp[0][i+1],									//##
//                            dp[0][i]+check(s[0][i],s[1][i],s[0][i+1]));	//#.        
// 			dp[1][i+1]=max(dp[1][i+1],										//#.
//                            dp[0][i]+check(s[0][i],s[1][i],s[1][i+1]));		//##
//         }
//         else if(i % 3 == 1){
//             if(i+3 < n){
//                 dp[0][i+3] = max(dp[0][i+3],
//                 dp[0][i] + check(s[0][i+1],s[0][i+2],s[0][i+3]) + check(s[1][i],s[1][i+1],s[1][i+2]));
//                 dp[1][i+3] = max(dp[1][i+3],
//                 dp[1][i] + check(s[0][i],s[0][i+1],s[0][i+2]) + check(s[1][i+1],s[1][i+2],s[1][i+3]));
//             }
//             dp[0][i+2] = max(dp[0][i+2],
//             dp[1][i] + check(s[0][i+1],s[0][i],s[1][i+1]));
//             dp[0][i+2] = max(dp[0][i+2],
//             dp[0][i] + check(s[1][i],s[0][i+1],s[1][i+1]));
//         }
//     }
//     cout << dp[0][n] << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;
//     cin >> t;
//     for(int i = 1; i <= t; i++){
//         solve();
//     }
//     return 0;
// }

/*A. Bus to Pénjamo*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int a[110];
// void solve(){
//     int n,r;cin >> n >> r;
//     int sum = 0;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
//     if(0);
//     else{
//         int happy = 0;
//         int row = 0;
//         int alone = 0;
//         for(int i = 1; i <= n; i++){
//             happy += a[i] - (a[i] % 2);
//             alone += a[i] % 2;
//             row += a[i]/2;
//         }
//         //cout << "? " << happy << " " << alone << "\n";
//         int last = r - row;
//         int y = 2*(alone - last);
//         y = max(0,y);
//         int x = (alone - y);
//         //cout << "? " << last << " " << x << " " << y << "\n";
//         x = max(0,x);
//         x = min(x,2*last);
//         cout << happy + x << "\n";
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;
//     cin >> t;
//     for(int i = 1; i <= t; i++){
//         solve();
//     }
//     return 0;
// }

/*B. Kar Salesman*/
/*2024.10.16 题解*/ //max(ai,sum/x)
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,x;cin >> n >> x;
//     ll mx = 0,sum = 0;
//     for(int i = 0; i < n; i++){
//         ll ai;cin >> ai;
//         mx = max(mx,ai);
//         sum += ai;
//     }
//     cout << max(mx,(sum + x - 1) / x) << endl;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;
//     cin >> t;
//     for(int i = 1; i <= t; i++){
//         solve();
//     }
//     return 0;
// }
/*WA  不知道问题在哪里*/
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// void solve(){
//     int n,x;cin >> n >> x;
//     priority_queue<int> q;
//     for(int i = 1; i <= n; i++){
//         int a;cin >> a;
//         q.push(a);
//     }
//     int cnt = 0;
//     //cout <<"? " << q.size() << "\n";
//     while(q.size()){
//         vector<int> tmp;
//         int mina = q.top();
//         int len = q.size();
//         for(int i = 1; i <= min(len,x); i++){
//             tmp.push_back(q.top());
//             mina = min(q.top(),mina);
//             q.pop();
//         }
//         //cout << "? " << mina <<" " << tmp.size()<< "\n";
//         cnt += mina;
//         for(int i = 0; i < tmp.size(); i++){
//             int num = tmp[i] - mina;
//             if(num > 0)q.push(num);
//         }
//     }
//    cout << cnt << "\n";
// }
// signed main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;
//     cin >> t;
//     for(int i = 1; i <= t; i++){
//         solve();
//     }
//     return 0;
// }