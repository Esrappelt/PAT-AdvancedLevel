#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &a,int s,int e,int &res)
{
    for(int i = s; i < e; ++i) if(a[i] != i)
    {
        ++res;
        swap(a[i],a[0]);
        return i;
    }
    return 0;
}
int main()
{
    int n,tmp,num = 0,res = 0,s,t = 1;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d",&tmp);
        a[tmp] = i;
        if(tmp && tmp != a[tmp]) ++num;
    }
    while(num)
    {
        if(!a[0]) s = solve(a,t,n,res),t = s;
        while(a[0])
        {
            swap(a[0],a[a[0]]);
            --num;
            ++res;
        }
    }
    printf("%d",res);
    return 0;
}
