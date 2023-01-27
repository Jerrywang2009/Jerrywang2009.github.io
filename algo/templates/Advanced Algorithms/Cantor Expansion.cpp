// TEMPLATE21. Rank of Permutation
#include <bits/stdc++.h>
#define pb push_back
#define rep(i, s, t) for(int i=s; i<=t; i++)
#define F first
#define S second
#define int long long
#define all(x) x.begin(), x.end()
#define debug(x) cout<<#x<<":"<<x<<endl;
#define lowbit(x) (x&(-x))
const int SIZE=1000010;
const int mod=998244353;
using namespace std;

int n, a[SIZE], c[SIZE]={0};
int prod[SIZE]={1};

void change(int x, int v)
{
	while(x<=n)
	{
		c[x]+=v; x+=lowbit(x);
	}
}

int query(int x)
{
	int res=0;
	while(x)
	{
		res+=c[x]; x-=lowbit(x);
	}
	return res%mod;
}

signed main()
{
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", a+i);
	rep(i, 1, n) prod[i]=prod[i-1]*i%mod;
	int sum=0;
	rep(i, 1, n)
	{
		int cnt=query(a[i]-1);
		/*
		rep(j, 1, i-1)
			if(a[j]<a[i]) cnt++;
		*/
		sum=(sum+(a[i]-1-cnt)*prod[n-i]%mod)%mod;
		change(a[i], 1);
	}
	printf("%lld", sum+1);

    return 0;
}

