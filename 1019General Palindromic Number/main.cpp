#include <bits/stdc++.h>
using namespace std;
vector<int> a;
bool judge()
{
    int len = a.size();
    for(unsigned int i = 0; i < len / 2; ++i)
        if(a[i] != a[len - i - 1])
            return false;
    return true;
}
bool Palindromic(int num,int base)
{
    while(num)
    {
        a.push_back(num%base);
        num /= base;
    }
    if(!judge())
        return false;
    return true;
}
int main()
{
    int num,base,cnt = 0;
    scanf("%d%d",&num,&base);
    if(Palindromic(num,base))
    {
        printf("Yes\n");
        if(!a.size())
            printf("0\n");
    }
    else
        printf("No\n");
    for(auto it = a.rbegin(); it != a.rend(); ++it)
    {
        cout << *it;
        if(cnt++ < a.size() - 1)
            printf(" ");
    }
    return 0;
}
