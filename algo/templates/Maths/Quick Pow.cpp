// TEMPLATE1. Quick Pow
#include <bits/stdc++.h>
#define int long long
#define SIZE 200010
#define all(x) x.begin(), x.end()
#define debug(x) cout<<#x<<":"<<x<<endl;
using namespace std;

signed main()
{
	int x, y, z; cin>>x>>y>>z;
	int ans=1%z;
	while(y) 
	{
		if(y&1) ans=ans*x%z;
		x=x*x%z;
		y>>=1;
	}
	cout<<ans;

    return 0;
}

