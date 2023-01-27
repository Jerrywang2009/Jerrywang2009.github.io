// TEMPLATE15. Nim
#include <bits/stdc++.h>
#define int long long
#define SIZE 200010
#define all(x) x.begin(), x.end()
#define debug(x) cout<<#x<<":"<<x<<endl;
using namespace std;

signed main()
{
	int T; cin>>T;
	while(T--)
	{
		int n; cin>>n;
		int s=0;
		while(n--)
		{
			int x; cin>>x;
			s^=x;
		}
		if(s==0) puts("No");
		else puts("Yes");
	}

    return 0;
}

