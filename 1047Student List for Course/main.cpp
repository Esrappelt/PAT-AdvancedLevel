#include <bits/stdc++.h>
using namespace std;
vector<string> tmp;
bool cmp(const int &a,const int &b)
{return tmp[a] < tmp[b];}

int main()
{
    int N,K,C,v;
    string name;
    scanf("%d%d",&N,&K);
    vector<int> course[K+1];
    for(int i = 0; i < N; ++i)
    {
        cin >> name;
        tmp.push_back(name);
        scanf("%d", &C);
        for(int j = 0; j < C; ++j)
        {
            scanf("%d", &v);
            course[v].push_back(i);
        }
    }
    for(int i = 1; i <= K; ++i)
    {
        printf("%d %d\n",i,course[i].size());
        sort(course[i].begin(),course[i].end(),cmp);
        for(unsigned j = 0; j < course[i].size(); ++j)
            printf("%s\n",tmp[course[i][j]].c_str());
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
struct student
{
    string name;
    vector<int> val;
};
bool cmp(const student &a,const student &b)
{return a.name < b.name;}
int main()
{
    int N,K,C,v;
    string name;
    scanf("%d%d",&N,&K);
    vector<student> res(N);
    map< int,vector<string> > ans;
    vector<string> tmp(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> res[i].name;
        scanf("%d", &C);
        for(int j = 0; j < C; ++j)
        {
            scanf("%d", &v);
            res[i].val.push_back(v);
        }
    }
    sort(res.begin(),res.end(),cmp);
    for(int i = 0; i < N; ++i)
    {
        for(unsigned j = 0; j < res[i].val.size(); ++j)
            ans[res[i].val[j]].push_back(res[i].name);
    }
    for(int it = 1; it <= K; ++it)
    {
        vector<string> temp = ans[it];
        printf("%d %d\n",it,temp.size());
        for(unsigned j = 0; j < temp.size(); ++j)
            printf("%s\n",temp[j].c_str());
    }
    return 0;
}
*/

/*ע��
Zhejiang University has 40000 students and provides 2500 courses. Now given the registered course list of each student, you are supposed to output the student name lists of all the courses.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=40000), the total number of students, and K (<=2500), the total number of courses. Then N lines follow, each contains a student's name (3 capital English letters plus a one-digit number), a positive number C (<=20) which is the number of courses that this student has registered, and then followed by C course numbers. For the sake of simplicity, the courses are numbered from 1 to K.

Output Specification:

For each test case, print the student name lists of all the courses in increasing order of the course numbers. For each course, first print in one line the course number and the number of registered students, separated by a space. Then output the students' names in alphabetical order. Each name occupies a line.

Sample Input:
10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5
Sample Output:
1 4
ANN0
BOB5
JAY9
LOR6
2 7
ANN0
BOB5
FRA8
JAY9
JOE4
KAT3
LOR6
3 1
BOB5
4 7
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
5 9
AMY7
ANN0
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
*/
