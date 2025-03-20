#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*Problem K. Welcome*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// int main(){
//     cout << "HBCPC2024\n";  
//     return 0;
// }

/*Problem A. Update*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// map<int,bool> g;
// int main(){
//     string s;cin >> s;
//     for(auto i : s){
//         if(i != 'i')g[i] = 1;
//     }
//     cout << g.size() << "\n";
//     return 0;
// }

/*Problem I. Subnet*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// string ss;
// int a1[4];
// int a2[4][1010];
// int num,n;
// string ans;
// //1.转化成二进制
// void so1(int x,string s){
//     int tmp = 0;
//     int cnt = 0;
//     for(int i = 0; i < s.size(); i++){
//         if(s[i] == '.'){
//             a2[cnt++][x] = tmp;
//             tmp = 0;
//             continue;
//         }
//         tmp*=10;
//         tmp += s[i] - '0';
//     }
//     a2[cnt++][x] = tmp;
// }
// void so2(){
//     for(int i = 0; i < 4; i++){
//         string s1;
//         for(int j = 0; j < 8; j++){
//             char ch = (a1[i] & 1) + '0';
//             s1 = ch + s1;
//             a1[i] >>= 1;
//         }
//         ans += s1; 
//     }
// }
// string so3(int x){
//     string ans;
//     for (int i = 0; i < 4; i++)
//     {
//         string s1;
//         for (int j = 0; j < 8; j++)
//         {
//             char ch = (a2[i][x] & 1) + '0';
//             s1 = ch + s1;
//             a2[i][x] >>= 1;
//         }
//         ans += s1;
//     }
//     return ans;
// }
// bool so4(string& s1,string& s2){
//     //cout << s1 << "\n";
//     //cout << s2 << "\n";
//     for(int i = 0; i < num; i++){
//         if(s1[i] != s2[i]) return 0;
//     }
//     return 1;
// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin >> ss;
//     int cnt = 0;
//     int tmp = 0;
//     for (int i = 0; i < ss.size(); i++)
//     {
//         if (ss[i] == '.' || ss[i] == '/')
//         {
//             a1[cnt++] = tmp;
//             tmp = 0; 
//             continue;
//         }
//         tmp *= 10;
//         tmp += ss[i] - '0';
//     }
//     num = tmp;
//     so2();
//     cin >> n;
//     //cout << "num " << num << "\n";
//     for(int i = 0; i < n; i++){
//         string s;cin >> s;
//         so1(i,s);
//         string s2 = so3(i); 
//         if(so4(ans,s2)) cout << "Yes\n";
//         else cout << "No\n";
//     }
//     return 0;
// }

/*Problem C. Goose Goose Duck*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// vector<int> ans;
// int n;
// const int N = 1e6 + 10;
// struct node{
//     int pos,f,s;
//     bool operator < (const node& w) const{
//         return s > w.s;
//     }
// } a[N];
// priority_queue<node> q;
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n;
//     for(int i = 0; i < n; i++){
//         int x,y;cin >> x >> y;
//         a[i] = {i+1,x,y};
//     }
//     sort(a,a+n,[](auto x,auto y){
//         return x.f < y.f;
//     });
//     int res = 0;
//     int cnt = 0;
//     while(1){
//         while(cnt < n && a[cnt].f <= res){
//             q.push(a[cnt]);
//             cnt++;
//         }
//         if(q.size() == 0) break;
//         auto t = q.top();q.pop();
//         if(t.s >= res && t.f <= res){
//             res++;
//             ans.push_back({t.pos});
//         } 
//     }
//     cout << res << "\n";
//     for(auto t : ans) cout << t << " ";
//     cout << "\n";
//     return 0;
// }

/*Problem G. Bracelet*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// int n,m,k;
// string s;
// string s1, s2, s3, s4;
// int so1(string& s){
//     int l = 0,r = 0;
//     int cnt1 = 0,cnt2 = 0,cnt3 = 0;
//     int ans = 0;
//     int res = 0;
//     int len = s.size();
//     //cout << len << "\n";
//     while(1){
//         bool flag = 0;
//         while (r < s.size()*2 && r < l+len && cnt1 <= n && cnt2 <= m && cnt3 <= k){
//             if(s[r%len] == '1') cnt1++;
//             else if(s[r%len] == '2') cnt2++;
//             else if(s[r%len] == '3') cnt3++;
//             if (cnt1 <= n && cnt2 <= m && cnt3 <= k)
//                 ans = max(ans, (cnt1 + cnt2 + cnt3) * 2);
//             r++;
//             flag = 1;
//         }
//         while (l <= r && (cnt1 > n || cnt2 > m || cnt3 > k)){
//             if (s[l%len] == '1')
//                 cnt1--;
//             else if (s[l%len] == '2')
//                 cnt2--;
//             else if (s[l%len] == '3')
//                 cnt3--;
//             if (cnt1 <= n && cnt2 <= m && cnt3 <= k)
//                 ans = max(ans, (cnt1 + cnt2 + cnt3) * 2);
//             l++;
//             flag = 1;
//         }
//         if (!flag && r < s.size() * 2 && r < l + len)
//         {
//             if (s[r%len] == '1')
//                 cnt1++;
//             else if (s[r%len] == '2')
//                 cnt2++;
//             else if (s[r%len] == '3')
//                 cnt3++;
//             if (cnt1 <= n && cnt2 <= m && cnt3 <= k)
//                 ans = max(ans, (cnt1 + cnt2 + cnt3) * 2);
//             r++;
//         }
//         else if (!flag && (r >= s.size() * 2 || r >= l + len)) break;
//     }
//    //cout << cnt1 << " " << cnt2 << " " << cnt3 << " " << "\n";
//     return ans;    
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n >> m >> k;
//     cin >> s;
//     //for(int i = 1; i <= (int)1e5+143; i++) s+='0';
//     //cout << s << "\n";
//     //cout << s.size() << "\n";
//     int len = s.size();
//     if(len <= 1) {
//         cout << 0 << "\n";
//         return 0;
//     }
//     for(int i = 0; i < s.size()-1; i+=2){
//         string tmp;tmp += s[i%len];
//         tmp += s[(i+1)%len];
//         if(tmp == "00") s1 += '1';
//         else if(tmp == "10" || tmp == "01") s1 += '2';
//         else if(tmp == "11") s1 += '3';
//         //cout << "& " << s1 << " " << tmp << "\n";
//     }
//     for (int i = 1; i < s.size(); i += 2)
//     {
//         string tmp;
//         tmp += s[i % len];
//         tmp += s[(i + 1) % len];
//         if (tmp == "00")
//             s2 += '1';
//         else if (tmp == "10" || tmp == "01")
//             s2 += '2';
//         else if (tmp == "11")
//             s2 += '3';
//     }
//     //cout << s1.size() << "\n";
//     //cout << s2.size() << "\n";
//     int ans1 = so1(s1);
//     int ans2 = so1(s2);
//     cout << max(ans1,ans2) << "\n";
// }
/*2024.6.2 题解（精）*/ //处理环形数组
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int, int>
int main(){
    ios::sync_with_stdio(0);
    int a,b,c;cin >> a >> b >> c;
    string s;cin >> s;
    s += s;
    int ans = 0;
    int len = s.size();
    int cnt1 = 0,cnt2 = 0,cnt3 = 0;
    for(int l = 0,r = 1; r < len; r += 2){
        auto sov1 = [&](int _l,int _f){
            if(s[_l] == s[_l+1]){
                if(s[_l] == '0'){
                    cnt1+= _f;
                }
                else cnt3+= _f;
            }
            else cnt2 += _f;
        };
        sov1(r-1,1);
        while(cnt1 > a || cnt2 > b || cnt3 > c || (r-l+1 > len/2)){
            sov1(l,-1);
            l += 2;
        }
        assert(l <= r+1);
        ans = max(ans,r-l+1);
    }
    cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int l = 1, r = 2; r < len; r += 2)
    {
        auto sov1 = [&](int _l, int _f)
        {
            if (s[_l] == s[_l + 1])
            {
                if (s[_l] == '0')
                {
                    cnt1 += _f;
                }
                else
                    cnt3 += _f;
            }
            else
                cnt2 += _f;
        };
        sov1(r - 1, 1);
        while (cnt1 > a || cnt2 > b || cnt3 > c || (r - l + 1 > len / 2))
        {
            sov1(l, -1);
            l += 2;
        }
        assert(l <= r + 1); //断言
        ans = max(ans, r - l + 1);
    }
    cout << ans << "\n";
    return 0;
}