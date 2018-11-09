#include <bits/stdc++.h>
using namespace std;
struct student
{
    string id;
    int pscore,midscore,finalscore,G;
    bool operator<(const student &v) const
    {return G != v.G ? G > v.G : id < v.id;}
};
map<string,student> ans;
vector<student> res;
int main()
{
    int p,m,n,s,score;
    scanf("%d%d%d",&p,&m,&n);
    for(int i = 0; i < p; ++i)
    {
        string id;
        cin >> id;
        scanf("%d",&score);
        if(score >= 200) ans[id] = student{id,score,-1,-1};
    }
    for(int i = 0; i < m; ++i)
    {
        string id;
        cin >> id;
        scanf("%d",&score);
        if(ans.find(id) != ans.end()) ans[id].midscore = score;
    }
    for(int i = 0; i < n; ++i)
    {
        string id;
        cin >> id;
        scanf("%d",&score);
        if(ans.find(id) != ans.end()) ans[id].finalscore = score;
    }
    for(auto it = ans.begin(); it != ans.end(); ++it)
    {
        student tmp = it->second;
        if(tmp.finalscore < tmp.midscore )
        {
            int h = tmp.finalscore == -1 ? 0 : tmp.finalscore;
            s = (int)(h * 0.6 + tmp.midscore * 0.4 + 0.5);
        }
        else s = tmp.finalscore;
        if(s >= 60){ tmp.G = s;res.push_back(tmp);}
    }
    sort(res.begin(),res.end());
    for(unsigned int i = 0; i < res.size(); ++i)
        printf("%s %d %d %d %d\n",res[i].id.c_str(),res[i].pscore,res[i].midscore,res[i].finalscore,res[i].G);
    return 0;
}
