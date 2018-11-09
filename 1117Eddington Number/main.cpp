#include <bits/stdc++.h>
using namespace std;
bool cmp(const int a,const int b) {return a > b; }
int main()
{
    int n,p = 1;
    scanf("%d",&n);
    //vector<int> dist(n+1);
    int *dist = new int[n+1];
    for(int i = 1; i <= n; ++i) scanf("%d",&dist[i]);
    //sort(dist.begin()+1,dist.end(),cmp);
    sort(dist+1,dist+n+1,cmp);
    while(dist[p] > p) p++;
    printf("%d",p-1);
    return 0;
}
