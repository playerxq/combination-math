// hdu-1510-方块数目.cpp : 定义控制台应用程序的入口点。
//
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
int n,r,c,sum;
char s[102];
int map[101][101];
int f[101];
int vis[101];
int val[101];
int temp[101];
void init()
{
	f[0]=0;
	f[1]=1;
	for(int i = 2;i<=100;i++)
		f[i]=f[i-1]+i;
}
int get_single_line(int r)//单独考虑第r行
{
	if(vis[r])
		return val[r];
	vis[r]=1;
	int count = 0;
	int sum = 0;
	for(int i = 1;i<=n;i++)
	{
		if(map[r][i]==0)
		{
			count++;
		}
		else
		{
			sum+=f[count];
			count = 0;
		}
	}
	sum+=f[count];
	return val[r]=sum;
}
int get_single_line_temp(int h)
{
	int count = 0;
	int sum = 0;
	for(int i = 1;i<=n;i++)
	{
		if(temp[i]==0)
		{
			count++;
		}
		else
		{
			sum+=f[count];
			count = 0;
		}
	}
	sum+=f[count];
	return sum;
}
int dfs(int cur)//考虑1:cur行
{
	if(cur==1)
		return get_single_line(1);
	int sum = dfs(cur-1);
	sum+=get_single_line(cur);
	for(int j = 1;j<=n;j++)
		temp[j]=map[cur][j];
	for(int i = cur-1;i>=1;i--)
	{
		//考虑i:cur行合并
		for(int j = 1;j<=n;j++)
		{
			temp[j] = temp[j]+map[i][j];
			if(temp[j])
				temp[j]=1;
		}
		sum+=get_single_line_temp(cur-i+1);
	}
	return sum;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	init();
	while(scanf("%d",&n)!=EOF)
	{
		r = 1;
		memset(map,0,sizeof(map));
		memset(vis,0,sizeof(vis));
		memset(val,0,sizeof(val));
		while(r<n+1)
		{
			scanf("%s",s+1);
			c = strlen(s+1);
			for(int i = 1;i<=c;i++)
			{
				if(s[i]=='#')
					map[r][i]=1;
				else
					map[r][i]=0;
			}
			r++;
		}
		printf("%d\n",dfs(n));
	}
}

