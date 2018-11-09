#include <bits/stdc++.h>
using namespace std;
const int Maxsize = 1e3 + 5;
int N,L;
bool vis[Maxsize];
vector<int> G[Maxsize];
void solve2(int t)
{
    memset(vis,false,sizeof(vis));
    int ans = 0,layer = 0;
    queue<int> q1;
    q1.push(t);
    vis[t] = true;
    while(!q1.empty())
    {
        queue<int> q2;
        while(!q1.empty())
        {
            int x = q1.front();q1.pop();
            for(unsigned int i = 0; i < G[x].size(); ++i)
            {
                if(!vis[G[x][i]])
                {
                    vis[G[x][i]] = true;
                    q2.push(G[x][i]);
                }
            }
        }
        ans += q2.size();
        q1 = q2;
        if(++layer == L) break;
    }
    printf("%d\n",ans);
}
void solve(int t)
{
    memset(vis,false,sizeof(vis));
    int ans = 0,layer = 0;
    queue<int> q1;
    q1.push(t);
    vis[t] = true;
    while(!q1.empty())
    {
        int cnt = 0,j = q1.size();
        while(j--)
        {
            int x = q1.front(); q1.pop();
            for(unsigned int i = 0; i < G[x].size(); ++i)
            {
                if(!vis[G[x][i]]) q1.push(G[x][i]),++cnt;
                vis[G[x][i]] = true;
            }
        }
        ans += cnt;
        if(++layer == L) break;
    }
    printf("%d\n",ans);
}
int main()
{
    int query,t,k;
    scanf("%d%d",&N,&L);
    for(int i = 1; i <= N; ++i)
    {
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d",&t);
            G[t].push_back(i);
        }
    }
    scanf("%d",&query);
    while(query--)
    {
        scanf("%d",&t);
        solve(t);
    }
    return 0;
}
