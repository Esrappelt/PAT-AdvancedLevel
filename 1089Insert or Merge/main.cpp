#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ans,t;
bool Equal()
{
    for(int i = 0; i < n; ++i) if(ans[i] != t[i])
        return false;
    return true;
}
void solve()
{
    int p = 0,q = 0,x = 1,flag = 0;
    while(t[p + 1] >= t[p] && p < n - 1) ++p;
    q = p + 1;
    while(t[q] == ans[q] && q < n) ++q;
    printf("%s\n", q == n ? "Insertion Sort" : "Merge Sort");
    if(q == n)
    {
        sort(t.begin(),t.begin() + p + 2);
        for(int i = 0; i < n; ++i) printf("%d%c",t[i],i == n - 1 ? '\n' : ' ');
    }
    else
    {
        while(1)
        {
            x *= 2;
            for(int i = 0; i < n / x; ++i) sort(ans.begin()+ i * x,ans.begin() + i * x + x);
            sort(ans.begin() + (n / x) * x,ans.end());
            if(flag) break;
            if(Equal()) flag = 1;
        }
        for(int i = 0; i < n; ++i) printf("%d%c",ans[i],i == n - 1 ? '\n' : ' ');
    }
}
int main()
{
    scanf("%d",&n);
    ans.resize(n),t.resize(n);
    for(int i = 0; i < n; ++i) scanf("%d",&ans[i]);
    for(int i = 0; i < n; ++i) scanf("%d",&t[i]);
    solve();
    return 0;
}
