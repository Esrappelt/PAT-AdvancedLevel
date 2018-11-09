#include <bits/stdc++.h>
using namespace std;
const int Maxsize = 1e5 + 10;
bool vis[Maxsize];
int main()
{
    int first,n,k,address;
    scanf("%d%d%d",&first,&n,&k);
    vector<int> data(Maxsize),next(Maxsize);
    vector< pair<int,int> > ans,ans1,ans2,ans3;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d",&address);
        scanf("%d%d",&data[address],&next[address]);
    }
    while(first != -1)
    {
        ans.push_back(make_pair(first,data[first]));
        first = next[first];
    }
    for(int i = 0; i < ans.size(); ++i)
    {
        if(ans[i].second < 0) ans1.push_back(ans[i]);
        else if(ans[i].second >= 0 && ans[i].second <= k) ans2.push_back(ans[i]);
        else if(ans[i].second > k) ans3.push_back(ans[i]);
    }
    for(int i = 1; i <= 3; ++i)
    {
        if(i == 1)
            for(int j = 0; j < ans1.size(); ++j) printf("%05d %d %05d\n",ans1[j].first,ans1[j].second,ans1[j+1].first);
        else if(i == 2)
        {
            for(int j = 0; j < ans2.size() - 1; ++j) printf("%05d %d %05d\n",ans2[j].first,ans2[j].second,ans2[j+1].first);
            //printf("%05d %d %05d\n",ans2[ans2.size() - 1].first,ans2[ans2.size() - 1].second,ans3[0].first);
        }
        else
        {
            for(int j = 0; j < ans3.size(); ++j)
            {
                if(i != ans3.size() - 1)
                    printf("%05d %d %05d\n",ans3[i].first,ans3[i].second,ans3[i+1].first);
                else
                    printf("%05d %d %d\n",ans3[i].first,ans3[i].second,-1);
            }
        }
    }
    return 0;
}
