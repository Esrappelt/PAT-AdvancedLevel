#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int k,n1 = 0,n2;
    cin >> s;
    for(n2 = 3; n2 <= s.length(); ++n2)
    {
        for(k = 1; k <= n2; ++k)
            if(2 * k + n2 == s.length() + 2 && k > n1) n1 = k;
    }
    n2 = s.length() + 2 - 2 * n1;
    for(int i = 0; i < n1 - 1; ++i)
    {
        printf("%c",s[i]);
        for(int j = 0; j < n2 - 2; ++j) putchar(' ');
        printf("%c\n",s[s.length()- i - 1]);
    }
    printf("%s",s.substr(n1 - 1,n2).c_str());
    return 0;
}

