#include <cstdio>
int main()
{
    int g1,s1,k1,g2,s2,k2;
    scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    printf("%d.%d.%d\n",(s1 + s2 + (k1 + k2) / 29) / 17 + g1 + g2,(s1 + s2 + (k1 + k2) / 29) % 17,(k1 + k2) % 29);
    return 0;
}
