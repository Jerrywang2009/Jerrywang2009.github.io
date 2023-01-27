// TEMPLATE10. Prime
#include <bits/stdc++.h>
#define int long long
const int SIZE=1e8+5;
#define all(x) x.begin(), x.end()
#define debug(x) cout<<#x<<":"<<x<<endl;
using namespace std;

bool f[SIZE];
int a[SIZE], cnt=1;

signed main()
{
	int n, q; cin>>n>>q;
	fill(f, f+SIZE, 1);
	f[0]=f[1]=0;
	for(int i=2; i<=n; i++)
	{
		if(f[i]) a[cnt++]=i;
		for(int k=1; k<=cnt && i*a[k]<=n; k++)
		{
			f[i*a[k]]=0;
			if(i%a[k]==0) break;
		}
	}
	while(q--)
	{
		int t; cin>>t;
		cout<<a[t]<<endl;
	}

    return 0;
}
