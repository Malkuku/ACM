//Round 996

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
// }
// int main(){
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*A. Two Frogs*/
// //相邻：NO
// //距离为1 -》 相邻态
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,a,b;cin >> n >> a >> b;
//     int c = abs(a - b);
//     if(c % 2){
//         cout << "No\n";
//     }else{
//         cout << "Yes\n";
//     }
// }
// int main(){
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*B. Crafting*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+10;
// int a[N],b[N];
// void solve(){
//     int n;cin >> n;
//     for(int i = 0; i < n; i++) cin >> a[i];
//     for(int i = 0; i < n; i++) cin >> b[i];
//     ll sum = 0;int pos = -1;
//     for(int i = 0; i < n; i++){
//         if(a[i] < b[i] && sum == 0){
//             sum = (b[i] - a[i]);
//             pos = i;
//             break;
//         }
//     }
//     if(sum == 0){
//         cout << "Yes\n";
//         return;
//     }
//     for(int i = 0; i < n; i++){
//         if(a[i] - sum < b[i] && pos != i){
//             cout << "No\n";
//             return;
//         }
//     }
//     cout << "Yes\n";
// }
// int main(){
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*C. The Trail*/
/*2025.1.26*/ //思维
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1010][1010];
bool b[1010][1010];
void solve(){
    int n,m;cin >> n >> m; string s;cin >> s;
    for(int i = 1;i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            b[i][j] = 0;
        } 
    }
    int x = 1,y = 1;
    b[1][1] = 1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'D') x++;
        else if(s[i] == 'R') y++;
        b[x][y] = 1;
    }
    auto get = [&](int x,int y){
        ll sum = 0; bool flag = 1;
        for(int i = 1; i <= n; i++){
            if(b[i][y] && i != x) flag = 0;
            sum += a[i][y];
        }
        if(flag){
            a[x][y] = -sum;
            b[x][y] = 0;
            return;
        }
        sum = 0;
        for(int i = 1; i <= m; i++){
            sum += a[x][i];
        }
        a[x][y] = -sum;
        b[x][y] = 0;
        return;
    };
    x = 1,y = 1;
    for(int i = 0; i < s.size(); i++){
        get(x,y);
        if(s[i] == 'D') x++;
        else if(s[i] == 'R') y++;
    }
    get(x,y);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << a[i][j] << " ";
        }cout << "\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    int t = 1;cin >> t;
    while(t--){
        solve();
    }
}
