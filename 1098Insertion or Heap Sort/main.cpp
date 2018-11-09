#include <bits/stdc++.h>
using namespace std;
vector<int> ans1,ans2;
int n;
void Adjust(int i,int n)
{
    int j = 2 * i + 1;
    while(j < n)
    {
        if(j < n - 1 && ans2[j] < ans2[j+1]) ++j;
        if(ans2[j] > ans2[i]) swap(ans2[i],ans2[j]);
        else break;
        i = j,j = 2 * j + 1;
    }
}
void Heapsort()
{
    int i = n - 1;
    while( i > 0 && ans2[i] >= ans2[i-1]) --i;
    swap(ans2[0],ans2[i]);
    Adjust(0,i);
}
void Judge()
{
    int i = 1;
    while(i < n && ans2[i - 1] <= ans2[i]) ++i;
    int j = i;
    while(i < n && ans1[i] == ans2[i]) ++i;
    printf("%s\n",i == n ? "Insertion Sort" : "Heap Sort");
    if(i == n) sort(ans2.begin(),ans2.begin() + j + 1);//²åÈëÅÅÐò
    else Heapsort();//¶ÑÅÅÐò
    for(int j = 0; j < n; ++j) printf("%d%c",ans2[j], j == n - 1 ? '\n' : ' ');
}
int main()
{
    scanf("%d",&n);
    ans1.resize(n),ans2.resize(n);
    for(int i = 0; i < n; ++i) scanf("%d",&ans1[i]);
    for(int i = 0; i < n; ++i) scanf("%d",&ans2[i]);
    Judge();
    return 0;
}
