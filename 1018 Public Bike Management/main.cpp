#include <bits/stdc++.h>
using namespace std;
struct pro {
    int no,dis;
    bool operator<(const pro &t) const {return dis > t.dis;}
};
const int inf = 9999,maxsize = 510;
int C_max,N,problemId,M,a,b,dis,vis[maxsize],dist[maxsize],bikenum[maxsize],minNeed = inf,minBack = inf;
vector<pro> G[maxsize];
vector<int> path[maxsize],tmp,finalres;
vector< vector<int> > myans;
void dijkstra() {//�������ȶ����Ż�
    fill(dist,dist + maxsize,inf);
    memset(vis,0,sizeof(vis));
    dist[0] = 0;
    priority_queue<pro> qu;
    qu.push({0,0});
    while(!qu.empty()) {
        pro cur = qu.top();qu.pop();
        int u = cur.no,shortest = dist[u];
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0; i < G[u].size(); i++) {
            int curno = G[u][i].no,curdis = G[u][i].dis + shortest;
            if(dist[curno] > curdis ) {
                dist[curno] = curdis;
                path[curno].clear();//�洢����·��
                path[curno].push_back(u);
                qu.push(pro{curno,dist[curno]});
            } else if(dist[curno] == curdis) path[curno].push_back(u);
        }
    }
}
void dfs(int e) {
    if(e == 0) {
        myans.push_back(tmp);
        return;
    }
    for(int i = 0; i < path[e].size(); i++) {
        tmp.push_back(e);
        dfs(path[e][i]);
        tmp.pop_back();
    }
}
void solve() {
    for(int i = 0; i < myans.size(); i++) {
        vector<int> t = myans[i];
        //��ʼ��need��back��Сֵ
        int need = 0,back = 0,restnum = 0;
        for(int j = t.size() - 1; j >= 0; j--) {
            int bnum = bikenum[t[j]];//���վ�����г�����
            if(bnum > C_max) back += (bnum - C_max);
            else {
                int curneed = C_max - bnum;
                if(back > curneed) back -= curneed;//���ʣ������г��ܹ�֧��
                else {//���back������֧��
                    need += (curneed - back);//����Ҫ��ô��
                    back = 0;//ʣ������Ϊ0
                }
            }
        }//������Сֵ
        if(need < minNeed) {
            finalres = t;
            minNeed = need;
            minBack = back;
        } else if(need == minNeed && back < minBack) {
            finalres = t;
            minBack = back;
        }
    }
    printf("%d 0",minNeed);
    for(int i = finalres.size() - 1; i >= 0; i--) printf("->%d",finalres[i]);
    printf(" %d",minBack);
}
void init() {
    scanf("%d%d%d%d",&C_max,&N,&problemId,&M);
    C_max /= 2;
    for(int i = 1; i <= N; i++) scanf("%d",&bikenum[i]);
    for(int i = 0; i < M; i++) {
        scanf("%d%d%d",&a,&b,&dis);
        G[a].push_back(pro{b,dis});
        G[b].push_back(pro{a,dis});
    }
}
int main()
{
    init();//��ʼ��
    dijkstra();//�����·��
    dfs(problemId);//�����·���洢����
    solve();//���
    return 0;
}

