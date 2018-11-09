#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,cnt = 0,i,j;
    char str1[10000],str2[10000];
    double sum = 0,temp;
    scanf("%d",&N);
    fflush(stdin);
    for(i = 0; i < N; i++)
    {
        scanf("%s ",str1);
        sscanf(str1,"%lf",&temp);//读str1这个字符串,自动获取str里的东西放入temp
        sprintf(str2,"%.2f",temp);//按照.2lf格式放入str2中
        for(j = 0; j < strlen(str1); j++)
            if(str1[j] != str2[j]) break;
        if(j != strlen(str1) || temp < -1000 || temp > 1000) printf("ERROR: %s is not a legal number\n",str1);
        else { sum += temp; cnt++; }
    }
    if(cnt == 1) printf("The average of 1 number is %.2f\n",sum);
    else if(cnt > 1) printf("The average of %d numbers is %.2f\n",cnt,sum / cnt);
    else printf("The average of 0 numbers is Undefined\n");
    return 0;
}
