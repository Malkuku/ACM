#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*NC16596 [NOIP2011]����ϵ��*/
/*2024.3.29 ����ʽ���� (��)*/
////WA:ȡģ���Լ�longlong
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int mod = 10007;
//ll power(ll x,ll n) {
//	ll ans = 1;
//	while (n) {
//		if (n & 1) {
//			ans *= x;
//			ans %= mod;
//		}
//		x *= x;
//		x %= mod;
//		n >>= 1;
//	}
//	return ans;
//}
//ll f[1010][1010]; // n // k
//ll C(int n, int k) {
//	for (int i = 0; i <= k; i++) {
//		f[0][i] = 1;
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= k; j++) {
//			f[i][j] = (f[i-1][j - 1] + f[i][j-1]) % mod;
//		}
//	}
//	return f[n][k];
//}
//int main() {
//	ll a, b, k, n, m;
//	cin >> a >> b >> k >> n >> m;
//	ll ans = power(a, n) % mod * power(b, m) % mod * C(n, k) % mod;
//	ans %= mod;
//	cout << ans << "\n";
//	return 0;
//}

/*NC19989 [HAOI2012]������*/
/*2024.5.6 �˷�������(WA1)*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<ll,ll>
//const int N = 1e5 + 10;
//set<PII> s;
//map<ll, ll> g;
//int main() {
//	ios::sync_with_stdio(0);
//	const int mod = 1e9 + 7;
//	ll n, m, k;
//	cin >> n >> m >> k;
//	ll sum = (n + 1) * n / 2;
//	sum %= mod;
//	ll ans = 1;
//	for (int i = 0; i < k; i++) {
//		ll x; cin >> x;
//		ll y; cin >> y;
//		s.insert({ x,y });
//	}
//	for (auto t : s) {
//		g[t.first] += t.second;
//		g[t.first] %= mod;
//	}
//	for (auto t : g) {
//		ans *= (sum - t.second);
//		//cout << t.first << " " << t.second << "\n";
//		ans %= mod;
//	}
//	//������
//	ll aa = sum;
//	m -= g.size();
//	//cout << sum << "\n";
//	while (m) {
//		if (m & 1) {
//			ans *= aa;
//			ans %= mod;
//		}
//		aa *= aa;
//		aa %= mod;
//		m >>= 1;
//		//cout << aa << m << "\n";
//	}
//	cout << ans % mod << "\n";
//	return 0;
//}

/*P4925 [1007] Scarlet���ַ�����������ô�ɰ� */ //�˷�ԭ��
/*2024.9.12 ���*/
// // s == 0ʱ��ans = k*(k-1)*(k-2)*(k-2)*...
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// ll k,L,mod;ll s,w;
// ll Mod(ll x){
//     return x%mod;
// }
// ll kms(ll a,ll b){
//     if(a == 0) return 0;
//     if(b == 0) return 1;
//     ll ans = 1;
//     while(b){
//         if(b&1){
//             ans = Mod(ans)*Mod(a) % mod;
//         }
//         a = Mod(a*a);
//         b /= 2;
//     }
//     return Mod(ans);
// }
// int main(){
//     ll ans = 0;
//     cin >> k >> L >> mod;
//     cin >> s >> w;
//     if(s){
//         ans = Mod(k-1+mod)*Mod(kms(Mod(k-2+mod),L-2));
//         ans = Mod(ans);
//     }
//     else{
//         ans = Mod(Mod(k)*Mod(k-1+mod))*Mod(kms(Mod(k-2+mod),L-2));
//         ans = Mod(ans);
//     }
//     cout << ans << "\n";
//     return 0;
// }

/*NC19999 [HAOI2016]������*/ //�ݳ�+�߾���

/*NC20277 [SCOI2010]�ַ���*/