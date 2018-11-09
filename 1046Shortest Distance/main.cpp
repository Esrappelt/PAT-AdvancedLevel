#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,b,val,sum = 0;
    scanf("%d",&n);
    vector<int> ans(n+1,0);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d",&val);
        ans[i] = ans[i-1] + val;
        sum += val;
    }
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",min( abs(ans[a-1] - ans[b-1]),sum - abs(ans[a-1] - ans[b-1]) ));
    }
    return 0;
}
