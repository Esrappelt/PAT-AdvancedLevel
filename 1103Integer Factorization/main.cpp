#include<bits/stdc++.h>
using namespace std;
int n,N,K,P,ans,num[21];
vector<int> path,res;
void dfs(int dep,int sum,int tmp)
{
    if(dep == K && tmp == N)
    {
        if(sum >= ans)
        {
            ans = sum;
            res = path;
        }
        return;
    }
    if(tmp > N || dep > K) return;
    int index = path.size() == 0 ? 1 : path[path.size() - 1];
    for(int i = index; i <= n; ++i)
    {
        if(num[i] + tmp > N) break;
        path.push_back(i);
        dfs(dep+1,sum + i,tmp + num[i]);
        path.pop_back();
    }
}
int main()
{
    scanf("%d%d%d",&N,&K,&P);
    n = sqrt(N);
    for(int i = 1; i <= n; ++i)
    {
        num[i] = 1;
        for(int j = 0; j < P; ++j)
            num[i] *= i;
    }
    dfs(0,0,0);
    if(res.empty())
    {
        printf("Impossible\n");
        return 0;
    }
    printf("%d = ",N);
    while(--K) printf("%d^%d + ",res[K],P);
    printf("%d^%d\n",res[K],P);
    return 0;
}
