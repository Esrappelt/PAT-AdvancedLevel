
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool judge(const string a)
{
    int i = 0,j = a.length() - 1;
    while(i < j)
    {
        if(a[i] != a[j])
            return false;
        ++i;
        --j;
    }
    return true;
}


string bigIntergerAdd(string &num)
{
    string ans(num);
    string add(num);
    reverse(add.begin(),add.end());
    int goBit = 0; // 存放进位
    // 利用string的+号特性  不采用逆序相加法
    for(int i = num.length() - 1; i >= 0; --i)
    {
        int tmp = (num[i] - '0') + (add[i] - '0') + goBit;
        num[i] = tmp % 10  + '0';
        goBit = tmp/10;
    }
    // 特殊情况处理
    if (goBit != 0)
        num.insert(0, "1");//第0个位置插入"1"
    return num;
}

int main()
{
    int i,k;
    string a;
    cin >> a >> k;
    for(i = 0; i < k; ++i)
    {
        if(judge(a))
            break;
        else
            a = bigIntergerAdd(a);
    }
    printf("%s\n%d\n",a.c_str(),i);
    return 0;
}

