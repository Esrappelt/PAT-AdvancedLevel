#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    int tmp[N];
    map<int,int> ans;
    for(int i = 0; i < N; ++i)
    {
        scanf("%d",&tmp[i]);
        ans[tmp[i]]++;
    }
    for(int i = 0; i < N; ++i)
    {
        if(1 == ans[tmp[i]])
        {
            printf("%d\n",tmp[i]);
            return 0;
        }
    }
    printf("None\n");
    return 0;
}
