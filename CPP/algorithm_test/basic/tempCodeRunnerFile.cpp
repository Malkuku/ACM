/*2024.5.31  题解*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
std::string _begin, _str, str;
//_begin 每组图形的开始部分
//_str 空柱子
// str  实际情况
int n,m;
int t[3][12],cnt[3],width;
//t[i][j]第i号柱第j层盘的编号
//cnt柱上的盘子数
//width最大盘的宽度

inline void print(){
    for(int floor = n,pos,len;floor;floor--){//第n层依次向上输出
        str = _str;
        for(int i = 0; i < 3; i++){//每个柱子此层的盘子
            if(cnt[i] >= floor){//如果有盘子
                len = 2*t[i][floor]+1;//盘子宽度
                pos = width*i+i+1+(width-len)/2;//起始位置
                for(int j = pos+1;j <= pos+len; j++){
                    str[j-1] = '*';
                }
            }
        }
        cout << str << "\n";
    }
}
void move(int a,int b){//从a移动到b
    t[b][++cnt[b]] = t[a][cnt[a]--];//b上增加的盘子等于a上减少的盘子
    cout<<_begin;
    print();
}

void hano(int n,int a,int b){
    if(n == 1){
        move(a,b);
        return;
    }
    hano(n-1,a,3-a-b); //中转柱，柱子编号从0开始
    move(a,b);
    hano(n - 1, 3 - a - b, b);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;m = 6*n+7;
    for(int i = 1; i <= n; i++) t[0][i] = n-i+1;//盘子由大到小依次编号
    cnt[0] = n;

    for(int i = 0; i < m; i++) _str+='.';
    width = 2*n+1;
    _str[width/2+1] = '|';
    _str[width+width/2+2] = '|';
    _str[width*2+width/2+3] = '|';
    _begin+='\n'+_str+'\n';

    cout << _begin;
    print();
    string tmp;
    for (int i = 0; i < m; i++) tmp += '-';
    _begin = tmp + "\n" + _begin;
    if(n&1) hano(n,0,1);
    else hano(n,0,2);
    return 0;
}