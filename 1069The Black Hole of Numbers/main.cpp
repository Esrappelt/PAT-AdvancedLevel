#include <bits/stdc++.h>
#include<string>
using namespace std;
bool cmp(char x,char y){return x > y;}
int main()
{
    string ans;
    cin >> ans;
    if(ans.length() < 4)
        ans.insert(0,4-ans.length(),'0');
    do
    {
        string x,y;
        x = y = ans;
        sort(x.begin(),x.end(),cmp);//½µÐò
        sort(y.begin(),y.end());//ÉýÐò
        int result =  atoi(x.c_str()) - atoi(y.c_str());
        ans = to_string(result);
        ans.insert(0,4-ans.length(),'0');
        cout << x << " - " << y << " = " << ans << endl;
    }while(ans != "6174" && ans != "0000");
    return 0;
}
