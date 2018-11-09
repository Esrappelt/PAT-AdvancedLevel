#include <bits/stdc++.h>
using namespace std;
int main()
{
    map< string,set<int> > booktitle,author,keyord,publisher,year;
    int n,query,k,id;
    char ch;
    scanf("%d",&n);
    while(n--)
    {
        string t1,t2,t3,t4,t5;
        scanf("%d",&id);
        getchar();
        getline(cin,t1);
        booktitle[t1].insert(id);
        getline(cin,t2);
        author[t2].insert(id);
        while(1)
        {
            cin >> t3;
            keyord[t3].insert(id);
            if((ch = getchar()) == '\n')
                break;
        }
        getline(cin,t4);
        publisher[t4].insert(id);
        getline(cin,t5);
        year[t5].insert(id);
    }
    scanf("%d",&query);
    for(int i = 0; i < query; ++i)
    {
        scanf("%d: ",&k);
        string tmp;
        getline(cin,tmp);
        printf("%d: %s\n",k,tmp.c_str());
        if(k == 1)
        {
            if(booktitle.find(tmp) != booktitle.end())
                for(auto jt = booktitle[tmp].begin(); jt != booktitle[tmp].end(); ++jt)
                    printf("%07d\n",*jt);
            else
                printf("Not Found\n");
        }
        else if(k == 2)
        {
            if(author.find(tmp) != author.end())
                for(auto jt = author[tmp].begin(); jt != author[tmp].end(); ++jt)
                    printf("%07d\n",*jt);
            else
                printf("Not Found\n");
        }
        else if(k == 3)
        {
            if(keyord.find(tmp) != keyord.end())
                for(auto jt = keyord[tmp].begin(); jt != keyord[tmp].end(); ++jt)
                    printf("%07d\n",*jt);
            else
                printf("Not Found\n");
        }
        else if(k == 4)
        {
            if(publisher.find(tmp) != publisher.end())
                for(auto jt = publisher[tmp].begin(); jt != publisher[tmp].end(); ++jt)
                    printf("%07d\n",*jt);
            else
                printf("Not Found\n");
        }
        else
        {
            if(year.find(tmp) != year.end())
                for(auto jt = year[tmp].begin(); jt != year[tmp].end(); ++jt)
                    printf("%07d\n",*jt);
            else
                printf("Not Found\n");
        }
    }
    //system("pause");
    return 0;
}
