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
	distrib = std::uniform_int_distribution<>(1,1000);
	int n = distrib(gen);
    //int n = 1000;
    fout << n << endl;
    for(int i = 0 ; i < n; i++){
        distrib = std::uniform_int_distribution<>(-50,50);
        int x = distrib(gen);
        distrib = std::uniform_int_distribution<>(1e3,1e4);
        int w = distrib(gen);
        distrib = std::uniform_int_distribution<>(1,10);
        int y = distrib(gen);
        fout << x <<" "<< w << " " << y << "\n";
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
	///work(19);
    s_work(2);
	return 0;
}
