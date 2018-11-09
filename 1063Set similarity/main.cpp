#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,test,n1,n2,val;
    scanf("%d", &n);
    vector<set<int> > ans;
    for(int k = 0; k < n; ++k)
    {
        scanf("%d",&m);
        set<int> tmp;
        for(int i = 0; i < m; ++i)
        {
            scanf("%d",&val);
            tmp.insert(val);
        }
        ans.push_back(tmp);//每一个都是set
    }
    scanf("%d", &test);
    for(int i = 0; i < test; ++i)
    {
        scanf("%d%d", &n1,&n2);
        int Nc = 0,Nt = ans[n1-1].size();
        printf("Nt = %d\n",Nt);
        for(auto it = ans[n2-1].begin(); it != ans[n2-1].end(); ++it)
        {
            if(ans[n1-1].find(*it) == ans[n1-1].end())//就是没有找到
                Nt++;//没有找到的++
            else//找到了就相同的++
                Nc++;
        }
        printf("Nc = %d\n",Nc);
        double ans = (double)Nc/Nt * 100;
        printf("%.1f%%\n",ans);
    }
    return 0;
}
