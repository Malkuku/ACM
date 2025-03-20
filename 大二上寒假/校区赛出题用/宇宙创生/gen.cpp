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
	distrib = std::uniform_int_distribution<>(1,1e3);
	//int n = distrib(gen);
    int n = 10;
    fout << n << endl;
    vector<int> a(n);
    for(int i = 0 ; i < n; i++){
        distrib = std::uniform_int_distribution<>(1,100);
        a[i] = distrib(gen);
    }
    std::shuffle(a.begin(),a.end(),gen);
    for(auto t : a) fout << t << " ";
    fout << endl;
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
    s_work(2);
	return 0;
}
