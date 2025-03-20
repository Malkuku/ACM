// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*F. Volunteering*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     int S,F;cin >> S >> F;
//     map<int,int> mp;
//     for(int i = 0; i < n; i++){
//         int b,e;cin >> b >> e;
//         mp[max(S,b)]++;
//         mp[min(e,F)]--;
//     }
//     //for(auto t : mp){
//     //    cout << t.first << " " << t.second << "\n";
//     //}cout << "-------\n";
//     ll pre = 0;
//     for(auto t : mp){
//         if(pre){
//             mp[t.first] += pre;
//         }
//         pre = mp[t.first];
//     }
//     //for(auto t : mp){
//     //    cout << t.first << " " << t.second << "\n";
//     //}cout << "-------\n";
//     map<int,ll> mp2;
//     pre = 0;ll value = 0;
//     for(auto t : mp){
//         if(pre){
//             mp2[pre] += t.first - value;
//         }       
//         pre = t.second;
//         value = t.first;
//     }
//     //for(auto t : mp2){
//     //    cout << t.first << " " << t.second << "\n";
//     //}cout << "-------\n";
//     ll sum = 0;
//     vector<ll> vc;
//     for(int i = n; i >= 1; i--){
//         sum += mp2[i];
//         vc.push_back(F-S-sum);
//     }
//     for(int i = vc.size()-1; i >= 0; i--){
//         cout << vc[i] << " ";
//     }cout << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }
/*2025.3.1*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;cin >> t;
    while(t--){
        solve();
    }
}

/*I. Fair Diversity*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,d;cin >> n >> d;
//     map<int,int> mp;
//     int maxn = 0;int minn = 2e9;
//     for(int i = 0; i < d; i++){
//         int a,b;cin >> a >> b;
//         mp[a]++,mp[b]++;
//     }
//     for(int i = 1; i <= n; i++){
//         maxn = max(maxn,mp[i]);
//         minn = min(minn,mp[i]);
//     } 
//     int cnt = 0;
//     for(int i = 1; i <= n; i++){
//         cnt += maxn - mp[i];
//     }
//     int cha = maxn - minn;
//     if(cha <= cnt - cha){
//         while(cnt % 2){
//             cnt += n;
//             maxn++;
//         }
//         cout << maxn << "\n";
//         return;
//     }else{
//         int yu = cha - (cnt - cha);
//         maxn += (yu+n-2)/(n-1);
//         cnt += yu % (n-1);
//         while(cnt % 2){
//             cnt += n;
//             maxn++;
//         }
//         cout << maxn << "\n";
//         return;
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }
