#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
long long dp[44];
long long a[44];
long long n;
long long C(long long n, long long m)
{
	m = min(m,n-m);
	long long res = 1;
	for(long long i = 1;i<=m;i++)
	{
		res = res*(n-i+1)/i;
	}
	return res;
}
void dfs(long long cur, long long num, long long sum,long long start)
{
	if(sum>num)
		return;
	if(sum==num)//已有方案为0:cur-1
	{
		long long k = 1;//当前种类的个数
		long long s = 1;
		for(long long i = 1;i<cur;i++)
		{
			if(a[i]!=a[i-1])//开始一个新种类  先统计之前种类的组成数
			{
				s*=C(dp[a[i-1]]+k-1,k);//a[i-1]这么多的节点共有k个 而a[i-1]的方式数dp[a[i-1]]，相当于x1+x2+...+xdp[a[i-1]]=k的非负整数解个数 xi代表dp[a[i-1]]中每个方式选择几次  总数是k
				k = 0;
			}
			k++;
		}
		s*=C(dp[a[cur-1]]+k-1,k);
		dp[num+1]+=s;
		return;
	}
	for(long long i = start;i<=num;i++)
	{
		a[cur]=i;
		dfs(cur+1,num,sum+i,i);
	}
}
void init()
{
	dp[0]=dp[1]=dp[2]=1;
	for(long long i = 3;i<=40;i++)
	{
		dp[i]=0;
		dfs(0,i-1,0,1);
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	init();
	while(scanf("%lld",&n)!=EOF)
	{
		printf("%lld\n",dp[n]);
	}
}