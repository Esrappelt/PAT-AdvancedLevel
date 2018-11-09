#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int ans[n];
    for(int i = 0; i < n; ++i) scanf("%d",&ans[i]);
    sort(ans,ans + n);
    int sum = accumulate(ans,ans + n,0),s = accumulate(ans,ans + n / 2,0);
    printf("%d %d\n",n & 1 ? 1 : 0,sum - 2 * s);
    return 0;
}
