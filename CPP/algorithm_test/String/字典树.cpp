
#include<bits/stdc++.h>
using namespace std;
#define ll long long


/*P2580 于是他错误的点名开始了 */ //静态数组字典树模板
/*2024.11.9*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 8e5+10 ;

struct Node{
    bool repeat; //是否重复
    int son[26]; //子树
    int num; //该前缀的出现次数
    bool isend; //是否为单词的结尾
}t[N];
int cnt = 1;// 当前新分配的储存位置 0--空根
void insert(string s){
    int now = 0;
    for(int i = 0; i < s.size(); i++){
        int ch = s[i] - 'a';
        if(t[now].son[ch] == 0){ //没有分配过
            t[now].son[ch] = cnt++; //分配cnt给字符
        }
        now = t[now].son[ch];
        t[now].num++; //统计前缀次数
    }
    t[now].isend = true; //单词结尾做标记
}

int find(string s){
    int now = 0;
    for(int i = 0; i < s.size();i++){
        int ch = s[i] - 'a';
        if(t[now].son[ch] == 0) return 3; //找不到
        now = t[now].son[ch];
    }
    if(!t[now].isend || !t[now].num) return 3;
    if(!t[now].repeat){
        t[now].repeat = 1;
        return 1; //第一次点名
    }
    return 2;
}

int main(){
    ios::sync_with_stdio(0);
    int n;cin >> n;
    for(int i = 0; i < n; i++){
         string s;cin >> s;
         insert(s);
    }
    int m;cin >> m;
    while(m--){
        string s;cin >> s;
        int ans = find(s);
        if(ans == 1){
            cout << "OK\n";
        }
        else if(ans == 2){
            cout << "REPEAT\n";
        }
        else if(ans == 3){
            cout << "WRONG\n";
        }
    }
   
    return 0;
}