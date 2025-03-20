#include "testlib.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    setName("check sum of two numbers"); // 设置评分器名称

    registerTestlibCmd(argc, argv); // 注册 Testlib 命令行参数

    int n = inf.readInt();
    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = inf.readInt();

    int ans = 0;
    for(int i = 0; i < n; i++) ans ^= a[i];

    vector<vector<int>> b(n,vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            b[i][j] = ouf.readInt();
        }
    }
    
    for(int i = 0; i < n; i++){
        if(b[0][i] != a[i]) {
            quitf(_wa, "The answer is wrong(1). ");
            return 0; 
        }
    }

    for(int i = 0; i < n; i++){
        int anss = 0;
        for(int j = 0; j < n; j++){
            anss ^= b[i][j];
        }
        if(anss != ans){
            quitf(_wa, "The answer is wrong(2). ");
            return 0; 
        }
    }

    for(int j = 0; j < n; j++){
        int anss = 0;
        for(int i = 0; i < n; i++){
            anss ^= b[i][j];
        }
        if(anss != ans){
            quitf(_wa, "The answer is wrong(2). ");
            return 0; 
        }
    }

    quitf(_ok, "The answer is correct."); 

    return 0;
}