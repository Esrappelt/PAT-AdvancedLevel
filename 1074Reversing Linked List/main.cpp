#include<bits/stdc++.h>
using namespace std;
const int Maxsize = 1e5 + 10;
int main()
{
    int n,k,first,address;
    scanf("%d%d%d",&first,&n,&k);
    vector<int> ans,data(Maxsize),next(Maxsize);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d",&address);
        scanf("%d%d",&data[address],&next[address]);
    }
    for(int i = first; i != -1; i = next[i]) ans.push_back(i);
    for(int i = 0; i + k <= ans.size(); i += k) reverse(&ans[i],&ans[i+k]);
    for(int i = 0; i < ans.size() - 1; ++i) printf("%05d %d %05d\n",ans[i],data[ans[i]],ans[i+1]);
    printf("%05d %d -1\n",ans[ans.size() - 1],data[ans[ans.size() - 1]]);
    return 0;
}
