#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct student
{
  string name;
  string id;
  char flag;
  int score;
};
bool cmp1(const student &x,const student &y)
{return y.score < x.score;}

bool cmp2(const student &x,const student &y)
{return x.score < y.score;}
int main()
{
    int N;
    student tmp;
    vector<student> male,female;
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)
    {
       cin >> tmp.name >> tmp.flag >> tmp.id >> tmp.score;
       if(tmp.flag == 'M')
           male.push_back(tmp);
       else
           female.push_back(tmp);
    }
    sort(male.begin(),male.end(),cmp2);
    sort(female.begin(),female.end(),cmp1);
    if(female.size() == 0)
        printf("Absent\n");
    else
        printf("%s %s\n",female[0].name.c_str(),female[0].id.c_str());

    if(male.size() == 0)
        printf("Absent\n");
    else
        printf("%s %s\n",male[0].name.c_str(),male[0].id.c_str());
    if(male.size()== 0 || female.size()==0)
        printf("NA\n");
    else
        printf("%d\n",female[0].score - male[0].score);
    return 0;
}
