
#include<bits/stdc++.h>
using namespace std;
#define ll long long


/*P3805 【模板】manacher */
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1.1e7 + 5;
// int p[N << 1]; //记录回文半径
// string s,ss;
// int manacher(string& ss){
//     int ans = 0;
//     for(int i = 0,c = 0,r = 0,len; i < ss.size(); i++){
//         len = r > i ? min(p[2*c-i],r-i) : 1; //是否被r包裹
//         while(i + len < ss.size() && i - len >= 0 && ss[i + len] == ss[i - len]){
//             len++; //自动外扩--自动处理四种情况
//         }
//         if(i + len > r){ //更新边界r，中心点c
//             r = i + len;
//             c = i;
//         }
//         p[i] = len;
//         ans = max(len,ans);
//     }
//     return ans - 1; //len - 1等于原始串回文半径 
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> s;
//     ss = "#";
//     //处理原始串
//     for(int i = 0; i < s.size(); i++) {
//         ss += s[i];
//         ss += '#';
//     }
//     //cout << s << " " << ss << "\n";
//     int ans = manacher(ss);
//     cout << ans << "\n";
//     return 0;
// }

/*P5410 【模板】扩展 KMP/exKMP（Z 函数） */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e7+10;
int z[N];
int e[N];
void getZ(string b){
    z[0] = b.size();
    for(int i = 1,c = 1,r = 1; i < b.size(); i++){
        int len = r > i ? min(r - i,z[i-c]) : 0;
        while(len + i < b.size() && b[len + i] == b[len]) len++;
        if(i+len > r){
            c = i;
            r = i + len;
        }
        z[i] = len;
    }
}
void getE(string a,string b){
    for(int i = 0,c = 0,r = 0; i < a.size(); i++){
        int len = r > i ? min(r - i,z[i-c]) : 0;
        while(len + i < a.size() && len < b.size() && a[len + i] == b[len]) len++;
        if(i+len > r){
            c = i;
            r = len + i;
        }
        e[i] = len;
    }
}
int main(){
    ios::sync_with_stdio(0);
    string a,b;
    cin >> a >> b;
    getZ(b);
    getE(a,b);
    ll ans = 0;
    for(int i = 0; i < b.size(); i++){
        ans ^= 1ll * (i+1) * (z[i]+1);
    }
    cout << ans << "\n";
    ans = 0;
    for(int i = 0; i < a.size(); i++){
        ans ^= 1ll * (i+1) * (e[i]+1);
    }
    cout << ans << "\n";
    return 0;
}