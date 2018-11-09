#include<bits/stdc++.h>
using namespace std;
const int Maxsize = 1e4 + 10,inf = 0x3f3f3f3f;
struct student
{
    int id,total = 0,perfect = 0,Rank;
    vector<int> score;
    bool pass = false;
};
vector<student> stu;
int cmp(const student a ,const student b)
{return a.total != b.total ? a.total > b.total : a.perfect != b.perfect ? a.perfect > b.perfect : a.id < b.id;}
int main()
{
    int id,problem,answer,n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    stu.resize(n+1);
    vector<int> full(k+1);
    for(int i = 1; i <= n; ++i)
    {
        stu[i].Rank = i;
        stu[i].score.resize(k+1,-1);
    }
    for(int i = 1; i <= k; ++i) scanf("%d",&full[i]);
    for(int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d",&id,&problem,&answer);
        stu[id].id = id;
        stu[id].score[problem] = max(stu[id].score[problem],answer);
        if(answer != -1) stu[id].pass = true;
        else if(stu[id].score[problem] == -1) stu[id].score[problem] = -inf;
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= k; ++j)
        {
            if(stu[i].score[j] != -inf && stu[i].score[j] != -1)
            {
                if(stu[i].score[j] == full[j]) stu[i].perfect++;
                stu[i].total += stu[i].score[j];
            }
        }
    }
    sort(stu.begin()+1,stu.end(),cmp);
    for(int i = 1,k = 1; i <= n; ++i)
    {
        stu[i].Rank = k;
        if(stu[i].total != stu[i+1].total) k = i + 1;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(stu[i].pass)
        {
            printf("%d %05d %d",stu[i].Rank,stu[i].id,stu[i].total);
            for(int j = 1; j <= k; ++j)
            {
                if(stu[i].score[j] != -1 && stu[i].score[j] != -inf)
                    printf(" %d",stu[i].score[j]);
                else if(stu[i].score[j] == -1)
                    printf(" -");
                else printf(" 0");
            }
            printf("\n");
        }
    }
    return 0;
}
