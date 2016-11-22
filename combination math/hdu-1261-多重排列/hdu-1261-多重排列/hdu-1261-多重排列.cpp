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
int a[1000],len;
void jiecheng(int n)
{
	int i,j,c,temp;
	a[0]=1;
	len = 1;
	for(i = 2;i<=n;i++)
	{
		c = 0;
		for(j = 0;j<len;j++)
		{
			temp = a[j]*i+c;
			a[j]=temp%10000;
			c = temp/10000;
		}
		if(c)
			a[len++]=c;
	}

}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n,i,j,k;
    int num[26],sum,temp;
    int carry;
    while(scanf("%d",&n)!=EOF&&n)
    {
       sum=0;
       for(i=0;i<n;i++)
       {
           scanf("%d",&num[i]);
           sum+=num[i];
       }
       jiecheng(sum);
       for(i=0;i<n;i++)//这是一个大数除以小数的算法
       {
           for(j=2;j<=num[i];j++)
           {
               carry=0;
               for(k=len-1;k>=0;k--)
               { 
                   temp=a[k]+carry*10000;
                   a[k]=temp/j;
                   carry=temp%j;
               }
               while(a[len-1]==0)
                   len--;
           }
       }
       printf("%d",a[len-1]);
       for(i=len-2;i>=0;i--)
           printf("%04d",a[i]);
       printf("\n");
    }
    return 0;
}