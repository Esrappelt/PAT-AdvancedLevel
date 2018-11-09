#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n1,n2,back = 0;
    scanf("%d",&n1);
    vector<int> cp(n1);
    for(int i = 0; i < n1; ++i) scanf("%d",&cp[i]);
    scanf("%d",&n2);
    vector<int> vn(n2);
    for(int i = 0; i < n2; ++i) scanf("%d",&vn[i]);
    sort(cp.begin(),cp.end());
    sort(vn.begin(),vn.end());
    for(int a = 0,b = 0; a < n1 && b < n2 && cp[a] < 0 && vn[b] < 0; ++a,++b) back += cp[a] * vn[b];
    for(int a = n1 - 1,b = n2 - 1; a >= 0 && b >= 0 && cp[a] > 0 && vn[b] > 0; --a,--b) back += cp[a] * vn[b];
    printf("%d\n",back);
    return 0;
}
