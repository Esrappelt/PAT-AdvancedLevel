#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string,int> ans;
    string pattern,tmp;
    getline(cin,pattern,'\n');
    int i = 0,max = 0;
    while(i <= pattern.length())
    {
        pattern[i] = tolower(pattern[i]);
        if(isalnum(pattern[i]))//isalnum()���� ����ĸ������
            tmp += pattern[i++];
        else
        {
            ans[tmp]++;
            tmp.clear();
            while(!isalnum(pattern[i])) i++;
        }
    }
    for(auto it = ans.begin(); it != ans.end(); ++it)
    {
        if(it->second > max)
            max = it->second;
    }
    //������ĸ���������һ��
    for(auto it = ans.begin(); it != ans.end(); ++it)
    {
        if(it->second == max)
        {
            cout << it->first << ' ' << it->second << endl;
            break;
        }
    }
    return 0;
}
