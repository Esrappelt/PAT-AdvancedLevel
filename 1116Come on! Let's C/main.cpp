#include <bits/stdc++.h>
using namespace std;
const int Maxsize = 1e5;
bool vis[Maxsize],exist[Maxsize];
bool isprime(int n)
{
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); ++i)
        if(n % i == 0) return false;
    return true;
}
int main()
{
    int n,k,t;
    map<int,string> ans;
    scanf("%d%d",&n,&t);
    ans[t] = "Mystery Award";
    exist[t] = true;
    for(int i = 1; i < n; ++i)
    {
        scanf("%d",&t);
        exist[t] = true;
        ans[t] = isprime(i+1) ? "Minion" : "Chocolate";
    }
    scanf("%d",&k);
    for(int i = 0; i < k; ++i)
    {
        scanf("%d:",&t);
        printf("%04d: ",t);
        if(!exist[t])
        {
            printf("Are you kidding?\n");
            continue;
        }
        if(vis[t])
        {
            printf("Checked\n");
            continue;
        }
        vis[t] = true;
        printf("%s\n",ans[t].c_str());
    }
    return 0;
}
