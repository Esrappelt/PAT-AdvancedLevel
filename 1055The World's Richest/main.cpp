#include <bits/stdc++.h>
using namespace std;
struct student
{
    string name;
    int age,networth;
    bool operator<(const student &thisval)
    {return networth == thisval.networth ? age == thisval.age ? name < thisval.name :age < thisval.age : networth > thisval.networth;}
};
vector<student> ans;
void Find(int M,int a,int b)
{
    int cnt = 0;
    for(unsigned i = 0; i < ans.size(); ++i)
    {
        if(ans[i].age >= a && ans[i].age <= b)
            printf("%s %d %d\n",ans[i].name.c_str(),ans[i].age,ans[i].networth);
        if(++cnt >= M)
            break;
    }
    if(0 == cnt)
        printf("None\n");
}
int main()
{
    student tmp;
    int N,K,M,a,b;
    scanf("%d%d",&N,&K);
    for(int i = 0; i < N; ++i)
    {
        cin >> tmp.name;
        scanf("%d%d",&tmp.age,&tmp.networth);
        ans.push_back(tmp);
    }
    sort(ans.begin(),ans.end());
    for(int i = 1; i <= K; ++i)
    {
        scanf("%d%d%d",&M,&a,&b);
        printf("Case #%d:\n",i);
        Find(M,a,b);
    }
    return 0;
}
