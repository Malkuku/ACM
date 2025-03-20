#include<bits/stdc++.h>
using namespace std;
#define ll long long

///*线性基模板*///
/*模板*/
// class lineP{
// public:
//     //获取线性基
//     void getP(){
//         for(int i = 0; i < N; i++){
//             add(a[i]);
//         }
//     }
//     //将数插入线性基中
//     void add(ll x){
//         for(int i = 60; i >= 0; i--){
//             if(x & (1ll << i)){
//                 if(p[i]) x^=p[i];
//                 else{
//                     p[i] = x;
//                     break;
//                 }
//             }
//         }
//     }
//     //求最大异或和--贪心过程
//     ll get_max_ans(){
//         ll ans = 0;
//         for(int i = 60; i >= 0; i--){
//             ans = max(ans,ans^p[i]);
//         }
//         return ans;
//     }
//     //求最小值：最小的p[i](如果是整个序列，则判断序列异或和是否可能为0)
//     //求第k小值
//     ll get_min_k_th(ll k){
//         if(k == 1 && flag) return 0;
//         if(flag) k--; //去掉0的情况
//         //处理线性基（新线性基与原性质相同）
//         for(int i = 1; i <= 60; i++){
//             for(int j = 1; j <= i; j++){
//                 if(p[i] & (1ll<<(j-1))) p[i] ^= p[j-1];
//             }
//         }
//         //遍历线性基
//         ll ans = 0;
//         for(int i = 0; i <= 60; i++){
//             if(p[i]){
//                 if(k&1) ans ^= p[i];
//                 k /= 2;
//             }
//         }
//         return ans;
//     }
//
//     //删除p中元素 -- ？？？
// private:
//     ll p[64]; //线性基
//     ll a[1010]; //原始数据
//     bool flag; //记录原序列是否可以异或出0
// };

///* 题目集 *///

/*P3812 【模板】线性基 */ //最大异或和
/*2024.9.24*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll p[64] = { 0 };
// void getP(ll x){
//     for(int i = 60; i >= 0; i--){
//         if(x & (1ll << i)){
//             if(p[i]) x^=p[i];
//             else {
//                 p[i] = x;
//                 break;
//             }
//         }
//     }
// }
// int main(){
//     int n;cin >> n;
//     for(int i = 0; i < n; i++){
//         ll x; cin >> x;
//         getP(x);
//     }
//     ll ans = 0;
//     for(int i = 60; i >= 0; i--){
//         ans = max(ans,ans^p[i]);
//     }
//     cout << ans << '\n';
//     return 0;
// }

/*hdu3949 XOR*/
/*2024.9.24*/ //非高斯消元法 //疑似WA
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll p[64];
// int num = 0;
// bool flag = 0;
// void getP(ll x){
//     ll sum = 0;
//     for(int i = 60; i >= 0; i--){
//         if(x & (1ll << i)){
//             if(p[i]) x^= p[i];
//             else{
//                 p[i] = x;
//                 num++;
//                 break;
//             }
//         }
//         if(p[i]) sum ^= p[i];
//     }
//     if(sum ^ x == 0) flag = 1;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     int t;cin >> t;
//     for(int _ = 1; _ <= t; _++){
//         cout << "Case #" << _ << ":\n";
//         memset(p,0,sizeof p);
//         num = 0;
//         flag = 0;
//         int n;cin >> n;
//         for(int i = 0; i < n; i++){
//             ll x;cin >> x;
//             getP(x);
//         }
//         for(int i = 1; i <= 60; i++){
//             for(int j = 1; j <= i; j++){
//                 if(p[i] & (1ll << (j-1))){
//                     //cout << "???\n";
//                     p[i] ^= p[j-1];
//                 }                
//             }
//         }
//         int q;cin >> q;
//         while(q--){
//             ll k; cin >> k;
//             ll ans = 0;
//             if(flag) k--;
//             if(k <= 0) {
//                 cout << 0 << "\n";
//                 continue;
//             }
//             if((1ll << num) - 1 < k){
//                 cout << -1 << "\n";
//                 continue;
//             }
//             for(int i = 0; i <= 60; i++){
//                 if(p[i]){
//                     if(k & 1) ans ^= p[i];
//                     k >>= 1;
//                 }
//             }
//             cout << ans << "\n";
//         }
//     }
//     return 0;
// }


