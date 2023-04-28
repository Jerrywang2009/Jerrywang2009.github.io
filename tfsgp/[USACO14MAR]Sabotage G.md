# [USACO14MAR]Sabotage G

## 题目描述

Farmer John's arch-nemesis, Farmer Paul, has decided to sabotage Farmer John's milking equipment!

The milking equipment consists of a row of N (3 <= N <= 100,000) milking machines, where the ith machine produces M\_i units of milk (1 <= M\_i <= 10,000).  Farmer Paul plans to disconnect a contiguous block of these machines -- from the ith machine up to the jth machine (2 <= i <= j <= N-1); note that Farmer Paul does not want to disconnect either the first or the last machine, since this will make his plot too easy to discover.  Farmer Paul's goal is to minimize the average milk production of the remaining machines.  Farmer Paul plans to remove at least 1 cow, even if it would be better for him to avoid sabotage entirely.

Fortunately, Farmer John has learned of Farmer Paul's evil plot, and he is wondering how bad his milk production will suffer if the plot succeeds.  Please help Farmer John figure out the minimum average milk production of the remaining machines if Farmer Paul does succeed.

农夫约翰的头号敌人保罗决定破坏农民约翰的挤奶设备。挤奶设备排成一行，共N（3<= N <=100000）台挤奶机，其中第i个台挤奶机生产M\_i单位（1 <= M\_i<=10,000）的牛奶。


保罗计划切断一段连续的挤奶机，从第i台挤奶机到第j台挤奶机（2<= i<= j<= N-1）。注意，他不希望断开第一台或最后一台挤奶机，因为这将会使他的计划太容易被发现。保罗的目标是让其余机器的平均产奶量最小。保罗计划除去至少1台挤奶机。

请计算剩余机器的最小平均产奶量。

## 输入格式

第 1 行：一个整数 N。

第 2 到 N+1 行：第 i+1 行包含一个整数 M\_i。

## 输出格式

第 1 行： 一个实数， 表示平均牛奶产量的最小值， 保留三位小数 （四舍五入）。

## 样例 #1

### 样例输入 #1

```
5
5
1
7
8
2
```

### 样例输出 #1

```
2.667
```

## 提示

【样例说明】

移去 7 和 8，剩下 5, 1, 2，平均值为 8/3。

【数据规模和约定】

对于 30%的数据，N <= 1,000。

对于 50%的数据，N <= 10,000。

对于 100%的数据，3 <= N <= 100,000，1 <= M\_i <= 10,000。

【时空限制】

0.2s/128M
## 解析

非常好的分数规划。容易想到二分答案。这种实数域上的二分，往往枚举二分次数更精确、更好写。

二分 $m$ ，也就是最终输出的最小平均数。不难想到，$check$ 以下内容：
$$
\dfrac{s-(sum_r-sum_l)}{n-(r-l)} \leq m
$$

$$
s-sum_r+sum_l\leq mn-mr+ml
$$

$$
s-mn\leq (sum_r-mr)-(sum_l-ml)
$$

对于以上式子，$s$ 代表 $a$ 数组总和，$sum_i$ 代表 $0-i$  的前缀和。

上式可简化为：
$$
s-mn\leq \sum^{r}_{i=l+1}(a_i-m)
$$
$max(\sum^{r}_{i=l+1}(a_i-m))$  可以使用 DP 的最大连续子段和快速求出。

## 代码
```cpp
// E 
#include <bits/stdc++.h>
#define int long long
#define SIZE 100010
#define all(x) x.begin(), x.end()
#define debug(x) cout<<#x<<":"<<x<<endl;
using namespace std;

inline int read()
{
    int k=0, f=1;
    char c=getchar();
    while(c<'0' || c>'9')
    {
        if(c=='-') f=-1; c=getchar();
    }
    while(c>='0' && c<='9')
    {
        k=k*10+c-48; c=getchar();
    }
    return k*f;
}

inline void write(int n)
{
    if(n==0) putchar('0');
    stack<int> S;
    while(n)
        S.push(n%10), n/=10;
    while(!S.empty())
    {
        int x=S.top(); S.pop();
        putchar(x+48);
    }
}

int n;
int a[SIZE];
int sum;

bool ok(double mid)
{
	double remain=sum-mid*n;
	double Max=INT_MIN, s=0;
	for(int i=1; i<n-1; i++)
	{
		s+=a[i]-mid;
		Max=max(Max, s);
		if(s<0) s=0;
	}
	return Max>=remain;
}

signed main()
{
	n=read();
	for(int i=0; i<n; i++)
		a[i]=read();
	sum=accumulate(a, a+n, 0);
	double l=0, r=INT_MAX;
	double res;
	for(int tt=0; tt<50; tt++)
	{
		double m=(l+r)/2;
		if(ok(m))
		{
			res=m;
			r=m;
		}
		else
			l=m;
	}
	cout<<fixed<<setprecision(3)<<res;

	return 0;
}
```