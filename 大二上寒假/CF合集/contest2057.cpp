//Hello 2025

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

/*C. Trip to the Olympiad*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll two[110];
void init(){
    two[0] = 1;
    for(int i = 1; i <= 32; i++){
        two[i] = two[i-1] * 2;
    }
}
void solve(){
    ll l,r;cin >> l >> r;
    for(int i = 32; i <= 0; i++){

    }
}
int main(){
    int t = 1;cin >> t;
    while(t--){
        solve();
    }
}

/*B. Gorilla and the Exam*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// void solve(){
//     int n,k;cin >> n >> k;
//     map<int,int> mp1;
//     for(int i = 0; i < n; i++) {
//         int x;cin >> x;
//         mp1[x]++;
//     }
//     vector<int> vc;
//     for(auto t : mp1){
//         vc.push_back(t.second);   
//     }
//     sort(vc.begin(),vc.end());
//     int size = mp1.size();
//     for(int i = 0; i < vc.size(); i++){
//         if(k >= vc[i]){
//             k -= vc[i];
//             size--;
//         }
//         else break;
//     }
//     cout << max(1,size) << "\n";
// }
// int main(){
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*A. MEX Table*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,m;cin >> n >> m;
//     cout << max(n,m)+1 << "\n";
// }
// int main(){
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }