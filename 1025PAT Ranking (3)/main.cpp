#include <bits/stdc++.h>
using namespace std;
struct node
{
    string id;
    int score,localnum,localrank;
    node(string name,int sc,int ln,int lr) : id(name),score(sc),localnum(ln),localrank(lr) {}
    bool operator<(const node &v) const { return score != v.score ? score > v.score : id < v.id;}
};
int main()
{
    int N,K,score;
    string id;
    vector<node> ans;
    scanf("%d",&N);
    for(int i = 1; i <= N; ++i)
    {
        scanf("%d",&K);
        vector<node> tmp;
        while(K--)
        {
            cin >> id >> score;
            tmp.push_back(node(id,score,-1,-1));
        }
        sort(tmp.begin(),tmp.end());
        for(int j = 0,k = 1; j < (int)tmp.size(); ++j)
        {
            ans.push_back(node(tmp[j].id,tmp[j].score,i,k));
            if(tmp[j].score != tmp[j+1].score && j < tmp.size() - 1) k = j + 2;
        }
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i = 0,k = 1; i < (int)ans.size(); ++i)
    {
        printf("%s %d %d %d\n",ans[i].id.c_str(),k,ans[i].localnum,ans[i].localrank);
        if(ans[i].score != ans[i+1].score && i < ans.size() - 1) k = i + 2;
    }
    return 0;
}
