#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> tree[maxn];
int minnum,mindep = maxn;
void dfs(int root,int dep)
{
    if(tree[root].size() == 0)
    {
        minnum = mindep > dep ? 1 : mindep == dep ? minnum + 1 : minnum;
        mindep = mindep < dep ? mindep : dep;
        return;
    }
    for(unsigned int i = 0; i < tree[root].size(); ++i)
        dfs(tree[root][i],dep+1);
}
int main()
{
    int n,k,tmp;
    double price,rate;
    scanf("%d%lf%lf",&n,&price,&rate);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d",&tmp);
            tree[i].push_back(tmp);
        }
    }
    dfs(0,0);
    printf("%.4f %d\n",price * pow(1+rate/100,mindep),minnum);
    return 0;
}
