#include <bits/stdc++.h>
using namespace std;
const int Maxsize = 1e5 + 10;
int exist[Maxsize] = {-1};
bool flag[Maxsize] = {false};
int main()
{
    vector<int> tmp;
    set<int> res;
    int a,b,t,n,m,k = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d%d",&a,&b);
        exist[a] = b;
        exist[b] = a;
    }
    scanf("%d",&m);
    for(int i = 0; i < m; ++i)
    {
        scanf("%d",&t);
        if(exist[t] == -1) res.insert(t);//不存在的直接放入答案里
        else
        {
            tmp.push_back(t);//存在的放入tmp里
            flag[t] = true;//表示存在的
        }
    }
    for(int i = 0; i < tmp.size(); ++i)
    {
        int x = tmp[i];
        if(flag[x])//如果妻子存在
        {
            int y = exist[x];
            if(flag[y]) flag[y] = false;//丈夫也在
            else res.insert(x);//丈夫不在
        }
    }
    printf("%d\n",res.size());
    for(auto it = res.begin(); it != res.end(); ++it,++k) printf("%05d%c", *it,k == res.size() - 1 ? '\n' :' ');
    return 0;
}
