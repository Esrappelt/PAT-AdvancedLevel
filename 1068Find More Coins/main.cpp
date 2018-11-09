#include <bits/stdc++.h>
using namespace std;
int main()
{
    int coinsnum,cap;
    scanf("%d%d",&coinsnum,&cap);
    vector<int> v(coinsnum+1,0);
    for(int i = 1; i <= coinsnum; ++i) scanf("%d",&v[i]);
    vector< vector<int> > c(coinsnum+1,vector<int> (cap+1,0));
    for(int i = 1; i <= coinsnum; ++i)
    {
        for(int j = 1; j <= cap; ++j)
        {
            if(j < v[i]) c[i][j] = c[i-1][j];
            else c[i][j] = max(c[i-1][j-v[i]] + v[i],c[i-1][j]);
        }
    }
    printf("%d",c[coinsnum][cap]);
    return 0;
}
