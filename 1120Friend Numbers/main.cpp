#include <bits/stdc++.h>
using namespace std;
int Friend(string tmp)
{
    int sum = 0;
    for(int i = 0; i < tmp.length(); ++i)
        sum += (tmp[i] - '0');
    return sum;
}
int main()
{
    set<int> ans;
    int n,k = 0;
    string tmp;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
    {
        cin >> tmp;
        ans.insert(Friend(tmp));
    }
    printf("%d\n",ans.size());
    for(auto it = ans.begin(); it != ans.end(); ++it,++k)
        printf("%d%c", *it,k == ans.size() - 1 ? '\n' : ' ');
    return 0;
}
