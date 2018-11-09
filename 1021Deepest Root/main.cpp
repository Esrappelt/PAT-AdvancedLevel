#include <bits/stdc++.h>
using namespace std;
//1021,并查集的应用
const int maxn = 1e5 + 5;
vector<int> root,ans[maxn];
int pre[maxn];
bool vis[maxn];
int Find(int x)
{
    while(x != pre[x]) x = pre[x];
    return x;
}
void Union(int x,int y)
{
    if(Find(x) != Find(y))
        pre[Find(x)] = Find(y);
}
int GetNum(int n)
{
    int num = 0;
    for(int i = 1; i <= n; ++i)
        if(Find(i) == i) num++;
    return num;
}
void dfs(int x,int dep,int &maxdep)
{
    if(vis[x]) return;
    vis[x] = true;
    if(maxdep < dep)
    {
        root.clear();
        maxdep = dep;
        root.push_back(x);
    }
    else if(maxdep == dep)
        root.push_back(x);
    for(unsigned int i = 0; i < ans[x].size(); ++i) dfs(ans[x][i],dep+1,maxdep);
}
int main()
{
    int n,a,b,maxdep1 = 0,maxdep2 = 0,d;
    scanf("%d",&n);
    for(int i = 0; i < maxn; ++i) pre[i] = i;
    for(int i = 0; i < n - 1; ++i)
    {
        scanf("%d%d",&a,&b);
        ans[a].push_back(b);
        ans[b].push_back(a);
        Union(a,b);
    }
    if(GetNum(n) == 1)
    {
        set<int> res;
        dfs(1,0,maxdep1);
        d = root[0];
        for(auto it = root.begin(); it != root.end(); ++it) res.insert(*it);
        root.clear();
        memset(vis,false,sizeof(vis));
        dfs(d,0,maxdep2);
        for(auto it = root.begin(); it != root.end(); ++it) res.insert(*it);
        for(auto it = res.begin(); it != res.end(); ++it) printf("%d\n",*it);
    }
    else printf("Error: %d components\n",GetNum(n));
    return 0;
}
