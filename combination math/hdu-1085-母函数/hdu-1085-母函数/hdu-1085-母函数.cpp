// hdu-1085-母函数.cpp : 定义控制台应用程序的入口点。
//给你cnt1个一元硬币，cnt2个两元硬币，cnt3个五元硬币，问不能凑出来的第一个面额是多少。
//(1+x+x^2+x^3+.........x^cnt1)∗(1+x^2+x^4+x^6+.........x^2cnt2)∗(1+x^5+x^10+x^15+............x^5cnt5)

#include "stdafx.h"


#include <cstdio>
#include <cstring>

const int N = 1e4;
int val[3] = {1, 2, 5}, cnt[3];
int c1[N], c2[N], mmax;

int main()
{
	while (~scanf("%d%d%d", &cnt[0], &cnt[1], &cnt[2]) && (cnt[0] || cnt[1] || cnt[2])) {
		memset(c1, 0, sizeof(c1));//c1表示之前运算结果
		memset(c2, 0, sizeof(c2));

		mmax = 0;
		for (int i = 0; i < 3; i++)
			mmax += cnt[i] * val[i];//总面额

		for (int i = 0; i <= cnt[0]; i++)	// 处理第一种硬币 (1+x+x^2+x^3+.........x^cnt1)中的系数放入c1
			c1[i] = 1;

		for (int i = 1; i < 3; i++) {	// 对后面的每种硬币 先用(1+x+x^2+x^3+.........x^cnt1)乘(1+x^2+x^4+x^6+.........x^2cnt2) 再乘(1+x^5+x^10+x^15+............x^5cnt5)
			for (int j = 0; j <= mmax; j++) {//对每种可能出现的面值
				if (c1[j] != 0) {	// 对于之前的项(c1)不为0 说明之前算出的多项式系数不为0
					for (int k = 0; k <= val[i] * cnt[i]; k += val[i]) {	// 模拟与当前项式相乘
						if (j + k <= mmax)//指数不超过最大面额
							c2[j + k] += c1[j];
					}
				}
			}
			// 把当前项保存在c1，清空c2
			memcpy(c1, c2, sizeof(c1));
			memset(c2, 0, sizeof(c2));
		}

		int i;
		for (i = 0; i <= mmax; i++) {
			if (c1[i] == 0)
				break;
		}
		printf("%d\n", i);
	}
	return 0;
}


