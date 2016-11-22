// hdu-1465-错排.cpp : 定义控制台应用程序的入口点。
//错排公式： 基本形式：d[1]=0;   d[2]=1
//递归式：d[n]= (n-1)*( d[n-1] + d[n-2])
/*
当有N封信的时候，前面N-1封信可以有N-1或者 N-2封错装
前者，对于每种错装，可从N-1封信中任意取一封和第N封错装，故=F(N-1)*(N-1)
后者简单，只能是没装错的那封和第N封交换信封，没装错的那封可以是前面N-1封中的任意一个，故
等于 F(N-2) * (N-1)
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

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n,i;
    long long a[25];
    a[2]=1;a[3]=2;
    for(i=4;i<=21;i++)
      a[i]=(i-1)*(a[i-1]+a[i-2]);
    while(scanf("%d",&n)!=EOF)
      printf("%I64d\n",a[n]);
    return 0;
}

