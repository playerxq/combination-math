// hdu-1465-����.cpp : �������̨Ӧ�ó������ڵ㡣
//���Ź�ʽ�� ������ʽ��d[1]=0;   d[2]=1
//�ݹ�ʽ��d[n]= (n-1)*( d[n-1] + d[n-2])
/*
����N���ŵ�ʱ��ǰ��N-1���ſ�����N-1���� N-2���װ
ǰ�ߣ�����ÿ�ִ�װ���ɴ�N-1����������ȡһ��͵�N���װ����=F(N-1)*(N-1)
���߼򵥣�ֻ����ûװ����Ƿ�͵�N�⽻���ŷ⣬ûװ����Ƿ������ǰ��N-1���е�����һ������
���� F(N-2) * (N-1)
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

