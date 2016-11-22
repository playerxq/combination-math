// hdu-1799-组合.cpp : 定义控制台应用程序的入口点。
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
int n,m;
int c[2001][2001];
void init()
{
	for(int i = 1;i<2001;i++)
	{
		c[i][0] = 1;
		c[i][1]=i;
		c[i][i]=1;
	}
	for(int i = 1;i<2001;i++)
	{
		for(int j = 1;j<i;j++)
		{
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%1007;
		}
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int t;
	init();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		printf("%d\n",c[n][m]);
	}
}

