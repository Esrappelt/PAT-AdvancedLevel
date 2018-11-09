#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,s,e,maxans = -1;
    scanf("%d",&n);
    vector<int> ans;
    for(int i = 2; i <= sqrt(n + 0.5) + 1; ++i)
        if(n % i == 0) ans.push_back(i);
    for(int i = 0; i < ans.size(); ++i)
    {
        for(int start = 0,sum = 1; ans[i+start] == ans[i] + start && sum * ans[i+start] <= n; )
        {
            sum *= ans[i+start];
            if(n % sum == 0 && (++start > maxans))
            {
                maxans = start;
                s = i;
                e = i + start;
            }
        }
    }
    printf("%d\n",maxans);
    if(ans.size())
        for(int i = s; i < e; ++i) printf("%d%c",ans[i],i == e - 1 ? '\n' : '*')
    else printf("1\n%d",n);
    return 0;
}
