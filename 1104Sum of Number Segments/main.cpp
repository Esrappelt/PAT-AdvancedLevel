#include <iostream>
#include <stdio.h>
using namespace std;


//����Ƭ�κ�:
//˼·���ҳ�����a[0]�ĸ���,a[1]�ĸ���,a[2]�ĸ���......a[n - 1]�ĸ���  Ȼ��ѭ�����
//a[0]����n * 1��,a[1]����(n -1) * 2��,a[2]����(n-2) * 3��......a[n - 1]����(n - n + 1) * (n - 1)��
//�����ܴ�����:���(n - i) * (i + 1) * a[i](i:(0 ~ n - 1));

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
