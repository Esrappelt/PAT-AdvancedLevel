#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<double,double> a,const pair<double,double> b) { return a.first / a.second < b.first / b.second; }
int main()
{
    int n,allask;
    double ans = 0;
    scanf("%d%d",&n,&allask);
    vector< pair<double,double> > cake(n);
    for(int i = 0; i < n; ++i) scanf("%lf",&cake[i].first);//需求
    for(int i = 0; i < n; ++i) scanf("%lf",&cake[i].second);//价钱
    sort(cake.begin(),cake.end(),cmp);
    for(int i = 0; i < n; ++i)
    {
        if(allask < cake[i].first)
        {
            ans += allask * cake[i].second / cake[i].first;
            //printf("%.2f",ans);答案写在这里不行，当i == 1的时候，如果allask大于cake[i].first，那么就没有输出，自己挖的坑啊。。
            break;
        }
        else
        {
            ans += cake[i].second;
            allask -= cake[i].first;
        }
    }
    printf("%.2f",ans);
    return 0;
}
