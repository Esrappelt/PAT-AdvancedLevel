#include <bits/stdc++.h>
using namespace std;
int gcd(long int a,long int b) {return b == 0 ? abs(a) : gcd(b, a % b);} //gcd(a,b) = gcd(b,a%b),gcd(a,0) = a
int main()
{
    int n;
    long int sum1,sum2,a,b,x,y;
    scanf("%d%ld/%ld",&n,&a,&b);
    sum1 = a / gcd(a,b),sum2 = b / gcd(a,b);
    for(int i = 1; i < n; ++i)
    {
        scanf("%ld/%ld",&a,&b);
        x = sum1 = sum1 * b + sum2 * a;
        y = sum2 = sum2 * b;
        sum1 = sum1 / gcd(x,y);
        sum2 = sum2 / gcd(x,y);
    }
    if(sum1 % sum2 == 0 ) printf("%ld",sum1/sum2);
    else
    {
        if(sum1 > sum2) printf("%ld %ld/%ld",sum1/sum2,sum1%sum2,sum2);
        else printf("%ld/%ld",sum1,sum2);
    }
    return 0;
}
