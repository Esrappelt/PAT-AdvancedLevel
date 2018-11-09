#include <bits/stdc++.h>
using namespace std;
const int Maxsize = 1e4 + 5;
int cnt[Maxsize],pre[Maxsize];
bool flag1[Maxsize],flag2[Maxsize];
struct family
{
    int id,mother,father;
    double estate,area;
};
struct res
{
    int id,number;
    double estate,area;
    bool operator<(const res &val) const
    {return area == val.area ? id < val.id : area > val.area;}
};
vector<family> fa;
vector<res> ans(Maxsize);
int Find(int x)
{
    int r = x,k = x,tmp;
    while(r != pre[r]) r = pre[r];
    while(k != r)//优化压缩
    {
        tmp = pre[k];
        pre[k] = r;
        k = tmp;
    }
    return r;
}
void Union(int x,int y)
{
    int f1 = Find(x),f2 = Find(y);
    if(f1 == f2) return;
    f1 < f2 ? pre[f2] = f1 : pre[f1] = f2;
}
void GetInfo()
{
    int cnt = 0;
    for(unsigned int i = 0; i < fa.size(); ++i)
    {
        int root = Find(fa[i].id);//找这个id的掌门
        ans[root].estate += fa[i].estate;
        ans[root].area += fa[i].area;
        ans[root].id = root;
        flag2[root] = true;
    }
    for(int i = 0; i < Maxsize; ++i)
    {
        if(flag2[i]) cnt++;
        if(flag1[i]) ans[Find(i)].number++;
    }
    printf("%d\n",cnt);
    for(int i = 0,k = 0; i < Maxsize && k != cnt; ++i)
    {
        if(flag2[i])
        {
            ans[i].area = (double)ans[i].area / ans[i].number;
            ans[i].estate = (double)ans[i].estate / ans[i].number;
            k++;
        }
    }
    sort(ans.begin(),ans.end());
    for(int i = 0; i < cnt; ++i)
        printf("%04d %d %.3f %.3f\n",ans[i].id,ans[i].number,ans[i].estate,ans[i].area);
}
int main()
{
    int n,k,t;
    for(int i = 0; i < Maxsize; ++i) pre[i] = i;//初始化!
    scanf("%d",&n);
    while(n--)
    {
        family tmp;
        scanf("%d%d%d%d",&tmp.id,&tmp.father,&tmp.mother,&k);
        flag1[tmp.id] = true;
        if(tmp.father != -1)
        {
            Union(tmp.id,tmp.father);
            flag1[tmp.father] = true;
        }
        if(tmp.mother != -1)
        {
            Union(tmp.id,tmp.mother);
            flag1[tmp.mother] = true;
        }
        while(k--)
        {
            scanf("%d",&t);
            Union(tmp.id,t);
            flag1[t] = true;
        }
        scanf("%lf%lf",&tmp.estate,&tmp.area);
        fa.push_back(tmp);
    }
    GetInfo();
    return 0;
}
