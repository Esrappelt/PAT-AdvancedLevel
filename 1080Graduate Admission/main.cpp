#include <bits/stdc++.h>
using namespace std;
struct student
{
    int Ge,Gi,id,rank;
    vector<int> choice;
};
vector< pair<int,int> > school[100 + 10];//first 代表 id,second 代表 rank
bool cmp1(const student a,const student b)
{ return a.Ge + a.Gi != b.Ge + b.Gi ? (a.Ge + a.Gi > b.Ge + b.Gi) : a.Ge > b.Ge; }
int main()
{
    int n,qnum,cnum;
    scanf("%d%d%d",&n,&qnum,&cnum);
    vector<int> quota(qnum);
    vector<student> stu(n);
    for(int i = 0; i < qnum; ++i) scanf("%d",&quota[i]);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d%d",&stu[i].Ge,&stu[i].Gi);
        stu[i].id = i;
        stu[i].choice.resize(cnum);
        for(int j = 0; j < cnum; ++j) scanf("%d",&stu[i].choice[j]);
    }
    sort(stu.begin(),stu.end(),cmp1);
    for(int i = 0,k = 0; i < n; ++i)//计算排名
    {
        stu[i].rank = k;
        if(stu[i].Ge != stu[i+1].Ge || stu[i].Gi != stu[i+1].Gi) k = i + 1;
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < cnum; ++j)
        {
            int select = stu[i].choice[j],length = school[select].size();
            if(school[select].size() < quota[select] || (school[select][length - 1].second == stu[i].rank) )
            {
                school[select].push_back(make_pair(stu[i].id,stu[i].rank));
                break;
            }
        }
    }
    for(int i = 0; i < qnum; ++i)
    {
        sort(school[i].begin(),school[i].end());
        for(auto it = school[i].begin(); it != school[i].end(); ++it)
        {
            if(it != school[i].begin()) printf(" ");
            printf("%d",(*it).first);
        }
        printf("\n");
    }
    return 0;
}
