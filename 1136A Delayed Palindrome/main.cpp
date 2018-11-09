#include <bits/stdc++.h>
using namespace std;
bool Palindrome(string num)
{
    for(int i = 0; i < num.length(); ++i)
        if(num[i] != num[num.length() - i - 1])
            return false;
    return true;
}
void Add(string a)
{
    static int dep = 0;
    if(dep == 10) { printf("Not found in 10 iterations.\n"); return;}
    string b(a),t(a);
    reverse(b.begin(),b.end());
    int gobit = 0;
    for(int i = b.length() - 1; i >= 0; --i)
    {
        int x = (a[i] - '0') + (b[i] - '0') + gobit;
        a[i] = x % 10 + '0';
        gobit = x / 10;
    }
    if(gobit != 0) a.insert(0,"1");
    printf("%s + %s = %s\n",t.c_str(),b.c_str(),a.c_str());
    if(Palindrome(a)) printf("%s is a palindromic number.\n",a.c_str());
    else { ++dep; Add(a);}
}
int main()
{
    string num;
    cin >> num;
    if(Palindrome(num)) printf("%s is a palindromic number.\n",num.c_str());
    else Add(num);
    return 0;
}
