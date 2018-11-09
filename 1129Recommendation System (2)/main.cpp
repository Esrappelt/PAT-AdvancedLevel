#include <bits/stdc++.h>
using namespace std;
struct cmp
{
    bool operator()( const pair<int,int> a ,const pair<int,int> b)
    {return a.second != b.second ? a.second > b.second : a.first < b.first;}
};
int main()
{
    map<int,int> ans;
    int n,k,v;
    scanf("%d%d%d",&n,&k,&v);
    ans[v]++;
    for(int i = 1; i < n; ++i)
    {
        scanf("%d",&v);
        printf("%d:",v);
        int j = 0;
        for(auto it = ans.begin(); it != ans.end() && j < k; ++it,++j) printf(" %d",(*it).first);
        printf("\n");
        ans[v]++;
    }
    return 0;
}
