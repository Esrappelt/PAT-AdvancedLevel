#include <bits/stdc++.h>
using namespace std;
const int Maxsize = 1e4 + 10;
vector<int> path,res,G[Maxsize];
int mindep,mintrans,preline[Maxsize][Maxsize];
bool vis[Maxsize];
int transfer(vector<int> path)
{
    int num = 0,pre = 0;
    for(int i = 1; i < (int)path.size(); ++i)
    {
        int p = path[i - 1],q = path[i];
        if(preline[p][q] != pre) ++num;
        pre = preline[p][q];
    }
    return num;
}
void dfs(int dep,int s,int e)
{
    if(s == e)
    {
        if(dep == mindep)
        {
            if(mintrans > transfer(path))
            {
                mintrans = transfer(path);
                res = path;
            }
        }
        if(dep < mindep)
        {
            mindep = dep;
            res = path;
            mintrans = transfer(path);
        }
        return;
    }
    for(int i = 0; i < (int)G[s].size(); ++i)
    {
        int v = G[s][i];
        if(!vis[v])
        {
            path.push_back(v);
            vis[v] = true;
            dfs(dep+1,v,e);
            vis[v] = false;
            path.pop_back();
        }
    }
}
int main()
{
    int n,m,p,q,query;
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d%d",&m,&p);
        while(--m)
        {
            scanf("%d",&q);
            G[p].push_back(q);
            G[q].push_back(p);
            preline[p][q] = preline[q][p] = i;
            p = q;
        }
    }
    scanf("%d",&query);
    while(query--)
    {
        path.clear();
        res.clear();
        memset(vis,false,sizeof(vis));
        mindep = mintrans = 0x3f3f3f3f;
        scanf("%d%d",&p,&q);
        path.push_back(p);
        vis[p] = true;
        dfs(0,p,q);
        int pre = -1,start = p;
        printf("%d\n",mindep);
        for(int i = 1; i < (int)res.size(); ++i)
        {
            int u = res[i-1],v = res[i];
            if(preline[u][v] != pre)
            {
                if(pre != -1) printf("Take Line#%d from %04d to %04d.\n",pre,start,u);
                pre = preline[u][v];
                start = u;
            }
        }
        printf("Take Line#%d from %04d to %04d.\n",pre,start,q);
    }
    return 0;
}
