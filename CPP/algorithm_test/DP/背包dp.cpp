#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/* P1541 [NOIP2010 提高组] 乌龟棋 */
/*2024.7.27*/ // 记忆化搜索
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 400;
// bool vis[N];
// int a[N],b[10];
// ll dp[45][45][45][45]; //表示每种牌使用了多少张
// int n, m;
// ll dfs(int n1,int n2,int n3,int n4){
//     if(n1 == b[1] && n2 == b[2] && n3 == b[3] && n4 == b[4]) return 0;
//     if(dp[n1][n2][n3][n4] != -1) return dp[n1][n2][n3][n4];
//     int pos = n1 +n2*2+n3*3+n4*4 + 1;
//     ll ans = 0;
//     if(n1 < b[1])
//         ans = max(ans, dfs(n1+1, n2, n3, n4) + a[pos + 1]);
//     if(n2 < b[2])
//         ans = max(ans, dfs(n1, n2+1, n3, n4) + a[pos + 2]);
//     if(n3 < b[3])
//         ans = max(ans, dfs(n1, n2, n3+1, n4) + a[pos + 3]);
//     if(n4 < b[4])
//         ans = max(ans, dfs(n1,n2,n3,n4+1) + a[pos + 4]);
//     return dp[n1][n2][n3][n4] = ans;
// }
// int main(){
//     cin >> n >> m;
//     memset(dp,-1,sizeof dp);
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
//     for(int i = 1; i <= m; i++){
//         int x; cin >> x;
//         b[x]++;
//     }
//     cout << dfs(0,0,0,0)+a[1] << "\n";
// }
/*2024.7.27 题解*/ //三维滚动背包
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll dp[45][45][45];
// int sum[10],a[1010];
// int n,m;
// int main(){
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
//     for(int i = 1; i <= m; i++){
//         int x;cin >>x;
//         sum[x]++;
//     }
//     for(int i = 0; i <= sum[1]; i++){
//         for(int j = 0; j <= sum[2]; j++){
//             for(int k = 0; k <= sum[3]; k++){
//                 for(int z = 0; z <= sum[4]; z++){
//                     int pos = i + j*2 + k*3 + z*4 + 1;
//                     if(j > 0)dp[j][k][z] = max(dp[j][k][z], dp[j - 1][k][z]);
//                     if(z > 0)dp[j][k][z] = max(dp[j][k][z],dp[j][k][z-1]);
//                     if(k > 0)dp[j][k][z] = max(dp[j][k][z], dp[j][k-1][z]);
//                     dp[j][k][z] += a[pos];
//                 }
//             }
//         }
//     }
//     cout << dp[sum[2]][sum[3]][sum[4]] << "\n";
//     return 0;
// }

/* P2347 [NOIP1996 �����] ������� */
/*2024.7.21*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e4+10;
// int w[10] = {0,1,2,3,5,10,20};
// int nums[10];
// int n = 6;
// int newn = 0,neww[N];
// bool dp[N];
// int main(){
//     for(int i = 1; i <= n; i++){
//         cin >> nums[i];
//     }
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= nums[i]; j <<= 1){
//             nums[i] -= j;
//             neww[++newn] = j * w[i];
//         }
//         if(nums[i]){
//             neww[++newn] = nums[i] * w[i];
//         }
//     }
//     int res = 0;
//     dp[0] = 1;
//     for(int i = 1; i <= newn; i++){
//         for(int j = 1000; j >= neww[i]; j--){
//             if(dp[j - neww[i]] && !dp[j]){
//                 dp[j] = 1;
//                 res++;
//             }
//         }
//     }
//     cout << "Total=" << res << "\n";
// }

/*P1776 ����ɸѡ */
/*2024.7.21*/ // 二进制划分多重背包（精）
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// ll dp[N];
// int v[N],w[N],m[N];
// //�ö����Ʋ�ֺ�õ�
// int newn = 0,neww[N],newv[N],newm[N];
// int main(){
//     ios::sync_with_stdio(0);
//     int n,W;
//     cin >> n >> W;
//     for(int i = 1; i <= n; i++){
//         cin >> v[i] >> w[i] >> m[i]; 
//     }
//     //�����Ʋ��
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= m[i]; j <<= 1){ //������ö��1,2,4,�����Ƶ����ʣ����ǿ������1--m��������
//             m[i] -= j; //��ȥ�Ѿ���ֵ�
//             newv[++newn] = j * v[i]; //����Ʒ
//             neww[newn] = j * w[i];
//         }
//         if(m[i]){  //��������
//             newv[++newn] = m[i] * v[i];
//             neww[newn] = m[i] * w[i];
//         }
//     }
//     for(int i = 1; i <= newn; i++){
//         for(int j = W; j >= neww[i]; j--){
//             dp[j] = max(dp[j],dp[j - neww[i]] + newv[i]);
//         }
//     }
//     cout << dp[W] << "\n";
//     return 0;
// }

/*lanqiao ��ˮ*/
////������൱�ڼ�ֵ
////����ÿ�����ˣ�������������Ӧ
////dp[i][0] ��ˮ��Ϊiʱ�Կ��˵�a mlˮ�������
////dp[i][1] ��c mlˮ
////dp[i][2] ��0 mlˮ
////dp[0][0] = 0
//// dp[i][0] = max(dp[i-a][0]+v,dp[i-b][0]+v,dp[i][0]+v);
//// ͬ��.....
//// �������
//// ������ȿ����Ǹ��ģ����Ƿ���ζ����Ҫ��ʼ��Ϊ������,//��ǰ��ĵ��Ʋ��������ս����Ҫ
//#include<iostream>
//#include<cstring>
//using namespace std;
//#define ll long long
//int n, m;
//const int N = 1e3 + 10;
//ll dp[N][3] = { 0 };
//int a[N];ll b[N]; int c[N]; ll d[N]; ll e[N];
//int main() {
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++) {
//		scanf("%d %lld %d %lld %lld", &a[i], &b[i], &c[i], &d[i], &e[i]);
//		//a -> b, c->d, 0->e
//	}
//	//memset(dp, -0x3f, sizeof(dp));
//	for (int i = 0; i < n; i++) {
//		for (int j = m; j >= 0; j--) {
//			dp[j][0] = dp[j][2] + e[i];
//			if(j-a[i] >= 0)dp[j][0] = max(dp[j-a[i]][0]+b[i],dp[j][0]);
//			if (j - c[i] >= 0)dp[j][0] = max(dp[j - c[i]][1] + d[i], dp[j][0]);
//			dp[j][1] = dp[j][2] + e[i];
//			if (j - a[i] >= 0)dp[j][1] = max(dp[j - a[i]][0] + b[i], dp[j][1]);
//			if (j - c[i] >= 0)dp[j][1] = max(dp[j - c[i]][1] + d[i], dp[j][1]);
//			dp[j][2] = dp[j][2] + e[i];
//			if (j - a[i] >= 0)dp[j][2] = max(dp[j - a[i]][0] + b[i], dp[j][2]);
//			if (j - c[i] >= 0)dp[j][2] = max(dp[j - c[i]][1] + d[i], dp[j][2]);
//			
//		}
//	}
//	ll ans = max(dp[m][0], dp[m][1]);
//	ans = max(ans, dp[m][2]);
//	printf("%lld\n", ans);
//	return 0;
//}

/*NC16693 װ������*/
////����������ֵ
////dp[j] �����ռ�Ϊjʱ������ֵ
////0 1����
//#include<iostream>
//using namespace std;
//int n, v;
//const int N = 2e4 + 10;
//int dp[N] = { 0 };
//int a[N];
//int main()
//{
//	scanf("%d %d", &v, &n);
//	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
//	dp[0] = 0;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = v; j >= a[i]; j--)
//		{
//			dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
//		}
//	}
//	printf("%d\n", v - dp[v]);
//
//	return 0;
//}

// /*NC16650 [NOIP2005]��ҩ*/
////0 1����
////dp[j] jʱ���ҩ������ֵ
//#include<iostream>
//using namespace std;
//int t, m;
//int tm[110];
//int co[110];
//int dp[1100] = { 0 };
//
//int main()
//{
//	scanf("%d %d", &t, &m);
//	for (int i = 1; i <= m; i++) scanf("%d %d", &tm[i], &co[i]);
//
//	dp[0] = 0;
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = t; j >= tm[i]; j--)
//		{
//			dp[j] = max(dp[j], dp[j - tm[i]] + co[i]);
//		}
//	}
//	printf("%d\n", dp[t]);
//
//	return 0;
//}

/*NC16666 [NOIP2006]���ĵĽ���*/
////0 1����
////����-��v[i] ��ֵ-��v[i]*w[i] 
//#include<iostream>
//using namespace std;
//const int N = 3e4 + 10;
//int k, m;
//int v[30];
//int w[30];
//int dp[N] = { 0 };
//
//int main()
//{
//	scanf("%d %d", &k, &m);
//	for (int i = 0; i < m; i++) scanf("%d %d", &v[i], &w[i]);
//	dp[0] = 0;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = k; j >= v[i]; j--)
//		{
//			dp[j] = max(dp[j], dp[j - v[i]] + v[i] * w[i]);
//		}
//	}
//	printf("%d\n", dp[k]);
//
//	return 0;
//}

/*NC19158 ʧ����ƽ (��)*/
////01�����İ�
////dp[j][k] jΪĩβʱ��ƽƽ������ֵkʱ��������ֵ
//#include<iostream>
//using namespace std;
//int dp[110][10010] = { 0 };
//int n, m, x;
//int a[10010];
//
//int main()
//{
//	int w = 0;
//	scanf("%d %d", &n, &m);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &a[i]);
//		w += a[i];
//	}
//	memset(dp, -0x3f, sizeof(dp));//Ϊʲô��Ҫ��ʼ���ɸ���� ����ϣ����ǰ��ķ�����Ʒ����ƽ�ϼ�������Ʒ�����Ǻ���ĵ��ƹ�ʽ�п����Ƶ�һ��û����Ʒ����ƽ�����Ը�����ʹ���ǲ���ʹ����
//	dp[0][0] = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j <= w; j++)
//		{
//			dp[i][j] = dp[i - 1][j];
//			dp[i][j] = max(dp[i][j], dp[i-1][abs(j - a[i])] + a[i]);//����ʱ��ƽ��ת���൱�������һ�߷���Ʒ
//			dp[i][j] = max(dp[i][j], dp[i-1][j + a[i]] + a[i]);//���ص�һ�߷���Ʒ
//		}
//	}
//	int ans = 0;
//	for (int i = 0; i <= m; i++) ans = max(ans, dp[n][i]);
//	printf("%d\n", ans);
//	return 0;
//}
/*2024.3.23*/
////dp[n][k] //�Ե�n������Ϊ��βʱ��������
//#include<bits/stdc++.h>
//using namespace std;
//int n, m;
//int dp[110][10010];
//int w[110];
//int main() {
//	cin >> n >> m;
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> w[i];
//		sum += w[i];
//	}
//	memset(dp, -0x3f, sizeof dp);//����ϣ����ǰ��Ļ����ϵ���,���Ƕ������������Ա�����
//	dp[0][0] = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = sum; j >= 0; j--) {//����ѹ��һάҲ����Ϊ���������������ӵ�
//			dp[i][j] = dp[i - 1][j];
//			dp[i][j] = max(dp[i-1][j + w[i]] + w[i], dp[i][j]);
//			dp[i][j] = max(dp[i - 1][abs(j - w[i])] + w[i], dp[i][j]);
//		}
//	}
//	int ans = 0;
//	for (int i = 0; i <= m; i++) {
//		ans = max(ans, dp[n][i]);
//	}
//	cout << ans << "\n";
//	return 0;
//}

/*NC231128 Steadily Growing Steam ��English��(WA)*/
////չʾ�ƶ�n���ƣ��ֳ�����,������ӵ��Ƶ�������ͬ��Alice������s�ѵ��ƣ�Bob��t��
////Bob skill: �����ƶ�ǰ��ѡ�����k���ƣ�double���ǵĵ���
////������֪��������ֺ�
////���֣�01����
////double ��Ӱ�챳��������
////����ѡ��n�����е�����
////card�ĵ���ֻ��1-13
////���ڸ�Ȩ
//#include<iostream>
//#include<cstring>
//#define ll long long
//using namespace std;
//
//int n, k;
//int v[110];
//int t[110];
//
//int main()
//{
//	scanf("%d %d", &n, &k);
//	for (int i = 0; i < n; i++) scanf("%d %d", &v[i], &t[i]);
//
//	return 0;
//}

/*NC21467 [NOIP2018]����ϵͳ (��)*/
////�ȼۣ�������b��Ԫ����������a����
////b��Ԫ��ȡ��a
////dp[i] i�Ƿ���Ա���ʾ����
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int T, n;
//int a[110];
//bool dp[25010] = { 0 };
//
//int main()
//{
//	scanf("%d", &T);
//	while (T--)
//	{
//		scanf("%d", &n);
//		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
//		sort(a, a + n);//��С�������У���Ϊ���Ԫ�ظ����ܱ�СԪ�ر�ʾ
//		memset(dp, 0, sizeof dp);
//
//		int ans = n;
//		dp[0] = 1;
//		for (int i = 0; i < n; i++)
//		{
//			if (dp[a[i]])//���Ա���ʾ��ɾȥ��Ԫ��
//			{
//				ans--;
//				continue;
//			}
//			for (int j = a[i]; j <= a[n - 1]; j++)//���������ȫ�������������
//			{
//				dp[j] = dp[j] || dp[j - a[i]]; //���j - a[i] Ԫ�ؿ��Ա���ʾ����ôjԪ��Ҳ���Ա���ʾ
//			}
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}
/*2024.3.23 �������ȫ����*/ //ϸ�ڣ�dp[j]�ĸ���
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 25000 + 10;
//int a[N];
//bool dp[N]; //i�Ƿ���Ա���ʾ����
//int main() {
//	int t;cin >> t;
//	while (t--) {
//		memset(dp, 0, sizeof dp);
//		int n; cin >> n;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//		}
//		sort(a + 1, a + 1 + n);
//		int ans = n;
//		dp[0] = 1;
//		for (int i = 1; i <= n; i++) {
//			if (dp[a[i]]) {
//				ans--;
//				continue;
//			}
//			for (int j = a[i]; j <= a[n]; j++) {
//				dp[j] = dp[j] || dp[j - a[i]]; // ||��ȷ��ԭ���Ѿ�����������dp��j�����ᱻ�ı�ɲ�����
//			}
//		}
//		cout << ans << "\n";
//	}
//	return 0;
//}

/*NC235950 ���ر���*/
/*2024.3.23*/
//#include<bits/stdc++.h>
//using namespace std;
//int n, T;
//int shu[110];
//int w[110];
//int v[110];
//int dp[110];
//int main() {
//	cin >> n >> T;
//	for (int i = 1; i <= n; i++) {
//		cin >> shu[i] >> w[i] >> v[i];
//	}
//	dp[0] = 0;
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= shu[i]; j++) {
//			for (int k = T; k >= w[i]; k--) {
//				dp[k] = max(dp[k], dp[k - w[i]] + v[i]);
//				ans = max(dp[k], ans);
//			}
//		}
//	}
//	cout << ans << "\n";
//	return 0;
//}

/*NC16671 [NOIP2006]������Ԥ�㷽��*/
/*2024.3.23 ��� ���鱳��*/ //������С�Ŀ�ʼӦ����0
////ԭ01����ֻ��ѡ�Ͳ�ѡ�������
////�������
////WA ��weghtӦ�� >= 0 ������ > 0
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//const int N = 70;
//ll cost[N][3]; //0���� //����1 //����2
//ll imp[N][3];
//ll dp[32010];
//
//int main() {
//	int s, m;
//	cin >> s >> m;
//	for (int i = 1; i <= m; i++) {
//		int v, p, q;
//		cin >> v >> p >> q;
//		if (q == 0) {
//			cost[i][0] = v;
//			imp[i][0] = p;
//		}
//		else {
//			if (cost[q][1] == 0) {
//				cost[q][1] = v;
//				imp[q][1] = p;
//			}
//			else {
//				cost[q][2] = v;
//				imp[q][2] = p;
//			}
//		}
//	}
//	dp[0] = 0;
//	ll ans = 0;
//	for (int i = 1; i <= m; i++) {
//		if (cost[i][0] <= 0) continue;
//		for (int j = s; j >= cost[i][0]; j--) {
//			dp[j] = max(dp[j], dp[j - cost[i][0]] + cost[i][0] * imp[i][0]);
//			int weght1 = j - cost[i][0] - cost[i][1];
//			int weght2 = j - cost[i][0] - cost[i][2];
//			int weght3 = j - cost[i][0] - cost[i][1] - cost[i][2];
//			ll qian1 = cost[i][0] * imp[i][0] + cost[i][1] * imp[i][1];
//			ll qian2 = cost[i][0] * imp[i][0] + cost[i][2] * imp[i][2];
//			ll qian3 = cost[i][0] * imp[i][0] + cost[i][2] * imp[i][2] + cost[i][1] * imp[i][1];
//			if (weght1 >= 0 && cost[i][1]) dp[j] = max(dp[j], dp[weght1] + qian1);
//			if (weght2 >= 0 && cost[i][2]) dp[j] = max(dp[j], dp[weght2] + qian2);
//			if (weght3 >= 0 && cost[i][1] && cost[i][2]) dp[j] = max(dp[j], dp[weght3] + qian3);
//		}
//	}
//	cout << dp[s] << "\n";
//	return 0;
//}
/*2024.3.23 ���*/
//#include<iostream>
//#include<vector>
//#include<map>
//#include<string>
//#include<algorithm>
//#include<set>
//#include<cmath>
//#include<iomanip>
//#include<memory.h>
//#include<queue>
//#define pii pair<int,int>
//using namespace std;
//typedef long long ll;
//const int Max = 1e5 + 5;
//int lst[Max];
//int dp[65][Max];
//int c[Max], v[Max], f[Max];
//vector<int> vec[Max];
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    for (int i = 1; i <= m; i++)
//    {
//        scanf("%d%d%d", &c[i], &v[i], &f[i]);
//        vec[f[i]].push_back(i);
//    }
//    for (int i = 1; i <= m; i++)
//    {
//        for (int j = 0; j <= n; j++)
//        {
//            dp[i][j] = dp[i - 1][j];
//            if (f[i] != 0) continue;
//            if (j >= c[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + v[i] * c[i]);
//            for (int k = 0; k < vec[i].size(); k++)
//            {
//                if (j >= c[i] + c[vec[i][k]]) dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i] - c[vec[i][k]]] + v[i] * c[i] + v[vec[i][k]] * c[vec[i][k]]);
//            }
//            if (vec[i].size() == 2 && j >= c[i] + c[vec[i][0]] + c[vec[i][1]])
//            {
//                dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i] - c[vec[i][0]] - c[vec[i][1]]] + c[i] * v[i] + c[vec[i][1]] * v[vec[i][1]] + c[vec[i][0]] * v[vec[i][0]]);
//            }
//        }
//    }
//    cout << dp[m][n] << endl;
//}

/*NC14699 ��������*/

/*NC235951 ��ҩ��ʦ*/ //map�Ż����󱳰�
/*2024.3.22 ��� ������*/
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//map<int, int> mp;
//
//signed main() {
//	ios::sync_with_stdio(0);
//	int n, s;
//	int t, v;
//	cin >> n >> s;
//	mp[0] = 0;
//	map<int, int>::reverse_iterator it;
//	while (n--) {
//		cin >> t >> v;
//		for (it = mp.rbegin();it != mp.rend(); it++) {
//			if ((*it).first + t <= s) {
//				mp[it->first + t] = max(mp[it->first + t], mp[it->first] + v);
//			}
//		}
//	}
//	int ans = 0;
//	for (auto t : mp) {
//		ans = max(ans, t.second);
//	}
//	cout << ans;
//	return 0;
//}
/*2024.3.22*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//ll n, s, t, v;
//map<ll, ll, greater<ll>> g;
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> s;
//	g[0] = 0;
//	while (n--) {
//		cin >> t >> v;
//		for (auto i : g) {
//			if (i.first + t <= s) {
//				g[i.first + t] = max(g[i.first + t], g[i.first] + v);
//			}
//		}
//	}
//	ll ans = 0;
//	for (auto i : g) {
//		ans = max(ans, i.second);
//	}
//	cout << ans << "\n";
//	return 0;
//}

