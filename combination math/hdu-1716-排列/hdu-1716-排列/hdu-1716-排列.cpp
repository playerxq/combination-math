// hdu-1716-排列.cpp : 定义控制台应用程序的入口点。
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
int a[5];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int c = 0;
	while(scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4])!=EOF)
	{
		if(a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0)
			break;
		if(c!=0)
			printf("\n");
		sort(a+1,a+4+1);
		while(a[1]==0)
		{
			next_permutation(a+1,a+4+1);
		}
		for(int i = 1;i<=4;i++)
			printf("%d",a[i]);
		int t = a[1];
		while(next_permutation(a+1,a+4+1))
		{
			if(a[1]==t)
				printf(" ");
			else
				printf("\n");
			for(int i = 1;i<=4;i++)
				printf("%d",a[i]);
			t=a[1];
		}
		printf("\n");
		c++;
	}
}

