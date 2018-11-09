#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b,c,d,week[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    cin >> a >> b >> c >> d;
    for(int i = 0,flag = 0; i < a.length() && i < b.length(); ++i)
    {
        if(!flag && a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G' )
        {
            printf("%s ",week[a[i]-'A'].c_str());
            flag = 1;
        }
        else if(flag && a[i] == b[i] && ( isdigit(a[i]) || a[i] >= 'A' && a[i] <= 'N' ))
        {
            printf("%02d:",isdigit(a[i]) ? (a[i] - '0') : (a[i] - 'A') + 10);
            break;
        }
    }
    for(int i = 0; i < c.length() && i < d.length(); ++i)
    {
        if(isalpha(c[i]) && c[i] == d[i])
        {
            printf("%02d",i);
            break;
        }
    }
    return 0;
}
