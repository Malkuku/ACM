#include<iostream>
#include<fstream>
#include<random>
#include<algorithm>
#include<ctime>
#define endl '\n'
const int N = 1e5;
using namespace std;

std::mt19937 gen(static_cast<unsigned int>(time(nullptr))); // 初始化随机数生成器，这里使用了Mersenne Twister算法
std::uniform_int_distribution<> distrib(1,5000); // 定义分布范围[,]

void create_data(const string path) {
    ofstream fout(path);
	distrib.reset();
	distrib = std::uniform_int_distribution<>(1,1e4);
	//int n = distrib(gen);
    int n = 1000;
    distrib = std::uniform_int_distribution<>(1,min((int)5e3,n+10));
    //int m = distrib(gen);
    int m = 5e3;
    distrib = std::uniform_int_distribution<>(50,1e4);
    int k = distrib(gen);
    //int k = 1e4;
    fout << n << " " << m << " " << k << endl;
    vector<int> a(n);
    for(int i = 0 ; i < n; i++){
        distrib = std::uniform_int_distribution<>(1,1000);
        a[i] = distrib(gen);
    }
    std::shuffle(a.begin(),a.end(),gen);
    for(auto t : a) fout << t << " ";
    fout << endl;

    distrib = std::uniform_int_distribution<>(1,n);
    for(int i = 0; i < m; i++){
        int x,y;
        while(1){
            x = distrib(gen);
            y = distrib(gen);
            if(x != y) break;
        }
        fout << x << " " << y << endl;
    }
	fout.close();
}

void work(int num){
	for(int i = 2; i <= num; i++){
		const string path = "test_in/" + to_string(i) + ".in";
		cout << path << "\n";
		create_data(path);
	}
}

void s_work(int num){
    const string path = "test_in/" + to_string(num) + ".in";
	cout << path << "\n";
	create_data(path);
}

int main() {
	//work(20);
    s_work(3);
	return 0;
}
