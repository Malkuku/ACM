#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*A. Medium Number*/
//int main() {
//	int t; cin >> t;
//	while (t--) {
//		int a[3];
//		for (int i = 0; i < 3; i++) {
//			cin >> a[i];
//		}
//		sort(a, a + 3);
//		cout << a[1] << "\n";
//	}
//	
//	return 0;
//}

/*B. Atilla's Favorite Problem*/
//int main() {
//	int t; cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		string s;
//		cin >> s;
//		int maxn = 0;
//		for (int i = 0; i < n; i++) {
//			maxn = max(s[i] - 'a' + 1, maxn);
//		}
//		cout << maxn << "\n";
//	}
//	return 0;
//}

/*C. Advantage*/ // WA
//const int N = 2e5 + 10;
//ll arr[N];
//vector<ll> s;
//int main() {
//	ios::sync_with_stdio(0);
//	int t; cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		s.clear();
//		s.reserve(n);
//		bool flag = 1;
//		ll maxn = 0;
//		for (int i = 0; i < n; i++) {
//			cin >> arr[i];
//			s.push_back(arr[i]);
//		}
//		sort(s.begin(), s.end(), [](ll x, ll y) {
//			return x > y;});
//		if (s[0] == s[1]) flag = 0;
//		s.erase(unique(s.begin(), s.end()), s.end());
//		ll max1 = s[0];
//		ll max2 = s[0];
//		if (s.size() > 1 && flag) {
//			max2 = s[1];
//		}
//		for (int i = 0; i < n; i++) {
//			if (arr[i] != max1) {
//				cout << arr[i] - max1 << " ";
//			}
//			else cout << arr[i] - max2 << " ";
//		}cout << "\n";
//	}
//	return 0;
//}

/*D. Challenging Valleys*/ //想复杂了
//const int N = 2e5 + 10;
//vector<int> arr;
//int main() {
//	int t; cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		arr.clear();
//		arr.reserve(n);
//		for (int i = 0; i < n; i++) {
//			int x; cin >> x;
//			arr.push_back(x);
//		}
//		bool flag = 0;
//		bool biao1 = 0;
//		bool biao2 = 0;
//		bool biao3 = 1;
//		if (n > 1 && arr[0] == arr[1]) biao1 = 1;
//		if (n >= 3 && arr[n - 1] == arr[n - 2]) biao2 = 1;
//		arr.erase(unique(arr.begin(), arr.end()), arr.end());
//		int len = arr.size();
//		int cnt = 0;
//		int xiao = arr[0];
//		for (int i = 0; i < len; i++) {
//			xiao = min(xiao, arr[i]);
//		}
//		
//		if (n == 1) flag = 1;
//		else if (biao1 && xiao == arr[0]) {
//			flag = 1;
//			for (int i = 0; i < len-1; i++) {
//				if (arr[i] > arr[i+1]) flag = 0;
//			}
//		}
//		//else if (biao2 && xiao == arr[len - 1])
//		//{
//		//	flag = 1;
//		//	for (int i = 0; i < len-1; i++) {
//		//		if (arr[i] < arr[i+1]) flag = 0;
//		//	}
//		//}
//		else if (xiao < arr[0] && xiao < arr[len - 1]) {
//			flag = 1;
//			int cnt = 0;
//			if (arr[0] < arr[1]) flag = 0;
//			for (int i = 0; i < len - 1; i++) {
//				if (cnt == 0 && arr[i] > arr[i + 1]) cnt = 1;
//				else if (cnt == 1 && arr[i] < arr[i + 1]) cnt = 2;
//				else if (cnt == 2 && arr[i] > arr[i + 1]) cnt = 3;
//			}
//			if (cnt != 2) flag = 0;
//		}
//
//		if (flag == 1) cout << "YES\n";
//		else cout << "NO\n";
//	}
//	return 0;
//}
/*2024.3.21*/
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<algorithm>
//#include<queue>
//#include<map>
//#include<vector>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 2e5 + 10;
//int arr[N];
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		int n;cin >> n;
//		int di = 0x3f3f3f3f;
//		int pos = 0;
//		bool flag = 0;
//		for (int i = 0; i < n; i++) {
//			cin >> arr[i];
//			if (arr[i] < di) {
//				pos = i;
//				di = arr[i];
//			}
//		}
//		for (int i = pos; i < n-1; i++) {
//			if (arr[i] > arr[i + 1]) {
//				flag = 1;
//				break;
//			}
//		}
//		for (int i = pos; i > 0; i--) {
//			if (arr[i] > arr[i - 1]) {
//				flag = 1;
//				break;
//			}
//		}
//		if (flag) cout << "NO\n";
//		else cout << "YES\n";
//	}
//	return 0;
//}

/*E. Binary Inversions*/ //要开long long
//const int N = 2e5 + 10;
//int arr[N];
//int arr1[N];
//int arr2[N];
//
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		for (int i = 0; i < n; i++) {
//			cin >> arr[i];
//			arr1[i] = arr[i];
//			arr2[i] = arr[i];
//		}
//		for (int i = 0; i < n; i++) {
//			if (arr1[i] == 0) {
//				arr1[i] = 1;
//				break;
//			}
//		}
//		ll sum1 = 0;
//		ll cnt = 0;
//		for (int i = 0; i < n; i++) {
//			if (arr1[i] == 0) sum1 = sum1 + cnt;
//			else cnt++;
//			
//		}
//
//		for (int i = n - 1; i >= 0; i--) {
//			if (arr2[i] == 1) {
//				arr2[i] = 0;
//				break;
//			}
//		}
//		ll sum2 = 0;
//		cnt = 0;
//		for (int i = 0; i < n; i++) {
//			if (arr2[i] == 0) sum2 = sum2 + cnt;
//			else cnt++;
//		}
//		ll sum3 = 0;
//		cnt = 0;
//		for (int i = 0; i < n; i++) {
//			if (arr[i] == 0) sum3 += cnt;
//			else cnt++;
//		}
//		cout << max(sum3,max(sum1, sum2)) << "\n";
//	}
//}
//
//

/*F. Quests*/ //要先弄懂间隔的计算再写
////imp max*d < c
////inf  s >= c
//const int N = 2e5 + 10;
//ll arr[N];
//ll c, d;
//ll n;
//bool find(int x) { // x -> k
//	ll sum = 0;
//	ll tmp = d;
//	int i = 0;
//	if ((tmp - 1) / (x + 1) == 0) {
//		for (int i = 0; i < min(n, d); i++) {
//			sum += arr[i];
//		}
//		if (sum < c) return 0;
//		else return 1;
//	}
//	ll cnt = (tmp - 1) / (x + 1) + 1;
//	ll res = (tmp - 1) % (x + 1) + 1;
//	ll ccc = x + 1;
//	while (ccc-- && i < n) {
//		if (res > 0) {
//			sum += arr[i] * cnt;
//			res--;
//		}
//		else {
//			sum += arr[i] * (cnt-1);
//		}
//		i++;
//	}
//	if (sum < c) return 0;//k偏大
//	else return 1;
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		cin >> n;
//		cin >> c >> d;
//		for (int i = 0; i < n; i++) {
//			cin >> arr[i];
//		}
//		sort(arr, arr + n, [](ll x, ll y) {
//			return x > y;
//		});
//
//		ll sum = 0;
//		for (int i = 0; i < min(n, d); i++) {
//			sum += arr[i];
//		}
//		if (sum >= c) {
//			cout << "Infinity\n";
//			continue;
//		}
//		if (arr[0] * d < c) {
//			cout << "Impossible\n";
//			continue;
//		}
//
//		int l = 1, r = d;
//		while (l <= r) {
//			int mid = (l + r) >> 1;
//			if (find(mid) == 0) r = mid - 1;
//			else l = mid + 1;
//		}
//		cout << r << "\n";
//	}
//	return 0;
//}

