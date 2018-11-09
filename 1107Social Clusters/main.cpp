#include <bits/stdc++.h>
using namespace std;
const int Maxsize = 1e3 + 5;
int pre[Maxsize],visit[Maxsize],num[Maxsize];
int Find(int x)
{
    int r = x,k = x,tmp;
    while(r != pre[r]) r = pre[r];
    while(k != r)
    {
        tmp = pre[k];
        pre[k] = r;
        k = tmp;
    }
    return r;
}
void Union(int x,int y)
{
    int f1 = Find(x),f2 = Find(y);
    if(f1 != f2)
    {
        pre[f1] = f2;
        num[f2] += num[f1];
    }
}
bool cmp(const int &x,const int &y)
{
    return x > y;
}
int main()
{
    int n,k,t,ans = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i)
    {
        num[i] = 1;//解法二不需要
        pre[i] = i;
    }
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d:",&k);
        while(k--)
        {
            scanf("%d",&t);
            if(visit[t]) Union(i,visit[t]);
            else visit[t] = i;
        }
    }
    for(int i = 1; i <= n; ++i)
        if(i == Find(i)) ans++;
    sort(num,num + ans + 1,cmp);
    printf("%d\n",ans);
    for(int i = 0; i < ans; ++i) printf("%d%c",num[i],i == ans - 1 ? '\n' : ' ');
    /*解法二：
    for(int i = 1; i <= n; ++i)
    {
        num[Find(i)]++;
        if(i == Find(i)) ans++;
    }
    sort(num,num+n+1,cmp);
    printf("%d\n",ans);
    for(int i = 0; i < ans; ++i) printf("%d%c",num[i],i == ans - 1 ? '\n' : ' ');
    */
    return 0;
}
