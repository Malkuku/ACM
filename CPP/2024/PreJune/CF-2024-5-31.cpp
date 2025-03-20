#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int, int>

/*A. Turtle and Piggy Are Playing a Game*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll two[40];
// void get1(){
//     two[0] = 1;
//     for(int i = 1; i <= 31; i++){
//         two[i] = two[i-1]*2;
//     }
// }
// int main(){
//     int t;cin >>t;
//     get1();
//     while(t--){
//         ll l, r;
//         cin >> l >> r;
//         int cnt = 0;
//         for (int i = 0; i <= 31; i++)
//         {
//             if (r < two[i])
//             {
//                 break;
//             }
//             else
//                 cnt++;
//         }
//         cout << cnt-1 << "\n";
//     }
//     return 0;
// }

/*B. Turtle and an Infinite Sequence*/
/*2024.6.3*/ //主要的问题是着急打表，打表后发现规律混乱，没有及时更改思考方向，这题的公式明显是可以推出第m秒的状态的
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// int main(){
//     ios::sync_with_stdio(0);
//     int t;cin >> t;
//     while(t--){
//         ll n,m;cin >> n >> m;
//         ll l = max(0ll,n-m);
//         ll r = n+m;//俩端
//         if(l == r){ //出现这种情况说明m为0
//             cout << l << "\n";
//             continue;
//         }
//         for(int i = 30; i >= 0; i--){
//             if(((l>>i)&1) == 0 && ((r>>i)&1)){ //从左到右找到第一个0，1的状态，0xxxx->1xxxx 这其中一定会或上01111
//                 cout << (l|((1<<i+1)-1)) << "\n";
//                 break;
//             }
//         }
//     }
// }

