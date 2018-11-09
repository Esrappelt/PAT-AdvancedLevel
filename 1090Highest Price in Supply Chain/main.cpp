#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> tree[maxn];
int maxnum,maxdep;
void dfs(int root,int dep)
{
    if(tree[root].size() == 0)
    {
        maxnum = maxdep < dep ? 1 : maxdep == dep ? maxnum + 1 : maxnum;
        maxdep = maxdep > dep ? maxdep : dep;
    }
    for(int i = 0; i < tree[root].size(); ++i)
        dfs(tree[root][i],dep+1);
}
int main()
{
    int N,tmp,root = 100000;
    double price,rate;
    scanf("%d%lf%lf",&N,&price,&rate);
    rate = rate / 100 + 1;
    for(int i = 0; i < N; ++i)
    {
        scanf("%d",&tmp);
        tmp = tmp == -1 ? root : tmp;
        tree[tmp].push_back(i);
    }
    dfs(root,0);
    printf("%.2f %d\n",price * pow(rate,maxdep - 1),maxnum);
    return 0;
}
