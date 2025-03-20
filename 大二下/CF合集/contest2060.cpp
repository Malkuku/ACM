//Codeforces Round 998 (Div. 3)

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

/*E Graph Composition */ 
/*2025.3.4 题解*/  //又没仔细读题
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int find(int x,vector<int>& fa){
//     return fa[x] = x == fa[x] ? fa[x] : find(fa[x],fa);
// }
// void solve(){
//     int n,m1,m2;cin >> n >> m1 >> m2;
//     vector<int> fa1(n+1),fa2(n+1);
//     vector<pair<int,int>> arr1(m1+1),arr2(m2+1);
//     for(int i = 1; i <= n; i++) fa1[i] = i,fa2[i] = i;
//     for(int i = 1; i <= m1; i++){
//         int x,y;cin >> x >> y;
//         arr1[i] = {x,y};
//     }
//     for(int i = 1; i <= m2; i++){
//         int x,y;cin >> x >> y;
//         if(find(x,fa2) != find(y,fa2)) fa2[find(x,fa2)] = find(y,fa2);
//         arr2[i] = {x,y};
//     }
//     int ans = 0;
//     for(int i = 1; i <= m1; i++){
//         int x = arr1[i].first,y = arr1[i].second;
//         if(find(x,fa2) != find(y,fa2)) ans++; 
//         else if(find(x,fa1) != find(y,fa1)) fa1[find(x,fa1)] = find(y,fa1);
//     }
//    std::map<int, std::vector<int> > mp;
//     for (int i = 1; i <= n; ++ i) {
//     	mp[find(i,fa2)].push_back(i);
//     }
//     for (int i = 1; i <= n; ++ i) {
//     	for (auto & x : mp[i]) {
//     		if (find(x,fa1) != find(i,fa1)) {
//     			++ ans;
//     			fa1[find(x,fa1)] = find(i,fa1);
//     		}
//     	}
//     }
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*D Subtract Min Sort*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++) cin >> a[i];
//     for(int i = 1; i < n; i++){
//         int tmp = min(a[i],a[i-1]);
//         a[i-1] -= tmp;
//         a[i] -= tmp;
//     }
//     for(int i = 1; i < n; i++){
//         if(a[i-1] > a[i]){
//             cout << "No\n";
//             return;
//         }
//     }
//     cout << "Yes\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*C Game of Mathletes */
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,k;cin >> n >> k;
//     vector<int> a(n);
//     map<int,int> mp;
//     for(int i = 0; i < n; i++) cin >> a[i];
//     for(int i = 0; i < n; i++) mp[a[i]]++;
//     ll ans = 0;
//     for(auto t : mp){
//         if(!mp.count(k-t.first)) continue;
//         int tmp = min(mp[k - t.first],mp[t.first]);
//         if(k - t.first == t.first) tmp /= 2;
//         mp[k - t.first] -= tmp;
//         mp[t.first] -= tmp;
//         ans += tmp;
//         //cout << "? " << ans << " " << tmp << " " << t.first << "\n";
//     }
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*B Farmer John's Card Game*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,m;cin >> n >> m;
//     vector<pair<vector<int>,int>> vc(n);
//     for(int i = 0; i < n; i++){
//         vc[i].second = i;
//         for(int j = 0; j < m; j++){
//             int x;cin >> x;
//             vc[i].first.push_back(x);
//         }
//         sort(vc[i].first.begin(),vc[i].first.end());
//     }
//     sort(vc.begin(),vc.end(),[](auto x,auto y){
//         return x.first[0] < y.first[0];
//     });
//     int pre = -1;
//     for(int j = 0; j < m; j++){
//         for(int i = 0; i < n; i++){
//             if(vc[i].first[j] < pre){
//                 cout << -1 << "\n";
//                 return;
//             }
//             pre = vc[i].first[j];
//         }
//     }
//     for(int i = 0; i < n; i++){
//         cout << vc[i].second+1 << " ";
//     }cout << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*A Fibonacciness */ //不认真读题的后果
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     vector<int> a(6);
//     cin >> a[1] >> a[2] >> a[4] >> a[5];
//     int ans = 0;
//     auto sov = [&](int x){
//         int cnt = 0;
//         if(a[1] + a[2] == x) cnt++;
//         if(a[2] + x == a[4]) cnt++;
//         if(x + a[4] == a[5]) cnt++;
//         return cnt;
//     };
//     a[3] = a[1] + a[2];
//     ans = max(ans,sov(a[3]));
//     a[3] = a[4] - a[2];
//     ans = max(ans,sov(a[3]));
//     a[3] = a[5] - a[4];
//     ans = max(ans,sov(a[3]));
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

