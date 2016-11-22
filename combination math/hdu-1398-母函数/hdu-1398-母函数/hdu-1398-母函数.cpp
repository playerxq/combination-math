// hdu-1398-ĸ����.cpp : �������̨Ӧ�ó������ڵ㡣
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
        num1[i]=1;//(1+x+x^2+...)��ϵ�� ��1����ɷ�ʽ
        num2[i]=0;
    }
    for(int i=2; i<=17; i++)//�Ժ���ÿ����ʽ(1+x^i^2+x^(2*i^2)+...)
    {
        for(int j=0; j<max; j++)//��֮ǰ�����num1�е�ÿ��ָ��
            for(int k=0; k+j<max; k+=i*i)//ö�ٵ�ǰ��ʽ��ָ�� 0*i^2,1*i^2,2*i^2...
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

