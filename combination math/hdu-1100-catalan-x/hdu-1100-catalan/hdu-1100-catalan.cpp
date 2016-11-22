// hdu-1100-catalan.cpp : 定义控制台应用程序的入口点。
//
/*
节点数为n的二叉树有h(n)个，考虑根节点下的左子树和右子树，
他们的节点数分别为（0，n-1）； （1，n-2）；。。。；（n-1，0），所以h（n） = h(0)*h(n-1)+h(1)*h(n-2)+...+h(n-1)*h(0),
且h（0）= 1， h（1）=1， 和卡特兰数的初始值与递推关系相符，所以我们得出h（n）就是个卡特兰数。

有了上述的结论，我们就可来定位x对应的节点数。我们首先生成一个卡特兰数的序列h（n)，再生成卡特兰数的前n项和的序列s（n），
给定一个x,我们可以找到这样一个n，让是s（n-1）< x <= s(n),从而得出这棵树是n个节点的。
再用x - s（n-1）的到它在h（n）中位置。因为x上限为500，000，000，所以我们很容易知道，n最大为18.

接下来，对于n个节点的树，我们已知它有h（n）个，我们再来对这h（n)棵树进行从1到h（n）排位，根据规则，从左边子树的个数高的排位高，我们先来分段，根据公式
h（n） = h(0)*h(n-1)+h(1)*h(n-2)+...+h(n-1)*h(0)
我们先利用x - s（n-1）来判断它在那一段索引，即它对应哪个h（x)*h(y), 这样就能知道他的左边子树的节点数为x，右边的为y

第三步，设上面得到的索引为pos,再根据规则，左边树应尽可能的小，遍历所有右边树的可能，即h(y)后，左边树再形成下一个树。也即若左边索引m,右边为k，则应为(k-1)h(y)+k=pos k=pos mod h(y) 且m×h(y)+pos mod h(y)=pos
以节点数和pos为参数递归的运算下去，直到节点数为1停止。最后把树木打印出来就是。
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
int n;
const int maxn=22;
long long h[maxn]={1,1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900,2674440,9694845,35357670,129644790,477638700,1767263190};
long long sum[maxn];
void init()
{
	sum[0]=0;
	for(int i = 1;i<maxn;i++)
		sum[i]=sum[i-1]+h[i];
}
void dfs(int id)
{
	if(!id)
		return;
	int c = 0;
	while(id>sum[c])
		c++;
	//总共c个节点
	id-=sum[c-1];//当前节点数目中的索引
	int lc = 0;//左节点数目
	int rc = c-1;
	int lid,rid;//左支与右支的索引
	lid = 1;
	rid = 1;
	while(id>h[lc]*h[c-1-lc]&&c-1-lc-1>=0)
	{
		id-=h[lc]*h[c-1-lc];
		lc++;
	}
	if(lc)
	{
		while(id>h[c-1-lc])//此时id对应的是h[lc]*h[rc]中全部方案中当前问题对应的索引,不断的去除右支的完全体 直到mod h(y)
		{
			id-=h[c-1-lc];
			lid++;//对应左支索引
		}
		lid+=sum[lc-1];//左支总索引
		printf("(");
		dfs(lid);
		printf(")");
	}
	printf("X");
	if(c-1-lc)
	{
		//此时id就对应右支的索引
		rid = id+sum[c-1-lc-1];
		printf("(");
		dfs(rid);
		printf(")");
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	init();
	while(scanf("%d",&n)!=EOF)
	{
		if(!n)
			break;
		dfs(n);
		printf("\n");
	}

}

