// hdu-1171-01����.cpp : �������̨Ӧ�ó������ڵ㡣
//����ܼ�ֵ��Ϊ��������ʹ���������ӽ���ȣ������������������������豸�е����м����豸��ֵ���ɣ���������Ƚϴ�������������һ������
//˼·�����ܺ�ƽ�ֺ󣬾���һ��01��������

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
        memset(val,0,sizeof(val));//������Ʒ�ĵ�����ֵ
        memset(dp,0,sizeof(dp));
        l = 0;//������Ʒ����
        sum = 0;//������Ʒ�ܼ�ֵ
        for(i = 0;i<n;i++)
        {
            scanf("%d%d",&a,&b);//��ֵ����Ŀ
            while(b--)
            {
                val[l++] = a;//����ֵ��������
                sum+=a;
            }
        }
        for(i = 0;i<l;i++)//���ο���������Ʒ
        {//�Ե�i����Ʒ���� �ܹ��ɵ�����Ϊval[i]:sum/2
            for(j = sum/2;j>=val[i];j--)//01����
            {
                dp[j] = max(dp[j],dp[j-val[i]]+val[i]);
            }
        }
        printf("%d %d\n",sum-dp[sum/2],dp[sum/2]);
    }

    return 0;
}


