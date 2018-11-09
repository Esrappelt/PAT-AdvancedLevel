#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int cnt = 0;
    map<char,int> ans;
    string a,b;
    cin >> a >> b;
    for(unsigned int i = 0; i < a.length(); ++i)
        ans[a[i]]++;
    for(unsigned int i = 0; i < b.length(); ++i)
    {
        if(ans[b[i]] > 0)
            ans[b[i]]--;
        else
            cnt++;
    }
    if(cnt)
        printf("No %d\n",cnt);
    else
        printf("Yes %d\n",a.length() - b.length());
    return 0;
}
