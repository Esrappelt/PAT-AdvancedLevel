#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<double,double> a,const pair<double,double> b) { return a.first / a.second < b.first / b.second; }
int main()
{
    int n,allask;
    double ans = 0;
    scanf("%d%d",&n,&allask);
    vector< pair<double,double> > cake(n);
    for(int i = 0; i < n; ++i) scanf("%lf",&cake[i].first);//����
    for(int i = 0; i < n; ++i) scanf("%lf",&cake[i].second);//��Ǯ
    sort(cake.begin(),cake.end(),cmp);
    for(int i = 0; i < n; ++i)
    {
        if(allask < cake[i].first)
        {
            ans += allask * cake[i].second / cake[i].first;
            //printf("%.2f",ans);��д�����ﲻ�У���i == 1��ʱ�����allask����cake[i].first����ô��û��������Լ��ڵĿӰ�����
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
