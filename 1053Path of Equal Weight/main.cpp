#include <bits/stdc++.h>
using namespace std;
struct Id
{int id,weight;};
struct node
{vector<Id> child;};
bool cmp(const Id &x,const Id &y)
{return x.weight > y.weight;}

vector<node> tree(101);
int ans[101];
void dfs(int root,int len,int sum,int S)
{
    if(sum == S && tree[root].child.size() == 0)
    {
        for(int i = 0; i < len; ++i)
            printf("%d%c", ans[i],i == len - 1 ? '\n' : ' ');
    }
    for(unsigned i = 0; i < tree[root].child.size(); ++i)
    {
        ans[len] = tree[root].child[i].weight;
        dfs(tree[root].child[i].id,len + 1,sum + tree[root].child[i].weight,S);
    }
}
int main()
{
    int N,M,S,id,k,tmp;
    scanf("%d%d%d",&N,&M,&S);
    vector<int> weight(101);
    for(int i = 0; i < N; ++i) scanf("%d",&weight[i]);
    for(int i = 0; i < M; ++i)
    {
        scanf("%d%d",&id,&k);
        tree[id].child.resize(k);
        for(int j = 0; j < k; ++j)
        {
            scanf("%d",&tmp);
            tree[id].child[j].id = tmp;
            tree[id].child[j].weight = weight[tmp];
        }
        sort(tree[id].child.begin(),tree[id].child.end(),cmp);
    }
    ans[0] = weight[0];
    dfs(0,1,weight[0],S);
    return 0;
}
