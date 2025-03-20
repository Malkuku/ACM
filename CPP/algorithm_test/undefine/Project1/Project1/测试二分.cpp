#define _CRT_SECURE_NO_WARNINGS 1

//1.需要返回的坐标 在判断是不能是 = 那一边的
//2.二分返回的坐标是最接近中间的那一个
//3.if else 的顺序与返回无关

//#include<iostream>
//using namespace std;
//int n;int arr[10000];
//int findLow(int x) {
//	int r = n, l = 1;
//	while (r >= l) {
//		int mid = (r + l) >> 1;
//		if (x < arr[mid]) r = mid - 1;
//		else l = mid + 1;
//	}
//	return r;
//}
//int findUp(int x) {
//	int r = n, l = 1;
//	while (r >= l) {
//		int mid = (r + l) >> 1;
//		if (x > arr[mid]) l = mid + 1;
//		else r = mid - 1;
//	}
//	return l;
//}
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> arr[i];
//	}
//	int x; cin >> x;
//	int pos1 = findLow(x);
//	int pos2 = findUp(x);
//	cout << "Low: " << pos1 << " " << arr[pos1] << "\n";
//	cout << "Up: " << pos2 << " " << arr[pos2] << "\n";
//	return 0;
//}