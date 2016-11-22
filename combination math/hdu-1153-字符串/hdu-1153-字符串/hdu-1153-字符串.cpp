// hdu-1153-�ַ���.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
ÿ1���ַ�����ȡ���µ��ַ���Ϊ�� 
a[1%n], a[2%n], a[3%n],��,a[(n-1)%n]; 
��2���ַ�����ȡ���µ��ַ���Ϊ: 
a[2%n], a[4%n], a[6%n],��,a[2(n-1)%n]; 
���a[1%n]==a[2%n],��a[2%n] == a[4%n],a[1%n]==a[4%n]; 
���a[1%n]!=a[2%n],��a[2%n]!=a[4%n],a[1%n]==a[4%n]; 
���ƿɵ�a[1%n]==a[4%n]==a[9%n]��==a[i *i % n] 
*/
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
int sb[100010];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	long long n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		if(n==2)
		{
			printf("Impossible\n");
		}
		else
		{
			memset(sb,0,sizeof(sb));
			for (int i = 0; i < n; i++) sb[i]=1;
			for (long long i = 1; i < n; i++)
			{
                   sb[i*i%n]=0;
            }
			for(int i = 1;i<n;i++)
				printf("%d",sb[i]);
			printf("\n");
		}
	}
}

