#include<bits/stdc++.h>
using namespace std;
struct node
{
    int address;
    int data;
    int next;
};
int main()
{
    vector<node> ans(100000);
    vector<node> res1,res2;
    set<int> Unique;
    int first,n,ad,data,next;
    scanf("%05d %d",&first,&n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%05d %d %05d",&ad,&data,&next);
        ans[ad].data = data;
        ans[ad].next = next;
        ans[ad].address = ad;
    }
    for(int i = first; i != -1; i = ans[i].next)
    {
        if(!Unique.count(abs(ans[i].data)))//没有这个值就要插进去，下一次就不等于0了,也就不能重复了
        {
            Unique.insert(abs(ans[i].data));
            res1.push_back(ans[i]);
        }
        else//重复的装入res2容器
            res2.push_back(ans[i]);
    }
    for(unsigned int i = 0; i < res1.size(); i++)
        i == res1.size() - 1 ? printf("%05d %d -1\n",res1[i].address,res1[i].data):printf("%05d %d %05d\n",res1[i].address,res1[i].data,res1[i+1].address);
    for(unsigned int i = 0; i < res2.size(); i++)
        i == res2.size() - 1 ? printf("%05d %d -1\n",res2[i].address,res2[i].data):printf("%05d %d %05d\n",res2[i].address,res2[i].data,res2[i+1].address);
    return 0;
}






