#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
using namespace std;
#define PII pair<int,int>
#define ll long long

/*A ���ʿ��� */
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#include<vector>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//int dx[] = { 1,0,-1,0 };
//int dy[] = { 0,1,0,-1 };
//int main() {
//	int a, b, k;
//	cin >> a >> b >> k;
//	if (a >= k * b)cout << "good\n";
//	else cout << "bad\n";
//	return 0;
//}

/*B ���һ��� */
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#include<vector>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//int dx[] = { 1,0,-1,0 };
//int dy[] = { 0,1,0,-1 };
//const int N = 2e5 + 10;
//int main() {
//	int n; cin >> n;
//	int a;
//	int cnt = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> a;
//		if (a % 2) cnt += 2;
//		else cnt++;
//	}
//	if (cnt % 2) cout << "gui\n";
//	else cout << "sweet\n";
//}

/*G �������Σ�easy�� (TLE)*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#include<vector>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//int n, m;
//char g[510][510];
//int ans = 0;
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		cin >> g[i];
//	}
//	for (int i = 0; i < n-1; i++) {
//		for (int j = 1; j < m-1; j++) {
//			if (g[i][j] == '*') {
//				int cnt = i+1;
//				while (cnt < n) {
//					bool cot = 1;
//					int res = 0;
//					int q = cnt - i;
//					if (g[cnt][j] == '*') {
//						int r = j+1, l = j-1;
//						while (r < m && l >= 0 && q--) {
//							if (g[cnt][r] == '*' && g[cnt][l] == '*') res += 2;
//							r++;l--;
//						}
//					}
//					else {
//						int r = j + 1, l = j - 1;
//						int res2 = 0; 
//						while (r < m && l >= 0 && q--) {
//							if (g[cnt][r] == '*' && g[cnt][l] == '*') res2 += 2;
//							r++;l--;
//						}
//						if (res2 != (cnt - i) * 2) cot = 0;
//					}
//					if (!cot) break;
//					if (res == (cnt - i) * 2) {
//						ans++;
//						//cout << i << " " << j << "\n";
//					}
//					cnt++;
//				}
//			}
//		}
//	}
//	cout << ans << "\n";
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#include<vector>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//int n, m;
//char g[3010][3010];
//int ans = 0;
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		cin >> g[i];
//	}
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = 1; j < m - 1; j++) {
//			if (g[i][j] == '*') {
//				int cnt = i + 1;
//				int cntt = 3;
//				while (cnt < n && cntt--) {
//					bool cot = 1;
//					int res = 0;
//					int q = cnt - i;
//					if (g[cnt][j] == '*') {
//						int r = j + 1, l = j - 1;
//						while (r < m && l >= 0 && q--) {
//							if (g[cnt][r] == '*' && g[cnt][l] == '*') res += 2;
//							r++;l--;
//						}
//					}
//					else {
//						int r = j + q, l = j - q;
//						if (g[cnt][r] != '*' || g[cnt][l] != '*') cot = 0;
//
//					}
//					if (!cot) break;
//					if (res == (cnt - i) * 2) {
//						ans++;
//						//cout << i << " " << j << "\n";
//					}
//					cnt++;
//				}
//			}
//		}
//	}
//	cout << ans << "\n";
//	return 0;
//}
/*2024.2.22 �۱������Ż�*/ //һ��Ҫ������ȥ���٣���������Ҳ����if�ķ�֧Ҫ�����ܵ��� //�ܹ��ൽһ������Ĺ��ൽһ�����ȥ
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#include<vector>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//int n, m;
//char g[510][510];
//int ans = 0;
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		cin >> g[i];
//	}
//	for (int i = 0; i < n-1; i++) {
//		for (int j = 1; j < m-1; j++) {
//			if (g[i][j] == '*') {
//				int x = 1;
//				while (x + i < n) {
//					//if (g[i][j] == '*' || g[i][j] == '*') 1 == 1;
//					//if (g[i][j] != '*') 2 == 2; //���Կ���ʱ��??û�гɹ�
//					if (j + x >= m || j - x < 0) break;
//					if (g[x + i][j + x] != '*' || g[x + i][j - x] != '*') break;
//					int r = j + x;
//					int l = j - x;
//					int res = 0;
//					for (int k = l; k <= r; k++) {
//						if (g[x + i][k] == '.') res++;
//					}
//					/*while (l < r) {
//						if (g[x+i][l] != '*' || g[x+i][r] != '*') break;
//						l++;
//						r--;
//						res++;
//					}*/
//					//if (res != x) flag = 1;//????? ����WA������
//					if (res == 0) ans++;
//					x++;
//				}
//			}
//		}
//	}
//	cout << ans << "\n";
//	return 0;
//}
/*2024.2.22 ��� ����ö��*/
//#include <bits/stdc++.h>
////#define int long long 
//using namespace std;
//char s[510][510];
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//
//    for (int i = 0; i < n; i++) {
//        cin >> s[i];
//    }
//
//    int cnt = 0;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (s[i][j] == '*') {
//                int x = 1;//����
//                while (i + x < n && j - x >= 0 && j + x < m && s[i + x][j - x] == '*' && s[i + x][j + x] == '*') {
//                    int sum = 0;
//                    for (int k = j - x; k <= j + x;k++) {
//                        if (s[x][k] == '.') sum++;
//                    }
//                    if (sum == 0) cnt++;
//                    x++;
//                }
//            }
//        }
//    }
//
//    cout << cnt << endl;
//
//    return 0;
//}



/*H �������Σ�hard��*/ //�߶���+Ԥ����

/*C ����*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#include<vector>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//char g[110][110];
//int n, m, x, y;
//int p, q;
//int op[110];
//int z[110];
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> m >> x >> y;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> g[i][j];
//		}
//	}
//	cin >> p >> q;
//	for (int i = 0; i < q; i++) {
//		cin >> op[i] >> z[i];
//	}
//	while (p--) {
//		for (int j = 0; j < q; j++) {
//			if (op[j] == 1) {
//				char tmp = g[z[j]][m];
//				for (int i = m + 1; i > 0; i--) {
//					g[z[j]][i] = g[z[j]][i - 1];
//				}
//				g[z[j]][1] = tmp;
//			}
//			else if (op[j] == 2) {
//				char tmp = g[n][z[j]];
//				for (int i = n + 1; i > 0; i--) {
//					g[i][z[j]] = g[i - 1][z[j]];
//				}
//				g[1][z[j]] = tmp;
//			}
//		}
//	}
//	cout << g[x][y] << "\n";
//	return 0;
//}

/*D �غ�*/ //˼ά
//�п��ܲ���ȫż��ʱ����2��4��8...��ǰ����1�����ڣ���ż��������(ȡ������С��ż��)
//һ������1 //���ܻᱻ�ظ�����
//���Լ�����Ӽ���ȡ
/*2024.2.22 <�غ�>*/
////һ�����ޱ仯����Ŀ��ץסʲô�ǲ���Ĳ��ǹؼ�
////���ۣ������������������ܺ͵Ĺ�������������������ƽ����
////WA:���������� //��n == 1��ʱ��
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#include<vector>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//ll n; ll sum = 0;
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		ll a;cin >> a;
//		sum += a;
//	}
//	ll avg = sum / n;
//	int ans = 0;
//	for (int i = 1; i <= sum / n; i++) {
//		if (sum % i == 0) ans++;
//	}
//	if (n == 1) cout << 1 << "\n";
//	else cout << ans << "\n";
//	return 0;
//}

/*E Ư������*/ //����������
////longlong
////����ȡ��̵�
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#include<vector>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//int dx[] = { 1,0,-1,0 };
//int dy[] = { 0,1,0,-1 };
/*2024.2.22 ǰ׺��+����*/
////���֪��һ����ĺ�Ϊk��һ�Σ�
////��     1 2 3 5 
////ǰ׺�� 1 3 5 8
////%6     1 3 5 3 //����������3��˵��3֮���һ�κ�==6��
////����ͬ�����ʾ�����
////��һ������� %k == 0˵��һ��ֱ����+=k
////WA: ǰ׺�͹�ʽ�±�д��
////WA: ��==sb ����������ħ
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#include<vector>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//
//const int N = 2e5 + 10;
//ll n, k;
//ll arr[N];
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> k;
//	int cnt = 0;
//	for (int i = 0; i < n; i++) cin >> arr[i];
//	ll sum = 0;
//	map<ll, bool> g;
//	for (int i = 0; i < n; i++) {
//		sum += arr[i];
//		if (sum % k == 0) {
//			cnt++;
//			sum = 0;
//			g.clear();
//		}
//		else if (g[sum % k]) {
//			cnt++;
//			sum = 0;
//			g.clear();
//		}
//		//else g[sum % k] == 1; //����sb
//		else g[sum % k] = 1;
//	}
//	cout << cnt << "\n";
//	return 0;
//}
//
//
