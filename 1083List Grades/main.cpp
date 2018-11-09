#include <iostream>
#include<bits/stdc++.h>
using namespace std;


struct student
{
    string name;
    string id;
    int grade;
    bool operator<(const student &x)
    {
        return grade >= x.grade;
    }
};

int main()
{
    int N,grade1,grade2;
    vector<student> ans,res;
    student tmp;
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)
    {
        cin >>  tmp.name >> tmp.id >> tmp.grade;
        ans.push_back(tmp);
    }
    scanf("%d%d",&grade1,&grade2);
    for(int i = 0; i < N; ++i)
    {
        if(ans[i].grade >= grade1 && ans[i].grade <= grade2)
            res.push_back(ans[i]);
    }
    if(res.size() == 0)
        printf("NONE\n");
    else
    {
        sort(res.begin(),res.end());
        for(unsigned i = 0; i < res.size(); ++i)
            printf("%s %s\n",res[i].name.c_str(),res[i].id.c_str());
    }
    return 0;

}
