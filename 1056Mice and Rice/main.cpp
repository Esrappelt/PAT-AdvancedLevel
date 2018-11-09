#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,t;
    queue<int> qu;
    scanf("%d%d",&n,&k);
    vector<int> weight(n),rank(n);
    for(int i = 0; i < n; ++i) scanf("%d",&weight[i]);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d",&t);
        qu.push(t);
    }
    while(qu.size() != 1)
    {
        queue<int> tmp;
        int Rank = (qu.size() % k == 0 ? qu.size() / k : qu.size() / k + 1) + 1;
        while(!qu.empty())
        {
            int maxw = -1,maxno = -1;
            for(int i = 0; i < k && !qu.empty(); ++i)
            {
                rank[qu.front()] = Rank;
                if(maxw < weight[qu.front()])
                {
                    maxw = weight[qu.front()];
                    maxno = qu.front();
                }
                qu.pop();
            }
            if(maxno != -1) tmp.push(maxno);
        }
        qu = tmp;
    }
    rank[qu.front()] = 1;
    for(int i = 0; i < n; ++i) printf("%d%c",rank[i],i == n - 1 ? '\n' : ' ');
    return 0;
}
