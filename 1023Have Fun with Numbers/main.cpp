#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int flag = 1;

void change(string &a)
{
    int gobit = 0,lenago = a.length();
    for(int i = a.length() - 1; i >= 0; --i)
    {
        int tmp = 2 * (a[i] - '0') + gobit;
        a[i] = tmp % 10 + '0';
        gobit = tmp / 10;
    }
    if(gobit != 0)
        a.insert(0,"1");
    if(a.length() != lenago)
        flag = 0;

}


int main()
{
    string a;
    cin >> a;
    map<int,int> ans;
    map<int,int> ::iterator iter;
    for(unsigned int i = 0; i < a.length(); ++i)
        ans[a[i]]++;
    change(a);
    for(unsigned int i = 0; i < a.length(); ++i)
        --ans[a[i]];
    if(0 == flag)
    {
        printf("No\n");
        return 0;
    }
    for(iter = ans.begin(); iter != ans.end(); ++iter)
    {
        if(iter->second != 0)
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n%s\n",a.c_str());
    return 0;
}
