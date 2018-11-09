#include <iostream>
#include <stdio.h>
using namespace std;


//数列片段和:
//思路：找出所有a[0]的个数,a[1]的个数,a[2]的个数......a[n - 1]的个数  然后循环相加
//a[0]出现n * 1次,a[1]出现(n -1) * 2次,a[2]出现(n-2) * 3次......a[n - 1]出现(n - n + 1) * (n - 1)次
//所以总次数是:求和(n - i) * (i + 1) * a[i](i:(0 ~ n - 1));

int main()
{
	double a[100000];
	int N,i;
	double sum = 0;
	cin >> N;
	for(i = 0; i < N; i++)
	{
		scanf("%lf",&a[i]);
		sum += (a[i]) * (double)(N - i) * (double)(i + 1);
	}
	printf("%.2lf",sum);
	return 0;
}
