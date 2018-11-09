#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int> mars;
    string a[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string b[] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    for(int i = 0; i < 13; ++i)
    {
        mars[a[i]] = i;
        mars[b[i]] = i * 13;
    }
    int n;
    scanf("%d\n",&n);
    while(n--)
    {
        string temp;
        getline(cin,temp);
        if(isdigit(temp[0]))//地球转火星
        {
            int num = atoi(temp.c_str());
            int high = num / 13,low = num % 13;
            printf("%s",b[high].c_str());
            if(high && low) printf(" %s",a[low].c_str());
            if(!high) printf("%s",a[low].c_str());
        }//火星转地球
        else
        {
            if(temp.length() > 3) printf("%d",mars[temp.substr(0,3)] + mars[temp.substr(4)]);
            else printf("%d",mars[temp]);
        }
        printf("\n");
    }
    return 0;
}

