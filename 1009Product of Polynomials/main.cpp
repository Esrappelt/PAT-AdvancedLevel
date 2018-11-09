#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int exp;
    double coef;
    bool operator<(const node &v)
    {
        return exp > v.exp;
    }
};

int main()
{
    int n,i,j;
    node tmp;
    vector<node> ans1,ans2,ans,res;
    scanf("%d",&n);
    for(i = 0; i < n; ++i)
    {
        scanf("%d%lf",&tmp.exp,&tmp.coef);
        ans1.push_back(tmp);
    }
    scanf("%d",&n);
    for(i = 0; i < n; ++i)
    {
        scanf("%d%lf",&tmp.exp,&tmp.coef);
        ans2.push_back(tmp);
    }
    for(i = 0; i < ans1.size(); ++i)
    {
        if(ans1[i].coef)
        {
            for(j = 0; j < ans2.size(); ++j)
            {
                if(ans2[j].coef)
                {
                    tmp.exp = ans1[i].exp + ans2[j].exp;
                    tmp.coef = ans1[i].coef * ans2[j].coef;
                    ans.push_back(tmp);
                }
            }
        }
    }
    tmp.coef = 0;
    sort(ans.begin(),ans.end());//½µÐòÅÅÐò
    for(i = 0; i < ans.size(); ++i)
    {
        tmp.exp = ans[i].exp;
        tmp.coef += ans[i].coef;
        if( ans[i].exp == ans[i+1].exp)
            continue;
        else
        {
            if(tmp.coef != 0)
                res.push_back(tmp);
            tmp.coef = 0;
        }
    }
    printf("%d",res.size());
    for(i = 0; i < res.size(); ++i)
        printf(" %d %.1f",res[i].exp,res[i].coef);
    printf("\n");
    return 0;
}
