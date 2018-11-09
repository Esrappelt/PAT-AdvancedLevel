#include <bits/stdc++.h>
using namespace std;
int main()
{
    int M,N,S;
    scanf("%d%d%d",&M,&N,&S);
    vector<string> wb(M+1);
    map<string,bool> vis;
    if(S > M) { printf("Keep going...\n"); return 0;}
    for(int i = 1; i <= M; ++i) cin >> wb[i];
    for(int i = S; i <= M; i += N)
    {
        if(vis[wb[i]] == false) printf("%s\n",wb[i].c_str());
        else
        {
            while(vis[wb[i]] == true) ++i;
            if(i <= M) printf("%s\n",wb[i].c_str());
        }
        vis[wb[i]] = true;
    }
    return 0;
}
