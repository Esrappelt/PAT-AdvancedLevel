#include <bits/stdc++.h>
using namespace std;
struct node
{
    int flag,time;
    string name;
};
bool cmp1( const node &a,const node &b) { return a.name != b.name ? a.name < b.name : a.time < b.time; }
bool cmp2( const node &a,const node &b) { return a.time < b.time; }
int main()
{
    map<string,int> ans;
    vector<node> id,res;
    int n,query,h,m,s,maxtime = -1;
    scanf("%d%d\n",&n,&query);
    vector<int> sum(n);
    for(int i = 0; i < n; ++i)
    {
        char name[14],state[4];
        node tmp;
        scanf("%s %d:%d:%d %s",name,&h,&m,&s,state);
        tmp.name = name,tmp.time = h * 60 * 60+ m * 60 + s;
        tmp.flag = (strcmp(state,"in") == 0) ? 1 : 0;
        id.push_back(tmp);
    }
    sort(id.begin(),id.end(),cmp1);
    for(int i = 1; i < id.size(); ++i)
    {
        node t1 = id[i-1],t2 = id[i];
        if(t1.flag == 1 && t2.flag == 0 && t1.name == t2.name)
        {
            res.push_back(t1);
            res.push_back(t2);
            ans[t1.name] += (t2.time - t1.time);
            maxtime = max(maxtime,ans[t1.name]);
        }
    }
    sort(res.begin(),res.end(),cmp2);
    sum[0] = 1;
    for(int i = 1; i < res.size(); ++i) sum[i] = sum[i-1] + (res[i].flag == 1 ? 1 : -1);
    for(int i = 0,j = 0; i < query; ++i)
    {
        scanf("%d:%d:%d",&h,&m,&s);
        int time = h * 60 * 60 + m * 60 + s;
        while(j < res.size())
        {
            if(time < res[j].time)
            {
                printf("%d\n",sum[j-1]);
                break;
            }
            if(j == res.size() - 1) printf("%d\n",sum[j]);
            ++j;
        }
    }
    for(auto it = ans.begin(); it != ans.end(); ++it)
        if(it->second == maxtime) printf("%s ",it->first.c_str());
    printf("%02d:%02d:%02d",maxtime / 3600 ,(maxtime - (maxtime / 3600 ) * 3600) / 60,maxtime % 60);
    return 0;
}
