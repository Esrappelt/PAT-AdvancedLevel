#include <bits/stdc++.h>
using namespace std;
const int Maxsize = 500 + 10;
int n,m,connectnum,eg[Maxsize][Maxsize],cnt[Maxsize];
bool vis[Maxsize];
void euler(int u)
{
    vis[u] = true;
    ++connectnum;
    for(int v = 1; v <= n; ++v)
        if(eg[u][v] && !vis[v]) euler(v);
}
int main()
{
    int a,b,oddnum = 0;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; ++i)
    {
        scanf("%d%d",&a,&b);
        eg[a][b] = eg[b][a] = 1;
        ++cnt[a],++cnt[b];
    }
    euler(1);
    for(int i = 1; i <= n; ++i)
    {
        if(cnt[i] % 2 == 1) ++oddnum;
        printf("%d%c",cnt[i], i == n ? '\n' : ' ');
    }
    if(oddnum == 0 && connectnum == n) printf("Eulerian");
    else if(oddnum == 2 && connectnum == n) printf("Semi-Eulerian");
    else printf("Non-Eulerian");
    return 0;
}
