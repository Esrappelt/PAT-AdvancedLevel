#include<bits/stdc++.h>
using namespace std;
int n;
long p;
vector<int> ans;
int solve()
{
    int k = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = k + i; j < n; ++j)
        {
            if(ans[j] > p * ans[i]) break;
            k = max(k,j - i + 1);
        }
    }
    return k;
}
int main()
{
    scanf("%d%ld",&n,&p);
    ans.resize(n);
    for(int i = 0; i < n; ++i) scanf("%d",&ans[i]);
    sort(ans.begin(),ans.end());
    printf("%d",solve());
    return 0;
}
