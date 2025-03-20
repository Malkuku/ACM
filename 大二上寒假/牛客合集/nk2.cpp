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

/*C 字符串外串*/
/*2025.2.24*/ //想到了m + 25的解法,但其实有m+26的
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+10;
// void solve(){
//     int n,m;cin >> n >> m;
//     if(n <= m || n > m + 26){
//         cout << "NO\n";
//         return;
//     }
//     string ans;
//     for(int i = 0; i < n - m; i++){
//         char ch = i + 'a';
//         ans += ch;
//     }
//     int len = ans.size();
//     string tmp;
//     //cout << "? " << ans.back() << "\n";
//     while(tmp.size() < n){
//         tmp += ans;
//     }
//     cout << "YES\n";
//     ans = tmp.substr(tmp.size() - n,n);
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

/*H 一起画很大的圆！*/ //r = a / sin(a)
/*2025.2.24 题解*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int a,b,c,d;cin >> a >> b >> c >> d;
//     if(abs(a - b) > abs(c - d)){
//         cout << a << " " << d << "\n";
//         cout << a + 1 << " " << d << "\n";
//         cout << b << " " << d - 1 << "\n";
//     }
//     else{
//         cout << a << " " << d << "\n";
//         cout << a << " " << d - 1 << "\n";
//         cout << a + 1 << " " << c << "\n";
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*D 字符串里串*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     string s;cin >> s;
//     int ans = 0;
//     map<char,bool> mp;
//     for(int i = 0; i < s.size(); i++){
//         if(!mp.count(s[i])){
//             mp[s[i]] = 1;
//         }else{
//             ans = max(ans,(int)s.size() - i);
//         }
//     }
//     map<char,bool> mp2;
//     for(int i = s.size()-1; i >= 0; i--){
//         if(!mp2.count(s[i])){
//             mp2[s[i]] = 1;
//         }else{
//             ans = max(ans,i+1);
//         }
//     }
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*K 可以分开吗？*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// char g[510][510];
// int st[510][510];
// int dx[] = {0,1,0,-1};
// int dy[] = {1,0,-1,0};
// int n,m;
// int bfs(int x,int y,int index){
//     queue<pair<int,int>> q;
//     int ans = 0;
//     q.push({x,y});
//     st[x][y] = 1;
//     while(q.size()){
//         auto t = q.front(); q.pop();
//         for(int i = 0; i < 4; i++){
//             int xx = t.first + dx[i];
//             int yy = t.second + dy[i];
//             //cout << "! " << xx << " " << yy << "\n";
//             if(xx < 1 || yy < 1 || xx > n || yy > m) continue;
//             if(g[xx][yy] == '1' && st[xx][yy]) continue;
//             if(g[xx][yy] == '0'){
//                 if(st[xx][yy] != index){
//                     //cout << "? " << xx << " " << yy << "\n";
//                     st[xx][yy] = index;
//                     ans++;
//                 }
//                 continue;
//             }
//             q.push({xx,yy});
//             st[xx][yy] = 1;
//         }
//     }
//     return ans;
// }
// void solve(){
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++){
//         cin >> g[i]+1;
//     }
//     // for(int i = 1; i <= n; i++){
//     //     for(int j = 1; j <= m; j++){
//     //         cout << g[i][j];
//     //     }cout << "\n";
//     // }
//     int ans = 1e9;
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= m; j++){
//             if(g[i][j] == '1' && !st[i][j]){
//                 ans = min(ans,bfs(i,j,i*m+j));
//             }
//         }
//     }
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*J 数据时间？*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// class User{
// public:
//     string id;
//     string date;
//     string time;
//     User(string id,string date,string time)
//     : id(id),date(date),time(time)
//     {}
// };
// vector<string> split(string target,char str){
//     vector<string> vc;
//     string s = "";
//     for(int i = 0; i < target.size(); i++){
//         if(target[i] == str){
//             vc.push_back(s);
//             //cout << "？ " << s << "\n";
//             s = "";
//         }
//         else s += target[i];
//     }
//     if(s.size()) vc.push_back(s);
//     return vc;
// }
// void solve(){
//     int n,h,m; cin >> n >> h >> m;
//     vector<User> vc;
//     for(int i = 0; i < n; i++){
//         string id,date,time;
//         cin >> id >> date >> time;
//         //cout << id << " " << date << " " << time << "\n";
//         User user = User(id,date,time);
//         vc.push_back(user);
//     }
//     vector<User> vc2;
//     for(int i = 0; i < vc.size(); i++){
//         string date = vc[i].date;
//         vector<string> date_s = split(date,'-');
//         string sh = to_string(h);
//         string sm = to_string(m);
//         if(sm.size() == 1) sm = '0' + sm; 
//         if(date_s[0] == sh && date_s[1] == sm){
//             vc2.push_back(vc[i]);
//         }
//     }
//     int ans1 = 0,ans2 = 0,ans3 = 0;
//     map<pair<string,int>,bool> mp;
//     for(int i = 0; i < vc2.size(); i++){
//         string id = vc2[i].id;
//         string time = vc2[i].time;
//         vector<string> time_s = split(time,':');
//         int hour = (time_s[0][0] - '0') * 10 + (time_s[0][1] - '0');
//         bool flag = (time_s[1] == "00" && time_s[2] == "00");
//         //cout << "? " <<hour << " " << flag << " " << time_s[1] << " " << time_s[2]  << "\n";
//         //1
//         if((hour >= 7 && hour < 9) || (hour >= 18 && hour < 20) || (flag && ( 
//             hour == 9 || hour == 20))){
//             if(!mp[{id,1}]){
//                 mp[{id,1}] = 1;
//                 ans1++;
//             }
//         }
//         //2
//         if((hour >= 11 && hour < 13) || (flag && ( hour == 13))){
//             if(!mp[{id,2}]){
//                 mp[{id,2}] = 1;
//                 ans2++;
//             }
//         }
//         //3
//         if((hour >= 22 || hour < 1) || (flag && (hour == 1))){
//             if(!mp[{id,3}]){
//                 mp[{id,3}] = 1;
//                 ans3++;
//             }
//         }
//     }
//     cout << ans1 << " " << ans2 << " " << ans3 << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*G 一起铸最好的剑！*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,m;cin >> n >> m;
//     ll tmp = m;
//     int cnt = 1;
//     if(m > 1e5 || m == 1){
//         cout << 1 << "\n";
//         return;
//     }
//     while(n > tmp){
//         tmp *= m;
//         cnt++;
//     }
//     //cout << "? " << cnt << " " << tmp << "\n";
//     if(cnt > 1 && abs((tmp/m) - n) <= abs(tmp - n)){
//         cnt--;
//     }
//     cout << cnt << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*F 一起找神秘的数！*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     ll l,r;cin >> l >> r;
//     cout << r - l + 1 << "\n"
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*A 一起奏响历史之音！*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int a[110];
// void solve(){
//     bool flag = 1;
//     a[1] = 1;
//     a[2] = 1;
//     a[3] = 1;
//     a[5] = 1;
//     a[6] = 1;
//     for(int i = 1; i <= 7; i++){
//         int x;cin >> x;
//         if(!a[x]) flag = 0;
//     }
//     if(flag) cout << "YES\n";
//     else cout << "NO\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*B 能去你家蹭口饭吃吗*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 5e5 + 10;
// int a[N];
// void solve(){
//     int n;cin >> n;
//     map<int,int> mp;
//     for(int i = 0; i < n; i++){
//          cin >> a[i];
//          mp[a[i]]++;
//     }
//     int ans;
//     int size = 0;
//     for(auto t : mp){
//         //cout << t.first << " " << t.second << " " << size << "\n";
//         if(size + t.second <= n / 2) size += t.second;
//         else {
//             ans = t.first - 1;
//             break;
//         }
//     }
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }