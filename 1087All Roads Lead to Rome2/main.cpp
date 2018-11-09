#include <bits/stdc++.h>
using namespace std;
const int Maxsize = 1e3 + 10,inf = 0x3f3f3f3f;
bool vis[Maxsize];
vector<int> ans,path,happy,G[Maxsize];
int cost[Maxsize][Maxsize],mincost = inf,maxhap = -1,maxavghap = -1,hapCnt = 1;
map<string,int> Stoi;
map<int,string> itoS;
void dfs(int s,int e)
{
    if(vis[s]) return;
    if(s == e)
    {
        int tmpcost = 0,tmphap = 0,t = 0;
        for(int i = 0; i < path.size(); ++i)
        {
            tmpcost += cost[t][path[i]];
            tmphap += happy[path[i]];
            t = path[i];
        }
        if(mincost > tmpcost)
        {
            mincost = tmpcost;
            ans = path;
            maxhap = tmphap;
            maxavghap = tmphap / path.size();
            hapCnt = 1;
        }
        else if(mincost == tmpcost)
        {
            if( tmphap > maxhap || ( tmphap == maxhap && maxavghap < tmphap / path.size() ) )
            {
                maxhap = tmphap;
                ans = path;
                maxavghap = tmphap / path.size();
            }
            ++hapCnt;
        }
        return;
    }
    for(int i = 0; i < G[s].size(); ++i)
    {
        if(!vis[s])
        {
            path.push_back(G[s][i]);
            vis[s] = true;
            dfs(G[s][i],e);
            vis[s] = false;
            path.pop_back();
        }
    }
}
int main()
{
    int n,m,weight;
    char start[4],name1[4],name2[4];
    scanf("%d %d %s",&n,&m,start);
    happy.resize(n);
    Stoi[start] = 0;
    for(int i = 1; i < n; ++i)
    {
        scanf("%s %d",name1,&happy[i]);
        Stoi[name1] = i,itoS[i] = name1;
    }
    while(m--)
    {
        scanf("%s %s %d",name1,name2,&weight);
        int from = Stoi[name1],to = Stoi[name2];
        G[from].push_back(to);
        G[to].push_back(from);
        cost[from][to] = cost[to][from] = weight;
    }
    memset(vis,false,sizeof(vis));
    dfs(Stoi[start],Stoi["ROM"]);
    printf("%d %d %d %d\n%s",hapCnt,mincost,maxhap,maxavghap,start);
    for(int i = 0; i < ans.size(); ++i) printf("->%s",itoS[ans[i]].c_str());
    return 0;
}
/*
6 6 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
BLN ROM 3
HZH PKN 5
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
*/
