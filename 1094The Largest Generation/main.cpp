#include <bits/stdc++.h>
using namespace std;
vector<int> tree[100];
int maxdep,ans[100];
void dfs(int root,int dep)
{
    ans[dep]++;
    if(tree[root].size() == 0)
        maxdep = maxdep > dep ? maxdep : dep;
    for(unsigned int i = 0; i < tree[root].size(); ++i)
        dfs(tree[root][i],dep+1);
}
void Level(int root)
{
    dfs(root,0);
    int maxans = ans[0],index = 0;
    for(int i = 1; i <= maxdep; ++i)
    {
        if(ans[i] > maxans)
        {
            index = i;
            maxans = ans[i];
        }
    }
    printf("%d %d\n",maxans,index+1);
}
void bfs(int root)
{
    int index = 0,dep = 0,maxans = 1;
    queue<int> q1;
    q1.push(root);
    while(!q1.empty())
    {
        queue<int> q2;
        while(!q1.empty())
        {
            int tmp = q1.front();
            q1.pop();
            for(unsigned i = 0; i < tree[tmp].size(); ++i)
                q2.push(tree[tmp][i]);
        }
        ++dep;
        if(maxans < q2.size())
        {
            index = dep;
            maxans = q2.size();
        }
        q1 = q2;
    }
    printf("%d %d\n",maxans,index+1);
}
int main()
{
    int n,m,id,k,tmp;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d",&id,&k);
        while(k--)
        {
            scanf("%d",&tmp);
            tree[id].push_back(tmp);
        }
    }
    //Level(1);
    bfs(1);
    return 0;
}
