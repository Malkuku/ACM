#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll=long long;
using ld=long double;
const int N=1e6+5;

ll prime[N], s[N], cnt;
bool vis[N];

void sieve(int n)
{
	for(ll i=2;i<=n;i++)
	{
		if(vis[i]==false)
			prime[++cnt]=i;
		for(ll j=1;j<=cnt;j++)
		{
			if(i*prime[j]>n)
				break;
			vis[i*prime[j]]=true;
			if(i%prime[j]==0)
				break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve(1e6+5);
	vis[1]=true;
	for(int i=1;i<=1e6;i++)
	{
		if(vis[i]==true) 
			s[i]=s[i-1];
		else
			s[i]=s[i-1]+i-1;
	}
	
	int T;
	cin>>T;
	while(T--)
	{
		int l,r;
		ll ans;
		cin>>l>>r;
		if(s[r]-s[l-1]!=0)
			ans=s[r]-s[l-1]+1;
		else
			ans=0;
		if(l==2)
			ans-=1;
		cout<<ans<<endl;
	}

	return 0;
}