// DPD Knapsack 1
#include <bits/stdc++.h>
#define int long long
#define SIZE 200010
#define all(x) x.begin(), x.end()
#define debug(x) cout<<#x<<":"<<x<<endl; 
using namespace std;

signed main()
{
	int n; cin>>n;
	int W; cin>>W;
	int w[n+1], v[n+1];
	for(int i=1; i<=n; i++)
		cin>>w[i]>>v[i];
	
	int f[W+1];
	fill(f, f+W+1, 0);
	for(int i=1; i<=n; i++)
		for(int x=W; x>=w[i]; x--)
			f[x]=max(f[x-w[i]]+v[i], f[x]);
	cout<<f[W];
	
	return 0;
}
