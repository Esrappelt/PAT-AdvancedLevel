#include <bits/stdc++.h>
using namespace std;
int n,m,t[1005];
vector<int> e[1005];
bool judege(int outdegree[]) {
    int indegree[1005];
    memcpy(indegree,outdegree,sizeof(indegree));
    for(int i = 0; i < n; ++i) {
        int v = t[i];
        if(indegree[v]) return false;
        for(int j = 0; j < e[v].size(); ++j) indegree[e[v][j]]--;
    }
    return true;
}
int main() {
    int indegree[1005];
    vector<int> ans;
    memset(indegree,0,sizeof(indegree));
    int a,b,query;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; ++i) {
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        indegree[b]++;
    }
    scanf("%d",&query);
    for(int j = 0; j < query; ++j) {
        for(int i = 0; i < n; ++i) scanf("%d",&t[i]);
        if(!judege(indegree)) ans.push_back(j);
    }
    for(int i = 0; i < ans.size(); ++i) printf("%d%c", ans[i],i == ans.size() - 1 ? '\n' : ' ');
    return 0;
}
