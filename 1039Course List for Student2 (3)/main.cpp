#include <bits/stdc++.h>
using namespace std;
int main()
{
    map< string, set<int> > stu;
    int query,k,icourse,ni;
    char id[5];
    scanf("%d%d",&query,&k);
    while(k--)
    {
        scanf("%d%d",&icourse,&ni);
        while(ni--)
        {
            scanf("%s",id);
            stu[id].insert(icourse);
        }
    }
    while(query--)
    {
        scanf("%s",id);
        printf("%s",id);
        printf(" %d",stu[id].size());
        for(auto it = stu[id].begin();it != stu[id].end(); ++it) printf(" %d",*it);
        printf("\n");
    }
    return 0;
}
