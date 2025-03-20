
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
#define ll long long

void solve(const char* path_in,const char* path_out){
    std::ifstream fin(path_in);
    std::ofstream fout(path_out);

    int t; fin >> t;
    while(t--){
        int g,e,l;fin >> g >> e >> l;
        string s;fin >> s;
        int g2 = 0,e2 = 0,l2 = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'G') g2++;
            else if(s[i] == 'E') e2++;
            else if(s[i] == 'L') l2++;
        }
   
        int ans = 0;
        int tmp = min(g,e2);
        ans += tmp;
        g -= tmp;
        e2 -= tmp;
        tmp = min(e,l2);
        ans += tmp;
        e -= tmp;
        l2 -= tmp;
        tmp = min(l,g2);
        ans += tmp;
        l -= tmp;
        g2 -= tmp;

        tmp = min(g,g2);
        g -= tmp;
        g2 -= tmp;
        tmp = min(e,e2);
        e -= tmp;
        e2 -= tmp;
        tmp = min(l,l2);
        l -= tmp;
        l2 -= tmp;

        ans -= (l+e+g);

        fout << ans << "\n"; 
    }
    

   fout.close();
   fin.close();
}

void work(int num){
    for(int i = 1; i <= num; i++){
        char path_in[50];
        char path_out[50];
        sprintf(path_in,"test_in/%d.in",i);
        sprintf(path_out,"test_out/%d.out",i);
        solve(path_in,path_out);
        cout << path_out << "\n";
    }
}

int main(){
    work(20);
    return 0;
}
