#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,m = 0,n = 0;
    long int tmp;
    vector<long int > s1,s2,ans;
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)
    {
        scanf("%ld",&tmp);
        s1.push_back(tmp);
    }
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)
    {
        scanf("%ld",&tmp);
        s2.push_back(tmp);
    }
    //归并排序
    while(m < s1.size() && n < s2.size())
    {
        if(s1[m] < s2[n])
        {
            ans.push_back(s1[m]);
            m++;
        }
        else
        {
            ans.push_back(s2[n]);
            n++;
        }
    }
    while(m < s1.size())
    {
        ans.push_back(s1[m]);
        m++;
    }
    while(n < s2.size())
    {
        ans.push_back(s2[n]);
        n++;
    }
    printf("%ld\n",ans[(ans.size() - 1)/2]);
    return 0;
}

/*
解法二：
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int m, n, p = 0, q = 0;
    scanf("%d", &m);
    vector<long int> v1(m);
    for(int i = 0; i < m; i++)
        scanf("%ld", &v1[i]);
    scanf("%d", &n);
    vector<long int> v2(n);
    for(int i = 0; i < n; i++)
        scanf("%ld", &v2[i]);
    int cnt = ((m + n) - 1) / 2;
    while(cnt) {
        while(p < m && q < n && v1[p] < v2[q] && cnt) {
            p++;
            cnt--;
        }
        while(p < m && q < n && v1[p] >= v2[q] && cnt) {
            q++;
            cnt--;
        }
        while(p < m && q >= n && cnt) {
            p++;
            cnt--;
        }
        while(p >= m && q < n && cnt) {
            q++;
            cnt--;
        }
    }
    long int ans;
    if(p < m && q < n)
        ans = v1[p] < v2[q] ? v1[p] : v2[q];
    else
        ans = p < m ? v1[p] : v2[q];
    printf("%ld", ans);
    return 0;
}
*/
