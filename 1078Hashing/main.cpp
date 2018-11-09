#include <bits/stdc++.h>
using namespace std;
const int Msize = 1e4 + 10;
bool vis[Msize];
bool isprime(int n)
{
    for(int i = 2; i <= sqrt(n); ++i)
        if(n % i == 0) return false;
    return (n != 0 && n != 1);
}
void solve(vector<int> ans,int msize)
{
    while(!isprime(msize)) ++msize;
    for(int i = 0,j; i < ans.size(); ++i)
    {
        if(i != 0) printf(" ");
        for(j = 0; j < msize; ++j)
        {
            int key = (ans[i] + j * j) % msize;
            if(!vis[key])
            {
                printf("%d",key);
                vis[key] = true;
                break;
            }
        }
        if(j == msize) printf("-");
    }
}
int main()
{
    int msize,n;
    scanf("%d%d",&msize,&n);
    vector<int> ans(n);
    for(int i = 0; i < n; ++i) scanf("%d",&ans[i]);
    solve(ans,msize);
    return 0;
}//只有一位数字才可以用整数+'0'的方法变成单个字符
