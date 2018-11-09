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
//重要的步骤
int change(int n,int radix)
{
    int m = 0;
    while(n)
    {
        m *= radix;//反向乘以他的进制数
        m += n % radix;//依次取他的最后一位
        n /= radix;//依次减少一位
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
