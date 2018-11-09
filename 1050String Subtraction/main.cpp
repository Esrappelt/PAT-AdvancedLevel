#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Given two strings S1 and S2, S = S1 - S2 is defined to be the remaining string after taking all the characters in S2 from S1. Your task is simply to calculate S1 - S2 for any given strings. However, it might not be that simple to do it fast.

Input Specification:

Each input file contains one test case. Each case consists of two lines which gives S1 and S2, respectively. The string lengths of both strings are no more than 104. It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.

Output Specification:

For each test case, print S1 - S2 in one line.

Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts.
*/

int visited[200];

int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(int i = 0; i < b.length(); ++i)
        visited[b[i]]++;
    for(int i = 0; i < a.length(); ++i)
    {
        if(!visited[a[i]])
            printf("%c",a[i]);
    }
    return 0;
}
