#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i = 0; i < n; ++i) scanf("%d",&a[i]);
    sort(a.begin(),a.end());
    double ans = a[0];
    for(int i = 1; i < n; ++i) ans = (double)(ans + a[i]) / 2;
    printf("%d",(int)(ans));
    return 0;
}
