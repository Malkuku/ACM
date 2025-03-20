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

/*D1. Turtle and a MEX Problem (Easy Version)*/
//统计每个序列 两个mex
//f(x) 1.小于最大mex -- 最大mex+1
//     2.大于最大mex -- x
//     3.特殊？ 作为mex 使得 第二个max mex 成立 - 2e5 ??!
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+10;
int a[N];
void solve(){
    ll n,m;cin >> n >> m;
    map<int,int> mex;
    ll max_mex = 0;
    for(int i = 0; i < n; i++){
        int k;cin >> k;
        vector<int> b(k);
        for(int j = 0; j < k; j++){
            cin >> b[j];
        }
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        ll tmp = 0;
        bool flag = 0;
        for(int j = 0; j < b.size();j++){
            //cout << "? " << tmp << " " << b[j] << "\n";
            if(b[j] == tmp) {
                tmp++;
            }
            else if(!flag) {
                tmp++;
                flag = 1;
                j--;
            }
            else break;
        }
        if(!flag) tmp++; //TARGE HERE!
        max_mex = max(max_mex,tmp);
    }
    //cout << m << " " << max_mex << "\n";
    ll ans = 0ll + max_mex * (min(m,max_mex)+1) + (m > max_mex 
    ? (1ll*(m - max_mex)*(m + max_mex + 1) / 2) : 0);
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    for(int _  = 1; _ <= t; _++){
        solve();
    }
    return 0;
}

/*C. Turtle and Good Pairs*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int num[27];
// void solve(){
//     int n;cin >> n;
//     memset(num,0,sizeof num);
//     int sum = 0;
//     for(int i = 0; i < n; i++){
//         char ch;cin >> ch;
//         num[ch - 'a']++;
//         sum++;
//     }
//     string ans;
//     char pos = '?';
//     while(sum){
//         bool flag = 0;
//         for(int i = 0;i < 26; i++){
//             if(num[i] != 0 && pos == '?'){
//                 num[i]--;
//                 ans+=(char)(i+'a');
//                 sum--;
//                 pos = '!';
//                 flag = 1;
//                 break;
//             }
//             else if(num[i] != 0 && (i+'a') != ans[ans.size()-1]){
//                 num[i]--;
//                 ans+= (char)(i+'a');
//                 sum--;
//                 flag = 1;
//                 break;
//             }
//         }
//         if(!flag){
//             for(int i = 0; i < 26; i++){
//                 if(num[i] != 0){
//                     ans += (char)(i+'a');
//                     sum--;
//                 }
//             }
//         }
//     }
//     cout << ans << "\n";
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

/*B. Turtle and Piggy Are Playing a Game 2*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// ll a[N];
// void solve(){
//     int n;cin >> n;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     deque<ll> q;
//     sort(a,a+n);
//     for(int i = 0; i < n; i++) q.push_back(a[i]);
//     while(q.size() > 1){
//         auto a = q.front(); q.pop_front();
//         auto b = q.front(); q.pop_front();
//         q.push_front(max(a,b));
//         if(q.size() <= 1) break;
//         auto a1 = q.back(); q.pop_back();
//         auto b1 = q.back(); q.pop_back();
//         q.push_back(min(a1,b1));
//     }
//     auto ans = q.front();
//     cout << ans << "\n";
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


/*A. Turtle and Good Strings*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     string s;cin >> s;
//     int len = 0;
//     string tmp;
//     tmp += s[0];
//     char head = s[0];
//     if(s[0] == s[s.size()-1]){
//         cout << "No\n";
//     }
//     else cout << "Yes\n";
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
