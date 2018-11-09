#include <bits/stdc++.h>
using namespace std;
const int Maxsize = 1e4 + 5;
vector<int> G[Maxsize];
bool vis[Maxsize];
int w[Maxsize],num,sum,maxid,maxv,cnt = 1;
map<string,int> Stoi,solve;//ÀëÉ¢»¯
map<int,string> ans;//´ð°¸
int Stoif(const string name)
{
    if(Stoi[name] == 0)
    {
        ans[cnt] = name;
        Stoi[name] = cnt++;
    }
    return Stoi[name];
}
void dfs(int id)
{
    if(vis[id]) return;
    vis[id] = true;
    sum += w[id];
    num++;
    if(maxv < w[id])
    {
        maxid = id;
        maxv = w[id];
    }
    for(unsigned int i = 0; i < G[id].size(); ++i) dfs(G[id][i]);
}
int main()
{
    int n,k,weight,id1,id2;
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; ++i)
    {
        string name1,name2;
        cin >> name1 >> name2 >> weight;
        id1 = Stoif(name1);
        id2 = Stoif(name2);
        w[id1] += weight;
        w[id2] += weight;
        G[id1].push_back(id2);
    }
    for(int i = 1; i < cnt; ++i)
    {
        if(!vis[i])
        {
            sum = num = maxid = 0,maxv = -1;
            dfs(i);
            if(sum > 2 * k && num > 2) solve.insert(make_pair(ans[maxid],num));
        }
    }
    printf("%d\n",solve.size());
    for(auto it = solve.begin(); it != solve.end(); ++it)
        printf("%s %d\n",it->first.c_str(),it->second);
    return 0;
}
