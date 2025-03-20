//https://codeforces.com/contestInvitation/e028adc38c0a3ea3f155490de2fddce628e6413c

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

/*Problem L. 拼拼拼图图图*/
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define PII pair<int,int>
// void solve(){
//     int a,b,c,d;cin >> a >> b >> c >> d;
//     if(a < 4){
//          cout << 0 << "\n";
//          return;
//     }
//     vector<PII> vc;
//     for(int i = 1; i <= d; i++){
//         vc.push_back({i,d/i});
//     }
//     int ans = 4;
//     int L = min(b,c);
//     for(int i = 0; i < vc.size(); i++){
//         if(L >= (vc[i].first + vc[i].second)){
//             ans = max(ans,(vc[i].first+2)*(vc[i].second+2));
//         } 
//         else{
//             //cout << "??? " << vc[i].first << " " << vc[i].second << "\n";
//             int tmp = min(vc[i].first,vc[i].second);
//             int tmpp = max(vc[i].first,vc[i].second);
//             if(L > min(vc[i].first,vc[i].second)){
//                 ans = max(ans,(tmp+2)*min(L-tmp+2,tmpp+2));
//                 //cout << "?? " << tmp << " " << L -tmp << "\n";
//             }
//             if(L > max(vc[i].first,vc[i].second)){       
//                 ans = max(ans,(tmpp+2)*min(L-tmpp+2,tmp+2));
//                 //cout << "?? " << tmp << " " << L -tmp << "\n";
//             }
//             if(L <= min(vc[i].first,vc[i].second)){
//                 for(int j = 1; j < L; j++){
//                     ans = max(ans,(j+2)*(L-j+2));
//                 }
//             }
//         }     
//         //cout << "? " << ans << " " << L << " " << vc[i].first << " " << vc[i].second << "\n";
//     }
//     ans = max(ans,(L+2)*2);
//     cout << ans << "\n";
// }
// signed main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*H. Square Root*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     string s;cin >> s;
//     int cnt = 0;
//     for(int i = 0; i < s.size(); i++){
//         if(s[i] == '1') cnt++;
//         else if(s[i] == '0') cnt = 0;
//         if(cnt == 3){
//             s[i-1] = '0';
//             cnt = 1;
//         }
//     }
//     cnt = 0;
//     double ans = 0;
//     for(int i = 0; i < s.size(); i++){
//         if(s[i] == '1') cnt++;
//         else if(s[i] == '0'){
//             ans += sqrt(cnt);
//             cnt = 0;
//         }
//     }
//     ans += sqrt(cnt);
//     cout << fixed << setprecision(10) <<ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }