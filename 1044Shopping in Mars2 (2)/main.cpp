#include <bits/stdc++.h>
using namespace std;
struct node
{
    int s,e,sum;
    node(int s,int e) : s(s),e(e) {}
    node(int s,int e,int sum) : s(s),e(e),sum(sum) {}
};
int cmp1(node a,node b) {return a.sum != b.sum ? a.sum < b.sum : a.s < b.s;}
int main()
{
    int n,target,s,e,minnum = 0x3f3f3f3f;
    scanf("%d%d",&n,&target);
    vector<int> num(n);
    vector<node> ans,res;
    for(int i = 0; i < n; ++i) scanf("%d",&num[i]);
    for(int i = 0; i < n; ++i)
    {
        int sum = num[i];
        if(sum > target) { res.push_back(node(i+1,i+1,sum)); continue;}
        if(sum == target) ans.push_back(node(i+1,i+1));
        else
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(sum + num[j] == target) ans.push_back(node(i+1,j+1));
                else if(sum + num[j] < target) sum += num[j];
                else
                {
                    int x = sum + num[j];
                    if(x - target <= minnum )
                    {
                        s = i + 1;
                        e = j + 1;
                        minnum = x - target;
                        res.push_back(node(s,e,minnum));
                    }
                    break;
                }
            }
        }
    }
    if(ans.size() != 0)
        for(int i = 0; i < ans.size(); ++i) printf("%d-%d\n",ans[i].s,ans[i].e);
    else
    {
        sort(res.begin(),res.end(),cmp1);
        for(int i = 0; i < res.size(); ++i)
        {
            printf("%d-%d\n",res[i].s,res[i].e);
            if(res[i].sum != res[i+1].sum) break;
        }
    }
    return 0;
}
