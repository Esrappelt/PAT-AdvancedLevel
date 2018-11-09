#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool Isprime(int n)
{
    if(n == 1 || n == 0)
        return false;
    for(int i = 2; i <= sqrt(n); ++i)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}
//��Ҫ�Ĳ���
int change(int n,int radix)
{
    int m = 0;
    while(n)
    {
        m *= radix;//����������Ľ�����
        m += n % radix;//����ȡ�������һλ
        n /= radix;//���μ���һλ
    }
    return m;
}

void ans(int n,int radix)
{
    int m = change(n,radix);
    if(Isprime(n) && Isprime(m))
        printf("Yes\n");
    else
        printf("No\n");
}

int main()
{
    int n,radix;
    while(1)
    {
        scanf("%d",&n);
        if(n < 0)
           break;
        scanf("%d",&radix);
        ans(n,radix);
    }
	return 0;
}
