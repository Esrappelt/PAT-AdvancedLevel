#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct stu
{
    string ID;
    int A,C,M,E;
    int ra,rc,rm,re;
}SS[10010];
bool cmp1(const stu a,const stu b) {return a.A > b.A;}
bool cmp2(const stu a,const stu b) {return a.C > b.C;}
bool cmp3(const stu a,const stu b) {return a.M > b.M;}
bool cmp4(const stu a,const stu b) {return a.E > b.E;}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i = 0; i < n; ++i)
        {
            cin >> SS[i].ID;
            scanf("%d%d%d",&SS[i].C,&SS[i].M,&SS[i].E);
            SS[i].A = (SS[i].C + SS[i].M + SS[i].E) / 3;
            SS[i].ra = SS[i].rc = SS[i].rm = SS[i].re = 1;
        }
        sort(SS,SS + n,cmp1);
        int count = 1;
        for(int i = 1; i < n; ++i)
        {
            if(SS[i].A == SS[i-1].A)
            {
                SS[i].ra = SS[i-1].ra;
                count++;
            }
            else
            {
                SS[i].ra = SS[i-1].ra + count;
                count = 1;
            }
        }
        sort(SS,SS + n,cmp2);
        count = 1;
        for(int i = 1; i < n; ++i)
        {
            if(SS[i].C == SS[i-1].C)
            {
                SS[i].rc = SS[i-1].rc;
                count++;
            }
            else
            {
                SS[i].rc = SS[i-1].rc + count;
                count = 1;
            }
        }
        sort(SS,SS + n,cmp3);
        count = 1;
        for(int i = 1; i < n; ++i)
        {
            if(SS[i].M == SS[i-1].M)
            {
                SS[i].rm = SS[i-1].rm;
                count++;
            }
            else
            {
                SS[i].rm = SS[i-1].rm + count;
                count = 1;
            }
        }
        sort(SS,SS + n,cmp4);
        count = 1;
        for(int i = 1; i < n; ++i)
        {
            if(SS[i].E == SS[i-1].E)
            {
                SS[i].re = SS[i-1].re;
                count++;
            }
            else
            {
                SS[i].re = SS[i-1].re + count;
                count = 1;
            }
        }
        for(int i = 0; i < m; ++i)
        {
            string goal;
            cin >> goal;
            int j = 0;
            for(j = 0; j < n; ++j)
                if(SS[j].ID == goal) break;
            if(j == n) printf("N/A\n");
            else
            {
                char high = 'E';
                int temp = SS[j].re;
                if(temp >= SS[j].rm)
                {
                    high = 'M';
                    temp = SS[j].rm;
                }
                if(temp >= SS[j].rc)
                {
                    high = 'C';
                    temp = SS[j].rc;
                }
                if(temp >= SS[j].ra)
                {
                    high = 'A';
                    temp = SS[j].ra;
                }
                printf("%d %c\n",temp,high);
            }
        }
    }
    return 0;
}
