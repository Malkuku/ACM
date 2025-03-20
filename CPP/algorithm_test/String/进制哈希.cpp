//通常取31，131，1313，13131作为进制数
//key值 abc 'a'*131^2 + 'b'*131^1 + 'c'*131^0

#include<bits/stdc++.h>
using namespace std;
#define ll long long



/*P4391 [BOI2009] Radio Transmission 无线传输 */ //最短循环节
/*2024.11.5*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ull unsigned long long
// ull pp = 131;
// const int N = 1e6+10;
// string s;
// ull P[N],H[N];
// int n;
// ull get_hash(int l,int r){
//     return H[r] - H[l-1] * P[r-l+1]; 
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n;cin >> s;
//     s = " " + s;
//     P[0] = 1;
//     for(int i = 1; i <= n; i++) P[i] = P[i-1] * pp;
//     for(int i = 1; i <= n; i++){
//         H[i] = H[i-1] *pp + s[i];
//     }
//     for(int i = 1; i <= n; i++){ //找【1，i】的循环节
//         bool flag = 1;
//         ull last = get_hash(1,i);
//         for(int j = 1; (j+1) <= n / i; j++){
//             if(get_hash(j * i +1,j*i + i) != last){
//                 flag = 0;
//                 break;
//             }
//         }
//         if(n % i != 0){
//             ull len = n % i;
//             if(get_hash(1,len) != get_hash(n - len + 1,n)){
//                 flag = 0;
//             }
//         }
//         if(flag){
//             cout << i << "\n";
//             return 0;
//         }
//     }
//     return 0;
// }

/*P3370 【模板】字符串哈希 */
/*2024.11.5*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ull unsigned long long //用于自然溢出的hash精度
// ull a[10010];
// char s[10010];
// ull BKDRHash(char * s){
//     ull p = 131,H= 0;
//     int n = strlen(s);
//     for(int i = 0; i < n; i++){
//         H = H * p + s[i] - 'a' + 1;
//     }
//     return H;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     int n;cin >> n;
//     for(int i = 0; i < n; i++){
//         cin >> s;
//         a[i] = BKDRHash(s);
//     }
//     int ans= 0;
//     sort(a,a+n);
//     for(int i = 0; i < n;i++){
//         if(a[i] != a[i+1]) ans++;
//     }
//     cout << ans << "\n";
//     return 0;
// }

/*P3501 [POI2010] ANT-Antisymmetry */ //BKDRHash求回文串
/*2024.11.5 题解*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ull unsigned long long
// const int N = 5e5+10;
// string s,t;
// int n,p = 131;
// long long ans;
// ull P[N],fix_s[N],fix_t[N]; //P的i次方，前缀hash和
// void bin_search(int x){
//     int L = 0,R = min(x,n-x);
//     while(L<R){
//         int mid = (L+R+1)>>1;
//         if(fix_s[x] - fix_s[x-mid]*P[mid] == fix_t[x+1] - fix_t[x+1+mid]*P[mid]){
//             L = mid;
//         }
//         else R = mid-1;
//     }
//     ans += L;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n;cin >> s;
//     s = " " + s;
//     t = " ";
//     ans = 0;
//     for(int i = 1; i <= n; i++) t += s[i] == '1' ? '0' : '1';
//     P[0] = 1;
//     for(int i = 1; i <= n; i++) P[i] = P[i-1] *p;
//     for(int i = 1; i <= n; i++) fix_s[i] = fix_s[i-1]*p + s[i];
//     for(int i = n; i >= 1; i--) fix_t[i] = fix_t[i+1]*p + t[i];
//     for(int i = 1;i <= n; i++) bin_search(i);
//     cout << ans << "\n";
//     return 0;
// }