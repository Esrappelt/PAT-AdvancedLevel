#include <bits/stdc++.h>
using namespace std;
const int Maxsize = 1e3 + 10,inf = 0x3f3f3f3f;
struct node
{
    int dis = inf,weight;
}eg[Maxsize][Maxsize];
int mincost = inf,mindist = inf;
bool vis[Maxsize];
vector<int> ans,path;
void dfs(int s,int d,int n)
{
    if(vis[s]) return;
    if(s == d)
    {
        path.push_back(d);
        int tmpdis = 0,tmpcost = 0;
        for(int i = 0; i < path.size() - 1; ++i)
        {
            int u = path[i],v = path[i+1];
            tmpcost += eg[u][v].weight;
            tmpdis += eg[u][v].dis;
        }
        if(tmpdis < mindist || (tmpdis == mindist && tmpcost < mincost ))
        {
            mindist = tmpdis;
            mincost = tmpcost;
            ans = path;
        }
        path.pop_back();
        return;
    }
    for(int i = 0; i < n; ++i)
    {
        if(eg[s][i].dis != inf && !vis[s])
        {
            path.push_back(s);
            vis[s] = true;
            dfs(i,d,n);
            vis[s] = false;
            path.pop_back();
        }
    }
}
int main()
{
    int n,m,s,d;
    scanf("%d%d%d%d",&n,&m,&s,&d);
    for(int i = 0; i < m; ++i)
    {
        int a,b,dis,weight;
        scanf("%d%d%d%d",&a,&b,&dis,&weight);
        eg[a][b].dis = eg[b][a].dis = dis;
        eg[a][b].weight = eg[b][a].weight = weight;
    }
    dfs(s,d,n);
    for(int i = 0; i < ans.size(); ++i) printf("%d ",ans[i]);
    printf("%d %d",mindist,mincost);
    return 0;
}
