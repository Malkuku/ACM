#pragma once
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*A. Problem Generator*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// int main(){
//     int t;cin >> t;
//     while(t--){
//         map<char, int> g;
//         int sum = 7;
//         int ans = 0;
//         int n,m; cin >> n >> m;
//         for(int i = 0; i < n; i++) {
//             char ch;cin >> ch;
//             g[ch]++;
//         }
//         for(auto i : g){
//             sum--;
//             ans += max(0,(m-i.second));
//         }
//         //cout << "&" << ans << "\n";
//         ans += sum*m;
//         cout << ans << "\n";
//     }
// }

/*B. Choosing Cubes*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// const int N = 11000;
// PII a[11000];
// int main(){
//     ios::sync_with_stdio(0);
//     int t;cin >> t;
//     while(t--){
//         int n,f,k;cin >> n >> f >> k;
//         for(int i = 1; i <= n; i++){
//             int x; cin >> x;
//             a[i] = {x,i};
//         }
//         int ans = a[f].first;
//         sort(a+1,a+1+n,[](auto x,auto y){
//             return x.first > y.first;
//         });
//         int flag = 0;
//         for(int i = 1; i <= k; i++){
//             if(a[i].first == ans) flag = 1;
//         }
//         if(k+1 <= n && a[k+1].first == ans && flag) flag = 2;
//         if(flag == 0) cout << "No\n";
//         else if(flag == 1) cout << "Yes\n";
//         else if(flag == 2) cout << "Maybe\n";
//     }
//     return 0;
// }

/*C. Sofia and the Lost Operations*/ //做得太着急了，效果反而适得其反
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// const int N = 2e5+10;
// int a[N];
// int b[N];
// map<int,int> g;
// map<int,bool> g2;
// queue<int> q;
// int main(){
//     ios::sync_with_stdio(0);
//     int t;cin >> t;
//     while(t--){
//         g.clear();
//         g2.clear();
//         while(q.size()) q.pop();
//         int n;cin >> n;
//         for(int i = 0; i < n; i++){
//             cin >> a[i];
//         }
//         for (int i = 0; i < n; i++){
//             cin >> b[i];
//             g2[b[i]] = 1;
//         }         
//         int m;cin >> m;
//         for(int i = 0; i < m; i++){
//             int x; cin >> x;
//             q.push(x);
//         }
//         int size = 0;
//         for(int i = 0; i < n; i++){
//             if(a[i] != b[i]){
//                 g[b[i]]++;
//                 size++;
//             }
//         }
//         bool flag = 1;
//        //for(auto i : g) cout << i.first << " ";
//        //cout << "\n";
//         while(q.size() && size){
//             auto t = q.front();q.pop();
//             if(g[t] > 0){
//                 g[t]--;
//                 size--;
//             }
//         }
//         if(size) flag = 0;
//         //cout << "? " << size << "\n";
//         while(q.size() > 1){
//             //auto t = q.front();
//             q.pop();
//             //cout << t << " ";
//         }// << "\n";
//         if(q.size()){
//             //cout << "? " << t << "\n";
//             auto t = q.front();
//             q.pop();
//             if (!g2.count(t))
//                 flag = 0;
//         }
//         if(flag) cout << "Yes\n";
//         else cout << "No\n";
//     }
//     return 0;
// }