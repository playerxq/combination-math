// hdu-1027-全排列.cpp : 定义控制台应用程序的入口点。
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

int N,M;
int sequence[1010];
int main()
{
 while(scanf("%d %d",&N,&M)!=EOF)
 {
  int i;
  for(i=0;i<N;i++)
  {
   sequence[i]=i+1;
  }
  for(i=2;i<=M;i++)
  {
   next_permutation(sequence,sequence+N);
  }
  for(i=0;i<N-1;i++)
  {
   printf("%d ",sequence[i]);
  }
  printf("%d\n",sequence[N-1]);
 }
 return 0;
}

