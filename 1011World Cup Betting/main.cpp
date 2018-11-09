#include <iostream>
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int index;
    double max;
    bool operator<(const node &x)
    {
        return  max < x.max;
    }
};


int main()
{
    int no = 0;
    node res[3];
    char a[3] = {'W','T','L'};
    double ans;
    double sum = 1.0;
    for(int i = 0; i < 3; ++i)
    {
        double max = 0;
        for(int j = 0; j < 3; ++j)
        {
            scanf("%lf",&ans);
            if(max < ans)
            {
                no = j;
                max = ans;
            }
        }
        res[i].index = no;
        res[i].max = max;
        sum *= max;
    }
    sort(res,res+3);
    for(int i = 0; i < 3; ++i)
        printf("%c ",a[res[i].index]);
    printf("%.2f\n",(sum * 0.65 - 1) * 2);
    return 0;
}
