#include <bits/stdc++.h>
using namespace std;
bool flag[200];
int main()
{
    int k,cnt = 1;
    unsigned int i;
    map<char,bool> res;
    set<char> ans;
    string a;
    scanf("%d", &k);
    getchar();
    getline(cin,a);
    a += '*';
    for(i = 1; i < a.length(); ++i)
    {
        char c = a[i-1];
        if(c == a[i])
        {
            cnt++;
            continue;
        }
        if(cnt % k != 0)//һ�����ǻ���
        {
            res[c] = false;
            flag[c] = true;
        }
        else//�����ǻ���
            res[c] = true;
        cnt = 1;
    }
    for(i = 0; i < a.length() - 1; ++i)
    {
        if(flag[a[i]] == true)//һ�����ǻ���
            res[a[i]] = false;
    }
    for(i = 0; i < a.length() - 1; ++i)
    {
        if( !ans.count(a[i]) && res[a[i]])//�ǻ��ģ����Ҳ����ظ�
            ans.insert(a[i]);
    }
    for(auto it = ans.begin(); it != ans.end(); ++it)
        printf("%c",*it);
    printf("\n");
    i = 0;
    while(i < a.length() - 1)
    {
        printf("%c",a[i]);
        if(res[a[i]])//�ǻ���
            i += k;
        else
            ++i;
    }
    return 0;
}
