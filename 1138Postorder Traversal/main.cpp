#include <bits/stdc++.h>
using namespace std;
vector<int> pre,in,ans;
void post(int root,int start,int end)
{
    if(start > end) return;
    int i = start;
    while(i < end && in[i] != pre[root]) i++;
    post(root + 1,start,i - 1);//root + 1
    post(root + i - start + 1,i + 1,end);
    ans.push_back(pre[root]);
}
int main()
{
    int n,val;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d",&val);
        pre.push_back(val);
    }
    for(int i = 0; i < n; ++i)
    {
        scanf("%d",&val);
        in.push_back(val);
    }
    post(0,0,n - 1);
    printf("%d\n",ans[0]);
    return 0;
}
