#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
#define ll long long

int a[1010];

void solve(const char* path_in,const char* path_out){
    std::ifstream fin(path_in);
    std::ofstream fout(path_out);

    int n;fin >> n;
    for(int i = 0; i < n; i++){
        fin >> a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fout << a[(i+j) % n] << " ";
        }fout << "\n";
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
