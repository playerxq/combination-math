// hdu-1171-01背包.cpp : 定义控制台应用程序的入口点。
//求把总价值分为两个数，使这两个数接近相等，而且这两个数必须由所有设备中的其中几种设备价值构成，并先输出比较大的数，再输出另一个数。
//思路：将总和平分后，就是一道01背包题了

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

int val[5005];
int dp[255555];

int main()
{
    int n,i,j,a,b,l,sum;
    while(~scanf("%d",&n),n>0)
    {
        memset(val,0,sizeof(val));//所有物品的单个价值
        memset(dp,0,sizeof(dp));
        l = 0;//所有物品总数
        sum = 0;//所有物品总价值
        for(i = 0;i<n;i++)
        {
            scanf("%d%d",&a,&b);//价值与数目
            while(b--)
            {
                val[l++] = a;//将价值存入数组
                sum+=a;
            }
        }
        for(i = 0;i<l;i++)//依次考虑所有物品
        {//对第i个物品而言 能构成的重量为val[i]:sum/2
            for(j = sum/2;j>=val[i];j--)//01背包
            {
                dp[j] = max(dp[j],dp[j-val[i]]+val[i]);
            }
        }
        printf("%d %d\n",sum-dp[sum/2],dp[sum/2]);
    }

    return 0;
}


