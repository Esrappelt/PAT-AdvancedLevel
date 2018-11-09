#include <bits/stdc++.h>
using namespace std;

bool change(string num)
{
    int a = 0,b = 0,c = 0;
    int m = num.length()/2,n = num.length();
    for(int i = 0; i < n; ++i)
    {
        int x = (num[i] - '0');
        c += x * pow(10,n - i - 1);
        if(i >= m )
            a += x * pow(10,n - i - 1);
    }
    b = (c - a)/(pow(10,m));
    //printf("a = %d,b = %d,c = %d\n",a,b,c);
    if( (a && b) && !( c % (a * b) ) )
        return true;
    return false;
}


int main()
{
    int n;
    string num;
    scanf("%d",&n);
    while(n--)
    {
        cin >> num;
        if(change(num))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
/*
Cutting an integer means to cut a K digits long integer Z into two integers of (K/2) digits long integers A and B. For example, after cutting Z = 167334, we have A = 167 and B = 334. It is interesting to see that Z can be devided by the product of A and B, as 167334 / (167 x 334) = 3. Given an integer Z, you are supposed to test if it is such an integer.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<= 20). Then N lines follow, each gives an integer Z (10<=Z<=231). It is guaranteed that the number of digits of Z is an even number.

Output Specification:

For each case, print a single line "Yes" if it is such a number, or "No" if not.

Sample Input:
3
167334
2333
12345678
Sample Output:
Yes
No
No

*/
