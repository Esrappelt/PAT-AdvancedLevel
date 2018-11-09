#include <bits/stdc++.h>
using namespace std;
const int Maxsize = 1e4;
bool vis[Maxsize];
vector<int> ans[Maxsize];
void dfs(int u)
{
    if(vis[u]) return;
    vis[u] = true;
    for(unsigned int i = 0; i < ans[u].size(); ++i)
        dfs(ans[u][i]);
}
int main()
{
    int n,m,a,b,t,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < m; ++i)
    {
        scanf("%d%d",&a,&b);
        ans[a].push_back(b);
        ans[b].push_back(a);
    }
    while(k--)
    {
        scanf("%d",&t);
        int res = 0;
        memset(vis,false,sizeof(vis));
        vis[t] = true;
        for(int i = 1; i <= n; ++i)
        {
            if(!vis[i])
            {
                dfs(i);
                res++;
            }
        }
        printf("%d\n",res - 1);
    }
    return 0;
}
