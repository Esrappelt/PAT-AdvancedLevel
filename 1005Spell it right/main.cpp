#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void show(int op)
{
    switch(op)
    {
    case 0:
        printf("zero");
        break;
    case 1:
        printf("one");
        break;
    case 2:
        printf("two");
        break;
    case 3:
        printf("three");
        break;
    case 4:
        printf("four");
        break;
    case 5:
        printf("five");
        break;
    case 6:
        printf("six");
        break;
    case 7:
        printf("seven");
        break;
    case 8:
        printf("eight");
        break;
    case 9:
        printf("nine");
        break;
    }
}

void fun(const vector<int> ans)
{
    for(int i = 0; i < ans.size(); ++i)
    {
        if(i == ans.size() - 1)
            show(ans[i]);
        else
        {
            show(ans[i]);
            printf(" ");
        }
    }
}

int main()
{
    int sum = 0,i = 0;
    string a;
    vector<int> ans;
    cin >> a;
    while(i < a.size())
    {
        sum += a[i] - '0';
        ++i;
    }
    if(sum == 0)
    {
        printf("zero\n");
        return 0;
    }
    while(sum)
    {
        ans.push_back(sum%10);
        sum /= 10;
    }
    reverse(ans.begin(),ans.end());
    fun(ans);
	return 0;
}
/*
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10^100).

Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five
*/
