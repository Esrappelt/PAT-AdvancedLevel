#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct student
{
    int id;
    string name;
    int score;
};

bool cmp1(const student &x,const student &y)
{
    return x.id < y.id;
}
bool cmp2(const student &x,const student &y)
{
    if(x.name == y.name)
        return x.id < y.id;
    return x.name < y.name;
}
bool cmp3(const student &x,const student &y)
{
    if(x.score == y.score)
        return x.id < y.id;
    return x.score < y.score;
}

int main()
{
    vector<student> ans;
    student tmp;
    int n,c;
    scanf("%d%d",&n,&c);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d",&tmp.id);
        cin >> tmp.name;
        scanf("%d",&tmp.score);
        ans.push_back(tmp);
    }
    switch(c)
    {
    case 1:
        sort(ans.begin(),ans.end(),cmp1);
        for(unsigned i = 0; i < ans.size(); ++i)
            printf("%06d %s %d\n",ans[i].id,ans[i].name.c_str(),ans[i].score);
        break;
    case 2:
        sort(ans.begin(),ans.end(),cmp2);
        for(unsigned i = 0; i < ans.size(); ++i)
            printf("%06d %s %d\n",ans[i].id,ans[i].name.c_str(),ans[i].score);
        break;
    case 3:
        sort(ans.begin(),ans.end(),cmp3);
        for(unsigned i = 0; i < ans.size(); ++i)
            printf("%06d %s %d\n",ans[i].id,ans[i].name.c_str(),ans[i].score);
        break;
    }
    return 0;
}
