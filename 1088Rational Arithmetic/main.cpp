#include<bits/stdc++.h>
using namespace std;
int gcd(long a,long b) { return b == 0 ? a : gcd(b,a % b); }
void print(long a,long a1)
{
    long ka = a / a1;
    a = a % a1;
    if(a < 0|| a1 < 0|| ka < 0) printf("(");
    if(a == 0) printf("%ld",ka);
    else if(ka != 0) printf("%ld %ld/%ld",ka,abs(a),abs(a1));
    else printf("%ld/%ld",a1 < 0 ? -a : a,a1 < 0 ? -a1 : a1);
    if(a < 0|| a1 < 0|| ka < 0) printf(")");
}
void print1(long a,long a1,long b,long b1,long c,long c1,char k)
{
    long t = gcd(c,c1);
    c /= t,c1 /= t;
    print(a,a1);
    printf(" %c ",k);
    print(b,b1);
    printf(" = ");
    print(c,c1);
    printf("\n");
}
int main()
{
    long a,a1,b,b1;
    long c[5][2];
    char sign[5]={'+','-','*','/'};
    scanf("%ld/%ld %ld/%ld",&a,&a1,&b,&b1);
    long t1 = gcd(a,a1),t2 = gcd(b,b1);
    a /= t1,a1 /= t1,b /= t2,b1 /= t2;
    c[0][1] = b1 * a1,c[0][0] = a * b1 + b * a1,c[1][1] = b1 * a1,c[1][0] = a * b1 - b * a1;
    c[2][1] = b1 * a1,c[2][0] = a * b,c[3][1] = a1 * b,c[3][0] = a * b1;
    for(int i = 0;i < 3; ++i) print1(a,a1,b,b1,c[i][0],c[i][1],sign[i]);
    if(b == 0)
    {
        print(a,a1);
        printf(" / ");
        print(b,b1);
        printf(" = ");
        printf("Inf");
        return 0;
    }
    print1(a,a1,b,b1,c[3][0],c[3][1],sign[3]);
}
