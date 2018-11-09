#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void change(int ans[],int res[],int all[])
{
    for(int i = 1; i <= 54; ++i)
    {
        int j = res[i];
        int val = ans[i];
        all[j] = val;
    }
}
int main()
{
    string name[] = {"",
                    "S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
                    "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
                    "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
                    "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
                    "J1","J2"
    };
    int N,res[55],ans[55],all[55];
    scanf("%d", &N);
    for(int i = 1; i <= 54; ++i)
        scanf("%d", &res[i]);

    for(int i = 1; i <= 54; ++i)
        ans[i] = i;
    for(int j = 0; j < N; ++j)
    {
        change(ans,res,all);
        for(int k = 1; k <= 54; ++k)
            ans[k] = all[k];
    }
    for(int i = 1; i <= 54; ++i)
    {
        printf("%s",name[all[i]].c_str());
        if(i < 54)
            printf(" ");
    }
    return 0;
}
