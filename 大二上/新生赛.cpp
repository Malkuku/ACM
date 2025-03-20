// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }



/* #QED2412X. 爱抽卡的佩佩*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    double p; cin >> p;
    cout << fixed << setprecision(8) << 1 / p << "\n";
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

/*#M. kiwi要打Phigros！*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e4+10;
// float a[N];
// void solve(){
//     int n;cin >> n;
//     int max_x = 0;
//     float max_rks = 0;
//     float sum = 0;
//     for(int i = 0; i < n; i++){
//         int x;float y; cin >> x >> y;
//         float rks;
//         if(y >= 0.7)rks = ((y*100 - 55)/45)*((y*100 - 55)/45)*x;
//         else rks = 0;
//         a[i] = rks;
//         if(x > max_x && y == 1){
//             max_x = x;
//             max_rks = rks;
//         }
//     }
//     sort(a,a+n,[](auto x,auto y){
//         return x > y;
//     });
//     for(int i = 0; i < min(n,19);i++){
//         sum += a[i];
//     }
//     sum += max_rks;
//     cout <<fixed <<setprecision(2) << (sum) / 20 << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }

/*#L. hhuggo的完美木桶*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e4+10;
// int a[N];
// void solve(){
//     int n,k;cin >> n >> k;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
//     int ans = 0;
//     for(int i = 1; i <= n; i++){
//         int left = upper_bound(a+1,a+1+n,a[i]-k) - a - 1;
//         int pos = lower_bound(a+1,a+1+n,a[i]) - a - 1;
//         int right = upper_bound(a+1,a+1+n,0ll+a[i]+k) - a - 1;
//         ans = max(ans,right - pos);
//         ans = max(ans,pos - left + 1);
//     }
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }


/*#K. kouki与阶乘之间的那些事？*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 5e5+10;
// ll kk[N];
// void getKK(){
//     kk[1] = 1;
//     for(int i = 2; i <= N-1; i++){
//         kk[i] = kk[i-1] * i;
//     }
// }
// void solve(){
//     int n;cin >> n;
//     ll x; cin >> x;
//     ll sum = 0;
//     for(int i = 0; i < n; i++){
//         int a;cin >> a;
//         sum += kk[a];
//     }
//     if(sum % x == 0) cout << "YES\n";
//     else cout << "NO\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     getKK();
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }


/*#J. 坐座位*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N =1e6+10;
// int a[N],b[N];
// void solve(){
//     int n;cin >> n;
//     memset(b,0,sizeof b);
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     b[a[1] - 1] = 1,b[a[1] + 1] = 1, b[a[1]] = 2;
//     for(int i = 2; i <= n; i++){
//         if(b[a[i]] != 1) {
//             cout  << "Yes\n";
//             return;
//         }
//         b[a[i]] = 2;
//         b[a[i]-1]=1,b[a[i]+1] = 1;
//     }
//     cout << "No\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }

/*#I. 充满智慧的质数*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     ll n;cin >> n;
//     cout << n-1 << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }


/*#A. homtrue*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     string ans = "homtrue";
//     int k;cin >> k;
//     if(k == 114514){
//         cout << "yc" << "\n";
//         return;
//     }
//     for(int i = ans.size() - 1;i >= 0; i--){
//         if(k & 1) ans[i] -= 'a' - 'A';
//         k >>= 1;
//     }
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }


/*#B. 暴食海獭*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// string s1 = "chikuwa";
// string s3 = "dorayaki"; 
// string s5 = "choki";
// string to = "karen";
// void solve(){
//     int n;cin >> n;
//     string s; cin >> s;
//     stack<int> ans;
//     for(int i = 0; i < s.size(); i++){
//         string tmp1 = s.substr(i,s1.size());
//         if(tmp1 == s1){
//             ans.push(1);
//             i += s1.size()-1;
//             continue;
//         }
//          string tmp3 = s.substr(i,s3.size());
//         if(tmp3 == s3){
//             ans.push(3);
//             i += s3.size()-1;
//             continue;
//         }
//          string tmp5 = s.substr(i,s5.size());
//         if(tmp5 == s5){
//             ans.push(5);
//             i += s5.size()-1;
//             continue;
//         }
//         string tmpto = s.substr(i,to.size());
//         if(tmpto == to){
//             if(ans.size()) ans.pop();
//             i += to.size()-1;
//             continue;
//         }
//     }
//     int sum = 0;
//     while(ans.size()){
//         sum += ans.top();
//         ans.pop();
//     }
//     cout << sum << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }


/*#E. 夏日幻魂*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;cin >> n;
    ll x = 0;ll y = 0;
    int turn = 0;
    for(int i = 0; i < n; i++){
        char ch; cin >> ch;
        int xx;cin >> xx;
        if(ch == 'F') {
            if(turn == 0) x += xx;
            else if(turn == 1) y += xx;
            else if(turn == 2) x -= xx;
            else if(turn == 3) y -= xx;
        }
        if(ch == 'B'){
            turn = (turn + 2) % 4;
            if(turn == 0) x += xx;
            else if(turn == 1) y += xx;
            else if(turn == 2) x -= xx;
            else if(turn == 3) y -= xx;
        }
        if(ch == 'L'){
            turn = (turn + 1) % 4;
            if(turn == 0) x += xx;
            else if(turn == 1) y += xx;
            else if(turn == 2) x -= xx;
            else if(turn == 3) y -= xx;
        }
        if(ch == 'R'){
            turn = (turn + 3) % 4;
            if(turn == 0) x += xx;
            else if(turn == 1) y += xx;
            else if(turn == 2) x -= xx;
            else if(turn == 3) y -= xx;
        }
    }
    cout << x << " " << y << " " << turn << "\n";
}
int main(){
   // ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    int t;cin >> t;
    for(int _  = 1; _ <= t; _++){
        solve();
    }
    return 0;
}


/*#F. 宝藏岛的平衡挑战*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int a[1100];
// void solve(){
//     int n,m;cin >> n >> m;
//     int left = 0,right = 0;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     for(int i = 1; i <= m+1; i++){
//         left += a[i];
//     }
//     for(int i = m+1; i <= n; i++){
//         right += a[i];
//     }
//     if(left > right){
//         cout <<"Left is heavier!\n";
//     }
//     else if(left < right){
//         cout << "Right is heavier!\n";
//     }
//     else{
//         cout << "It's balanced!\n";
//     }
//     cout << max(left,right) << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }


/*#G. 等式构造*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int sov1(ll x){
//     ll ans = 1;
//     for(int i = 2; i <= x; i++){
//         ans *= i;
//     }
//     return ans;
// }
// void solve(){
//     ll n;cin >> n;
//     cout << 2*(sov1(n)-n) << " " << 2*(sov1(n)-2*n) << " " << 2;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }


/*#H. 魔咒解密*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// string p1,p2,s;
// int kmp(int pos,string& p){
//     for(int i = 0; i < p.size(); i++){
//         if(p[i] != s[pos + i] 
//         && (p[i] != '#' || (s[pos+i] > '9' || s[pos+i] < '0'))) 
//         return -1; 
//     }
//     return pos+p.size();
// }
// void solve(){
//    cin >> p1 >> p2 >> s;
//     vector<string> ans;
//     bool flag = 0;int head_pos = 0;
//     for(int i = 0; i < s.size(); i++){
//         if(flag == 0){
//             int pos1 = kmp(i,p1);
//             if(pos1 == -1) continue;
//             else{
//                 flag = 1;
//                 head_pos = pos1;
//                 i = pos1 - 1;
//             }
//         }
//         else{
//             int pos2 = kmp(i,p2);
//             if(pos2 == -1) continue;
//             else{
//                 flag = 0;
//                 if(head_pos > i-1) ans.push_back({""});
//                 else ans.push_back({s.substr(head_pos,i-1-head_pos+1)});
//                 //cout << head_pos << " : " << i-1 << "\n";
//                 i = pos2 - 1;
//             }
//         }
//     }
//     cout << ans.size() << "\n";
//     for(int i = 0; i < ans.size(); i++){
//         cout << ans[i] << "\n";
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }