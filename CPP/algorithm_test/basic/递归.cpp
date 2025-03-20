#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*NC204382 中序序列*/ //二叉树（精）
//题中给了“只有一个节点时看作左节点”，使得中间节点得以在先后序遍历中唯一确定
/*2024.7.6 题解*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// vector<int> ans;
// class Solution
// {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      *
//      * @param n int 二叉树节点数量
//      * @param pre intvector 前序序列
//      * @param suf intvector 后序序列
//      * @return intvector
//      */
//     void zhong(int l1,int r1,int l2,int r2,vector<int>& pre,vector<int>& suf){
//         if(l1 > r1) return;
//         if(l1 == r1){
//             ans.push_back(pre[l1]);//最左，只有一个节点，左节点
//             return;
//         }
//         //在后序中找到左右子树
//         int pos = -1;
//         for(int i = l2; i <= r2; i++){
//             if(suf[i] == pre[l1+1]){
//                 pos = i; //包括自己往前是左子树，向后到pre[l1]是右子树
//             }
//         }
//         //左子树 //l1+1是l1的左子树
//         //pos-l2 相当于包含的左子树长度
//         if(r1 > l1) zhong(l1+1,l1+1+pos-l2,l2,pos,pre,suf); 
//         if(r1 >= l1 || r2 >= l2) ans.push_back(pre[l1]);//中节点
//
//         //右子树
//         //l1+1+左子树长度+1 == 右子树的根坐标
//         //pos+1左子树根+1 == 右子树,r2-1 除去中节点
//         if(r2 > l2) zhong(l1+pos-l2+2,r1,pos+1,r2-1,pre,suf);
//     }
//     vector<int> solve(int n, vector<int> &pre, vector<int> &suf)
//     {
//         zhong(0,n-1,0,n-1,pre,suf);
//         return ans;
//     }
// };

/*NC16692 [NOIP2001]求先序排列*/ //二叉树
/*2024.6.1 题解()**/ //中根分割左右子树
// //先找到根节点并输出，即后序遍历的最后一点。
// //将中序遍历和后序遍历后的序列各分为两棵子树。
// //递归，重复一，二步骤，直到中序遍历后的长度小于等于0。
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// void tree(string s1,string s2){
//     int len1 = s1.size();
//     int len2 = s2.size();
//     if(len1 > 0){
//         char ch = s2[len2-1];
//         cout << ch;
//         int pos = s1.find(ch);
//         tree(s1.substr(0,pos),s2.substr(0,pos));//左子树
//         tree(s1.substr(pos+1),s2.substr(pos,len1-pos-1));//右子树
//     }
// }
// int main(){
//     string str1,str2;cin >> str1 >> str2;
//     tree(str1,str2);
//     return 0;
// }


/*NC201605 Bits*/ //汉罗塔+恶心打印
/*2024.5.31 卡在移动(UF)*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// string s;
// int n;
// char get1(char a,char b,char c){
//     if(a == 'a' && c == 'b') return '1';//ab
//     if(a == 'a' && c == 'c') return '2'; //ac
//     if (a == 'b' && c == 'a') return '3'; //ba
//     if(a == 'b' && c == 'c') return '4';//bc
//     if(a == 'c' && c == 'a') return '5';//ca
//     if(a == 'c' && c == 'b') return '6';//cb
// }
// void hano(int n,char a,char b,char c){
//     if(n == 1){
//         s += get1(a,b,c);
//         return;
//     }
//     hano(n-1,a,c,b);
//     s+=get1(a,b,c);
//     hano(n-1,b,a,c);
// }
// char g[3000][3000];
// char f[3000];
// int pos1,pos2,pos3;
// void init1()
// { // 初始化棋盘
//     pos1 = ((2 * n + 1 + 1) >> 1) + 1;
//     pos2 = (3 * (2 * n + 1) + 4 + 1) >> 1;
//     pos3 = (3 * (2 * n + 1) + 4) - ((2 * n + 1 + 1) >> 1);
//     for(int i = 1; i <= n + 2; i++){
//         for(int j = 1; j <= 3*(2*n+1)+4;j++){
//             g[i][j] = '.';
//         }
//     }
//     for(int i = 2; i <= n + 2; i++){
//         g[i][pos1] = '|';
//         g[i][pos2] = '|';
//         g[i][pos3] = '|';
//     }
//     memset(f+1, '-', 3 * (2 * n + 1) + 4);
//     for(int i = n + 2; i >= 3; i--){
//         for(int l = 0; l <= i - 2; l++){
//             g[i][pos1-l] = '*';
//         }
//         for(int r = 0; r <= i - 2; r++){
//             g[i][pos1+r] = '*';
//         }
//     }
// }
// void print1(){
//     for(int i = 1; i <= n + 2; i++) printf("%s\n",g[i]+1);
//     printf("%s\n",f+1);
// }
// int main(){
//     cin >> n;
//     if(n & 1) hano(n,'a','c','b');
//     else hano(n,'a','b','c');
//     init1();
//     print1();
// }
/*2024.5.31  题解(精)*/ //分成一层层
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// std::string _begin, _str, str;
// //_begin 每组图形的开始部分
// //_str 空柱子
// // str  实际情况
// int n,m;
// int t[3][12],cnt[3],width;
// //t[i][j]第i号柱第j层盘的编号
// //cnt柱上的盘子数
// //width最大盘的宽度
// inline void print(){
//     for(int floor = n,pos,len;floor;floor--){//第n层依次向上输出
//         str = _str;
//         for(int i = 0; i < 3; i++){//每个柱子此层的盘子
//             if(cnt[i] >= floor){//如果有盘子
//                 len = 2*t[i][floor]+1;//盘子宽度
//                 pos = width*i+i+1+(width-len)/2;//起始位置
//                 for(int j = pos+1;j <= pos+len; j++){
//                     str[j-1] = '*';
//                 }
//             }
//         }
//         cout << str << "\n";
//     }
// }
// void move(int a,int b){//从a移动到b
//     t[b][++cnt[b]] = t[a][cnt[a]--];//b上增加的盘子等于a上减少的盘子
//     cout<<_begin;
//     print();
// }
// void hano(int n,int a,int b){
//     if(n == 1){
//         move(a,b);
//         return;
//     }
//     hano(n-1,a,3-a-b); //中转柱，柱子编号从0开始
//     move(a,b);
//     hano(n - 1, 3 - a - b, b);
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n;m = 6*n+7;
//     for(int i = 1; i <= n; i++) t[0][i] = n-i+1;//盘子由大到小依次编号
//     cnt[0] = n;
//
//     for(int i = 0; i < m; i++) _str+='.',_begin+='.';
//     width = 2*n+1;
//     _str[width/2+1] = '|';
//     _str[width+width/2+2] = '|';
//     _str[width*2+width/2+3] = '|';
//     _begin+='\n'+_str+'\n';
//
//     cout << _begin;
//     print();
//     string tmp;
//     for (int i = 0; i < m; i++) tmp += '-';
//     _begin = tmp + "\n" + _begin;
//     if(n&1) hano(n,0,1);
//     else hano(n,0,2);
//     return 0;
// }

/*NC201839 	牛牛的汉诺塔*/ //汉罗塔（精）
/*2024.5.30 打表法*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// map<string,ll> g;
// ll sum = 0;
// void hano(int n,char A,char B,char C){
//     if(n == 55){ //要注意打表是目前A，B，C所对应的状态，而不是实际a,b,c对应的状态
//         string ab;
//         ab += A, ab += B;
//         string ac;
//         ac += A, ac += C;
//         string ba;
//         ba += B, ba += A;
//         string bc;
//         bc += B, bc += C;
//         string ca;
//         ca += C, ca += A;
//         string cb;
//         cb += C, cb += B;
//         g[ab] += 4003199668773783;
//         g[ac] += 8006399337547567;
//         g[ba] += 8006399337547539;
//         g[bc] += 4003199668773783;
//         g[ca] += 4003199668773756;
//         g[cb] += 8006399337547539;
//         sum += 36028797018963967;
//         return;
//     }
//     if(n == 40){
//         string ab;
//         ab += A, ab += B;
//         string ac;
//         ac += A, ac += C;
//         string ba;
//         ba += B, ba += A;
//         string bc;
//         bc += B, bc += C;
//         string ca;
//         ca += C, ca += A;
//         string cb;
//         cb += C, cb += B;
//         g[ab] += 244335917290;
//         g[ac] += 122167958655;
//         g[ba] += 122167958635;
//         g[bc] += 244335917290;
//         g[ca] += 244335917270;
//         g[cb] += 122167958635;
//         sum += 1099511627775;
//         return;
//     }
//     if(n == 20){
//         string ab;ab += A, ab += B;
//         string ac;ac += A, ac += C;
//         string ba;ba += B, ba += A;
//         string bc;bc += B, bc += C;
//         string ca;ca += C, ca += A;
//         string cb;cb += C, cb += B;
//         g[ab] += 233020;
//         g[ac] += 116515;
//         g[ba] += 116505;
//         g[bc] += 233020;
//         g[ca] += 233010;
//         g[cb] += 116505;
//         sum += 1048575;
//         return;
//     }
//     if(n == 1){
//         string s;s+=A;
//         s+=C;
//         g[s]++;
//         sum++;
//         return;
//     }
//     hano(n-1,A,C,B);
//     string s;
//     s += A;
//     s += C;
//     g[s]++;
//     sum++;
//     hano(n-1,B,A,C);
// }
// int main(){
//     ios::sync_with_stdio(0);
//     int n;cin >> n;
//     hano(n,'A','B','C');
//     cout << "A->B:" << g["AB"] << "\n";
//     cout << "A->C:" << g["AC"] << "\n";
//     cout << "B->A:" << g["BA"] << "\n";
//     cout << "B->C:" << g["BC"] << "\n";
//     cout << "C->A:" << g["CA"] << "\n";
//     cout << "C->B:" << g["CB"] << "\n";
//     cout << "SUM:" << sum << "\n";
//     return 0;
// }
/*2024.5.30 题解 记忆化搜索*/ //仿照的是打表的方法，在递归里面写dp不可取
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ms(a,b) memset((a),(b),sizeof(a))
// int _(char a,char b){
//     if(a == 'a' && b == 'b') return 1;//ab
//     if(a == 'a' && b == 'c') return 2;//ac
//     if(a == 'b' && b == 'a') return 3;//ba
//     if(a == 'b' && b == 'c') return 4;//bc
//     if(a == 'c' && b == 'a') return 5;//ca
//     if(a == 'c' && b == 'b') return 6;//cb
// }
// struct node{
//     ll sum[7];
//     node(){ms(sum,0);};//构造 初始化数组
//     node operator +(const node & x)const{ //tmp【i】分别加上另一个tmp【i】的值
//         node tmp;
//         for(int i = 1; i <= 6;i++) tmp.sum[i] = sum[i] + x.sum[i];
//         return tmp;
//     }
//     ll getsum(){
//         ll tmp = 0;
//         for(int i = 1; i <= 6; i++) tmp += sum[i];
//         return tmp;
//     }
// }ans;
// using tu = tuple<int,char,char,char>;//元组
// map<tu,bool> vis;//该组合是否已经被搜索到
// map<tu,node>ma;//该组合下的node值
// node hano(int n,char a,char b,char c){
//     tu p = make_tuple(n,a,b,c); //这里不能用{}
//     if(vis[p]) return ma[p]; //访问过，直接返回值
//     node tmp;
//     if(n == 1){
//         tmp.sum[_(a,c)]++;
//         return tmp;
//     }
//     tmp = tmp + hano(n-1,a,c,b);
//     tmp.sum[_(a,c)]++;
//     tmp = tmp + hano(n-1,b,a,c);
//     vis[p] = 1;
//     return ma[p] = tmp;
// }
//
// int main(){
//     ios::sync_with_stdio(0);
//     int n; cin >> n;
//     node ans = hano(n,'a','b','c');
//     printf("A->B:%lld\n", ans.sum[1]);
//     printf("A->C:%lld\n", ans.sum[2]);
//     printf("B->A:%lld\n", ans.sum[3]);
//     printf("B->C:%lld\n", ans.sum[4]);
//     printf("C->A:%lld\n", ans.sum[5]);
//     printf("C->B:%lld\n", ans.sum[6]);
//     printf("SUM:%lld\n", ans.getsum());
//     return 0;
// }


/*NC207028 第k小数*/ //快读卡常
/*2024.5.29*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 5e6+10;
// inline int read()
// {
//     int x = 0, f = 1;
//     char ch = getchar();
//     while (ch < '0' || ch > '9')
//     {
//         if (ch == '-')
//             f = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9')
//     {
//         x = (x << 1) + (x << 3) + (ch ^ 48);
//         ch = getchar();
//     }
//     return x * f;
// }
// int a[N];
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0),cout.tie(0);
//     int t = read();
//     while(t--){
//         int n = read(),k = read();
//         for(int i = 0; i < n; i++) a[i] = read();
//         sort(a,a+n);
//         cout << a[k-1] << "\n";
//     }
// }

/*NC208813 求逆序数*/
/*2024.5.29*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int a[1010];
// int main(){
//     int n;cin >> n;
//     for(int i = 0; i < n; i++) cin >> a[i];
//     int cnt = 0;
//     for(int i = 0; i < n; i++){
//         for(int j = i+1; j < n; j++){
//             if(a[i] > a[j]) cnt++;
//         }
//     }
//     cout << cnt << "\n";
//     return 0;
// }

/*NC22164 更相减损术*/
/*2024.5.29*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll gcd(ll a,ll b){
//     return b ? gcd(b,a%b) : a;
// }
// int main(){
//     ll a,b;cin >> a >> b;
//     cout << gcd(a,b) << "\n";
// }
/*更相减损术做法*/
// // 第一步：任意给定两个正整数；判断它们是否都是偶数。若是，则用2约简；若不是则执行第二步。
// //第二步：以较大的数减较小的数，接着把所得的差与较小的数比较，并以大数减小数。继续这个操作，直到所得的减数和差相等为止。
// //则第一步中约掉的若干个2的积与第二步中等数的乘积就是所求的最大公约数。
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
//
// int main(){
//     ll a,b,c;
//     cin >> a >> b;
//     ll ans = 1;
//     while(!(a&1||b&1)){
//         a/=2,b/=2,ans*=2;
//     }
//     while(a != b){ 
//         c = abs(a - b); //abs防止报错 
//         a = b;
//         b = c;
//     }
//     ans *= b;
//     cout << ans << "\n";
//     return 0;
// }

/*NC15173 The Biggest Water Problem*/
/*2024.5.29*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int ans = 0;
// void sov1(ll x)
// {
//     if (x <= 9)
//     {
//         ans = x;
//         return;
//     }
//     ll tmp = 0;
//     while (x)
//     {
//         tmp += x % 10;
//         x /= 10;
//     }
//     sov1(tmp);
// }
// int main(){
//     ll x;cin >> x;
//     sov1(x);
//     cout << ans << "\n";
// }
