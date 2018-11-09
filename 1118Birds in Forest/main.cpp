#include <bits/stdc++.h>
using namespace std;
const int Maxsize = 1e4 + 5;
int pre[Maxsize],cnt[Maxsize];
bool flag[Maxsize];
int Find(int x)
{
    int r = x,k = x,tmp;
    while(pre[r] != r) r = pre[r];
    while(k != r)//直到它是掌门
    {
        tmp = pre[k];//pre[k]表示k的上级先保存一下
        pre[k] = r;
        k = tmp;//让k = tmp 表示让x的上级全部都要成为掌门的直接手下
    }
    return r;//返回掌门
}
void Union(int x,int y)
{
    int f1 = Find(x),f2 = Find(y);
    if(f1 != f2) pre[f1] = f2;
}
void getBirdsInfo()
{
    int BirdsNum = 0,BirdstreeNum = 0;
    for(int i = 0; i < Maxsize; ++i)
    {
        if(flag[i])//有这个弟子
            cnt[Find(i)]++;//统计以i的掌门为下标  计数掌门有多少个弟子
    }
    for(int i = 0; i < Maxsize; ++i)
    {
        if(flag[i] && cnt[i])//如果这个弟子存在并且这个弟子有掌门或者自己是掌门
        {
            BirdstreeNum++;//有一个掌门就是有一颗树
            BirdsNum += cnt[i];//一个掌门上的所有弟子的数量求和
        }
    }
    printf("%d %d\n",BirdstreeNum,BirdsNum);
}
bool Judge(int x,int y)
{
    return Find(x) == Find(y);
}
int main()
{
    int n,k,id,tmp,q,a,b;
    scanf("%d", &n);
    for(int i = 0; i < Maxsize; ++i)
        pre[i] = i;//不要忘了初始化
    for(int i = 0; i < n; ++i)
    {
        scanf("%d%d",&k,&id);
        flag[id] = true;
        while(--k)
        {
            scanf("%d",&tmp);
            Union(tmp,id);
            flag[tmp] = true;
        }
    }
    getBirdsInfo();
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d%d", &a,&b);
        printf("%s\n",Judge(a,b) ? "Yes" : "No");
    }
    return 0;
}
