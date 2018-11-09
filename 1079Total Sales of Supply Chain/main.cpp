#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct node
{
    int salenum;
    vector<int> child;
};
vector<node> tree(maxn);
double ans,price,rate;
void dfs(int root,int dep)
{
    if(tree[root].child.size() == 0)
    {
        ans += tree[root].salenum * pow( rate/100 + 1,dep);
        return;
    }
    for(unsigned int i = 0; i < tree[root].child.size(); ++i)
        dfs(tree[root].child[i],dep+1);
}
void bfs()
{
    int dep = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        queue<int> p;
        while(!q.empty())
        {
            int tmp = q.front();
            q.pop();
            if(tree[tmp].child.size() == 0)
                ans += tree[tmp].salenum * pow(1+rate/100,dep);
            for(unsigned int i = 0; i < tree[tmp].child.size(); ++i)
                p.push(tree[tmp].child[i]);
        }
        dep++;
        q = p;
    }
}
int main()
{
    int N,k,tmp;
    scanf("%d%lf%lf",&N,&price,&rate);
    for(int i = 0; i < N; ++i)
    {
        scanf("%d",&k);
        if(k)
        {
            for(int j = 0; j < k; ++j)
            {
                scanf("%d",&tmp);
                tree[i].child.push_back(tmp);
            }
        }
        else
            scanf("%d",&tree[i].salenum);
    }
    //dfs(0,0);
    bfs();
    printf("%.1f\n",ans*price);
    return 0;
}
