// hdu-1521-��������.cpp : �������̨Ӧ�ó������ڵ㡣
//(1+x+x^2+..+x^n1)(1+x+x^2+...+x^n2)...�ҳ�x^mϵ�����ö�������
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
double c1[11],c2[11];
int f[11];
int a[11];
void init()
{
	f[0]=1;
	for(int i = 1;i<=10;i++)
	{
		f[i]=f[i-1]*i;
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	init();
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i = 1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i = 0;i<11;i++)
		{
			c1[i]=c2[i]=0.0;
		}
		for(int i = 0;i<=a[1];i++)
		{
			c1[i]=1.0/f[i];
		}
		for(int i = 2;i<=n;i++)
		{
			for(int j = 0;j<=m;j++)
			{
				for(int k = 0;k<=a[i]&&j+k<=m;k++)
				{
					c2[j+k]+=c1[j]/f[k];
				}
			}
			for(int j = 0;j<=m;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		printf("%.0lf\n",c1[m]*f[m]);
	}
}

