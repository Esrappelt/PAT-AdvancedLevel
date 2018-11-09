#include <bits/stdc++.h>
using namespace std;
void cmp(string a,string &b)
{
    for(int i = 0,j = 0; i < a.length() && j < b.length(); ++i,++j)
    {
        if(a[i] != b[j])
        {
            b = b.substr(0,j);
            break;
        }
    }
}
int main()
{
    int n;
    string name,ans;
    scanf("%d\n",&n);
    getline(cin,ans);
    reverse(ans.begin(),ans.end());
    for(int i = 1; i < n; ++i)
    {
        getline(cin,name);
        reverse(name.begin(),name.end());
        cmp(name,ans);
    }
    reverse(ans.begin(),ans.end());
    printf("%s",ans.empty() ? "nai" : ans.c_str());
    return 0;
}



