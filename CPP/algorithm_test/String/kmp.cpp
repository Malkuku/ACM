//1.得到Next数组
//2.通过Next数组跳过匹配串

#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*hdu2087 剪花布条*/ //KMP模板
/*2024.11.12*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1010;
int Next[N];
int cnt = 0;
void getNext(string p){
    Next[0] = 0;Next[1] = 0;
    for(int i = 1; i < p.size(); i++){
        int j = Next[i];
        while(j && p[i] != p[j]){
            j = Next[j];
        }
        if(p[i] == p[j]) Next[i + 1] = j+1;
        else Next[i+1] = 0;
    }
}
int main(){
    ios::sync_with_stdio(0);
    string s;cin >> s;
    while(s[0] != '#'){
        string p;cin >> p;
        cnt = 0;
        int last = -1;
        getNext(p);
        //for(int i = 0; i < p.size(); i++) cout << Next[i] << " ";
        //cout << "\n";

        int j = 0;
        for(int i = 0; i < s.size(); i++){
            while(j && s[i] != p[j]){
                j = Next[j];
            }
            if(s[i] == p[j]) j++;
            if(j == p.size()){
                if(i- last >= p.size()){ //本题:判断匹配能否分开
                    cnt++;
                    last = i;
                }
            }
        }
        cout << cnt << "\n";
        cin >> s;
    }
    return 0;
}