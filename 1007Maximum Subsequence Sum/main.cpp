#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//������
int main()
{

    int N,temp = 0,maxsum = -1,start = 0,end = 0;
    vector<int> ans;
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)
    {
        scanf("%d",&temp);
        ans.push_back(temp);
    }
 /*   //�ⷨһ��
    for(int i = 0; i < ans.size(); ++i)
    {
        temp = 0;
        for(int j = i; j < ans.size(); ++j)
        {
            temp += ans[j];
            if(temp > maxsum)
            {
                maxsum = temp;
                start = ans[i];//first number
                end = ans[j];//final number
            }
        }
    }
    if(maxsum < 0)//��С��0�Ͱ����������
        printf("%d %d %d\n",0,ans[0],ans[N-1]);
    else
        printf("%d %d %d\n",maxsum,start,end);
*/
    //�ⷨ����
    int index_i = 0,index_j = 0,index_start = 0,index_end = ans.size() - 1;
    for(int i = 0; i < ans.size(); ++i)
    {
        if(temp >= 0)//ֻҪ����0 �������Ž�
        {
            temp += ans[i];
            index_j = i;
        }
        else
        {
            temp = ans[i];
            index_i = index_j = i;//ʧ����������
        }
        if(temp > maxsum || (temp == 0 && index_end == ans.size() - 1))
        {
            maxsum = temp;
            index_start = index_i;
            index_end = index_j;
        }
    }
    printf("%d %d %d\n",maxsum,ans[index_start],ans[index_end]);
    return 0;
}
//ע��
/*
Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/
