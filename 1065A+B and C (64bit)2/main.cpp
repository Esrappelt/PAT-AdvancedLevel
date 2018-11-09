#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 1; i <= T; ++i)
    {
        bool flag;
        long long A,B,C;
        scanf("%lld%lld%lld",&A,&B,&C);
        if(A > 0 && B > 0 && A > LONG_MAX - B) flag = true;
        else if(A < 0 && B < 0 && A < LONG_MIN - B ) flag = false;
        else flag = A + B > C;
        printf("Case #%d: %s\n",i,flag ? "true" : "false");
    }
    return 0;
}
