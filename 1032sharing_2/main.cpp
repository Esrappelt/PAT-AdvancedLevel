#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int ans[100000],nextad[100000];
int main()
{
    int first,second,N,ad;
    char data;
    scanf("%d%d%d",&first,&second,&N);
    for(int i = 0; i < N; ++i)
    {
        scanf("%d",&ad);
        scanf(" %c %d",&data,&nextad[ad]);
    }
    for(int i = first; i != -1; i = nextad[i])
        ans[i] = 1;
    for(int i = second; i != -1; i = nextad[i])
        if(ans[i])
        {
            printf("%05d\n",i);
            return 0;
        }
    printf("-1\n");
    return 0;
}
