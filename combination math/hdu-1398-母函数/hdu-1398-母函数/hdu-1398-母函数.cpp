// hdu-1398-母函数.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<stdio.h>
#include<math.h>
#define max 302
int num1[300];
int num2[300];
void init()
{
    for(int i=0; i<max; i++)
    {
        num1[i]=1;//(1+x+x^2+...)的系数 即1的组成方式
        num2[i]=0;
    }
    for(int i=2; i<=17; i++)//对后续每个乘式(1+x^i^2+x^(2*i^2)+...)
    {
        for(int j=0; j<max; j++)//对之前算出的num1中的每个指数
            for(int k=0; k+j<max; k+=i*i)//枚举当前乘式的指数 0*i^2,1*i^2,2*i^2...
            {
                num2[k+j]+=num1[j];
            }
        for(int i=0; i<max; i++)
        {
            num1[i]=num2[i];
            num2[i]=0;
        }
    }

}
int main()
{
    int n;
    init();
    while(scanf("%d",&n),n)
    {
        printf("%d\n",num1[n]);
    }
    return 0;
}

