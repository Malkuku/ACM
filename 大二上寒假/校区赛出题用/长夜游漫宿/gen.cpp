#include<iostream>
#include<fstream>
#include<random>
#include<algorithm>
#define endl '\n'
const int N = 1e5;
using namespace std;

std::random_device rd;  // 用于获得种子
std::mt19937 gen(rd()); // 初始化随机数生成器，这里使用了Mersenne Twister算法
std::uniform_int_distribution<> distrib(1,5000); // 定义分布范围[,]

void create_data(const string path) {
	ofstream fout(path);
	distrib.reset();
	distrib = std::uniform_int_distribution<>(1,5000);
	int t = distrib(gen);
	fout << t << endl;
	for (int i = 0; i < t; i++) {
        vector<int> arr(3);
        int maxn = 1e6 / t;
		distrib = std::uniform_int_distribution<>(1, maxn);
		arr[0] = distrib(gen);
        distrib = std::uniform_int_distribution<>(0, maxn - arr[0]);
		arr[1] = distrib(gen);
		distrib = std::uniform_int_distribution<>(0, maxn - arr[0] - arr[1]);
		arr[2] = distrib(gen);
        std::shuffle(arr.begin(), arr.end(), gen);
		fout << arr[0] << " " << arr[1] << " " << arr[2] << endl;

        int len  = arr[0] + arr[1] + arr[2];
		distrib = std::uniform_int_distribution<>(0, 2);
        string s;
		for (int j = 0; j < len; j++) {
            if(distrib(gen) == 0) s += 'G';
            else if(distrib(gen) == 1) s+= 'E';
            else s += 'L'; 
		}
        fout << s << endl;
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

int main() {
	work(20);
	return 0;
}
